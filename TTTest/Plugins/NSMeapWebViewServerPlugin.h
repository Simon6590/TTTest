//
//  NSMeapWebViewServerPlugin.h
//  Cordova_TEST
//
//  Created by yalin yang on 14-3-27.
//
//

/**
 * @file        NSMeapWebViewServerPlugin.h
 * @brief       WebViewNationServer插件.
 * @version     1.0
 * @date        2014-3-27
 *
 * [2014-03-27] <杨亚霖> v1.0
 *
 * + v1.0版发布.
 *
 */

#import "CDVPlugin.h"

/**
 *  WebViewNationServer插件.
 */
@interface NSMeapWebViewServerPlugin : CDVPlugin

/**
 *  获取屏幕分辨率
 *
 *  @param arguments 传参 []
 *  @param options   配置
 */
- (void)goBack:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

@end
