//
//  NSMeapDataAtt.h
//  MEAPServer
//
//  Created by yangyalin on 13-3-12.
//  Copyright (c) 2013年 yangyalin. All rights reserved.
//


/**
 * @file        NSMeapDataAtt.h
 * @brief       数据加封装解析组件.
 * @version     1.0
 * @date        2013-3-12
 *
 * [2013-06-07] <杨亚霖> v1.0
 *
 * + v1.0版发布.
 *
 */

/// bean属性的类型.
typedef enum
{
    INT_ATT_TYPE,       //!< int类型.
    DOUBLE_ATT_TYPE,    //!< double类型.
    STRING_ATT_TYPE,    //!< string类型.
    FILE_ATT_TYPE,      //!< file类型.
    BOOL_ATT_TYPE,      //!< bool类型.
    TIME_ATT_TYPE,      //!< time类型.
    LONG_ATT_TYPE,      //!< long类型.
}DATA_TYPE;

#import <Foundation/Foundation.h>

@class NSMeapDataAttFile;

/// bean对象的属性对象
@interface NSMeapDataAtt : NSObject

/**
 *	@brief	通过data_type创建对象
 *
 *	@param 	elementName 	对象名
 *	@param 	data_type 	对象类型
 *
 *	@return	NSMeapDataAtt 对象
 */
+ (NSMeapDataAtt *)creatMeapAttWithElementName:(NSString *)elementName type:(DATA_TYPE)data_type;

/**
 *	@brief	通过data_type创建对象
 *
 *	@param 	elementName 	对象名
 *	@param 	data_type 	对象类型
 *	@param 	value 	参数值
 *
 *	@return	NSMeapDataAtt 对象
 */
+ (NSMeapDataAtt *)creatMeapAttWithElementName:(NSString *)elementName type:(DATA_TYPE)data_type value:(NSString *)value;
/**
 *	@brief	创建file对象
 *
 *	@param 	elementName 	对象名
 *	@param 	fileName 	文件名
 *	@param 	fileType 	文件类型
 *	@param 	fileContent 	NSData类型的文件内容
 *
 *	@return	NSMeapDataAttFile 对象
 */
+ (NSMeapDataAttFile *)creatMeapFileAttElementName:(NSString *)elementName fileName:(NSString *)fileName fileType:(NSString *)fileType fileContent:(NSData *)fileContent;

/**
 *	@brief	创建file对象
 *
 *	@param 	elementName 	对象名
 *	@param 	fileName 	文件名
 *	@param 	fileType 	文件类型
 *	@param 	fileContent 	NSString类型的文件内容
 *
 *	@return	NSMeapDataAttFile 对象
 */
+ (NSMeapDataAttFile *)creatMeapFileAttElementName:(NSString *)elementName fileName:(NSString *)fileName fileType:(NSString *)fileType fileStrContent:(NSString *)fileContent;

/**
 *	@brief	设置属性
 *
 *	@param 	attInfo 	属性值
 */
- (void)setAttributes:(id)attInfo;

/**
 *	@brief	把NSMeapDataAtt对象转换成为一个xml字符串
 *
 *	@return	xml字符串
 */
- (NSString *)XMLString;

/**
 *	@brief	把NSMeapDataAtt属性生成一个对象 方便生成json字符串
 *
 *	@return	包含NSMeapDataAtt属性的对象
 */
- (id)JSONStringObject;

/**
 *	@brief	bean属性对象的字符串
 */
@property (nonatomic, retain) NSString     *elementString;

/**
 *	@brief	bean属性对象的元素名
 */
@property (nonatomic, retain) NSString      *elementName;

/**
 *	@brief	bean属性对象的值
 */
@property (nonatomic, retain) NSString      *value;

/**
 *	@brief	bean属性对象值的基本类型
 */
@property (nonatomic) DATA_TYPE             data_type;

@end
