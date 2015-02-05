//
//  NSMeapScaleImageView.h
//  NSMeapImageView
//
//  Created by yalin on 13-10-28.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

/**
 *	@brief	基础展示控件,可以放大缩小.
 */
@interface NSMeapScaleImageView : UIView

- (id)initWithImage:(UIImage *)image;

/// 图片信息
@property (nonatomic, retain) UIImage   *image;

/// 允许缩小倍数
@property(nonatomic) CGFloat minimumZoomScale;     // default is 1.0
/// 允许放大倍数
@property(nonatomic) CGFloat maximumZoomScale;     // default is 3.0. must be > minimum zoom scale to enable zooming


@end
