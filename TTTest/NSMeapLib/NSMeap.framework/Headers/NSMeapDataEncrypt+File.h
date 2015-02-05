//
//  NSMeapDataEncrypt+File.h
//  NSMeap
//
//  Created by 罗忠燕 on 13-11-6.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        NSMeapDataEncrypt+File.h
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

/// File类型数据加密类别.
@interface NSMeapDataEncrypt (File)

/**
 *	@brief	返回某个加密区的所有加密的文件
 *
 *	@param 	sectionName
 *
 *	@return	返回加密的文件对象数组 数组元素是：NSMeapEncryptFileModel
 */
+ (NSArray *)getAllEncryptFileForSection:(NSString *)sectionName;

/**
 *	@brief	在某个区加密一个源文件
 *
 *	@param 	filePath 	源文件的路径
 *	@param 	sectionName 区名
 *	@param 	error 	错误信息返回
 *
 *	@return	返回加密的文件的Id
 */
+ (NSString *)saveFile:(NSString *)filePath forSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	在某个区获取一个加密的文件
 *
 *	@param 	fileID 	文件的id
 *	@param 	sectionName 区名
 *	@param 	error 	错误信息返回
 *
 *	@return	解密文件的路径
 */
+ (NSString *)getFileWithID:(NSString *)fileID forSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	加密某个区的某个文件
 *
 *	@param 	fileID 	文件ID
 *	@param 	sectionName 	区名
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：加密成功 NO：加密失败
 */
+ (BOOL)encryptFile:(NSString *)fileID forSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	解密某个区的某个文件
 *
 *	@param 	fileID 	文件ID
 *	@param 	sectionName 	区名
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：解密成功 NO：解密失败
 */
+ (BOOL)decryptFile:(NSString *)fileID forSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	加密某个区的所有文件
 *
 *	@param 	sectionName 	区名
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：解密成功 NO：解密失败
 */
+ (BOOL)encryptAllFileForSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	解密某个区的所有文件
 *
 *	@param 	sectionName 	区名
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：解密成功 NO：解密失败
 */
+ (BOOL)decryptAllFileForSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	删除某个区的某个文件
 *
 *	@param 	stringID 	文件ID
 *	@param 	sectionName 	区名
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：删除成功 NO：删除失败
 */
+ (BOOL)clearFile:(NSString *)fileID forSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	删除某个区的所有文件
 *
 *	@param 	sectionName 	区名
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：删除成功 NO：删除失败
 */
+ (BOOL)clearAllFileForSection:(NSString *)sectionName error:(NSError **)error;

@end
