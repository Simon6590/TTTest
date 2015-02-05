//
//  NSMLoginView.h
//  MeapSDK
//
//  Created by 罗忠燕 on 13-7-3.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NSMeapSSOServer.h"
#import "NSMeapCaptchaView.h"

/// 登录视图组件
@interface NSMeapLoginView : UIView <NSMeapSSOServerDelegate>

/// 主背景图 可自己设置图片 默认是设备屏幕大小
@property (nonatomic, retain) UIImageView            *loginMainBack_ImageView;
/// 用户名输入框
@property (nonatomic, retain) UITextField            *userName_TextField;
/// 密码输入框
@property (nonatomic, retain) UITextField            *password_TextField;
/// 验证码输入框
@property (nonatomic, retain) UITextField            *captcha_TextField;
/// 验证码显示按钮
@property (nonatomic, retain) NSMeapCaptchaView      *captcha_Button;
/// 登录按钮 自己控制样式 位置
@property (nonatomic, retain) UIButton               *onLineLogin_Button;
/// 登录按钮 自己控制样式 位置
@property (nonatomic, retain) UIButton               *offLineLogin_Button;

@property (nonatomic, retain) NSMeapSSOServer           *loginControl;

/**
 *	@brief	创建登录视图组件
 *
 *	@param 	frame 	视图的位置大小
 *
 *	@return	NSMLoginView登录视图组件
 */
+ (id)creatLoginView:(CGRect)frame;

@end


