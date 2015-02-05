//
//  NSMCalendarActionsheet.h
//  CalendarTest
//
//  Created by 罗忠燕 on 13-9-2.
//  Copyright (c) 2013年 罗忠燕. All rights reserved.
//

/**
 * @file        NSMeapCalendarActionsheet.h
 * @brief       日历组件.
 * @version     1.0
 * @date        2013-8-8
 *
 * [2013-06-07] <罗忠燕> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <UIKit/UIKit.h>

@class NSMeapCalendarActionsheet;
/// 以Actionsheet形式出现的日历组件 代理
@protocol NSMeapCalendarActionsheetDelegate <NSObject>

@optional

/**
 *	@brief	从以Actionsheet形式出现的日历组件选择一段日期
 *
 *	@param 	calendar 	NSMCalendarActionsheet
 *	@param 	startDay 	开始日期
 *	@param 	endDay      结束日期
 */
- (void)rangeDateInActionsheetCalendar:(NSMeapCalendarActionsheet *)calendar startDay:(NSDateComponents *)startDay endDay:(NSDateComponents *)endDay;

/**
 *	@brief	从以Actionsheet形式出现的日历组件选择一段日期
 *
 *	@param 	calendar 	NSMCalendarActionsheet
 *	@param 	startDay 	农历开始日期
 *	@param 	endDay      农历结束日期
 */
- (void)rangeDateInActionsheetCalendar:(NSMeapCalendarActionsheet *)calendar startChineseDay:(NSString *)startDay endChineseDay:(NSString *)endDay;

/**
 *	@brief	从以Actionsheet形式出现的日历组件选择某个日期
 *
 *	@param 	calendar 	NSMCalendarActionsheet
 *	@param 	day         选择的日期
 */
- (void)selectDateInActionsheetCalendar:(NSMeapCalendarActionsheet *)calendar day:(NSDateComponents *)day;

/**
 *	@brief	从以Actionsheet形式出现的日历组件选择某个日期
 *
 *	@param 	calendar 	NSMCalendarActionsheet
 *	@param 	day         农历选择的日期
 */
- (void)selectDateInActionsheetCalendar:(NSMeapCalendarActionsheet *)calendar chineseDay:(NSString *)day;

@end

/// 以Actionsheet形式出现的日历组件
@interface NSMeapCalendarActionsheet : UIActionSheet

@property (nonatomic, assign) id <NSMeapCalendarActionsheetDelegate> calendarDelegate;

/**
 *	@brief	创建日历组件 日历组件以Actionsheet形式出现
 *
 *	@return	NSMCalendarActionsheet
 */
- (id)initCalendarActionsheet;

@end


