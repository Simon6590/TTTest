//
//  NSMeapCalendar.h
//  Cordova_TEST
//
//  Created by 罗忠燕 on 13-7-15.
//
//

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

@interface NSMeapCalendarPlugin : CDVPlugin

- (void)getCalendar:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

@end
