//
//  NSMeapCamera.h
//  MeapSDK
//
//  Created by 十九 on 13-8-7.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        NSMeapCamera.h
 * @brief       媒体库组件.
 * @version     1.0
 * @date        2013-8-7
 *
 * [2013-06-07] <罗忠燕> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <Foundation/Foundation.h>

@protocol NSMeapCameraDelegate;
/// 媒体库组件、拍照和录像
@interface NSMeapCamera : NSObject
CLASS_SINGLETON_INTERFACE(NSMeapCamera)

/// 代理
@property (nonatomic,assign) id<NSMeapCameraDelegate> delegate;

/**
 *	@brief	调用照相机
 *
 *	@param 	superController 要调用照相机的UIViewController	
 */
-(void)takePhotoWithController:(UIViewController *)superController;
/**
 *	@brief	调用录像机
 *
 *	@param 	superController 要调用录像机的UIViewController
 */
-(void)takeVideoWithController:(UIViewController *)superController;

@end

@protocol NSMeapCameraDelegate <NSObject>

@optional

/**
 *	@brief	拍照或录像失败回调
 *
 *	@param 	message 	失败信息
 */
-(void)cameraFinishedFailedWithMessage:(NSString *)message;


-(void)cameraDidFinishPickingMediaWithInfo:(NSDictionary *)info;
@end