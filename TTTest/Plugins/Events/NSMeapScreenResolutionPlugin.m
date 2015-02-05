//
//  NSMeapScreemResolutionPlugin.m
//  Cordova_TEST
//
//  Created by Yalin on 14-3-24.
//
//

#import "NSMeapScreenResolutionPlugin.h"

@implementation NSMeapScreenResolutionPlugin

/**
 *  获取屏幕分辨率
 *
 *  @param arguments 无
 *  @param options   配置
 */
- (void)getScreenResolution:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    NSString *callBackID = [arguments objectAtIndex:0];
    
    CGRect screen = [[UIScreen mainScreen] bounds];
    CGFloat scale = [UIScreen mainScreen].scale;
    
    NSString *returnStr = [NSString stringWithFormat:@"{\"rw\":\"%.0f\",\"rh\":\"%.0f\",\"pw\":\"%.0f\",\"ph\":\"%.0f\"}",scale * screen.size.width,scale * screen.size.height,screen.size.width,screen.size.height];
    
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:returnStr];
    [self success:result callbackId:callBackID];
}

@end
