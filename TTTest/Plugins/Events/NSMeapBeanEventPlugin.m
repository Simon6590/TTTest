//
//  NSMeapBeanEvent.m
//  Cordova_TEST
//
//  Created by yalin on 13-9-12.
//
//

#import "NSMeapBeanEventPlugin.h"
#import "AppDelegate.h"
#import "MainViewController.h"

@implementation NSMeapBeanEventPlugin

- (void)receiveMsg:(NSMeapDataBean *)bean
{
    [[NSMeapCallJsMethod shareNSMeapCallJsMethod] callJsMethodWithMethod:@"sycnBeanEvent" paramStr:[bean JSONString]];
}

@end
