//
//  NSMeapZipPlugin.h
//  Cordova_TEST
//
//  Created by yalin yang on 14-3-27.
//
//

/**
 * @file        NSMeapZipPlugin.h
 * @brief       Zip压缩解压插件.
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
 *  Zip压缩解压插件.
 */
@interface NSMeapZipPlugin : CDVPlugin 

/**
 *  获取屏幕分辨率
 *
 *  @param arguments 传参 [未压缩的文件路径]
 *  @param options   配置
 */
- (void)zipCompression:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

/**
 *  获取屏幕分辨率
 *
 *  @param arguments 传参 [压缩文件路径]
 *  @param options   配置
 */
- (void)zipDecompression:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

@end


