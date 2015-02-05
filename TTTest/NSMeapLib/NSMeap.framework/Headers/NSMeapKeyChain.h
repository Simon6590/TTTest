//
//  NSMeapKeyChain.h
//  Ebank
//
//  Created by yangyalin on 13-4-10.
//  Copyright (c) 2013年 yangyalin. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 钥匙窜 单点登录
@interface NSMeapKeyChain : NSObject

/// 单例定义
CLASS_SINGLETON_INTERFACE(NSMeapKeyChain)

/**
 *	@brief	判断是否可以直接登陆
 *
 *	@return	BOOL值
 */
- (BOOL)checkLogin;

/**
 *	@brief	获取设备唯一标识
 *
 *	@return	设备ID的字符串
 */
- (NSString *)getDeviceID;

/**
 *	@brief	设置以及username
 */
@property (nonatomic, retain) NSString      *userName;

/**
 *	@brief	设置以及password
 */
@property (nonatomic, retain) NSString      *passWord;

/**
 *	@brief	设置以及token
 */
@property (nonatomic, retain) NSString      *token;

@end
