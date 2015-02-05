//
//  NSMeapWebViewServerPlugin.m
//  Cordova_TEST
//
//  Created by yalin yang on 14-3-27.
//
//

#import "NSMeapWebViewServerPlugin.h"

@implementation NSMeapWebViewServerPlugin

/**
 *  获取屏幕分辨率
 *
 *  @param arguments 传参 []
 *  @param options   配置
 */
- (void)goBack:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    NSString *callBackID = [arguments objectAtIndex:0];
    
    [self.webView goBack];
    
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"0"];
    [self success:result callbackId:callBackID];
}

@end
