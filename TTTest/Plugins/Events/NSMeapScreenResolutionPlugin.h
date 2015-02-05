//
//  NSMeapScreemResolutionPlugin.h
//  Cordova_TEST
//
//  Created by Yalin on 14-3-24.
//
//

/**
 * @file        NSMeapScreenResolutionPlugin.h
 * @brief       获取屏幕分辨率插件.
 * @version     1.0
 * @date        2014-3-24
 *
 * [2014-03-24] <杨亚霖> v1.0
 *
 * + v1.0版发布.
 *
 */

#import "CDVPlugin.h"

/**
 *  获取屏幕分辨率插件.
 */
@interface NSMeapScreenResolutionPlugin : CDVPlugin

/**
 *  获取屏幕分辨率
 *
 *  @param arguments 无
 *  @param options   配置
 */
- (void)getScreenResolution:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

@end
