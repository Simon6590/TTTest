//
//  NSMeapConfigIPPlugin.h
//  Cordova_TEST
//
//  Created by 韩立娜 on 13-9-12.
//
//

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

@interface NSMeapConfigIPPlugin : CDVPlugin
/**
 * 配置IP
 * 参数：0 id
        1 serverIP          服务器IP地址
        2 serverPath        中间路径
        3 httpsPort         https端口号
 */
- (void)configIP:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

@end
