//
//  NSMeapCalendar.m
//  Cordova_TEST
//
//  Created by 罗忠燕 on 13-7-15.
//
//

#import "NSMeapCalendarPlugin.h"
#import "DSLCalendarView.h"

// ------------------------------------
// iPhone DatePicker
// ------------------------------------
#pragma mark - iPhone DatePicker
@protocol NSMIPhoneCalendarActionSheetDelegate <NSObject>

- (void)didSelectedDateInActionSheet:(NSDate *)date;

@end

@interface NSMIPhoneCalendarActionSheet : UIView <DSLCalendarViewDelegate>

@property (nonatomic, assign) id <NSMIPhoneCalendarActionSheetDelegate> delegateActionSheet;
@property (nonatomic, retain) UIToolbar     *toolBar;
@property (nonatomic, retain) DSLCalendarView  *calendarView;

@end

@implementation NSMIPhoneCalendarActionSheet

- (void)dealloc
{
    self.toolBar = nil;
    self.calendarView = nil;
    
    [super dealloc];
}

- (id)initWithCoder:(NSCoder *)aDecoder
{
    self = [super initWithCoder:aDecoder];
    if (self)
    {
        [self initView];
    }
    return self;
}

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self)
    {
        [self initView];
    }
    return self;
}

- (void)initView
{
    self.frame = CGRectMake(0, 0, 320, 354);
    
    self.calendarView = [[[DSLCalendarView alloc] initWithFrame:CGRectMake(0, 44, 320, 310)] autorelease];
    self.calendarView.delegate = self;
    [self addSubview:self.calendarView];
    
    //* 添加toolbar
    self.toolBar = [[[UIToolbar alloc] initWithFrame:CGRectMake(0, 0, 320, 44)] autorelease];
    self.toolBar.barStyle = UIBarStyleBlackOpaque;
    
    UIBarButtonItem *sureButton = [[UIBarButtonItem alloc] initWithTitle:@"确定" style:UIBarButtonItemStyleDone target:self action:@selector(sureButtonPressed)];
    
    UIBarButtonItem *cancelButton = [[UIBarButtonItem alloc] initWithTitle:@"取消" style:UIBarButtonItemStyleBordered target:self action:@selector(cancelButtonPressed)];
    
    UIBarButtonItem *fixedButton  = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace target:nil action:nil];
    
    NSArray *buttonArray = [NSArray arrayWithObjects:fixedButton,cancelButton, sureButton, nil];
    [sureButton release];
    [cancelButton release];
    
    [self.toolBar setItems:buttonArray];
    [self addSubview:self.toolBar];
}

- (void)cancelButtonPressed
{
    [UIView beginAnimations:nil context:nil];
    [UIView setAnimationCurve:UIViewAnimationCurveEaseIn];
    [UIView setAnimationDuration:0.3];
    self.frame = CGRectMake(0, 480, 320, 354);
    [UIView commitAnimations];
}

- (void)sureButtonPressed
{
//    if ([self.delegateActionSheet respondsToSelector:@selector(didSelectedDateInActionSheet:)])
//        
//    {
//        [self.delegateActionSheet didSelectedDateInActionSheet:[self.datePicker.date dateByAddingTimeInterval:8 * 60 * 60]];
//    }
    
    [self cancelButtonPressed];
}

#pragma mark - DSLCalendarView Delegate
- (void)calendarView:(DSLCalendarView *)calendarView didSelectRange:(DSLCalendarRange *)range
{
    if (range != nil)
    {
        NSLog( @"Selected %d/%d - %d/%d", range.startDay.day, range.startDay.month, range.endDay.day, range.endDay.month);
    }
    else
    {
        NSLog( @"No selection" );
    }
}

- (DSLCalendarRange*)calendarView:(DSLCalendarView *)calendarView didDragToDay:(NSDateComponents *)day selectingRange:(DSLCalendarRange *)range
{
    if (NO)
    { // Only select a single day
        return [[DSLCalendarRange alloc] initWithStartDay:day endDay:day];
    }
    else if (NO)
    { // Don't allow selections before today
        NSDateComponents *today = [[NSDate date] dslCalendarView_dayWithCalendar:calendarView.visibleMonth.calendar];
        
        NSDateComponents *startDate = range.startDay;
        NSDateComponents *endDate = range.endDay;
        
        if ([self day:startDate isBeforeDay:today] && [self day:endDate isBeforeDay:today])
        {
            return nil;
        }
        else
        {
            if ([self day:startDate isBeforeDay:today])
            {
                startDate = [today copy];
            }
            if ([self day:endDate isBeforeDay:today])
            {
                endDate = [today copy];
            }
            
            return [[DSLCalendarRange alloc] initWithStartDay:startDate endDay:endDate];
        }
    }
    
    return range;
}

