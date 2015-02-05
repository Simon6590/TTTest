//
//  NSMeapCallJsMethod.h
//  Cordova_TEST
//
//  Created by Yalin on 14-3-20.
//
//

/**
 * @file        NSMeapCallJsMethod.h
 * @brief       调用js方法插件.
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
 *  调用js方法插件.
 */
@interface NSMeapCallJsMethod : NSObject
CLASS_SINGLETON_INTERFACE(NSMeapCallJsMethod)

/**
 *  调用js方法
 *
 *  @param method   方法名
 *  @param paramStr 参数的字符串
 */
- (void)callJsMethodWithMethod:(NSString *)method paramStr:(NSString *)paramStr;

@end
