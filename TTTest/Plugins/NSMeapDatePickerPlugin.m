//
//  NSMeapDatePicker.m
//  Cordova_TEST
//
//  Created by 罗忠燕 on 13-7-15.
//
//

#import "NSMeapDatePickerPlugin.h"
//#import <NSMeapGeneralComponets/nsmeap>
#import <NSMeapGeneralComponets/NSMeapDatePickerActionSheet.h>
#import <NSMeapGeneralComponets/NSMeapDatePickerPopView.h>
#import <NSMeapGeneralComponets/NSMeapCustomDatePickerView.h>
#import <NSMeapGeneralComponets/NSMeapCustomDatePickerActionsheet.h>
#import <NSMeapGeneralComponets/NSMeapCustomDatePickerPopView.h>
#import "MainViewController.h"

typedef  enum
{
    NSMDatePicker_Native,      // 默认
    NSMDatePicker_AutoDefine,
    
}NSMDatePickerType;

typedef enum
{
    NSMDatePicker_PopView,       // 默认
    NSMDatePicker_ActionSheet,
    NSMDatePicker_Alert,
    
}NSMDatePickerShowType;

@interface NSMeapDatePickerPlugin ()<NSMeapDatePickerActionSheetDelegate,NSMeapDatePickerPopViewDelegate,NSMeapCustomDatePickerViewDelegate>

// 用ActionSheet的形式展现日期选择器
@property (nonatomic, retain) NSMeapDatePickerActionSheet *datePickerActionSheet;
// 用PopView的形式展现日期选择器
@property (nonatomic, retain) NSMeapDatePickerPopView     *datePickerPopView;
//
@property (nonatomic, retain) NSMeapCustomDatePickerActionsheet *iPhoneCustomDatePicker;
//
@property (nonatomic, retain) NSMeapCustomDatePickerPopView     *iPadCustomDatePicker;
//
@property (nonatomic, retain) NSString                 *currentCallBackID;
// 日期选择器的模式
@property(nonatomic)  UIDatePickerMode datePickerMode;
//
@property (nonatomic) NSMDatePickerType                datePickerType;

@property (nonatomic) CGPoint location;

@end

@implementation NSMeapDatePickerPlugin

- (void)dealloc
{
    self.datePickerActionSheet = nil;
    self.datePickerPopView = nil;
    self.currentCallBackID = nil;
    self.iPadCustomDatePicker = nil;
    self.iPhoneCustomDatePicker = nil;
    [super dealloc];
}

//---------------------
// 获取日期
// arguments: 参数数组
// 0: id
// 1: pointX 日期选择器的X坐标  (btn.offsetLeft+btn.offsetWidth/2)
// 2: pointY 日期选择器的Y坐标  (btn.offsetTop+btn.offsetHeight/2)
//---------------------
- (void)getDate:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.currentCallBackID = [arguments queueHead];
    
    if ([arguments count] >= 4)
    {
        // 获取坐标
        NSString *XString = [[arguments objectAtIndex:1] isKindOfClass:[NSNull class]] ? [NSString stringWithFormat:@"%f",self.viewController.view.frame.size.height/2] : [arguments objectAtIndex:1];
        NSString *YString = [[arguments objectAtIndex:2] isKindOfClass:[NSNull class]] ? [NSString stringWithFormat:@"%f",self.viewController.view.frame.size.width/2] : [arguments objectAtIndex:2];
        
        float x = [XString floatValue];
        float y = [YString floatValue];
        self.location = CGPointMake(x, y);
        
        NSString *dateModel = [[arguments objectAtIndex:3] isKindOfClass:[NSNull class]] ? @"date" : [arguments objectAtIndex:3];
        [self setDateModel:dateModel];
        
        [self getDateFromNativeDatePicker];
    }
    else
    {
        // 参数为0的时候，默认出错，错误回调
        CDVPluginResult *result = nil;
        NSString *returnStr = @"DatePicker 参数不对";
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:returnStr];
        [self error:result callbackId:self.currentCallBackID];
    }
}

- (void)setDateModel:(NSString *)dateModel
{
    if ([dateModel isEqualToString:@"date"])
    {
        _datePickerType = NSMDatePicker_Native;
        _datePickerMode = UIDatePickerModeDate;
    }
    else if ([dateModel isEqualToString:@"date_time"])
    {
        _datePickerType = NSMDatePicker_Native;
        _datePickerMode = UIDatePickerModeDateAndTime;
    }
    else if ([dateModel isEqualToString:@"time"])
    {
        _datePickerType = NSMDatePicker_Native;
        _datePickerMode = UIDatePickerModeTime;
    }
    else if ([dateModel isEqualToString:@"hour_Minute"])
    {
        _datePickerType = NSMDatePicker_Native;
        _datePickerMode = UIDatePickerModeCountDownTimer;
    }
    else if ([dateModel isEqualToString:@"chineseDate"])
    {
        _datePickerType = NSMDatePicker_AutoDefine;
    }
}

