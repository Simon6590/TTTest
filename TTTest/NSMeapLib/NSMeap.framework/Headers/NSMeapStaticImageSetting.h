//
//  NSMeapStaticImageSetting.h
//  NSMeap
//
//  Created by yalin on 13-11-4.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *	@brief	应用内图标配置,通过此类注册的button或UIImageView,后台可以通过配置来更改程序控件图标;
 *  后台通过identifier来识别哪个控件的图标.
 */
@interface NSMeapStaticImageSetting : NSObject
CLASS_SINGLETON_INTERFACE(NSMeapStaticImageSetting)

/**
 *	@brief	添加一个button
 *
 *	@param 	button      需要添加的button
 *	@param 	identifier 	唯一标识
 */
- (void)addButton:(UIButton *)button identifier:(NSString *)identifier;

/**
 *	@brief	添加一个imageview
 *
 *	@param 	imageView      需要添加的imageview
 *	@param 	identifier 	唯一标识
 */
- (void)addImageView:(UIImageView *)imageView identifier:(NSString *)identifier;

/**
 *	@brief	移除一个button
 *
 *	@param 	identifier      唯一标识
 */
- (void)removeButtonIdentifier:(NSString *)identifier;

/**
 *	@brief	移除一个imageview
 *
 *	@param 	identifier      唯一标识
 */
- (void)removeImageViewIdentifier:(NSString *)identifier;

@end
