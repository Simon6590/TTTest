//
//  NSMeapDataAttDouble.h
//  MeapDataControl
//
//  Created by yangyalin on 13-3-14.
//  Copyright (c) 2013年 yangyalin. All rights reserved.
//

/**
 * @file        NSMeapDataAttDouble.h
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

/// double数据类型对象
@interface NSMeapDataAttDouble : NSMeapDataAtt

/**
 *	@brief	NSMeapDataAtt对象的double值
 */
@property (nonatomic) double doubleValue;

@end
