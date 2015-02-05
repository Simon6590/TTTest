//
//  NSMeapSSOServerPlugin.h
//  Cordova_TEST
//
//  Created by 罗忠燕 on 14-3-9.
//
//

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

@interface NSMeapSSOServerPlugin : CDVPlugin

/**
 *	@brief	SSO设置参数接口
 *
 *	@param 	arguments 	参数数组
 *	0: id
 *	1: parma 参数名
 *	2: dataType 参数类型
 *  3: value 参数值
 *  4: isOffLineParam 是否为离线登录参数
 *	@param 	options 	
 */
- (void)setParma:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

/**
 *	@brief	SSO获取参数值
 *
 *	@param 	parmaName 	参数名
 *
 *	@return	参数值
 */
- (void)getParma:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

#pragma mark - 在线方法
/**
 *	@brief	开始在线登录
 */
- (void)startOnLineLogin:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

/**
 *	@brief	开始离线登录,调用之前
 *
 */
- (void)startOffLineLogin:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

/**
 *  注销在线
 */
- (void)logout:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

/**
 *  检测SSO是否登录过
 *
 */
- (void)checkSSOLogin:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

@end
