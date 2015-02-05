//
//  NSMeapDataAttLong.h
//  FirstMEAP
//
//  Created by yangyalin on 13-4-9.
//  Copyright (c) 2013年 yangyalin. All rights reserved.
//

/**
 * @file        NSMeapDataAttLong.h
 * @brief       数据加封装解析组件.
 * @version     1.0
 * @date        2013-3-14
 *
 * [2013-06-07] <杨亚霖> v1.0
 *
 * + v1.0版发布.
 *
 */

#import "NSMeapDataAtt.h"

/// long数据类型对象
@interface NSMeapDataAttLong : NSMeapDataAtt

/**
 *	@brief	NSMeapDataAtt对象的long值
 */
@property (nonatomic) long  longValue;

@end
