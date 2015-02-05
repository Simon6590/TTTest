//
//  AppDelegate.m
//  TTTest
//
//  Created by Simon on 14-3-31.
//  Copyright (c) 2014年 Simon. All rights reserved.
//

#import "AppDelegate.h"

#import "CDVPlugin.h"
#import "MainViewController.h"
#import <HXiMateSDK/iMateAppFace.h>
@implementation AppDelegate

- (void)dealloc
{
    [super dealloc];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:@"NSMEAP_HYBIRD_UPDATE_SUCCESS_NOTIFICATION" object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:@"NSMEAP_HYBIRD_UPDATE_FAILED_NOTIFICATION" object:nil];
}

- (id)init
{

    /** If you need to do any extra app-specific initialization, you can do it here
     *  -jm
     **/
    NSHTTPCookieStorage* cookieStorage = [NSHTTPCookieStorage sharedHTTPCookieStorage];

    [cookieStorage setCookieAcceptPolicy:NSHTTPCookieAcceptPolicyAlways];

    int cacheSizeMemory = 8 * 1024 * 1024; // 8MB
    int cacheSizeDisk = 32 * 1024 * 1024; // 32MB
    #if __has_feature(objc_arc)
        NSURLCache* sharedCache = [[NSURLCache alloc] initWithMemoryCapacity:cacheSizeMemory diskCapacity:cacheSizeDisk diskPath:@"nsurlcache"];
    #else
        NSURLCache* sharedCache = [[[NSURLCache alloc] initWithMemoryCapacity:cacheSizeMemory diskCapacity:cacheSizeDisk diskPath:@"nsurlcache"] autorelease];
    #endif
    [NSURLCache setSharedURLCache:sharedCache];

    self = [super init];
    return self;
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
    /***打开外接设备连接****/
    //首次安装默认值
    //默认ip地址
    [NSMeapInterface shareNSMeapInterface].meapServerIP = @"";
    //默认服务器路径
    [NSMeapInterface shareNSMeapInterface].meapServerPath = @"";
    //初始化iMaeAppFace
    iMateAppFace *iMateFace = [iMateAppFace sharedController];
    //创建iMate连接
    [iMateFace openSession];

    // NSMeap接口
    [[NSMeapInterface shareNSMeapInterface] meapLaunchFinishWithOption:launchOptions];
    [[NSMeapEventMsgManager shareNSMeapEventMsgManager] startEventListener];
        
    // NSMeap注册代码
    [[NSMeapInterface shareNSMeapInterface] meapBandingApp:NSMEAP_APPBANDING_NONE];
    CGRect screenBounds = [[UIScreen mainScreen] bounds];

    #if __has_feature(objc_arc)
        self.window = [[UIWindow alloc] initWithFrame:screenBounds];
    #else
        self.window = [[[UIWindow alloc] initWithFrame:screenBounds] autorelease];
    #endif
    self.window.autoresizesSubviews = YES;

    #if __has_feature(objc_arc)
        self.viewController = [[MainViewController alloc] init];
    #else
        self.viewController = [[[MainViewController alloc] init] autorelease];
    #endif
    self.viewController.useSplashScreen = YES;

    // Set your app's start page by setting the <content src='foo.html' /> tag in config.xml.
    // If necessary, uncomment the line below to override it.
    // self.viewController.startPage = @"index.html";

    // NOTE: To customize the view's frame size (which defaults to full screen), override
    // [self.viewController viewWillAppear:] in your view controller.

    self.window.rootViewController = self.viewController;
    [self.window makeKeyAndVisible];
    //注册小版本更新的通知
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(updateHtmlSuccess) name:@"NSMEAP_HYBIRD_UPDATE_SUCCESS_NOTIFICATION" object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(updateHtmlFaild) name:@"NSMEAP_HYBIRD_UPDATE_FAILED_NOTIFICATION" object:nil];
    return YES;
}
							
