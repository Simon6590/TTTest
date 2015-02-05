//
//  NSMeapEditOfficeFilePlugin.h
//  Cordova_TEST
//
//  Created by Yalin on 14-3-20.
//
//

/**
 * @file        NSMeapEditOfficeFilePlugin.h
 * @brief       通过第三方软件编辑Office插件.
 * @version     1.0
 * @date        2014-3-20
 *
 * [2014-03-20] <杨亚霖> v1.0
 *
 * + v1.0版发布.
 *
 */

#import "CDVPlugin.h"

/**
 *  浏览Office插件
 */
@interface NSMeapEditOfficeFilePlugin : CDVPlugin <UIDocumentInteractionControllerDelegate>

/// 回调用的ID
@property (nonatomic, retain) NSString      *callBackID;

/// 第三方调用controller
@property (nonatomic, retain) UIDocumentInteractionController   *controller;

/**
 *  编辑Office文档
 *
 *  @param arguments 传参 [文件路径]
 *  @param options   配置
 */
- (void)editOfficeFile:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

@end
