//
//  NSMeapConfigIPPlugin.m
//  Cordova_TEST
//
//  Created by 韩立娜 on 13-9-12.
//
//

#import "NSMeapConfigIPPlugin.h"

@implementation NSMeapConfigIPPlugin

-(void)configIP:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    NSString *currentCallBackID = [arguments objectAtIndex:0];
    if ([arguments count] >= 4)
    {
        NSString *meapServerIP = [arguments objectAtIndex:1];
        NSString *meapServerPath = [arguments objectAtIndex:2];
        NSString *meapHttpsPort = [arguments objectAtIndex:3];
        [[NSMeapInterface shareNSMeapInterface]setMeapServerIP:meapServerIP];
        [[NSMeapInterface shareNSMeapInterface]setMeapServerPath:meapServerPath];
        [[NSMeapInterface shareNSMeapInterface]setMeapHttpsPort:meapHttpsPort];
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"设置成功"];
        [self success:result callbackId:currentCallBackID];
    }
    else
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"NSMeapConfigIP 参数数目不对!"];
        [self error:result callbackId:currentCallBackID];
    }
}

@end
