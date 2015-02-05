//
//  NSMeapMapEvent.m
//  Cordova_TEST
//
//  Created by yalin on 13-9-12.
//
//

#import "NSMeapMapEventPlugin.h"
#import "AppDelegate.h"
#import "MainViewController.h"

@implementation NSMeapMapEventPlugin

- (void)receiveMsg:(NSDictionary *)info
{
    
    NSData *data = [NSJSONSerialization dataWithJSONObject:info options:NSJSONWritingPrettyPrinted error:nil];
    NSString *jsonStr = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    [[NSMeapCallJsMethod shareNSMeapCallJsMethod] callJsMethodWithMethod:@"sycnMapEvent" paramStr:jsonStr];
    [jsonStr release];
}

@end
