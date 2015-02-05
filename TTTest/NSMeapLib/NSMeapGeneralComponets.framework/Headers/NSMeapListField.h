//
//  NSMeapListField.h
//  MeapSDK
//
//  Created by 韩立娜 on 13-10-8.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        NSMeapListField.h
 * @brief       下拉框控件.
 * @version     1.0
 * @date        2013-10-8
 *
 * [2013-06-07] <罗忠燕> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <UIKit/UIKit.h>

#define HIGHT_ROW self.frame.size.height

@protocol NSMeapListFieldDelegate;

/// 下拉框控件
@interface NSMeapListField : UIView<UITableViewDataSource,UITableViewDelegate,UITextFieldDelegate>

@property (nonatomic, assign) id <NSMeapListFieldDelegate>      yydelegate;
/// 文本框
@property (nonatomic, retain)   UITextField *textField;
/// 背景图
@property (nonatomic, retain)   UIImageView *backgroundView;
/// 右边的显示按钮
@property (nonatomic, retain) UIButton      *showButton;

/// 显示的数组
@property (nonatomic, retain)   NSArray     *values;
/// 每个值的id数组
@property (nonatomic, retain)   NSArray     *IDArray;

/// 当前的id值 如果没有则为nil
@property (nonatomic, readonly) NSString    *currentID;

@end


@protocol NSMeapListFieldDelegate <NSObject>

- (void)ListFieldPressed:(NSMeapListField *)field index:(NSUInteger)index;
- (void)textFieldDidBeginEditing:(UITextField *)textField;

@end
