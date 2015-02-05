//
//  NSMeapDataEncrypt+String.h
//  NSMeap
//
//  Created by 罗忠燕 on 13-11-6.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        NSMeapDataEncrypt+String.h
 * @brief       数据加密组件.
 * @version     1.0
 * @date        2013-11-6
 *
 * [2013-06-07] <罗忠燕> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <Foundation/Foundation.h>
#import "NSMeapDataEncrypt.h"

/// String类型数据加密类别.
@interface NSMeapDataEncrypt (String)

/**
 *	@brief	返回某个加密区的所有加密的字符串
 *
 *	@param 	sectionName  区名
 *
 *	@return	返回加密的字符串对象数组 数组元素是：NSMeapEncryptStringModel
 */
+ (NSArray *)getAllEncryptStringForSection:(NSString *)sectionName;

/**
 *	@brief	在某个区加密保存一个字符串
 *
 *	@param 	string 	需要加密的字符串
 *	@param 	error 	错误信息返回
 *	@param 	sectionName 区名
 *
 *	@return	加密的字符串的ID
 */
+ (NSString *)saveString:(NSString *)string forSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	在某个区获取一个解密的字符串
 *
 *	@param 	stringID 	字符串加密返回的字符串的id
 *	@param 	error 	错误信息返回
 *	@param 	sectionName 区名
 *
 *	@return	返回一个解密的字符串
 */
+ (NSString *)getStringWithID:(NSString *)stringID forSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	加密某个区的某个字符串
 *
 *	@param 	stringID 	字符串ID
 *	@param 	sectionName 	区名
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：加密成功 NO：加密失败
 */
+ (BOOL)encryptString:(NSString *)stringID forSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	解密某个区的某个字符串
 *
 *	@param 	stringID 	字符串ID
 *	@param 	sectionName 	区名
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：解密成功 NO：解密失败
 */
+ (BOOL)decryptString:(NSString *)stringID forSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	加密某个区的所有字符串
 *
 *	@param 	sectionName 	区名
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：解密成功 NO：解密失败
 */
+ (BOOL)encryptAllStringForSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	解密某个区的所有字符串
 *
 *	@param 	sectionName 	区名
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：解密成功 NO：解密失败
 */
+ (BOOL)decryptAllStringForSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	删除某个区的某个字符串
 *
 *	@param 	stringID 	字符串ID
 *	@param 	sectionName 	区名
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：删除成功 NO：删除失败
 */
+ (BOOL)clearString:(NSString *)stringID forSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	删除某个区的所有字符串
 *
 *	@param 	sectionName 	区名
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：删除成功 NO：删除失败
 */
+ (BOOL)clearAllStringForSection:(NSString *)sectionName error:(NSError **)error;

@end
