//
//  NSMCaptchaView.h
//  MeapSDK
//
//  Created by 罗忠燕 on 13-7-3.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        NSMeapCaptchaView.h
 * @brief       验证码组件.
 * @version     1.0
 * @date        2013-7-3
 *
 * [2013-06-07] <罗忠燕> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <UIKit/UIKit.h>
#import "NSMeapCaptchaServer.h"

/// 获取验证码的服务视图组件
@interface NSMeapCaptchaView : UIView

/** 标明图形验证码对应的事件
 *	@brief	对应各个接口的method
 */
@property (nonatomic, retain) NSString      *eventMethod;

/**
 *  验证码类型
 */
@property (nonatomic) NSMEAP_CAPTCHA_TYPE   captchaType;

/**
 *  验证码服务类
 */
@property (nonatomic, retain)  NSMeapCaptchaServer *captchaServer;

/**
 *	@brief	刷新重新获取验证码
 */
- (void)refreshCaptcha;

@end
