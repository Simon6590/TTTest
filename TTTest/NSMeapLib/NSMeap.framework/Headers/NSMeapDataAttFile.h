//
//  NSMeapDataAttFile.h
//  MeapDataControl
//
//  Created by yangyalin on 13-3-14.
//  Copyright (c) 2013年 yangyalin. All rights reserved.
//

/**
 * @file        NSMeapDataAttFile.h
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

/// file数据类型对象
@interface NSMeapDataAttFile : NSMeapDataAtt <NSXMLParserDelegate>

/**
 *	@brief	文件名
 */
@property (nonatomic, retain) NSString *fileName;

/**
 *	@brief	文件内容
 */
@property (nonatomic, retain) NSString *fileContent;

/**
 *	@brief	文件类型
 */
@property (nonatomic, retain) NSString *fileType;

@end
