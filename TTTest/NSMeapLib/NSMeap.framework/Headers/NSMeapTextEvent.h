//
//  NSMeapTextEvent.h
//  NSMeap
//
//  Created by yalin on 13-8-16.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        NSMeapTextEvent.h
 * @brief       同步下发监听组件.
 * @version     1.0
 * @date        2013-8-16
 *
 * [2013-06-07] <杨亚霖> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <Foundation/Foundation.h>

/**
 *	@brief	抽象类,可继承它实现一个监听事件.
 *  类需要重写receiveMsg:方法,返回一个参数是一个NSString对象.
 */
@interface NSMeapTextEvent : NSObject

@end
