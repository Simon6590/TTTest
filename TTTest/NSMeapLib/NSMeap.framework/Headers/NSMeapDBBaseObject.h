//
//  NSMeapDBBaseObject.h
//  NSMeap
//
//  Created by 韩立娜 on 13-9-9.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        NSMeapDBBaseObject.h
 * @brief       数据加封装解析组件.
 * @version     1.0
 * @date        2013-9-9
 *
 * [2013-06-07] <韩立娜> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <Foundation/Foundation.h>

/// 本地数据库Sqlit创建表的基本对象类
@interface NSMeapDBBaseObject : NSObject

/// 数据id
@property (nonatomic,assign) long meap_id;

@end
