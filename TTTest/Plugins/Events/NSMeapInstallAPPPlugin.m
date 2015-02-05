//
//  NSMeapInstallAPPPlugin.m
//  Cordova_TEST
//
//  Created by Yalin on 14-3-20.
//
//

#import "NSMeapInstallAPPPlugin.h"

@implementation NSMeapInstallAPPPlugin

/**
 *  安装APP
 *
 *  @param arguments 传参 [plist文件地址]
 *  @param options   配置
 */
- (void)installApp:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    NSString *callBackID = [arguments objectAtIndex:0];
    NSString *plistURL = [arguments objectAtIndex:1];
    
    NSString *urlstring = [NSString stringWithFormat:@"itms-services://?action=download-manifest&url=%@",plistURL];
    
    CDVPluginResult *result = nil;
    
    if ([[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:urlstring]])
    {
        NSString *returnStr = @"0";
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:returnStr];
        [self success:result callbackId:callBackID];
        
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:urlstring]];
    }
    else
    {
        NSString *returnStr = @"1";
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:returnStr];
        [self error:result callbackId:callBackID];
    }
}

@end
