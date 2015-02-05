//
//  NSMeapQRCode.h
//  NSMeapQRCode
//
//  Created by 十九 on 13-7-17.
//  Copyright (c) 2013年 韩 立娜. All rights reserved.
//
/**
 *  二维码扫描组件
 */
/**
 *	@brief	二维码扫描组件,组件基于zxing二维码库做了一系列的效果,可以方便调用.
 *  用此文件需要引入:
 *  zxing框架
 *  AVFoundation
 *  AudioToolbox
 *  CoreVideo
 *  CoreMedia
 *  libiconv
 *  AddressBook
 *  AddressBookUI
 */


#import <Foundation/Foundation.h>

@protocol NSMeapQRCodeDelegate;

@interface NSMeapQRCode : NSObject<UIImagePickerControllerDelegate>

@property (nonatomic,assign) id <NSMeapQRCodeDelegate> delegate;


/**
 *	@brief	单例
 *
 */
+(NSMeapQRCode *)shareInstance;

/**
 *	@brief	字符串生成二维码图片
 *
 *	@param 	text 	字符串
 *	@param 	size 	图片尺寸
 *
 *	@return	UIImage 二维码图片
 */
+(UIImage *)qrImageForString:(NSString *)text imageSize:(CGFloat)size;

/**
 *	@brief	扫描二维码
 *
 *	@param 	superController  UIViewController对象
 */
-(void)scanQRCodeWithController:(UIViewController *)superController;


/**
 *	@brief	扫描二维码
 *
 *	@param 	superController  UIViewController对象
 */
- (NSString *)resultWithImage:(UIImage *)image;

/**
 *	@brief	退出扫描视图
 */
- (void)didmissQRCodeController;

/**
 *	@brief	设置前置view
 *  @param 	superController  UIViewController对象
 */
- (void)setPreView:(UIView *)view;

@end

@protocol NSMeapQRCodeDelegate <NSObject>

/**
 *  @brief	获得二维码文本信息 回调方法
 */
-(void)qrStringCallBack:(NSString *)result;

@optional
/**
 *  @brief	表面的视图,现在只有一个UIInterfaceOrientationPortrait方向
 */
- (UIView *)preView;

@end