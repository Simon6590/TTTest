//
//  NSMeapDataEncrypt+Data.h
//  NSMeap
//
//  Created by 罗忠燕 on 13-11-6.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        NSMeapDataEncrypt+Data.h
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

/// NSData类型数据加密类别.
@interface NSMeapDataEncrypt (Data)

/**
 *	@brief	返回某个加密区的所有加密的数据
 *
 *	@param 	sectionName 区名
 *
 *	@return	返回加密的数据对象数组 数组元素是：NSMeapEncryptDataModel
 */
+ (NSArray *)getAllEncryptDataForSection:(NSString *)sectionName;

/**
 *	@brief	在某个区加密一个数据并保存
 *
 *	@param 	data 	需要加密的字符串
 *	@param 	sectionName 区名
 *	@param 	error 	错误信息返回
 *
 *	@return	返回一个加密的数据的Id
 */
+ (NSString *)saveData:(NSData *)data forSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	在某个区获取一个加密的数据
 *
 *	@param 	dataID 	数据的id
 *	@param 	sectionName 区名
 *	@param 	error 	错误信息返回
 *
 *	@return	返回一个加密的数据
 */
+ (NSData *)getDataWithID:(NSString *)dataID forSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	加密某个区的某个NSData
 *
 *	@param 	dataID 	数据ID
 *	@param 	sectionName 	区名
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：加密成功 NO：加密失败
 */
+ (BOOL)encryptData:(NSString *)dataID forSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	解密某个区的某个NSData
 *
 *	@param 	stringID 	数据ID
 *	@param 	sectionName 	区名
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：解密成功 NO：解密失败
 */
+ (BOOL)decryptData:(NSString *)dataID forSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	加密某个区的所有数据
 *
 *	@param 	sectionName 	区名
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：解密成功 NO：解密失败
 */
+ (BOOL)encryptAllDataForSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	解密某个区的所有数据
 *
 *	@param 	sectionName 	区名
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：解密成功 NO：解密失败
 */
+ (BOOL)decryptAllDataForSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	删除某个区的某个数据
 *
 *	@param 	stringID 	数据ID
 *	@param 	sectionName 	区名
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：删除成功 NO：删除失败
 */
+ (BOOL)clearData:(NSString *)dataID forSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	删除某个区的所有数据
 *
 *	@param 	sectionName 	区名
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：删除成功 NO：删除失败
 */
+ (BOOL)clearAllDataForSection:(NSString *)sectionName error:(NSError **)error;


@end
