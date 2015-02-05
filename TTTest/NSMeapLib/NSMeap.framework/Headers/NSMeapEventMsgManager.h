//
//  NSMeapEventMsgManager.h
//  NSMeap
//
//  Created by yalin on 13-8-19.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        NSMeapEventMsgManager.h
 * @brief       同步下发监听组件.
 * @version     1.0
 * @date        2013-7-23
 *
 * [2013-06-07] <杨亚霖> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <Foundation/Foundation.h>

/// 监听事件管理类,同步下发命令单例,负责后台命令的处理
@interface NSMeapEventMsgManager : NSObject
CLASS_SINGLETON_INTERFACE(NSMeapEventMsgManager)

/**
 *	@brief	开始监听
 */
- (void)startEventListener;

/**
 *	@brief	停止监听
 */
- (void)stopEventListener;

/**
 *	@brief	添加一个监听
 *
 *	@param 	className 	自己写的监听类名
 */
- (void)addEventListenerWithClassName:(NSString *)className;

/**
 *	@brief	移除一个监听
 *
 *	@param 	className 	自己写的监听类名
 */
- (void)removeEventListenerWithClassName:(NSString *)className;

@end