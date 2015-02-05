//
//  NSMeapWebRequest.m
//  Cordova_TEST
//
//  Created by yalin on 13-7-15.
//
//

#import "NSMeapWebRequestPlugin.h"

@interface NSMeapWebRequestPlugin () <NSMeapRequestDelegate>

@property (nonatomic, retain) NSMeapUploadFile        *uploadRequest;

@property (nonatomic, retain) NSMeapRequest              *request;

@property (nonatomic, retain) NSString          *currentCallBackID;

@end

@implementation NSMeapWebRequestPlugin

- (void)dealloc
{
//    REMOVE_NOTIFICATION(UPLOAD_SUCCESS_NOTIFICATION, self, nil);
    [_uploadRequest release];
    [_currentCallBackID release];
    [_request release];
    [super dealloc];
}

- (id)init
{
    self = [super init];
    if (self)
    {
//        ADD_NOTIFICATION(UPLOAD_SUCCESS_NOTIFICATION, self, @selector(uploadSuccess:), nil);
        self.uploadRequest = [[[NSMeapUploadFile alloc] init] autorelease];
    }
    return self;
}

- (void)uploadSuccess:(NSNotification *)noti
{
    NSString *name = [noti object];
//    NSLog(@"%@ 上传成功!",name);
    
    CDVPluginResult *result = nil;
    NSString *jsString = nil;
    
    NSString *returnStr = [NSString stringWithFormat:@"%@ 上传成功!",name];
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:returnStr];
    jsString = (NSString *)[result toSuccessCallbackString:self.currentCallBackID];
//    NSLog(@"jsString: %@",jsString);
    
    [self writeJavascript:jsString];
}

- (void)httpRequest:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    if ([arguments count] < 7)
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"NativeRequest 服务 参数数目不对!"];
        [self error:result callbackId:self.currentCallBackID];
        
        return;
    }
    
    self.currentCallBackID = (NSString *)[arguments objectAtIndex:0];
    NSString *method = (NSString *)[arguments objectAtIndex:1];
    NSString *bodyJson = (NSString *)[arguments objectAtIndex:2];
    NSString *isHttps = (NSString *)[arguments objectAtIndex:3];//01 http 02 单向https  03 双向https
    NSString *encryptionType=(NSString *)[arguments objectAtIndex:4];// 01 无加密 02 3des 03 rsa
    NSString *isSalt=(NSString *)[arguments objectAtIndex:5];
    NSString *isCompres=(NSString *)[arguments objectAtIndex:6];
    
//    NSString *filePath = [[NSBundle mainBundle] pathForResource:@"国信灵通（NQSKY）MEAP技术白皮书" ofType:@"pdf"];
//    
//    if (!_uploadRequest)
//    {
//        ADD_NOTIFICATION(UPLOAD_SUCCESS_NOTIFICATION, self, @selector(uploadSuccess:), nil);
//        self.uploadRequest = [[[MeapUploadFile alloc] init] autorelease];
//    }
    
    self.request = [[[NSMeapRequest alloc] init] autorelease];
//    [self.uploadRequest addUploadFileWithFileName:@"国信灵通（NQSKY）MEAP技术白皮书.pdf" filePath:filePath];
    if ([isHttps isEqualToString:@"01"])
    {
        self.request.isHttps = NO;
    }
    else if([isHttps isEqualToString:@"02"])
    {
        self.request.isHttps = YES;
    }
    else if ([isHttps isEqualToString:@"03"])
    {
        self.request.isHttps = YES;
        [self.request setHttpsBidirectionalAuthCertificateFilePath:[[NSBundle mainBundle] pathForResource:@"yyl" ofType:@".p12"] cerPassword:@"123456"];
    }
    
    if ([arguments count] >= 8)
    {
        NSString *interface = [arguments objectAtIndex:8];
        self.request.interface = interface;
    }
    
    if ([arguments count] >= 9)
    {
        NSString *group = [arguments objectAtIndex:9];
        self.request.group = group;
    }
    
    if ([encryptionType isEqualToString:@"01"])
    {
        self.request.encryptType = DATA_NO_ENCRYPT;
    }
    else if ([encryptionType isEqualToString:@"02"])
    {
        self.request.encryptType = DATA_3DES_ENCRYPT;
    }
    else if ([encryptionType isEqualToString:@"03"])
    {
        self.request.encryptType = DATA_RSA_ENCRYPT;
    }
    
    self.request.hasHttpSalt = [isSalt isEqualToString:@"true"] ? YES : NO;
    self.request.isZip = [isCompres isEqualToString:@"true"] ? YES : NO;
    self.request.httpDelegate = self;
    [self.request setMethod:method];
    
    
    if ([arguments count] >= 7)
    {
        NSString *version = (NSString *)[arguments objectAtIndex:7];
        self.request.version=version;
        if (version && ![version isEqualToString:@""]) {
            version = version;
        }
    }
//    [self.request setHeadParma:@"version" dataType:STRING_ATT_TYPE value:@"0.1"];
    
    NSMeapDataTree *bodyTree = [NSMeapDataTree treeWithJSONString:bodyJson];
    NSMeapDataBean *bodyBean = [bodyTree rootBean];
    for (NSString *attName in [bodyBean.attributeInfo allKeys])
    {
        NSArray *attArr = [bodyBean meapAttsWithIndexString:attName];
        for (NSMeapDataAtt *att in attArr)
        {
            [self.request appendBodyParma:att.elementName dataType:att.data_type value:att.value];
        }
    }
    
    for (NSMeapDataBean *childBean in bodyBean.subBeans)
    {
        [self.request appendBodyBeanValue:childBean];
    }
    
    [self.request startAsynchronous];
    
}

//-----------
// 请求成功时调用方法
// request: 当前请求对象
// tree: 请求成功后生成的tree对象
//-----------
- (void)meapHttp:(NSMeapRequest *)request requestSuccessHeadTree:(NSMeapDataTree *)headTree bodyTree:(NSMeapDataTree *)bodyTree
{
    CDVPluginResult *result = nil;
//    NSString *jsString = nil;
    
    NSString *returnStr = [bodyTree JSONString];
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:returnStr];
    [self success:result callbackId:self.currentCallBackID];
    
//    jsString = (NSString *)[result toSuccessCallbackString:self.currentCallBackID];
//    NSLog(@"success jsString: %@",jsString);
//    
//    [self writeJavascript:jsString];
}

//-----------
// 请求成功时 code为0 是调用的方法
// request: 当前请求对象
// tree: 请求成功后生成的tree对象
//-----------
- (void)meapHttp:(NSMeapRequest *)request requestFailedHeadTree:(NSMeapDataTree *)headTree bodyTree:(NSMeapDataTree *)bodyTree
{
    CDVPluginResult *result = nil;
//    NSString *jsString = nil;
    
    NSString *returnStr = [bodyTree JSONString];
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:returnStr];
    [self error:result callbackId:self.currentCallBackID];
    
//    jsString = (NSString *)[result toErrorCallbackString:self.currentCallBackID];
//    jsString = (NSString *)[result toSuccessCallbackString:self.currentCallBackID];
//    NSLog(@"fail jsString: %@",jsString);
    
//    [self writeJavascript:jsString];
}

@end
