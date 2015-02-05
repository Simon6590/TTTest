//
//  NSMeapInstallAPPPlugin.h
//  Cordova_TEST
//
//  Created by Yalin on 14-3-20.
//
//

/**
 * @file        NSMeapInstallAPPPlugin.h
 * @brief       安装APP插件.
 * @version     1.0
 * @date        2014-3-20
 *
 * [2014-03-20] <杨亚霖> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

/**
 *  安装APP的插件
 */
@interface NSMeapInstallAPPPlugin : CDVPlugin

/**
 *  安装APP
 *
 *  @param arguments 传参 [plist文件地址]
 *  @param options   配置
 */
- (void)installApp:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

@end
