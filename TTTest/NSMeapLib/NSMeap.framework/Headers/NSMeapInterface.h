//
//  MeapSDK.h
//  Ebank
//
//  Created by yangyalin on 13-4-17.
//  Copyright (c) 2013年 yangyalin. All rights reserved.
//

/**
 * @file        NSMeapInterface.h
 * @brief       Meap组件接口.
 * @version     1.0
 * @date        2013-3-14
 *
 * [2013-06-07] <杨亚霖> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <Foundation/Foundation.h>

/// 注册MEAP成功后发送的通知
#define NSMEAP_APPBANDING_PUSH_SUCCED @"NSMEAP_APPBANDING_PUSH_SUCCED"

/// 程序SDK主入口,主要在appdelegate中调用.
@interface NSMeapInterface : NSObject
CLASS_SINGLETON_INTERFACE(NSMeapInterface)

/// 应用注册的模式
typedef enum
{
    NSMEAP_APPBANDING_NONE,      //!< 无模式 */
    NSMEAP_APPBANDING_PUSH,      //!< 推送模式 */
    NSMEAP_APPBANDING_SMS,       //!< 短信模式 */
    NSMEAP_APPBANDING_EMAIL,     //!< 邮件模式 */
    NSMEAP_APPBANDING_INTERNAL,  //!< 内置模式 */
    
}NSMEAP_APPBANDING_TYPE;

/// Meap服务器IP
@property (nonatomic, retain) NSString *meapServerIP;

/// Meap服务器中间路径
@property (nonatomic, retain) NSString *meapServerPath;

/// HTTPS 服务端口
@property (nonatomic, retain) NSString *meapHttpsPort;

#pragma mark - meap检查更新
/**
 *	@brief	客户端native更新检查
 */
- (void)checkNativeUpdateDelegate:(id <NSMeapCheckAppUpdateDelegate>)delegate;

/**
 *	@brief	Hybrid小版本更新
 */
-(void)checkHybridUpdateDelegate:(id <NSMeapCheckHybridUpdateDeleagte>)delegate;

#pragma mark - 启动器
/**
 *	@brief	程序启动,启动meapsdk流程
 *
 *	@param 	info 	程序进入时带的信息
 */
- (void)meapLaunchFinishWithOption:(NSDictionary *)info;

/**
 *	@brief	注册推送成功回调
 *
 *	@param 	deviceToken 	返回deviceToken，用于推送的key
 */
- (void)meapRegisterNotificationsWithDeviceToken:(NSData *)deviceToken;

/**
 *	@brief	接收到推送调用meapsdk进行处理
 *
 *	@param 	info 	推送信息
 */
- (void)meapReceiveNotificationWithInfo:(NSDictionary *)info;

/**
 *	@brief	程序进入后台 调用的方法
 */
- (void)meapApplicationDidEnterBackground;

/**
 *	@brief	程序进入后台 调用的方法
 */
- (void)meapApplicationWillEnterForeground;

#pragma mark - MEAP注册方法
/**
 *	@brief 判断是否已注册过App
 *
 *	@return	YES：注册过 NO：没有注册过
 */
- (BOOL)isAppBanded;

/**
 *	@brief	Meap注册App 应用绑定方法
 *
 *	@param 	bandType 	注册方式
 *
 */
- (void)meapBandingApp:(NSMEAP_APPBANDING_TYPE)bandType;

/**
 *	@brief	设置IP地址弹出框，针对插件
 */
-(void)setIPAlert;
@end
