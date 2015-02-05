//
//  NSMeapLockPlugin.h
//  ADSS
//
//  Created by Simon on 14-3-18.
//  Copyright (c) 2014年 Simon. All rights reserved.
//

/**
 * @file        NSMeapLockPlugin.h
 * @brief       密码锁插件.
 * @version     1.0
 * @date        2014-3-18
 *
 * [2014-03-18] <杨亚霖> v1.0
 *
 * + v1.0版发布.
 *
 */

#import "CDVPlugin.h"

/**
 *  密码锁插件.
 */
@interface NSMeapPasswordLockPlugin : CDVPlugin

/**
 *  获取屏幕分辨率
 *
 *  @param arguments 无
 *  @param options   配置
 */
- (void)showPasswordLock:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;



@end
