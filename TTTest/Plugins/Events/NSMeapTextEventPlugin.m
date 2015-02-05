//
//  NSMeapTextEvent.m
//  Cordova_TEST
//
//  Created by yalin on 13-9-12.
//
//


#import "NSMeapTextEventPlugin.h"
#import "AppDelegate.h"
#import "MainViewController.h"

@implementation NSMeapTextEventPlugin

- (void)receiveMsg:(NSString *)text
{
    [[NSMeapCallJsMethod shareNSMeapCallJsMethod] callJsMethodWithMethod:@"sycnTextEvent" paramStr:text];
}

@end
