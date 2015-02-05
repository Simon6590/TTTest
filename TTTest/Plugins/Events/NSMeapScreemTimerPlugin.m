//
//  NSMeapScreemTimerPlugin.m
//  Cordova_TEST
//
//  Created by Yalin on 14-3-19.
//
//

#import "NSMeapScreemTimerPlugin.h"
#import "CDVWebViewDelegate.h"

@interface NSMeapScreemTimerPlugin ()

/// 回调用的ID
@property (nonatomic, retain) NSString *callBackID;

/// 计时器
@property (nonatomic, retain) NSTimer   *timer;

/// 过期事件
@property (nonatomic, assign) NSInteger outTime;

/// 过期时间
@property (nonatomic, assign) NSInteger     timeCount;

/// 进入后台的时间记录
@property (nonatomic, retain) NSDate    *enterBackgroundDate;

@end

@implementation NSMeapScreemTimerPlugin

- (void)dealloc
{
    self.callBackID = nil;
    if ([self.timer isValid])
    {
        [self.timer invalidate];
    }
    self.timer = nil;
    
    [[NSNotificationCenter defaultCenter] removeObserver:self name:NSMeapScreemTouchBeginEventNotification object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:NSMeapScreemTouchEndEventNotification object:nil];
    self.enterBackgroundDate = nil;
    [super dealloc];
}

/**
 *  监听屏幕动作开始
 *
 *  @param arguments 参数 [到时时间(以秒为单位)]
 *  @param options   配置
 */
- (void)startListener:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.callBackID = [arguments objectAtIndex:0];
    
    NSInteger timer = 0;
    if ([arguments count] > 1)
    {
        timer = [[arguments objectAtIndex:1] integerValue];
    }
    
    if (timer == 0)
    {
        DEBUG_NSLOG(@"无效的Timer");
        return;
    }
    
    if ([self.timer isValid])
    {
        [self.timer invalidate];
    }
    
    self.outTime = timer;
    self.timeCount = 0;
    self.timer = [NSTimer scheduledTimerWithTimeInterval:1 target:self selector:@selector(timeOut) userInfo:nil repeats:YES];
//    UIKeyboardDidShowNotification
    [[NSNotificationCenter defaultCenter] removeObserver:self name:NSMeapScreemTouchBeginEventNotification object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:NSMeapScreemTouchEndEventNotification object:nil];
    
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIApplicationDidEnterBackgroundNotification object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIApplicationWillEnterForegroundNotification object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(touchBegin) name:NSMeapScreemTouchBeginEventNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(touchEnd) name:NSMeapScreemTouchEndEventNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(enterBackground) name:UIApplicationDidEnterBackgroundNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(enterForeground) name:UIApplicationWillEnterForegroundNotification object:nil];
}

- (void)timeOut
{
    self.timeCount++;
    
    if (self.timeCount >= self.outTime)
    {
        CDVPluginResult *result = nil;
        //    NSString *jsString = nil;
        NSString *returnStr = @"0";
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:returnStr];
        [self success:result callbackId:self.callBackID];
        
        [self.timer invalidate];
    }
}

- (void)touchBegin
{
    self.timeCount = 0;
}

- (void)touchEnd
{
    self.timeCount = 0;
//    self.timer = [NSTimer scheduledTimerWithTimeInterval:self.outTime target:self selector:@selector(timeOut) userInfo:nil repeats:NO];
}

- (void)enterBackground
{
    self.enterBackgroundDate = [NSDate date];
}

- (void)enterForeground
{
    NSDate *nowDate = [NSDate date];
    NSTimeInterval date = [nowDate timeIntervalSinceDate:self.enterBackgroundDate];
    self.timeCount += date;
}

@end
