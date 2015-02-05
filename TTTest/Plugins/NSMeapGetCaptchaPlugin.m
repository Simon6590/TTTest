//
//  NSMeapGetCaptcha.m
//  Cordova_TEST
//
//  Created by 韩立娜 on 13-8-21.
//
//

///获取验证码插件
#import "NSMeapGetCaptchaPlugin.h"
#import <NSMeapBusinessComponents/NSMeapCaptchaServer.h>
@interface NSMeapGetCaptchaPlugin () <NSMeapCaptchaServerDelegate>

@property (nonatomic,retain) NSString *currentCallBackID;
@property (nonatomic,retain) NSMeapCaptchaServer *get_Captcha;
@end

@implementation NSMeapGetCaptchaPlugin

-(void)dealloc
{
    self.currentCallBackID = nil;
    self.get_Captcha = nil;
    [super dealloc];
}

-(void)getCaptcha:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    if ([arguments count]>0)
    {
        self.currentCallBackID=[arguments objectAtIndex:0];
        self.get_Captcha=[[[NSMeapCaptchaServer alloc]init]autorelease];
        [self.get_Captcha setDelegate:self];
        [self.get_Captcha getCaptcha:NSMEAP_CAPTCHA_CHAR];
    }
    else
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"获取验证码 参数数目不对!"];
        [self error:result callbackId:self.currentCallBackID];
    }
}
#pragma mark NSMCaptchaServerDelegate
-(void)getCaptchaSucceed:(NSString *)captcha
{
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:captcha];
    [self success:result callbackId:self.currentCallBackID];
}
-(void)getCaptchaFailed:(NSString *)message
{
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:message];
    [self error:result callbackId:self.currentCallBackID];
}
@end
