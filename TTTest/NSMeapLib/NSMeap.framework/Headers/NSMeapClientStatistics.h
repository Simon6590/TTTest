//
//  MeapStatistics.h
//  MeapSDK
//
//  Created by Guo Mingliang on 13-7-23.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 *	@brief	事件统计组件用于统计客户端的事件行为
 */

#import <Foundation/Foundation.h>
#import "NSMeapRequest.h"

/// 事件统计组件 用于统计客户端的事件行为
@interface NSMeapClientStatistics : NSObject<NSMeapRequestDelegate>

CLASS_SINGLETON_INTERFACE (NSMeapClientStatistics)

/**
 *	@brief	简单事件统计
 *
 *	@param 	event_id 	当前统计的事件ID
 */
- (void)sendEvent:(NSString *)event_id;

/**
 *	@brief	多标签事件统计
 *
 *	@param 	event_id 	当前统计的事件ID
 *	@param 	unid 	当前统计事件的标签
 */
- (void)sendEvent:(NSString *)event_id unid:(NSString *)unid;

/**
 *	@brief	事件累计统计
 *
 *	@param 	event_id 	当前统计的事件ID
 *	@param 	acc 	触发次数
 */
- (void)sendEvent:(NSString *)event_id acc:(NSUInteger)acc;

/**
 *	@brief	事件累计统计 
 *
 *	@param 	event_id 	当前统计的事件ID
 *	@param 	unid 	当前标签
 *	@param 	acc 	触发次数
 */
- (void)sendEvent:(NSString *)event_id unid:(NSString *)unid acc:(NSUInteger)acc;

/**
 *	@brief	事件带数据的反馈
 *
 *	@param 	event_id 	当前统计的事件ID
 *	@param 	info 	具体信息
 */
- (void)sendEvent:(NSString *)event_id info:(NSDictionary *)info;

/**
 *	@brief	渠道统计
 *
 *	@param 	channelId 	渠道
 */
- (void)channel:(NSString *)channelId;


#pragma mark - 事件 时长
/**
 *	@brief	数据统计
 *
 *	@param 	enent_id 	事件ID
 *	@param 	duration 	时长
 */
- (void)sendEvent:(NSString *)event_id duration:(NSTimeInterval)duration;

/**
 *	@brief	数据统计
 *
 *	@param 	enent_id 	事件ID
 *	@param 	unid 	当前标签
 *	@param 	duration 	时长
 */
- (void)sendEvent:(NSString *)event_id unid:(NSString *)unid duration:(NSTimeInterval)duration;

/**
 *	@brief	数据统计
 *
 *	@param 	enent_id 	事件ID
 *	@param 	unid 	当前标签
 *	@param 	info 	具体信息
 *	@param 	duration 	时长
 */
- (void)sendEvent:(NSString *)event_id info:(NSDictionary *)info duration:(NSTimeInterval)duration;

@end
