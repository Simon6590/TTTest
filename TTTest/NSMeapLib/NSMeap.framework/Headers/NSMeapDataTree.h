//
//  NSMeapDataTree.h
//  MEAPServer
//
//  Created by yangyalin on 13-3-12.
//  Copyright (c) 2013年 yangyalin. All rights reserved.
//

/**
 * @file        NSMeapDataTree.h
 * @brief       数据加封装解析组件.
 * @version     1.0
 * @date        2013-3-12
 *
 * [2013-06-07] <杨亚霖> v1.0
 *
 * + v1.0版发布.
 *
 */



#import <Foundation/Foundation.h>

//#define BEAN_TYPE           @"b"
//#define INT_TYPE            @"int"
//#define DOUBLE_TYPE         @"dec"
//#define STRING_TYPE         @"str"
//#define FILE_TYPE           @"file"
//#define BOOL_TYPE           @"bool"
//#define TIME_TYPE           @"time"
//#define LONG_TYPE           @"long"

#define BEAN_TYPE           @"abcd废武功hi阿飞交分解诶啊我；分解啊我；分解啊我；分解哇哦；gheifhauew"
#define INT_TYPE            @"i"
#define DOUBLE_TYPE         @"d"
#define STRING_TYPE         @"s"
#define FILE_TYPE           @"f"
#define BOOL_TYPE           @"b"
#define TIME_TYPE           @"t"
#define LONG_TYPE           @"l"

@class NSMeapDataBean;

/// 与服务器交互的数据对象
@interface NSMeapDataTree : NSObject

/**
 *	@brief	通过xml字符串初始化一个tree对象
 *
 *	@param 	xmlString 	xml 字符串
 *
 *	@return tree 对象
 */
+ (id)treeWithXMLString:(NSString *)xmlString;

/**
 *	@brief	通过json字符串初始化一个tree对象
 *
 *	@param 	jsonString 	jion 字符串
 *
 *	@return	tree 对象
 */
+ (id)treeWithJSONString:(NSString *)jsonString;

/**
 *	@brief	通过xml文件初始化一个tree对象
 *
 *	@param 	filePath 	xml 文件
 *
 *	@return	tree 对象
 */
+ (id)treeWithXMLFile:(NSString *)filePath;

/**
 *	@brief	通过json文件初始化一个tree对象
 *
 *	@param 	filePath 	json 文件
 *
 *	@return	tree 对象
 */
+ (id)treeWithJSONFile:(NSString *)filePath;

/**
 *	@brief	通过bean初始化一个tree对象
 *
 *	@param 	bean 	NSMeapDataBean 对象
 *
 *	@return	tree 对象
 */
+ (id)treeWithMeapBean:(NSMeapDataBean *)bean;

/**
 *	@brief	tree对象的根bean对象
 */
@property (nonatomic, retain) NSMeapDataBean  *rootBean;

/**
 *	@brief	通过索引储存的bean对象
 *          key是索引值 value是bean的数组对象
 */
@property (nonatomic, retain) NSDictionary *indexBean;

/**
 *	@brief	把tree对象转换成为一个xml字符串
 *
 *	@return	xml 字符串
 */
- (NSString *)XMLString;

/**
 *	@brief	把tree对象转换成为一个json字符串
 *
 *	@return	json 字符串
 */
- (NSString *)JSONString;

/**
 *	@brief	把tree对象转换成为一个xml文件
 *
 *	@param 	filePath 	文件路径
 */
- (void)XMLFileWithPath:(NSString *)filePath;

/**
 *	@brief	把tree对象转换成为一个json文件
 *
 *	@param 	filePath 	文件路径
 */
- (void)JSONFileWithPath:(NSString *)filePath;

/**
 *	@brief	通过一个索引值获得bean对象
 *
 *	@param 	indexString 	索引
 *
 *	@return	NSMeapDataBean 对象
 */
- (NSMeapDataBean *)meapBeanWithIndexString:(NSString *)indexString;

/**
 *	@brief	通过一个索引值获得bean对象的集合
 *
 *	@param 	indexString 	索引
 *
 *	@return	包含bean对象的数组
 */
- (NSArray *)meapBeansWithIndexString:(NSString *)indexString;

@end
