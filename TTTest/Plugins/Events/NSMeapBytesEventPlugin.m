//
//  NSMeapBytesEvent.m
//  Cordova_TEST
//
//  Created by yalin on 13-9-12.
//
//

#import "NSMeapBytesEventPlugin.h"
#import "AppDelegate.h"
#import "MainViewController.h"
#import "SBJsonWriter.h"

@implementation NSMeapBytesEventPlugin

- (void)receiveMsg:(NSMeapDataAttFile *)file
{
    
    NSDictionary *info = [file JSONStringObject];
    
    NSData *data = [NSJSONSerialization dataWithJSONObject:info options:NSJSONWritingPrettyPrinted error:nil];
    NSString *jsonStr = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    [[NSMeapCallJsMethod shareNSMeapCallJsMethod] callJsMethodWithMethod:@"sycnBytesEvent" paramStr:jsonStr];
    
    [jsonStr release];
}

@end
