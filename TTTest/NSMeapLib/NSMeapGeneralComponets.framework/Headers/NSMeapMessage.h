//
//  NSMMessage.h
//  MeapSDK
//
//  Created by 罗忠燕 on 13-7-19.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MessageUI/MessageUI.h>

/// 发送消息的组件
@interface NSMeapMessage : NSObject

/**
 *	@brief	单例
 *
 *	@return	NSMMessage
 */
+ (NSMeapMessage *)shareNSMeapMessage;

/**
 *	@brief	本机发送短信
 *
 *	@param 	message 	短信内容
 *	@param 	toRecipients 	短信的接收者,支持向多个人发送,号码用逗号隔开: “18612447362,18610729420”
 *	@param 	controller 	用来打开发短信控制器的控制器
 */
- (void)sendMessage:(NSString *)message toRecipients:(NSString *)toRecipients controller:(UIViewController *)controller;

/**
 *	@brief	走Meap平台发送短信
 *
 *	@param 	message 	短信类容
 *	@param 	toRecipients 短信的接收者,支持向多个人发送,号码用逗号隔开: “18612447362,18610729420”	
 */
- (void)sendMessageByMeap:(NSString *)message toRecipients:(NSString *)toRecipients;

@end
