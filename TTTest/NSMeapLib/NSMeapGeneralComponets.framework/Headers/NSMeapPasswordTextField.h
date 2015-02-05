//
//  NSMPasswordTextField.h
//  MeapSDK
//
//  Created by 罗忠燕 on 13-9-25.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <UIKit/UIKit.h>
/// 密码最大长度
#define MAX_PASSWORD_LENGTH 16
/// 密码最小长度
#define MIN_PASSWORD_LENGTH 6

/// 密码输入框
@interface NSMeapPasswordTextField : UITextField

/// 设置正常状态的背景图片
@property (nonatomic, retain) UIImage *normalBackgroungImage;
/// 设置选中状态的背景图片
@property (nonatomic, retain) UIImage *hilightBackgroundImage;

@end
