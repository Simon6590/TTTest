//
//  NSMLoginControl.h
//  MeapSDK
//
//  Created by 罗忠燕 on 13-7-17.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        NSMeapSSOServer.h
 * @brief       SSO登录服务组件.
 * @version     1.0
 * @date        2014-3-1
 *
 * [2013-06-07] <罗忠燕> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <Foundation/Foundation.h>

@class NSMeapSSOServer;

/// 登录服务组件代理
@protocol NSMeapSSOServerDelegate <NSObject>

@optional

/**
 *	@brief	登录成功回调
 *
 *	@param 	loginControl 	NSMLoginControl登录服务
 */
- (void)meapLoginSuccess:(NSMeapSSOServer *)loginControl;

/**
 *	@brief	登录失败回调
 *
 *	@param 	loginControl 	NSMLoginControl登录服务
 *  @param  error           错误信息
 */
- (void)meapLoginFailed:(NSMeapSSOServer *)loginControl error:(NSError *)error;

/**
 *  注销成功回调
 *
 *  @param logoutControl NSMLoginControl登录服务
 */
- (void)meapLogoutSuccess:(NSMeapSSOServer *)logoutControl;

/**
 *  注销失败回调
 *
 *  @param logoutControl NSMLoginControl登录服务
 */
- (void)meapLogoutFail:(NSMeapSSOServer *)logoutControl error:(NSError *)error;

@end

/// 登录服务组件
@interface NSMeapSSOServer : NSObject

/// 登录服务的代理设置
@property (nonatomic, assign) id <NSMeapSSOServerDelegate> delegate;

/**
 *	@brief	设置其他登录参数
 *
 *	@param 	parma 	参数名
 *	@param 	data_type 	参数类型
 *	@param 	value 	参数值
 */
- (void)setParma:(NSString *)parma dataType:(DATA_TYPE)data_type value:(NSString *)value isOffLineParam:(BOOL)isOffLineParam;

/**
 *	@brief	获取参数值
 *
 *	@param 	parmaName 	参数名
 *
 *	@return	参数值
 */
- (NSString *)getParma:(NSString *)parmaName;

#pragma mark - 在线方法
/**
 *	@brief	开始在线登录
 */
- (void)startOnLineLogin;

- (void)login;

/**
 *	@brief	开始离线登录,调用之前
 *
 */
- (void)startOffLineLogin;

/**
 *  注销在线
 */
- (void)logout;

/**
 *  检测SSO是否登录过
 *
 */
+ (BOOL)checkSSOLogin;

@end
