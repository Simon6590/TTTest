//
//  NSMGetCaptcha.h
//  MeapSDK
//
//  Created by 韩立娜 on 13-8-21.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        NSMeapCaptchaServer.h
 * @brief       验证码组件.
 * @version     1.0
 * @date        2013-8-21
 *
 * [2013-06-07] <韩立娜> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <Foundation/Foundation.h>

/// 验证码类型
typedef enum
{
    NSMEAP_CAPTCHA_NUMANDChAR,  //!< 数字字母 */
    NSMEAP_CAPTCHA_NUM,         //!< 数字 */
    NSMEAP_CAPTCHA_CHAR,        //!< 字母 */
    NSMEAP_CAPTCHA_CHINESE,     //!< 汉字 */
    NSMEAP_CAPTCHA_ARITHMETIC,  //!< 算术 */
    NSMEAP_CAPTCHA_IDIOM,       //!< 成语 */
}NSMEAP_CAPTCHA_TYPE;

/// 获取验证码的服务组件代理
@protocol NSMeapCaptchaServerDelegate;

/// 获取验证码的服务组件
@interface NSMeapCaptchaServer : NSObject

/** 标明图形验证码对应的事件
 *	@brief	对应各个接口的method
 */
@property (nonatomic, retain) NSString  *eventMethod;
/**
 *	@brief	NSMGetCaptchaDelegate
 */
@property (nonatomic,assign)id<NSMeapCaptchaServerDelegate> delegate;


@property (nonatomic, readonly) NSString  *sessionID;

/**
 *	@brief	获取验证码
 */
-(void)getCaptcha:(NSMEAP_CAPTCHA_TYPE)type;

/**
 *  验证
 *
 *  @param captcha 需要验证的码
 */
- (BOOL)checkCatcha:(NSString *)captcha error:(NSError **)error;

@end

@protocol NSMeapCaptchaServerDelegate <NSObject>

@optional
/**
 *	@brief	获取验证码成功回调
 *
 *	@param 	captcha 	验证码的信息
 */
-(void)getCaptchaSucceed:(NSString *)captcha sessionID:(NSString *)sessionID;

/**
 *	@brief	获取验证码失败回调
 *
 *	@param 	message 	失败信息
 */
-(void)getCaptchaFailed:(NSString *)message;

@end