//
//  日期选择器的视图类
//  IDJDatePickerView.h
//
//  Created by Lihaifeng on 11-11-22, QQ:61673110.
//  Copyright (c) 2011年 www.idianjing.com. All rights reserved.
//

#import <UIKit/UIKit.h>

#define YEAR_START 1970 ///滚轮显示的起始年份
#define YEAR_END 2049   ///滚轮显示的结束年份

@protocol NSMeapCustomDatePickerViewDelegate;

/// 日历显示的类型
enum calendarType {
    Gregorian1 = 1,
    Chinese1
};

@interface NSMeapCustomDatePickerView : UIView

@property (nonatomic) int type;
@property (nonatomic, retain) NSMutableArray *years;  ///第一列的数据容器
@property (nonatomic, retain) NSMutableArray *months; ///第二列的数据容器
@property (nonatomic, retain) NSMutableArray *days;   ///第三列的数据容器
@property (nonatomic) int jiaYear;
@property (nonatomic, assign) id  <NSMeapCustomDatePickerViewDelegate> delegate;
@property (nonatomic, retain) UIToolbar *toolBar;

- (id)initWithFrame:(CGRect)frame type:(int)type;

/// 调用这个方法，设置cell和scroll的值均为1
- (void)didSelectCell:(NSUInteger)cell inScroll:(NSUInteger)scroll;

@end

@protocol NSMeapCustomDatePickerViewDelegate <NSObject>
@optional

/// 取消按钮
- (void)cancelBtnClick;

/// 点击确定按钮,如果不需要toolbar,只需将toolBar隐藏，用上面的方法即可传值
- (void)didSelectCalendarYearType:(NSString *)yearType Year:(NSString *)year Month:(NSString *)month Day:(NSString *)day;

@end
