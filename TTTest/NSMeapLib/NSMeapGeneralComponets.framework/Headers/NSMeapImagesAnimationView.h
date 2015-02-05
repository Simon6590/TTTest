//
//  NSMImagesAnimationView.h
//  MeapSDK
//
//  Created by 罗忠燕 on 13-10-9.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <UIKit/UIKit.h>

/// 图片切换效果
typedef enum
{
    NSMEAP_IMAGES_ANIMATION_DEFAULT,        //!< 自动加手动切换图片 */
    NSMEAP_IMAGES_ANIMATION_HANDMOTION,     //!< 手动切换图片 */
    NSMEAP_IMAGES_ANIMATION_SLEFMOTION,     //!< 自动切换图片 */
    NSMEAP_IMAGES_ANIMATION_FADEINOUT,      //!< 淡入淡出切换图片 */
    NSMEAP_IMAGES_ANIMATION_RIPPLEEFFECT,   //!< 波纹切换图片 */
    NSMEAP_IMAGES_ANIMATION_COVER,          //!< 覆盖切换图片 */
}NSMEAP_IMAGES_ANIMATION_TYPE;

@class NSMeapImagesAnimationView;
/// 图片集动画效果显示视图代理
@protocol NSMeapImagesAnimationViewDelegate <NSObject>

/**
 *	@brief	图片集合视图中选中的图片的index
 *
 *	@param 	imagesAnimationView
 *	@param 	imageIndex 	选中的图片的下标
 */
- (void)didSelectedInImagesAnimationView:(NSMeapImagesAnimationView *)imagesAnimationView imageIndex:(NSInteger)imageIndex;

@end

/// 图片集动画效果显示视图
@interface NSMeapImagesAnimationView : UIView

/// 图片集数组
@property (nonatomic, retain) NSArray           *imagesArray;

@property (nonatomic) NSMEAP_IMAGES_ANIMATION_TYPE  animationType;

@property (nonatomic, assign) id <NSMeapImagesAnimationViewDelegate> delegate;

@end
