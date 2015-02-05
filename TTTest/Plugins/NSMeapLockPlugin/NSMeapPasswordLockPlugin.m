//
//  NSMeapLockPlugin.m
//  ADSS
//
//  Created by Simon on 14-3-18.
//  Copyright (c) 2014年 Simon. All rights reserved.
//

#import "NSMeapPasswordLockPlugin.h"
#import "LockViewController.h"
#import "CheckViewController.h"

@interface NSMeapPasswordLockPlugin () <LockViewDelegate>

@property (nonatomic, retain) NSString *currentCallBackID;
@property (nonatomic, assign) NSInteger statusID;
@property (nonatomic, retain) LockViewController *lockController;
@property (nonatomic, retain) CheckViewController *checkController;

@end

@implementation NSMeapPasswordLockPlugin
- (void)showPasswordLock:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.currentCallBackID = [arguments objectAtIndex:0];
    self.statusID = [[arguments objectAtIndex:1] integerValue];
    if (self.statusID == 01)
    {
        self.lockController = [[[LockViewController alloc]init] autorelease];
        self.lockController.delegate = self;
        [self.viewController presentViewController:self.lockController animated:YES completion:nil];
    }
    else if (self.statusID == 02)
    {
        if ([arguments count] >= 3)
        {
            NSString *password = [arguments objectAtIndex:2];
            
            self.checkController = [[[CheckViewController alloc] init] autorelease];
            self.checkController.delegate = self;
            self.checkController.password = password;
            [self.viewController presentViewController:self.checkController animated:YES completion:nil];
        }
    }
}

- (void) lockViewPassWord:(NSString *)passWord
{
    
    CDVPluginResult *resultDate = nil;
    NSString *resultString = passWord;
    resultDate = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:resultString];
    [self success:resultDate callbackId:self.currentCallBackID];
}

- (void) forgetPassword
{
    
    CDVPluginResult *resultDate = nil;
    NSString *resultString = @"resign";
    resultDate = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:resultString];
    [self success:resultDate callbackId:self.currentCallBackID];
}
@end
