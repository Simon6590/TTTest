//
//  NSMeapNetworkStatusPlugin.h
//  Cordova_TEST
//
//  Created by yalin on 13-7-19.
//
//

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

@interface NSMeapNetworkStatusPlugin : CDVPlugin

/**
 *	@brief	判断网络状态
 *
 *	@param 	arguments 	参数数组  参数：id
 *	@param 	options 	无
 */
- (void)isNetConnect:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

@end
