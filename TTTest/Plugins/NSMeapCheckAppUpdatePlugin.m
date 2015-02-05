//
//  NSMeapCheckAppUpdate.m
//  Cordova_TEST
//
//  Created by 韩立娜 on 13-8-20.
//
//

#import "NSMeapCheckAppUpdatePlugin.h"

@interface NSMeapCheckAppUpdatePlugin () <NSMeapCheckAppUpdateDelegate>
@property (nonatomic, retain) NSString *currentCallBackID;
@end
@implementation NSMeapCheckAppUpdatePlugin
-(void)dealloc
{
    self.currentCallBackID = nil;
    [super dealloc];
}

-(void)checkUpdateApp:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    if ([arguments count]>0)
    {
        self.currentCallBackID=[arguments objectAtIndex:0];
        [[NSMeapInterface shareNSMeapInterface] checkNativeUpdateDelegate:self];
    }
    else
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"APP版本更新 参数数目不对!"];
        [self error:result callbackId:self.currentCallBackID];
    }
    
}
#pragma mark MeapCheckUpdateDelegate
-(void)appNeedUpdate:(BOOL)needUpdate
{
    CDVPluginResult *result = nil;
    if (needUpdate) {
        
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"01"];
    }
    else
    {
        
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"02"];
    }
    [self success:result callbackId:self.currentCallBackID];
}
-(void)checkAppUpdateError:(NSString *)error
{
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error];
    [self error:result callbackId:self.currentCallBackID];
}
@end
