//
//  UIView+ActivityIndicator.h
//  LoadingDemo
//
//  Created by 韩立娜 on 13-9-24.
//  Copyright (c) 2013年 韩立娜. All rights reserved.
//

/**
 * @file        UIView+NSMeapLoading.h
 * @brief       下拉框控件.
 * @version     1.0
 * @date        2013-9-24
 *
 * [2013-06-07] <韩立娜> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <UIKit/UIKit.h>

/// 加载ActivityIndicator类别
@interface UIView (NSMeapLoading)

/**
 *	@brief	显示ActivityIndicator
 */
-(void)showActivityIndicator;

/**
 *	@brief	显示ActivityIndicator
 *
 *	@param 	style 	UIActivityIndicatorViewStyle
 *	@param 	color 	颜色
 */
-(void)showActivityIndicator:(UIActivityIndicatorViewStyle)style color:(UIColor *)color;

/**
 *	@brief	移除ActivityIndicator
 */
-(void)dismissActivityIndicator;

@end
///半透明指示层
@interface UIView (HUD)

/**
 *	@brief	显示HUD
 */
-(void)showHUD;

/**
 *	@brief	显示HUD
 *
 *	@param 	animated 	是否加动画
 */
-(void)showHUD:(BOOL)animated;

/**
 *	@brief	显示HUD
 *
 *	@param 	animated 	是否加动画
 *	@param 	labelText 	提示字符串
 */
-(void)showHUD:(BOOL)animated labelText:(NSString *)labelText;

/**
 *	@brief	显示HUD
 *
 *	@param 	animated 	是否加动画
 *	@param 	labelText 	提示字符串
 *	@param 	detailText 	详细提示字符串
 */
-(void)showHUD:(BOOL)animated labelText:(NSString *)labelText detailText:(NSString *)detailText;

/**
 *	@brief	显示HUD
 *
 *	@param 	animated 	是否加动画
 *	@param 	labelText 	提示字符串
 *	@param 	detailText 	详细提示字符串
 *	@param 	customView 	自定义视图
 */
-(void)showHUD:(BOOL)animated labelText:(NSString *)labelText detailText:(NSString *)detailText customView:(UIView *)customView;

/**
 *	@brief	移除HUD
 */
-(void)dismissHUD;

/**
 *	@brief	移除HUD
 *
 *	@param 	animated 	是否加动画
 */
-(void)dismissHUD:(BOOL)animated;
@end
