//
//  NSMeapCheckAppUpdate.h
//  Cordova_TEST
//
//  Created by 韩立娜 on 13-8-20.
//
//

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

@interface NSMeapCheckAppUpdatePlugin : CDVPlugin

/**
 *	@brief	检查APP版本更新
 *
 *	@param 	arguments 	参数数组
 *          0：id
 *	@param 	options 	
 */
- (void)checkUpdateApp:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;
@end
