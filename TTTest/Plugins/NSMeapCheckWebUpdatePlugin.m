//
//  NSMeapCheckWebUpdate.m
//  Cordova_TEST
//
//  Created by 韩立娜 on 13-8-20.
//
//

#import "NSMeapCheckWebUpdatePlugin.h"
#import "MainViewController.h"
#import "AppDelegate.h"

@interface NSMeapCheckWebUpdatePlugin ()<NSMeapCheckHybridUpdateDeleagte>

@property (nonatomic, retain) NSString *currentCallBackID;

@end

@implementation NSMeapCheckWebUpdatePlugin

-(void)dealloc
{
    self.currentCallBackID = nil;
    
    [super dealloc];
}
/**
 *	@brief	检查APP版本更新
 *
 *	@param 	arguments 	参数数组
 *          0：id
 *	@param 	options
 */
- (void)checkUpdateRes:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.currentCallBackID=[arguments objectAtIndex:0];
    if ([arguments count]>0)
    {
        [[NSMeapInterface shareNSMeapInterface] checkHybridUpdateDelegate:self];
    }
    else
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"检查JS版本更新 参数数目不对!"];
        [self error:result callbackId:self.currentCallBackID];
    }
}
#pragma mark MeapUpdateHtmlVersionDeleagte
-(void)htmlNeedUpdate:(BOOL)needUpdate
{
    if (!needUpdate)
    {
        CDVPluginResult *result = nil;
         result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"02"];
        [self success:result callbackId:self.currentCallBackID];
    }
    
}


-(void)checkHtmlUpdateSuccess
{
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"版本更新成功"];
    [self success:result callbackId:self.currentCallBackID];
    
    AppDelegate *delegate = [[UIApplication sharedApplication] delegate];
    
#if __has_feature(objc_arc)
    delegate.viewController = [[MainViewController alloc] init];
#else
    delegate.viewController = [[[MainViewController alloc] init] autorelease];
#endif
    
    delegate.window.rootViewController = delegate.viewController;
}

-(void)checkHtmlUpdateError:(NSString *)error
{
    CDVPluginResult *result = nil;
    NSString *message=[NSString stringWithFormat:@"%@",error];
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:message];
    [self error:result callbackId:self.currentCallBackID];
}
@end
