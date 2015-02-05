//
//  NSMUITextField.h
//  MeapSDK
//
//  Created by 罗忠燕 on 13-7-24.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <UIKit/UIKit.h>

/// 可以设置内边距的UITextField
@interface NSMeapUITextField : UITextField
{
    BOOL isEnablePadding;   //!< 设置是否可以设置内边距Padding
    float paddingLeft;      //!< 内左边距
    float paddingRight;     //!< 内右边距
    float paddingTop;       //!< 内上边距
    float paddingBottom;    //!< 内下边距
}

/**
 *	@brief	设置内边距
 *
 *	@param 	enable 	是否可以设置内边距
 *	@param 	top 	内上边距
 *	@param 	right 	内右边距
 *	@param 	bottom 	内下边距
 *	@param 	left 	内左边距
 */
- (void)setPadding:(BOOL)enable top:(float)top right:(float)right bottom:(float)bottom left:(float)left;

@end
