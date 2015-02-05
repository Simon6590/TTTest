//
//  NSMeapSSOServerPlugin.m
//  Cordova_TEST
//
//  Created by 罗忠燕 on 14-3-9.
//
//

#import "NSMeapSSOServerPlugin.h"
#import <NSMeapBusinessComponents/NSMeapBusinessComponents.h>

@interface NSMeapSSOServerPlugin () <NSMeapSSOServerDelegate>

@property (nonatomic, retain)  NSMeapSSOServer      *loginServer;
@property (nonatomic, retain) NSString                 *currentCallBackID;

@end

@implementation NSMeapSSOServerPlugin

- (void)dealloc
{
    self.loginServer = nil;
    [super dealloc];
}

- (id)init
{
    self = [super init];
    if (self) 
    {
        self.loginServer = [[NSMeapSSOServer alloc] init];
        self.loginServer.delegate = self;
    }
    return self;
}

/**
 *	@brief	SSO设置参数接口
 *
 *	@param 	arguments 	参数数组
 *	0: id
 *	1: parma 参数名
 *	2: dataType 参数类型
 *  3: value 参数值
 *  4: isOffLineParam 是否为离线登录参数
 *	@param 	options 	
 */
- (void)setParma:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.currentCallBackID = [arguments queueHead];
    if ([arguments count] >= 5 )
    {
        NSString *parma = [arguments objectAtIndex:1];
        NSString *dataType = [arguments objectAtIndex:2];
        NSString *value = [arguments objectAtIndex:3];
        NSString *isOffLineParam = [arguments objectAtIndex:4];
        
        [self.loginServer setParma:parma dataType:[dataType intValue] value:value isOffLineParam:[isOffLineParam boolValue]];
    }
}

/**
 *	@brief	SSO获取参数值
 *
 *	@param 	parmaName 	参数名
 *
 *	@return	参数值
 */
- (void)getParma:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.currentCallBackID = [arguments queueHead];
    if ([arguments count] >= 5 )
        {
        NSString *parmaName = [arguments objectAtIndex:1];
        
        NSString *value = [self.loginServer getParma:parmaName];
        
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:value];
        [self success:result callbackId:self.currentCallBackID];
    }
}

#pragma mark - 在线方法
/**
 *	@brief	开始在线登录
 */
- (void)startOnLineLogin:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.currentCallBackID = [arguments queueHead];
    [self.loginServer startOnLineLogin];
}

/**
 *	@brief	开始离线登录,调用之前
 *
 */
- (void)startOffLineLogin:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.currentCallBackID = [arguments queueHead];
    [self.loginServer startOffLineLogin];
}

/**
 *  注销在线
 */
- (void)logout:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.currentCallBackID = [arguments queueHead];
    [self.loginServer logout];
}

/**
 *  检测SSO是否登录过
 *
 */
- (void)checkSSOLogin:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.currentCallBackID = [arguments queueHead];
    CDVPluginResult *result = nil;
    if ([NSMeapSSOServer checkSSOLogin])
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"1"];
    }
    else
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"0"];
    }
    
    [self success:result callbackId:self.currentCallBackID];
}

#pragma mark - NSMeapSSOServerDelegate
/**
 *	@brief	登录成功回调
 *
 *	@param 	loginControl 	NSMLoginControl登录服务
 */
- (void)meapLoginSuccess:(NSMeapSSOServer *)loginControl
{
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"1"];
    [self success:result callbackId:self.currentCallBackID];
}

/**
 *	@brief	登录失败回调
 *
 *	@param 	loginControl 	NSMLoginControl登录服务
 *  @param  error           错误信息
 */
- (void)meapLoginFailed:(NSMeapSSOServer *)loginControl error:(NSError *)error
{
//    NSString *alert = [NSString stringWithFormat:@"登录失败: %@",[error localizedDescription]];
//    AlertlogError(alert);
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"0"];
    [self success:result callbackId:self.currentCallBackID];
}

/**
 *  注销成功回调
 *
 *  @param logoutControl NSMLoginControl登录服务
 */
- (void)meapLogoutSuccess:(NSMeapSSOServer *)logoutControl
{
//    AlertlogError(@"注销成功");
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"1"];
    [self success:result callbackId:self.currentCallBackID];
}

/**
 *  注销失败回调
 *
 *  @param logoutControl NSMLoginControl登录服务
 */
- (void)meapLogoutFail:(NSMeapSSOServer *)logoutControl error:(NSError *)error
{
//    NSString *alert = [NSString stringWithFormat:@"注销失败: %@",[error localizedDescription]];
//    AlertlogError(alert);
    
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"0"];
    [self success:result callbackId:self.currentCallBackID];
}

@end
