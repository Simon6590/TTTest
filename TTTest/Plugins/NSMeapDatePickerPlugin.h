//
//  NSMeapDatePicker.h
//  Cordova_TEST
//
//  Created by 罗忠燕 on 13-7-15.
//
//

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

@interface NSMeapDatePickerPlugin : CDVPlugin

//---------------------
// 获取日期
// arguments: 参数数组
// 0: id
// 1: pointX 日期选择器的X坐标  (btn.offsetLeft+btn.offsetWidth/2)
// 2: pointY 日期选择器的Y坐标  (btn.offsetTop+btn.offsetHeight/2)
// 3: model （chineseDate、date、date_time、time、hour_Minute） 
//---------------------
- (void)getDate:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

@end
