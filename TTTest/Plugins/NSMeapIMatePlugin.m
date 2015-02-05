//
//  NSMeapIMate.m
//  Cordova_TEST
//
//  Created by 韩立娜 on 13-9-16.
//
//

#import "NSMeapIMatePlugin.h"
#import <HXiMateSDK/iMateAppFace.h>
#import <NSMeap/GTMBase64.h>
#import "SBJson.h"

@interface NSMeapIMatePlugin () <iMateAppFaceDelegate>

@property (nonatomic, retain) NSString      *currentCallBackID;
@property (nonatomic, retain) iMateAppFace  *imateAppFace;

@end

@implementation NSMeapIMatePlugin

-(void)dealloc
{
    self.currentCallBackID = nil;
    [self.imateAppFace cancel];
    
    [super dealloc];
}

- (void)dispose
{
    [self.imateAppFace cancel];
    [super dispose];
}

- (CDVPlugin*)initWithWebView:(UIWebView*)theWebView
{
     NSMeapIMatePlugin *plugin = [super initWithWebView:theWebView];
    if (plugin)
    {
        //获取iMateAppFace实例
        self.imateAppFace = [iMateAppFace sharedController];
        //设置delegate对象
        self.imateAppFace.delegate = self;
    }
    return plugin;
}

/**
 *	@brief	刷卡操作
 *
 *	@param 	arguments 	参数数组：[0]id [1]timeout
 *	@param 	options
 */
- (void)swipeCard:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.currentCallBackID = [arguments objectAtIndex:0];
    if ([arguments count] != 2)
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"NSMeapIMate 参数数目不对!"];
        [self error:result callbackId:self.currentCallBackID];
        return;
    }
    else
    {
        //检查iMate的连接情况
        if ( ![_imateAppFace connectingTest])
        {
            CDVPluginResult *result = nil;
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"iMate蓝牙未连接"];
            [self error:result callbackId:self.currentCallBackID];
            DEBUG_NSLOG(@"iMate未连接");
            return;
        }
        else
        {
            DEBUG_NSLOG(@"iMate已连接");
            NSInteger timeout = [[arguments objectAtIndex:1]intValue];
            if ( [_imateAppFace isWorking] )
            {
                [_imateAppFace cancel];
                return;
            }
            [_imateAppFace swipeCard:timeout];
        }
    }
}


/**
 *	@brief	读取身份证
 *
 *	@param 	arguments 	参数数组：[0]id [1]timeout 身份证放到读卡位置的最长等待时间(秒)
 *	@param 	options
 */
- (void)idReadMessage:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.currentCallBackID = [arguments objectAtIndex:0];
    if ([arguments count] != 2)
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"NSMeapIMate 参数数目不对!"];
        [self error:result callbackId:self.currentCallBackID];
        return;
    }
    else
    {
        //检查iMate的连接情况
        if ( ![_imateAppFace connectingTest])
        {
            CDVPluginResult *result = nil;
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"iMate蓝牙未连接"];
            [self error:result callbackId:self.currentCallBackID];
            DEBUG_NSLOG(@"iMate未连接");
            return;
        }
        else
        {
            DEBUG_NSLOG(@"iMate已连接");
            NSInteger timeout = [[arguments objectAtIndex:1]intValue];
            if ( [_imateAppFace isWorking] )
            {
                [_imateAppFace cancel];
                return;
            }
            [_imateAppFace idReadMessage:timeout];
        }
    }
}

/**
 *	@brief	获取电池电量
 *
 *	@param 	arguments 	参数数组：[0]id
 *	@param 	options
 */
- (void)batteryLevel:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.currentCallBackID = [arguments objectAtIndex:0];
    //检查iMate的连接情况
    if ( ![_imateAppFace connectingTest])
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"iMate蓝牙未连接"];
        [self error:result callbackId:self.currentCallBackID];
        DEBUG_NSLOG(@"iMate未连接");
        return;
    }
    else
    {
        DEBUG_NSLOG(@"iMate已连接");
        if ( [_imateAppFace isWorking] )
        {
            [_imateAppFace cancel];
            return;
        }
        [_imateAppFace batteryLevel];
    }
}

#pragma mark - iMateAppFaceDelegate
- (void)iMateDelegateConnectStatus:(BOOL)isConnecting
{
    if (isConnecting)
    {
        DEBUG_NSLOG(@"iMate连接成功!");
    }
    else
    {
        DEBUG_NSLOG(@"iMate连接断开!");
    }
}

- (void)iMateDelegateNoResponse:(NSString *)error
{
    DEBUG_NSLOG(@"iMateDelegateNoResponse: %@",error);
}

- (void)iMateDelegateResponsePackError
{
    DEBUG_NSLOG(@"应答报文错误");
}

/**
 *	@brief	刷卡操作执行结束后，该方法被调用，返回结果
 *
 *	@param 	returnCode  0 -> 成功 其他 -> 失败,输出 error 信息
 *	@param 	track2 	二磁道信息
 *	@param 	track3 	三磁道信息
 *	@param 	error 	错误信息
 *
 *	@return
 */
