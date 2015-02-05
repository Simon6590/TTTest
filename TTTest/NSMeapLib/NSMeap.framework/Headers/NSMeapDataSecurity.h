//
//  MeapDataSecurity.h
//  MeapSDK
//
//  Created by yalin on 13-7-17.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <Foundation/Foundation.h>

///	数据加密组件
@interface  NSMeapDataSecurity: NSObject

CLASS_SINGLETON_INTERFACE(NSMeapDataSecurity)

/// 加密 解密密码
@property (nonatomic, readonly) NSString    *password;

/**
 *	@brief	判断密码是否有效
 *
 *	@param 	error 	返回的错误信息
 *
 *	@return	YES：有效的  NO：无效的、或没有密码
 */
- (BOOL)isPasswordValid:(NSError **)error;

/**
 *	@brief	加密、解密密码
 *
 *	@param 	password 	本地密码
 *	@param 	overTime 	密码过期的周期
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：设置成功 NO：设置错误
 */
- (BOOL)setOrCheckPassword:(NSString *)password overTime:(NSTimeInterval)overTime error:(NSError **)error;

/**
 *	@brief	检测数据是否加密
 *
 *	@param 	dataId 	数据id
 *
 *	@return	YES：加密的 NO：没有加密的
 */
- (BOOL)checkIsEncryed:(NSString *)dataId;

/**
 *	@brief	加密一个字符串保存
 *
 *	@param 	string 	需要加密的字符串
 *	@param 	error 	错误
 *
 *	@return	加密的字符串的ID
 */
- (NSString *)saveString:(NSString *)string error:(NSError **)error;

/**
 *	@brief	获取一个加密的字符串
 *
 *	@param 	stringID 	字符串的id
 *	@param 	error 	错误信息返回
 *
 *	@return	返回一个加密的字符串
 */
- (NSString *)getStringWithID:(NSString *)stringID error:(NSError **)error;

/**
 *	@brief	加密一个数据并保存
 *
 *	@param 	data 	需要加密的字符串
 *	@param 	error 	错误信息返回
 *
 *	@return	返回一个加密的数据的Id
 */
- (NSString *)saveData:(NSData *)data error:(NSError **)error;

/**
 *	@brief	获取一个加密的数据
 *
 *	@param 	dataID 	数据的id
 *	@param 	error 	错误信息返回
 *
 *	@return	返回一个加密的数据
 */
- (NSData *)getDataWithID:(NSString *)dataID error:(NSError **)error;

/**
 *	@brief	加密一个文件
 *
 *	@param 	filePath 	文件的路径
 *	@param 	error 	错误信息返回
 *
 *	@return	返回一个加密的文件的Id
 */
- (NSString *)saveFile:(NSString *)filePath error:(NSError **)error;

/**
 *	@brief	获取一个加密的文件
 *
 *	@param 	fileID 	文件的id
 *	@param 	error 	错误信息返回
 *
 *	@return	文件的路径
 */
- (NSString *)getFileWithID:(NSString *)fileID error:(NSError **)error;

/**
 *	@brief	加密已有的数据
 *
 *	@param 	dataId 	数据id
 *	@param 	error 	错误信息返回
 */
- (BOOL)encrypteData:(NSString *)dataId error:(NSError **)error;

/**
 *	@brief	解密已有的数据
 *
 *	@param 	dataId 	数据id
 *	@param 	error 	错误信息返回
 */
- (BOOL)decrypteData:(NSString *)dataId error:(NSError **)error;

/**
 *	@brief	加密所有数据
 *
 *	@param 	error 	错误信息返回
 */
- (void)encrypteAllData:(NSError **)error;

/**
 *	@brief	解密所有数据
 *
 *	@param 	error 	错误信息返回
 */
- (void)decrypteAllData:(NSError **)error;

/**
 *	@brief	清空一个加密的数据
 *
 *	@param 	dataID 	数据或者string的id
 */
- (void)clearID:(NSString *)dataID error:(NSError **)error;

/**
 *	@brief	清空所有加密的数据
 */
- (void)clearAllData:(NSError **)error;

/**
 *	@brief	清空密码,会清空数据
 */
- (void)clearPassword;


@end
