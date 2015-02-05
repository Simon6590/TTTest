//
//  MeapHeader.h
//  FirstMEAP
//
//  Created by yangyalin on 13-4-9.
//  Copyright (c) 2013年 yangyalin. All rights reserved.
//


/** NSMeap
 *  描述: 用于定义MEAP底层必须的宏字符串
 *  包含MEAP底层常用的头文件
 *
 *  框架需要引入的framework有:
 *  CFNetwork.framework
 *  CoreGraphics.framework
 *  CoreTelephony.framework
 *  Foundation.framework
 *  MobileCoreServices.framework
 *  Security.framework
 *  SystemConfiguration.framework
 *  libsqlite3.0.dylib
 *  libz.1.2.5.dylib
 *  UIKit.framework
 *
 *  框架引入的第三方框架有:
 *  ZipArchive
 *  OpenSSLRSAWrapper
 *  GTMBase64
 */

// ****************************************************************************
#pragma mark - https 和 http 地址
// 示例 http:// IP地址/服务器路径/service.jws
// https://218.247.3.234:443/service.jws


/**
 *  首次安装默认值
 */
// 默认IP地址
#define SERVER_ADDRESS      @"218.247.3.234"
// 默认服务器路径
#define SERVER_MIDDLE_PTAH  @""
// HTTPS 端口
#define SERVER_HTTPS_PORT   @"443"
// APPKey
#define APP_KEY             @""
// Default Version
#define DEFAULT_VERSION     @""
// Default Group
#define DEFAULT_GROUP       @""
/// 内置注册验证模式  内置一个secreted_salt_key
#define NSMEAP_APPBANDING_INTERNAL_SALTKEY  @"DLmr7SOQYnyjl4m4ovDLW6C7"

// ****************************************************************************

/// 简单定义
#import "YY_Unit_Extend.h"
/// 正则表达式校验器
#import "NSMeapVerifyEngine.h"
/// 代理
#import "NSMeapDelegate.h"
/// 框架入口
#import "NSMeapInterface.h"

/// 数据解析封装
#import "NSMeapURL.h"

#import "NSMeapDataTree.h"
#import "NSMeapDataBean.h"
#import "NSMeapDataAtt.h"

#import "NSMeapDataAttBool.h"
#import "NSMeapDataAttDate.h"
#import "NSMeapDataAttDouble.h"
#import "NSMeapDataAttFile.h"
#import "NSMeapDataAttInt.h"
#import "NSMeapDataAttString.h"
#import "NSMeapDataAttLong.h"
// 网络请求、上传、下载、网络状态
#import "NSMeapRequest.h"
#import "NSMeapUploadFile.h"
#import "NSMeapDownloadFile.h"
#import "NSMeapNetWorkStatus.h"
/// 数据加密
#import "NSMeapDataSecurity.h"
#import "NSMeapDataEncrypt+Data.h"
#import "NSMeapDataEncrypt+File.h"
#import "NSMeapDataEncrypt+String.h"
/// 数据库操作
#import "NSMeapDB.h"
#import "NSMeapDBBaseObject.h"
#import "NSMeapSqlHanldler.h"
/// 同步下发监听
#import "NSMeapEventMsgManager.h"
#import "NSMeapMapEvent.h"
#import "NSMeapBeanEvent.h"
#import "NSMeapBytesEvent.h"
#import "NSMeapTextEvent.h"
/// keyChain
#import "NSMeapKeyChain.h"
/// 统计
#import "NSMeapClientStatistics.h"
/// 自定义loading框
#import "NSMeapAlertHUD.h"
/// 应用图标配置
#import "NSMeapStaticImageSetting.h"
/// 图像处理(拉伸、放大)
#import "UIImage+NSMeapImageProcessing.h"

/// 版本信息
#import "NSMeapVersion.h"

