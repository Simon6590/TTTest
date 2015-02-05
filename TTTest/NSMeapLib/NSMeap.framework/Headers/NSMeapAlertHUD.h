//
//  MeapRegisterWaitView.h
//  MeapSDK
//
//  Created by 罗忠燕 on 13-8-13.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

/// 注册时的等待提示界面
@interface NSMeapAlertHUD : UIAlertView


/**
 *	@brief	不带隐藏提示界面按钮的创建方法
 *
 *	@return	MeapRegisterWaitView
 */
- (id)initWithView;

/**
 *	@brief	带隐藏提示界面按钮的创建方法
 *
 *	@param 	cancelButtonTitle 	取消隐藏按钮
 *	@param 	delegate 	代理  
 *
 *	@return	MeapRegisterWaitView
 */
- (id)initViewWithCancelButton:(NSString *)cancelButtonTitle delegate:(id)delegate;

/**
 *	@brief	显示提示的MeapRegisterWaitView
 */
- (void)showWaitingActive;

/**
 *	@brief	隐藏提示的MeapRegisterWaitView
 */
- (void)hiddenWaitActive;

@end
