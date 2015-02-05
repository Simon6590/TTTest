//
//  NSMeapIMate.h
//  Cordova_TEST
//
//  Created by 韩立娜 on 13-9-16.
//
//

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

@interface NSMeapIMatePlugin : CDVPlugin

/**
 *	@brief	刷卡操作
 *
 *	@param 	arguments 	参数数组：[0]id  [1]timeout
 *	@param 	options 	
 */
- (void)swipeCard:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

/**
 *	@brief	读取身份证
 *
 *	@param 	arguments 	参数数组：[0]id [1]timeout 身份证放到读卡位置的最长等待时间(秒)
 *	@param 	options 	
 */
- (void)idReadMessage:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

/**
 *	@brief	获取电池电量
 *
 *	@param 	arguments 	参数数组：[0]id
 *	@param 	options 	
 */
- (void)batteryLevel:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

@end
