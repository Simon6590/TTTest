//
//  NSMeapURL.h
//  NSMeap
//
//  Created by yalin on 14-1-14.
//  Copyright (c) 2014年 nationsky. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *	@brief	网络请求URL格式报文,数据模型
 */
@interface NSMeapURL : NSObject

/**
 *	@brief	协议
 */
@property (nonatomic, retain) NSString      *protocol;

/**
 *	@brief	用户名
 */
@property (nonatomic, retain) NSString      *username;

/**
 *	@brief	密码
 */
@property (nonatomic, retain) NSString      *password;

/**
 *	@brief	IP
 */
@property (nonatomic, retain) NSString      *host;

/**
 *	@brief	端口
 */
@property (nonatomic, retain) NSString      *port;

/**
 *	@brief	服务路径
 */
@property (nonatomic, retain) NSString      *path;

#pragma mark - 初始化
/**
 *	@brief	初始化通过url字符串
 *
 *	@param 	urlStr 	url字符串
 *
 *	@return	NSMeapURL对象
 */
- (id)initWithURLString:(NSString *)urlStr;

#pragma mark - 转为字符串
/**
 *	@brief	模型转换为字符串
 *
 *	@return	返回URL字符串
 */
- (NSString *)urlString;

#pragma mark - 添加移除参数

/**
 *	@brief	添加URL对象
 *
 *	@param 	url 	NSMeapURL对象
 *	@param 	key 	参数名
 *
 */
- (void)addParameterURL:(NSMeapURL *)url key:(NSString *)key;

/**
 *	@brief	添加参数
 *
 *	@param 	str 	参数值
 *	@param 	key 	参数名
 *
 */
- (void)addParameterStr:(NSString *)str key:(NSString *)key;

/**
 *	@brief	添加参数
 *
 *	@param 	parameters 	参数字典
 *
 */
- (void)addParameterWithParameters:(NSDictionary *)parameters;

/**
 *	@brief	移除一个参数
 *
 *	@param 	key     参数名
 *
 */
- (void)removeParameterWithKey:(NSString *)key;

/**
 *	@brief	移除一个参数
 *
 *	@param 	key     参数名
 *
 */
- (void)removeParameterWithKeys:(NSArray *)keys;

#pragma mark - 获取参数
/**
 *	@brief	获取参数值
 *
 *	@param 	key 	参数名
 *
 *	@return	若有值,则数组中为value,若没有,则返回nil.
 */
- (NSArray *)parameterWithKey:(NSString *)key;

/**
 *	@brief	获取参数值
 *
 *	@param 	method 	方法名
 *	@param 	att 	属性
 *
 *	@return	若有值,则数组中为value,若没有,则返回nil.
 */
- (NSArray *)parameterWithMethod:(NSString *)method att:(NSString *)att;

/**
 *	@brief	获取URL参数值
 *
 *	@param 	key 	参数名
 *
 *	@return	若有值,则数组中为NSMeapURL对象,若没有,则返回nil.
 */
- (NSArray *)URLParameterWithKey:(NSString *)key;

/**
 *	@brief	获取URL参数值
 *
 *	@param 	method 	方法名
 *	@param 	att 	属性
 *
 *	@return	若有值,则数组中为NSMeapURL对象,若没有,则返回nil.
 */
- (NSArray *)URLParameterWithMethod:(NSString *)method att:(NSString *)att;

/**
 *  返回所有的参数名
 *
 *  @return 字符串数组
 */
- (NSArray *)allKeys;

@end
