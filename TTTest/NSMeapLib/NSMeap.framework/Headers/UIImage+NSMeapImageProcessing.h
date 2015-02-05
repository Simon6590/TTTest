//
//  UIImage+NSMeapImageProcessing.h
//  NSMeap
//
//  Created by yalin on 13-11-6.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        UIImage+NSMeapImageProcessing.h
 * @brief       图像拉伸缩放组件.
 * @version     1.0
 * @date        2013-11-6
 *
 * [2013-06-07] <杨亚霖> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <UIKit/UIKit.h>

/// 处理图片拉伸缩放的类别
@interface UIImage (NSMeapImageProcessing)

/**
 *	@brief	在固定的范围(不会拉伸图像,没有透明像素,生成的图像不一定是targetSize大小)
 *
 *	@param 	targetSize 	画布大小
 */
- (UIImage *)imageByScalingToMinSize:(CGSize)targetSize;

/**
 *	@brief	在固定的范围(不会拉伸图像,自动等比例缩放,生成targetSize大小的图像)
 *
 *	@param 	targetSize 	画布大小
 */
- (UIImage *)imageByScalingToSize:(CGSize)targetSize;

/**
 *	@brief	在固定的范围
 *
 *	@param 	targetSize      画布大小
 *	@param 	contentSize 	图像内容大小
 */
- (UIImage *)imageByScalingToSize:(CGSize)targetSize contentSize:(CGSize)contentSize;

/**
 *	@brief	不等比例压缩(会拉伸)
 *
 *	@param 	targetSize 	画布大小
 */
- (UIImage *)imageByNotEquleToSize:(CGSize)targetSize;

@end
