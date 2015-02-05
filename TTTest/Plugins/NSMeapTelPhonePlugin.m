//
//  NSMeapTelPhone.m
//  Cordova_TEST
//
//  Created by 罗忠燕 on 13-7-19.
//
//

#import "NSMeapTelPhonePlugin.h"


@interface  NSMeapTelPhonePlugin () 

@property (nonatomic, retain) NSString *currentCallBackID;

@end

@implementation NSMeapTelPhonePlugin

- (void)dealloc
{
    self.currentCallBackID = nil;
    [super dealloc];
}

//---------------------
// 打电话插件调用接口
// arguments: 参数数组
// 0: id
// 1: 电话号码
//---------------------
- (void)callPhone:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.currentCallBackID = [arguments queueHead];
    
    NSString *deviceType = [UIDevice currentDevice].model;
    
    if([deviceType isEqualToString:@"iPod touch"]||[deviceType  isEqualToString:@"iPad"]||[deviceType  isEqualToString:@"iPhone Simulator"] || [deviceType  isEqualToString:@"iPad Simulator"])
    {
        UIAlertView *alert=[[UIAlertView alloc] initWithTitle:nil
                                                      message:@"当前设备不能打电话"
                                                     delegate:nil
                                            cancelButtonTitle:@"OK"
                                            otherButtonTitles:nil,nil];
        [alert show];
        [alert release];
        
        CDVPluginResult *resultDate = nil;
        NSString *resultString = @"当前设备不能打电话";
        resultDate = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:resultString];
        [self success:resultDate callbackId:self.currentCallBackID];
        
        return;
    }
    else
    {
        if ([arguments count] >= 2)
        {
            NSString *num = [[NSString alloc] initWithFormat:@"telprompt://%@",[arguments objectAtIndex:1]];
            [[UIApplication sharedApplication] openURL:[NSURL URLWithString:num]];
        }
    }
}

@end
