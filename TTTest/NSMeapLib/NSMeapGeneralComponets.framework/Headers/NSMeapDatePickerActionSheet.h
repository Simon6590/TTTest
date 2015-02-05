//
//  NSMDatePickerActionSheet.h
//  MeapSDK
//
//  Created by 罗忠燕 on 13-7-19.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        NSMeapDatePickerActionSheet.h
 * @brief       日期/时间选择器组件.
 * @version     1.0
 * @date        2013-7-19
 *
 * [2013-06-07] <罗忠燕> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <UIKit/UIKit.h>

/// NSMDatePickerActionSheet日期/时间选择器的代理
@protocol NSMeapDatePickerActionSheetDelegate <NSObject>
@optional
/**
 *	@brief	选择日期后的回调，并返回选择的日期/时间
 *
 *	@param 	date 	选择的日期/时间
 */
- (void)didSelectedDateInActionSheet:(NSDate *)date;
@end

/// 日期/时间选择器组件（用UIActionSheet弹出，适用于iPhone）
@interface NSMeapDatePickerActionSheet : UIActionSheet

/**
 *	@brief	NSMDatePickerActionSheet日期选择器的代理
 */
@property (nonatomic, assign) id <NSMeapDatePickerActionSheetDelegate> delegateActionSheet;

/**
 *	@brief	日期选择器的模式
 */
@property(nonatomic)  UIDatePickerMode datePickerMode;

@end