- (void)calendarView:(DSLCalendarView *)calendarView willChangeToVisibleMonth:(NSDateComponents *)month duration:(NSTimeInterval)duration
{
    NSLog(@"Will show %@ in %.3f seconds", month, duration);
}

- (void)calendarView:(DSLCalendarView *)calendarView didChangeToVisibleMonth:(NSDateComponents *)month
{
    NSLog(@"Now showing %@", month);
}

- (BOOL)day:(NSDateComponents*)day1 isBeforeDay:(NSDateComponents*)day2
{
    return ([day1.date compare:day2.date] == NSOrderedAscending);
}

@end


// ------------------------------------
// NSMeapCalendar
// ------------------------------------
#pragma mark - NSMeapCalendar 
@interface  NSMeapCalendarPlugin ()<NSMIPhoneCalendarActionSheetDelegate>

@property (nonatomic, retain) NSMIPhoneCalendarActionSheet  *calendarActionSheet;

@property (nonatomic, retain) UIPopoverController           *popController;

@property (nonatomic, retain) NSString                      *currentCallBackID;

@end

@implementation NSMeapCalendarPlugin

- (void)dealloc
{
    self.calendarActionSheet = nil;
    self.popController = nil;
    self.currentCallBackID = nil;
    
    [super dealloc];
}

- (void)getCalendar:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    if ([arguments count] >= 2)
    {
        self.currentCallBackID = (NSString *)[arguments objectAtIndex:0];
        // 必须传二个参数，第二个参数 DatePicker的展现形式是原生的还是自定义的
        NSString *datePickerType = (NSString *)[arguments objectAtIndex:1];
        
        if ([datePickerType isEqualToString:@"native"])
        {
            [self showCalendarView];
        }
        else if ([datePickerType isEqualToString:@"autoDefine"])
        {
            
        }
    }
    else
    {
        // 参数为0的时候，默认出错，错误回调
        CDVPluginResult *result = nil;
        NSString *returnStr = @"参数不对";
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:returnStr];
        [self error:result callbackId:self.currentCallBackID];
    }
}

//----------
// 调用原生的日期选择器
//----------
- (void)showCalendarView
{
    if ([[UIDevice currentDevice] userInterfaceIdiom] ==  UIUserInterfaceIdiomPhone)
    {
        if (self.calendarActionSheet == nil)
        {
            self.calendarActionSheet = [[[NSMIPhoneCalendarActionSheet alloc] init] autorelease];
            self.calendarActionSheet.delegateActionSheet = self;
        }
        
        self.calendarActionSheet.frame = CGRectMake(0, 480, 320, 354);
        [self.viewController.view addSubview:self.calendarActionSheet];
        [UIView beginAnimations:nil context:nil];
        [UIView setAnimationCurve:UIViewAnimationCurveEaseIn];
        [UIView setAnimationDuration:0.3];
        self.calendarActionSheet.frame = CGRectMake(0, 480-354, 320, 354);
        [UIView commitAnimations];
    }
    else if ([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPad)
    {
//        UIViewController *contentController = [[UIViewController alloc] init];
//        contentController.view.frame = CGRectMake(0, 0, 320, 310);
//        [contentController.view addSubview:self.calendarView];
//        
//        self.popController = [[[UIPopoverController alloc] initWithContentViewController:contentController] autorelease];
//        self.popController.popoverContentSize = CGSizeMake(320,310);
//        [self.popController presentPopoverFromRect:CGRectMake(100, 100, 2, 2) inView:self.viewController.view permittedArrowDirections:UIPopoverArrowDirectionAny animated:YES];
//        [contentController release];
    }
}

#pragma mark - 
- (void)didSelectedDateInActionSheet:(NSDate *)date
{
    
}

@end