// ----------
// 调用原生的日期选择器
// ----------
- (void)getDateFromNativeDatePicker
{
    if ([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPhone)
    {
        if (_datePickerType == NSMDatePicker_AutoDefine)
        {
            if (self.iPhoneCustomDatePicker == nil)
            {
                self.iPhoneCustomDatePicker = [[[NSMeapCustomDatePickerActionsheet alloc] initWithDelegate:self] autorelease];
            }
            [self.iPhoneCustomDatePicker showInView:self.viewController.view];
        }
        else if (_datePickerType == NSMDatePicker_Native)
        {
            if (self.datePickerActionSheet == nil)
            {
                self.datePickerActionSheet = [[[NSMeapDatePickerActionSheet alloc] initWithTitle:nil delegate:nil cancelButtonTitle:@"取消" destructiveButtonTitle:@"" otherButtonTitles:@"", nil] autorelease];
                self.datePickerActionSheet.delegateActionSheet = self;
                self.datePickerActionSheet.datePickerMode = _datePickerMode;
            }
            [self.datePickerActionSheet showInView:self.viewController.view];
        }
    }
    else if ([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPad)
    {
        if (_datePickerType == NSMDatePicker_AutoDefine)
        {
            if (self.iPadCustomDatePicker == nil)
            {
                self.iPadCustomDatePicker = [[[NSMeapCustomDatePickerPopView alloc]initWithContentViewController:nil delegateController:self] autorelease];
                self.iPadCustomDatePicker.popoverContentSize = CGSizeMake(320, 238);
            }
            [self.iPadCustomDatePicker presentPopoverFromRect:CGRectMake(_location.x, _location.y, 2, 2) inView:self.viewController.view permittedArrowDirections:UIPopoverArrowDirectionUp animated:YES];
        }
        else if (_datePickerType == NSMDatePicker_Native)
        {
            if (self.datePickerPopView == nil)
            {
                self.datePickerPopView = [[[NSMeapDatePickerPopView alloc] initWithContentViewController:nil] autorelease];
                self.datePickerPopView.popoverContentSize = CGSizeMake(320, 260);
                self.datePickerPopView.delegatePopView = self;
                self.datePickerPopView.datePickerMode = _datePickerMode;
            }
            [self.datePickerPopView presentPopoverFromRect:CGRectMake(_location.x, _location.y, 2, 2) inView:self.viewController.view permittedArrowDirections:UIPopoverArrowDirectionUp animated:YES];
        }
    }
}

//----------
// NSDate 转换成字符串
//----------
- (NSString *)stringForDate:(NSDate *)date
{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    if (_datePickerMode == UIDatePickerModeDateAndTime)
    {
        [formatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
    }
    else if (_datePickerMode == UIDatePickerModeDate)
    {
        [formatter setDateFormat:@"yyyy-MM-dd"];
    }
    else if (_datePickerMode == UIDatePickerModeTime)
    {
        [formatter setDateFormat:@"HH:mm:ss"];
    }
    else if (_datePickerMode == UIDatePickerModeCountDownTimer)
    {
        [formatter setDateFormat:@"HH:mm"];
    }
    
    NSString *dateString = [formatter stringFromDate:date];
    [formatter release];
    
    return dateString;
}

#pragma mark - 代理 NSMDatePickerActionSheetDelegate
/**
 *	@brief	选择日期后的回调代理方法
 *
 *	@param 	date 	选择的日期
 */
-(void)didSelectedDateInActionSheet:(NSDate *)date
{
    NSString *string = [self stringForDate:date];
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:string];
    [self success:result callbackId:self.currentCallBackID];
}

#pragma mark - 代理 NSMeapDatePickerPopViewDelegate
/**
 *	@brief	选择日期后的回调，并返回选择的日期/时间
 *
 *	@param 	date 	选择的日期/时间
 */
- (void)didSelectedDateInPopView:(NSDate *)date
{
    NSString *string = [self stringForDate:date];
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:string];
    [self success:result callbackId:self.currentCallBackID];
}

#pragma mark - 代理 NSMCustomDatePickerViewDelegate
//取消农历
- (void)cancelBtnClick
{
    if ([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPhone)
    {
        [self.iPhoneCustomDatePicker dismissWithClickedButtonIndex:0 animated:YES];
    }
    else if ([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPad)
    {
        [self.iPadCustomDatePicker dismissPopoverAnimated:YES];
    }
}

- (void)didSelectCalendarYearType:(NSString *)yearType Year:(NSString *)year Month:(NSString *)month Day:(NSString *)day
{
    NSString *string = [NSString stringWithFormat:@"%@(%@)年%@%@",yearType,year,month,day];
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:string];
    [self success:result callbackId:self.currentCallBackID];
}

@end
