//
//  NSMeapNetworkStatusPlugin.m
//  Cordova_TEST
//
//  Created by yalin on 13-7-19.
//
//

#import "NSMeapNetworkStatusPlugin.h"
#import <NSMeap/NSMeapNetWorkStatus.h>

@implementation NSMeapNetworkStatusPlugin

- (void)isNetConnect:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    NSString *message = @"";
   
    if ( [NSMeapNetWorkStatus checkNetWork] == NSMEAP_NETWORK_NONE)
    {
        message = @"03";
    }
    else if ([NSMeapNetWorkStatus checkNetWork] == NSMEAP_NETWORK_3G)
    {
        message = @"02";
    }
    else if([NSMeapNetWorkStatus checkNetWork] == NSMEAP_NETWORK_WIFI)
    {
        message=@"01";
    }
    
    NSString *currentCallBackID = [arguments objectAtIndex:0];
    CDVPluginResult *result = nil;
    if ([message length]>0)
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:message];
        [self success:result callbackId:currentCallBackID];
    }
    else
    {
        result=[CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"查询失败"];
        [self error:result callbackId:currentCallBackID];
    }
    
    
}

@end
