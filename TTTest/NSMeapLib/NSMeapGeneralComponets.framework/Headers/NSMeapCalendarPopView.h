//
//  NSMCalendarPopView.h
//  CalendarTest
//
//  Created by 罗忠燕 on 13-9-22.
//  Copyright (c) 2013年 罗忠燕. All rights reserved.
//

/**
 * @file        NSMeapCalendarPopView.h
 * @brief       日历组件.
 * @version     1.0
 * @date        2013-9-22
 *
 * [2013-06-07] <罗忠燕> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <UIKit/UIKit.h>

@class NSMeapCalendarPopView;
/// 以PopView形式出现的日历组件 代理
@protocol NSMeapCalendarPopViewDelegate <NSObject>

@optional

/**
 *	@brief	从以PopView形式出现的日历组件选择一段日期
 *
 *	@param 	calendar 	NSMCalendarPopView
 *	@param 	startDay 	开始日期
 *	@param 	endDay      结束日期
 */
- (void)rangeDateInPopViewCalendar:(NSMeapCalendarPopView *)calendar startDay:(NSDateComponents *)startDay  endDay:(NSDateComponents *)endDay;

/**
 *	@brief	从以PopView形式出现的日历组件选择一段日期
 *
 *	@param 	calendar 	NSMCalendarPopView
 *	@param 	startDay 	农历开始日期
 *	@param 	endDay      农历结束日期
 */
- (void)rangeDateInPopViewCalendar:(NSMeapCalendarPopView *)calendar startChineseDay:(NSString *)startDay endChineseDay:(NSString *)endDay;

/**
 *	@brief	从以PopView形式出现的日历组件选择某个日期
 *
 *	@param 	calendar 	NSMCalendarPopView
 *	@param 	day         选择的日期
 */
- (void)selectDateInPopViewCalendar:(NSMeapCalendarPopView *)calendar day:(NSDateComponents *)day;

/**
 *	@brief	从以PopView形式出现的日历组件选择某个日期
 *
 *	@param 	calendar 	NSMCalendarPopView
 *	@param 	day         农历选择的日期
 */
- (void)selectDateInPopViewCalendar:(NSMeapCalendarPopView *)calendar chineseDay:(NSString *)day;

@end

/// 以PopView形式出现的日历组件 
@interface NSMeapCalendarPopView : UIPopoverController

@property (nonatomic, assign) id <NSMeapCalendarPopViewDelegate> calendarDelegate;

/**
 *	@brief	创建日历组件 日历组件以PopView形式出现
 *
 *	@return	NSMCalendarPopView
 */
- (id)initCalendarPopView;

@end
