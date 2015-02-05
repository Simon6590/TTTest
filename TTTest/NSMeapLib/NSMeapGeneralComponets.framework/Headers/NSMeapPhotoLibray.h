//
//  NSMeapPhotoLibray.h
//  MeapSDK
//
//  Created by 十九 on 13-8-8.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NSMeapPhotoLibrayDelegate;
/// 照片库组件
@interface NSMeapPhotoLibray : NSObject
CLASS_SINGLETON_INTERFACE(NSMeapPhotoLibray)

/// 代理
@property (nonatomic,assign) id<NSMeapPhotoLibrayDelegate> delegate;

/**
 *	@brief	获取照片库
 *
 *	@param 	superController 	要调用照片库的UIViewController
 */
-(void)getPhotos:(UIViewController *)superController;

@end

@protocol NSMeapPhotoLibrayDelegate <NSObject>

@optional
/**
 *	@brief	调用照片库 选择照片成功回调
 *
 *	@param 	info 	照片的信息 
 */
-(void)getPhotoSucceedInfo:(NSDictionary *)info;
/**
 *	@brief	调用照片库 失败回调
 *
 *	@param 	errorInfo 	失败信息
 */
-(void)getPhotoFailedInfo:(NSString *)errorInfo;
@end