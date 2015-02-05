//
//  NSMeapDataEncrypt.h
//  NSMeap
//
//  Created by 罗忠燕 on 13-11-6.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        NSMeapDataEncrypt.h
 * @brief       数据加密组件.
 * @version     1.0
 * @date        2013-09-07
 *
 * # update （更新日志）
 *
 * [2013-06-07] <lzy> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <Foundation/Foundation.h>
#import "NSMeapEncryptSectionModel.h"
#import "NSMeapEncryptStringModel.h"
#import "NSMeapEncryptDataModel.h"
#import "NSMeapEncryptFileModel.h"


/// 数据加密组件管理类.
@interface NSMeapDataEncrypt : NSObject

/**
 *	@brief	创建新的加密区
 *
 *	@param 	sectionName 	区名
 *	@param 	password 	密码
 *	@param 	overTime    密码过期时间
 *	@param 	error 	错误信息返回
 *
 *	@return	YES：创建成功 NO：创建失败
 */
+ (BOOL)creatNewSection:(NSString *)sectionName password:(NSString *)password passwordOverTime:(NSTimeInterval)overTime error:(NSError **)error;

/**
 *	@brief	输入密码校验某个区的密码
 *
 *	@param 	sectionName 	区名
 *
 *	@return YES：输入密码正确 NO：输入密码错误
 */
+ (BOOL)checkPassword:(NSString *)password forSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	判断某个区是否存在
 *
 *	@param 	sectionName 区名
 *
 *	@return	YES：存在 NO：不存在
 */
+ (BOOL)exitSection:(NSString *)sectionName;

/**
 *	@brief	判断某个区的密码是否过期
 *
 *	@param 	sectionName 区名
 *
 *	@return	YES：已过期 NO：没有过期
 */
+ (BOOL)isPasswordOverTimeForSection:(NSString *)sectionName;

/**
 *	@brief	某个区的加密密码
 *
 *	@param 	sectionName 	区名
 *
 *	@return	密码
 */
+ (NSString *)encryptKeyForSection:(NSString *)sectionName;

/**
 *	@brief	重置加密区的密码过期时间
 *
 *	@param 	overTime 	过期时间
 *	@param 	sectionName 	区名
 *
 */
+ (void)resetPasswordOverTime:(NSTimeInterval)overTime forSection:(NSString *)sectionName;

/**
 *	@brief	加密某个分区的数据
 *
 *	@param 	sectionName 	区名
 */
+ (BOOL)encryptAllSectionDataForSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief 解密某个分区的数据
 *
 *	@param 	sectionName 	区名
 */
+ (BOOL)decryptAllSectionDataForSection:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	返回所有的区信息
 *
 *	@return	所有区信息的数组 数组元素是：NSMeapEncryptSectionModel
 */
+ (NSArray *)getAllSectionsInfo;

/**
 *	@brief	删除某个分区并且删除这个分区的数据
 *
 *	@param 	sectionName 	区名
 *
 */
+ (BOOL)removeSectionAndAllSectionData:(NSString *)sectionName error:(NSError **)error;

/**
 *	@brief	清除某个区的所有数据，不删除该分区
 *
 *	@param 	sectionName 区名
 *
 */
+ (BOOL)clearAllSectionDataForSection:(NSString *)sectionName error:(NSError **)error;


@end
