//
//  NSMeapQRCodePlugin.m
//  Cordova_TEST
//
//  Created by 十九 on 13-7-19.
//
//

#import "NSMeapQRCodePlugin.h"
#import "NSMeapQRCode.h"
@interface NSMeapQRCodePlugin ()<NSMeapQRCodeDelegate>

@property (nonatomic,retain) NSString *currentCallBackID;

@end
@implementation NSMeapQRCodePlugin

- (void)dealloc
{
    self.currentCallBackID = nil;
    
    [super dealloc];
}

//------------
//字符串生成二维码图片插件调用接口
//arguments: 参数数组
//0: id
//1:text 字符串
//2:imageSize 图片大小
//------------
-(void)qrImageForString:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.currentCallBackID = [arguments objectAtIndex:0];
    if ([arguments count]>2)
    {
        UIImage *image=[NSMeapQRCode qrImageForString:[arguments objectAtIndex:1] imageSize:[[arguments objectAtIndex:2]floatValue]];
        
        NSData *imageData;
        NSString *path;
        NSString *fileName;
        if (UIImagePNGRepresentation(image) == nil)
        {
            fileName = [[[NSDate date] description] stringByAppendingString:@"qrImage.jpg"];
            imageData = UIImageJPEGRepresentation(image, 1);
            path=[NSTemporaryDirectory() stringByAppendingString:fileName];
            [imageData writeToFile:path atomically:YES];
            
        }
        else
        {
            fileName = [[[NSDate date] description] stringByAppendingString:@"qrImage.png"];
            imageData = UIImagePNGRepresentation(image);
            path=[NSTemporaryDirectory() stringByAppendingString:fileName];
            [imageData writeToFile:path atomically:YES];
        }
        if (imageData!=nil&&path!=nil)
        {
            CDVPluginResult *result = nil;
            NSString *returnStr = path;
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:returnStr];
            [self success:result callbackId:self.currentCallBackID];
        }
        else
        {
            CDVPluginResult *result = nil;
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"QRCode 参数数目不对!"];
            [self error:result callbackId:self.currentCallBackID];
        }
        
    }
    else
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"QRCode 参数数目不对!"];
        [self error:result callbackId:self.currentCallBackID];
    }
}

//-----------
//扫描二维码 插件接口
//arguments: 参数数组
//0: id
//1:superController 要调用扫面页面的controller
//-----------
-(void)scanQRCodeWithController:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.currentCallBackID = [arguments objectAtIndex:0];
    if ([[[UIDevice currentDevice]localizedModel]isEqualToString:@"iPhone Simulator"]||[[[UIDevice currentDevice]localizedModel]isEqualToString:@"iPad Simulator"]) {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"设备不支持扫描!"];
        [self error:result callbackId:self.currentCallBackID];
        return;
    }
    [[NSMeapQRCode shareInstance]setDelegate:self];
    [[NSMeapQRCode shareInstance]scanQRCodeWithController:self.viewController];
}

#pragma mark NSMeapQRCode Delegate
-(void)qrStringCallBack:(NSString *)result{
    CDVPluginResult *presult = nil;
    NSString *returnStr=result;
    presult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:returnStr];
    [self success:presult callbackId:self.currentCallBackID];
}
@end
