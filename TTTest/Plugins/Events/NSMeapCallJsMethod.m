//
//  NSMeapCallJsMethod.m
//  Cordova_TEST
//
//  Created by Yalin on 14-3-20.
//
//

#import "NSMeapCallJsMethod.h"
#import "AppDelegate.h"
#import "MainViewController.h"

@implementation NSMeapCallJsMethod
CLASS_SINGLETON_IMPLEMENTATION(NSMeapCallJsMethod)

/**
 *  调用js方法
 *
 *  @param method   方法名
 *  @param paramStr 参数的字符串
 */
- (void)callJsMethodWithMethod:(NSString *)method paramStr:(NSString *)paramStr
{
//    AppDelegate *delegate = [[UIApplication sharedApplication] delegate];
//    MainViewController *controller = (MainViewController *)delegate.window.rootViewController;
    
    NSString *jsParamStr = [paramStr stringByReplacingOccurrencesOfString:@"\\" withString:@"\\\\"];
    jsParamStr = [jsParamStr stringByReplacingOccurrencesOfString:@"\n" withString:@"\\\n"];
    jsParamStr = [jsParamStr stringByReplacingOccurrencesOfString:@"\r" withString:@"\\\r"];
    jsParamStr = [jsParamStr stringByReplacingOccurrencesOfString:@"\t" withString:@"\\\t"];
    jsParamStr = [jsParamStr stringByReplacingOccurrencesOfString:@"\"" withString:@"\\\""];
    
    NSString *js = [NSString stringWithFormat:@"%@(\"%@\");",method,jsParamStr];
    
//    dispatch_async(dispatch_get_main_queue(), ^
//    {
//        [controller.webView stringByEvaluatingJavaScriptFromString:js];
//    });
    
    [self performSelector:@selector(loadJS:) withObject:js afterDelay:1];
}

- (void)loadJS:(NSString *)js
{
    AppDelegate *delegate = [[UIApplication sharedApplication] delegate];
    MainViewController *controller = (MainViewController *)delegate.window.rootViewController;
    [controller.webView stringByEvaluatingJavaScriptFromString:js];
}

@end
