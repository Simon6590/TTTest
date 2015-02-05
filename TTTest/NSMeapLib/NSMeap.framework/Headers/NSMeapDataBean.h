//
//  NSMeapDataBean.h
//  MEAPServer
//
//  Created by yangyalin on 13-3-12.
//  Copyright (c) 2013年 yangyalin. All rights reserved.
//

/**
 * @file        NSMeapDataBean.h
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

@class NSMeapDataAtt;

/// 与服务器交互的bean对象
@interface NSMeapDataBean : NSObject

/**
 *	@brief	bean对象的元素名
 */
@property (nonatomic, retain) NSString      *elementName;

/**
 *	@brief	bean对象的属性字典 键是elementname
 */
@property (nonatomic, retain) NSDictionary  *attributeInfo;

/**
 *	@brief	bean对象的子节点
 */
@property (nonatomic, retain) NSArray       *subBeans;

/**
 *	@brief	创建NSMeapDataBean对象
 *
 *	@param 	elementName 	对象的名称
 *
 *	@return	NSMeapDataBean 对象
 */
+ (NSMeapDataBean *)creatMeapBeanWithElementName:(NSString *)elementName;

/**
 *	@brief	把tree对象转换成为一个xml字符串
 *
 *	@return	xml字符串
 */
- (NSString *)XMLString;

/**
 *	@brief	把tree对象转换成为一个json字符串
 *
 *	@return	json字符串
 */
- (NSString *)JSONString;

/**
 *	@brief	通过一个索引值获得NSMeapDataAtt对象
 *
 *	@param 	indexString 	索引
 *
 *	@return	NSMeapDataAtt 对象
 */
- (NSMeapDataAtt *)meapAttWithIndexString:(NSString *)indexString;

/**
 *	@brief	通过一个索引值获得NSMeapDataAtt对象数组
 *
 *	@param 	indexString 	索引
 *
 *	@return	NSMeapDataAtt对象数组
 */
- (NSArray *)meapAttsWithIndexString:(NSString *)indexString;

/**
 *	@brief	添加子Bean对象
 *
 *	@param 	subBean 	子Bean对象
 */
- (void)addSubBean:(NSMeapDataBean *)subBean;

/**
 *	@brief	添加子属性对象
 *
 *	@param 	meapAtt 	属性对象NSMeapDataAtt
 */
- (void)addMeapAtt:(NSMeapDataAtt *)meapAtt;

@end