- (void)iMateDelegateSwipeCard:(NSInteger)returnCode track2:(NSString*)track2 track3:(NSString *)track3 error:(NSString *)error
{
    NSMutableDictionary *cardInfo = [NSMutableDictionary dictionary];
    // returnCode==0 表示成功返回信息
    if (returnCode == 0)
    {
        // 数据
        track2 = track2 == nil ? @"" : track2;
        track3 = track3 == nil ? @"" : track3;
        [cardInfo setObject:track2 forKey:@"track2"];
        [cardInfo setObject:track3 forKey:@"track3"];
        // 数据装换成jsonString返回
        NSError *error = nil;
        SBJsonWriter *jsonWriter = [[SBJsonWriter alloc] init];
        NSString *jsonString = [jsonWriter stringWithObject:cardInfo error:&error];
        if (error)
        {
            // 数据解析错误，返回错误信息
            CDVPluginResult *result = nil;
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:[error localizedDescription]];
            [self error:result callbackId:self.currentCallBackID];
        }
        else
        {
            CDVPluginResult *result = nil;
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:jsonString];
            [self success:result callbackId:self.currentCallBackID];
        }
        [jsonWriter release];
    }
    else
    {
        // 没有返回卡信息，返回错误信息
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error];
        [self error:result callbackId:self.currentCallBackID];
    }
}

/**
 *	@brief	IC卡复位操作执行结束后，该方法被调用，返回结果
 *
 *	@param 	returnCode 	0 -> 成功 其他 -> 失败 输出 error 信息
 *	@param 	resetData 	复位数据,16 进制数据
 *	@param 	tag
 *	@param 	error 	错误信息
 *
 *	@return
 */
- (void)iMateDelegateICResetCard:(NSInteger)returnCode resetData:(NSData *)resetData tag:(NSInteger)tag error:(NSString *)error
{
    if (returnCode == 0)
    {
        NSString *resetString = [iMateAppFace oneTwoData:resetData];
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:resetString];
        [self success:result callbackId:self.currentCallBackID];
    }
    else
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error];
        [self error:result callbackId:self.currentCallBackID];
    }
}

/**
 *	@brief	IC卡APDU操作执行结束后，该方法被调用，返回结果
 *
 *	@param 	returnCode 	0 -> 成功  其他 -> 失败,输出 error 信息
 *	@param 	responseApdu 	执行 IC 卡指令返回数据,16 进制数据
 *	@param 	error 	错误信息
 */
- (void)iMateICApdu:(NSInteger)returnCode responseApdu:(NSData*)responseApdu error:(NSString *)error
{
    if (returnCode == 0)
    {
        NSString *resetString = [iMateAppFace oneTwoData:responseApdu];
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:resetString];
        [self success:result callbackId:self.currentCallBackID];
    }
    else
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error];
        [self error:result callbackId:self.currentCallBackID];
    }
}

/**
 *	@brief	读身份证操作执行结束后，该方法被调用，返回结果。可调用processIdCardInfo对information拆分成数组
 *
 *	@param 	returnCode 	0 -> 成功 其他 -> 失败,输出 error 信息
 *	@param 	information 	身份证原始信息(未解析)
 *	@param 	photo 	身份证图
 *	@param 	error 	错误信息
 *
 *	@return
 */
