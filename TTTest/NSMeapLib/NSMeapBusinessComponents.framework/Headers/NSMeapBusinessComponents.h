//
//  NSMeapBusinessComponents.h
//  NSMeapBusinessComponents
//
//  Created by yalin on 13-10-15.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//
#import <NSMeap/NSMeap.h>

/// 通用控件版本信息
#import "NSMeapBusinessComponentsVersion.h"

/// 获取验证码的服务组件
#import "NSMeapCaptchaServer.h"
/// 获取验证码的视图组件 组件是一个按钮 和UIButton的用法一样
#import "NSMeapCaptchaView.h"

/// 登录服务组件 提供登录接口 可直接调用登录
#import "NSMeapSSOServer.h"
/// 登录视图组件 提供基本登录简单视图 用户可自定义登录视图 然后调用登录服务组件登录
#import "NSMeapLoginView.h"

/// office展示组件 支持.doc\.xsl\.png\.pdf 等格式的文件浏览
#import "NSMeapOfficeShow.h"



