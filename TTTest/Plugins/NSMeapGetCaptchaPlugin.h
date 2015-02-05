//
//  NSMeapGetCaptcha.h
//  Cordova_TEST
//
//  Created by 韩立娜 on 13-8-21.
//
//
///获取验证码插件
#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

@interface NSMeapGetCaptchaPlugin : CDVPlugin

- (void)getCaptcha:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

@end