- (void)iMateDelegateIDReadMessage:(NSInteger)returnCode information:(NSData *)information photo:(NSData*)photo error:(NSString *)error
{
    NSMutableDictionary *idInfo = [NSMutableDictionary dictionaryWithCapacity:0];
    NSString *photoStr = nil;
    // 成功返回身份证信息
    if (returnCode == 0)
    {
        // 身份证原始信息数据解析
        NSArray *array = [iMateAppFace processIdCardInfo:information];
        NSString *name = [array objectAtIndex:0];
        name = name != nil ? name : @"";
        [idInfo setObject:name forKey:@"name"];
        
        NSString *sex = [array objectAtIndex:1];
        sex = sex != nil ? sex : @"";
        [idInfo setObject:sex forKey:@"sex"];
        
        NSString *nation = [array objectAtIndex:2];
        nation = nation != nil ? nation : @"";
        [idInfo setObject:nation forKey:@"nation"];
        
        NSString *birthDay = [NSString stringWithFormat:@"%@-%@-%@",[array objectAtIndex:3],[array objectAtIndex:4],[array objectAtIndex:5]];
        [idInfo setObject:birthDay forKey:@"birthDay"];
        
        NSString *address = [array objectAtIndex:6];
        address = address != nil ? address : @"";
        [idInfo setObject:address forKey:@"address"];
        
        NSString *cardNum = [array objectAtIndex:7];
        cardNum = cardNum != nil ? cardNum : @"";
        [idInfo setObject:cardNum forKey:@"cardNum"];
        
        NSString *publishPartment = [array objectAtIndex:8];
        publishPartment = publishPartment != nil ? publishPartment : @"";
        [idInfo setObject:publishPartment forKey:@"publishPartment"];
        
        NSString * validityDate = [array objectAtIndex:9];
        validityDate = validityDate != nil ? validityDate : @"";
        [idInfo setObject:validityDate forKey:@"validityDate"];
        
        NSString * otherInfo = [array objectAtIndex:10];
        otherInfo = otherInfo != nil ? otherInfo : @"";
        [idInfo setObject:otherInfo forKey:@"otherInfo"];
        
        photoStr = [GTMBase64 stringByEncodingData:photo];
        photoStr = photoStr != nil ? photoStr : @"";
        [idInfo setObject:photoStr forKey:@"photoStr"];
        DEBUG_NSLOG(@"idInfo:%@",idInfo);
        
        // 数据转换jsonString
        NSError *error = nil;
        SBJsonWriter *jsonWriter = [[SBJsonWriter alloc] init];
        NSString *jsonString = [jsonWriter stringWithObject:idInfo error:&error];
        if (error)
        {
            // 转换错误，返回错误信息
            CDVPluginResult *result = nil;
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:[error localizedDescription]];
            [self error:result callbackId:self.currentCallBackID];
        }
        else
        {
            // 转换成功，返回身份证信息
            CDVPluginResult *result = nil;
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:jsonString];
            [self success:result callbackId:self.currentCallBackID];
        }
        [jsonWriter release];
    }
    else
    {
        // 身份证信息返回不成功，返回错误信息
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error];
        [self error:result callbackId:self.currentCallBackID];
    }
}

/**
 *	@brief	获取电池电量操作执行结束后，该方法被调用，返回结果，level取值在0-100之间
 *
 *	@param 	returnCode 		0 -> 成功  其他 -> 失败,输出 error 信息
 *	@param 	level 	电池电量
 *	@param 	error 	错误信息
 */
- (void)iMateBatteryLevel:(NSInteger)returnCode level:(NSInteger)level error:(NSString *)error
{
    if (returnCode == 0)
    {
        NSString *message = [NSString stringWithFormat:@"%d",level];
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:message];
        [self success:result callbackId:self.currentCallBackID];
    }
    else
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error];
        [self error:result callbackId:self.currentCallBackID];
    }
}

/**
 *	@brief	读取扩展内存操作执行结束后，该方法被调用，返回结果
 *
 *	@param 	returnCode 	0 -> 成功 其他 -> 失败,输出 error 信息
 *	@param 	data 	读出数据 16 进制数据
 *	@param 	error 	错误信息
 *
 *	@return
 */
- (void)iMateDelegateXmemRead:(NSInteger)returnCode data:(NSData *)data error:(NSString *)error
{
    if (returnCode == 0)
    {
        NSString *dateString = [iMateAppFace oneTwoData:data];
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:dateString];
        [self success:result callbackId:self.currentCallBackID];
    }
    else
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error];
        [self error:result callbackId:self.currentCallBackID];
    }
}

/**
 *	@brief  写扩展内存操作执行结束后，该方法被调用，返回结果
 *
 *	@param 	returnCode 	0 -> 成功 其他 -> 失败,输出 error 信息
 *	@param 	error 	错误信息
 *
 *	@return
 */
- (void)iMateDelegateXmemWrite:(NSInteger)returnCode error:(NSString *)error
{
    if (returnCode == 0)
    {
        NSString *returnCodeStr = [NSString stringWithFormat:@"%i",returnCode];
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:returnCodeStr];
        [self success:result callbackId:self.currentCallBackID];
    }
    else
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error];
        [self error:result callbackId:self.currentCallBackID];
    }
}

/**
 *	@brief	卡片操作状态信息
 *
 *	@param 	statusString 状态信息
 *
 *	@return
 */
- (void)iMateDelegateRuningStatus:(NSString *)statusString
{
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:statusString];
    [self success:result callbackId:self.currentCallBackID];
}

#pragma mark printer delegate
/**
 *	@brief	当打印机蓝牙连接连通或者中断时，该方法被调用，通知目前的蓝牙连接状态
 *
 *	@param 	status 	打印机蓝牙连接状态
 *
 *	@return	
 */
- (void)printerDelegateStatusResponse:(NSInteger)status
{
    NSString *statusStr = nil;
    switch (status)
    {
        case PRINTER_OK:
            statusStr = @"打印机状态正常!";
            break;
        case PRINTER_CONNECTED:
            statusStr = @"打印机已连接!";
            break;
        case PRINTER_NOT_CONNECTED:
            statusStr = @"打印机未连接!";
            break;
        case PRINTER_OUT_OF_PAPER:
            statusStr = @"打印机缺纸!";
            break;
    }
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:statusStr];
    [self success:result callbackId:self.currentCallBackID];
}

@end