// this happens while we are running ( in the background, or from within our own app )
// only valid if Cordova_TEST-Info.plist specifies a protocol to handle
//程序跳回调用方法
- (BOOL)application:(UIApplication*)application handleOpenURL:(NSURL*)url
{

    if ([url isFileURL])
    {
        NSString *fileName = [url lastPathComponent];
        NSArray *files = [fileName componentsSeparatedByString:@"."];
        
        if ([files count] != 2)
        {
            DEBUG_NSLOG(@"文件名不对");
        }
        
        NSString *suffix = [files objectAtIndex:1];
        fileName = [files objectAtIndex:0];
        
        NSError *error = nil;
        
        // 防止文件名重复
        int index = 0;
        NSString *savePath = nil;
        while (YES)
        {
            NSString *tempName = nil;
            if (index == 0)
            {
                tempName = [NSString stringWithFormat:@"%@.%@",fileName,suffix];
            }
            else
            {
                tempName = [NSString stringWithFormat:@"%@ %d.%@",fileName,index,suffix];
            }
            
            savePath = [NSHomeDirectory() stringByAppendingPathComponent:[NSString stringWithFormat:@"Documents/%@",tempName]];
            if (![[NSFileManager defaultManager] fileExistsAtPath:savePath])
            {
                NSData *sourceData = [NSData dataWithContentsOfURL:url];
                [sourceData writeToFile:savePath options:0 error:&error];
                break;
            }
            
            index++;
        }
        
        if (error)
        {
            NSLog(@"receiveFilePath error: %@",error);
        }
        else
        {
            [[NSMeapCallJsMethod shareNSMeapCallJsMethod] callJsMethodWithMethod:@"receiveFilePath" paramStr:savePath];
        }
    }
    else
    {
        // APP1://abcde
        NSArray *appsParams = [[url absoluteString] componentsSeparatedByString:@"://"];
        NSString *appID = [appsParams objectAtIndex:0];
        NSString *param = nil;
        if ([appsParams count] == 2)
        {
            param = [appsParams objectAtIndex:1];
        }
        
        NSString *paramString = nil;
        if (param && ![param isEqualToString:@""])
        {
            paramString = [NSString stringWithFormat:@"%@,%@",appID,param];
        }
        else
        {
            paramString = [NSString stringWithFormat:@"%@",appID];
        }
        
        [[NSMeapCallJsMethod shareNSMeapCallJsMethod] callJsMethodWithMethod:@"openWithAPP" paramStr:paramString];
    }

    if (!url) {
        return NO;
    }

    // calls into javascript global function 'handleOpenURL'
    NSString* jsString = [NSString stringWithFormat:@"handleOpenURL(\"%@\");", url];
    [self.viewController.webView stringByEvaluatingJavaScriptFromString:jsString];

    // all plugins will get the notification, and their handlers will be called
    [[NSNotificationCenter defaultCenter] postNotification:[NSNotification notificationWithName:CDVPluginHandleOpenURLNotification object:url]];

    return YES;

}
- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}
//程序进入后台
- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    /***关闭外接设备连接****/
    [[iMateAppFace sharedController] closeSession];
        
    // NSMeap接口
    [[NSMeapInterface shareNSMeapInterface] meapApplicationDidEnterBackground];
        [[NSMeapCallJsMethod shareNSMeapCallJsMethod] callJsMethodWithMethod:@"appEnterBackground" paramStr:@""];
}
//程序进入前台
- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    /***打开外接设备连接****/
    [[iMateAppFace sharedController] openSession];
        
    // NSMeap接口
    [[NSMeapInterface shareNSMeapInterface] meapApplicationWillEnterForeground];
        [[NSMeapCallJsMethod shareNSMeapCallJsMethod] callJsMethodWithMethod:@"appEnterForeground" paramStr:@""];
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

/*
 * 推送方法 start
 */
#pragma mark - Push Notification
- (void)application:(UIApplication *)app didRegisterForRemoteNotificationsWithDeviceToken:(NSData *) deviceToken
{

    [[NSMeapInterface shareNSMeapInterface] meapRegisterNotificationsWithDeviceToken:deviceToken];
}

- (void)application:(UIApplication *)app didFailToRegisterForRemoteNotificationsWithError:(NSError *)err
{
#if DEBUG
    NSLog(@"Error: %@", err);
#endif

}

//应用在前台的时候才会执行该方法 推送插件
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
{

    [[NSMeapInterface shareNSMeapInterface] meapReceiveNotificationWithInfo:userInfo];
        [[NSMeapCallJsMethod shareNSMeapCallJsMethod] callJsMethodWithMethod:@"receivePushListener" paramStr:@""];
}

// repost the localnotification using the default NSNotificationCenter so multiple plugins may respond
- (void)            application:(UIApplication*)application
    didReceiveLocalNotification:(UILocalNotification*)notification
{
    // re-post ( broadcast )
    [[NSNotificationCenter defaultCenter] postNotificationName:CDVLocalNotification object:notification];
}

- (NSUInteger)application:(UIApplication*)application supportedInterfaceOrientationsForWindow:(UIWindow*)window
{
    // iPhone doesn't support upside down by default, while the iPad does.  Override to allow all orientations always, and let the root view controller decide what's allowed (the supported orientations mask gets intersected).
    NSUInteger supportedInterfaceOrientations = (1 << UIInterfaceOrientationPortrait) | (1 << UIInterfaceOrientationLandscapeLeft) | (1 << UIInterfaceOrientationLandscapeRight) | (1 << UIInterfaceOrientationPortraitUpsideDown);

    return supportedInterfaceOrientations;
}

- (void)applicationDidReceiveMemoryWarning:(UIApplication*)application
{
    [[NSURLCache sharedURLCache] removeAllCachedResponses];
}
#pragma mark UIApplicationDelegate implementation

- (void)updateHtmlSuccess
{
#if __has_feature(objc_arc)
    self.viewController = [[MainViewController alloc] init];
#else
    self.viewController = [[[MainViewController alloc] init] autorelease];
#endif
    
    self.window.rootViewController = self.viewController;
}

- (void)updateHtmlFaild
{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:nil message:@"更新失败" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
    [alert show];
    [alert release];
}
@end
