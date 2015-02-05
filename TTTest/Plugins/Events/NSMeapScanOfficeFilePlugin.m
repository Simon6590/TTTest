//
//  NSMeapScanOfficeFilePlugin.m
//  Cordova_TEST
//
//  Created by Yalin on 14-3-20.
//
//

#import "NSMeapScanOfficeFilePlugin.h"
#import <NSMeapGeneralComponets/NSMeapGeneralComponets.h>

@implementation NSMeapScanOfficeFilePlugin

- (void)dealloc
{
    self.navController = nil;
    [super dealloc];
}

/**
 *  浏览Office文档
 *
 *  @param arguments 传参 [文件路径]
 *  @param options   配置
 */
- (void)scanOfficeFile:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.callBackID = [arguments objectAtIndex:0];
    NSString *filePath = [arguments objectAtIndex:1];
    NSString *title = [filePath lastPathComponent];
    
    UIViewController *controller = [[[UIViewController alloc] init] autorelease];
    UIWebView *webView = [[[UIWebView alloc] initWithFrame:controller.view.frame] autorelease];
    webView.scalesPageToFit = YES;
    [webView loadRequest:[NSURLRequest requestWithURL:[NSURL fileURLWithPath:filePath]]];
    [controller.view addSubview:webView];
    
    self.navController = [[[UINavigationController alloc] initWithRootViewController:controller] autorelease];
    
    UIBarButtonItem *item = [[UIBarButtonItem alloc] initWithTitle:@"完成" style:UIBarButtonItemStyleDone target:self action:@selector(scanFinished)];
    controller.navigationItem.rightBarButtonItem = item;
    controller.navigationItem.title = title;
    
    [self.viewController presentViewController:self.navController animated:YES completion:nil];
}

- (void)scanFinished
{
    [self.navController dismissViewControllerAnimated:YES completion:nil];
    
    CDVPluginResult *result = nil;
    NSString *returnStr = @"0";
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:returnStr];
    [self success:result callbackId:self.callBackID];
}

@end
