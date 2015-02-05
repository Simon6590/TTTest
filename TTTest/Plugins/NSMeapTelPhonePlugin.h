//
//  NSMeapTelPhone.h
//  Cordova_TEST
//
//  Created by 罗忠燕 on 13-7-19.
//
//


//---------------------
// 打电话插件
//---------------------

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

@interface NSMeapTelPhonePlugin : CDVPlugin

//---------------------
// 打电话插件调用接口
// arguments: 参数数组
// 0: id
// 1: 电话号码
//---------------------
- (void)callPhone:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

@end
