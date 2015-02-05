//
//  NSMeapTabBar.h
//  NSMeapTabBarController
//
//  Created by 韩立娜 on 13-9-22.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NSMeapTabItem.h"

typedef enum
{
    NSMEAP_TABBAR_ORIENTATION_PORTRAIT,         //!< 竖屏显示 */
    NSMEAP_TABBAR_ORIENTATION_LANDSCAPE,        //!< 横屏显示 */
}NSMEAP_TABBAR_ORIENTATION;

@protocol NSMeapTabBarDelegate;

@interface NSMeapTabBar : UIView

/// NSMeapTabBarDelegate
@property (nonatomic, assign) id<NSMeapTabBarDelegate>      delegate;
/// NSMeapTabItem数组
@property (nonatomic, readonly) NSMutableArray              *tabItems;
/// NSMEAP_TABBAR_ORIENTATION
@property (nonatomic, readonly) NSMEAP_TABBAR_ORIENTATION   tabBarOrientation;
/// 选中的下标
@property (nonatomic, assign) NSInteger                     selectedIndex;

/**
 *	@brief	初始化视图
 *
 *	@param 	frame 	视图的frame
 *	@param 	tabItems NSMeapTabItem 数组
 *
 *	@return	
 */
- (id)initWithFrame:(CGRect)frame tabItems:(NSArray *)tabItems orientation:(NSMEAP_TABBAR_ORIENTATION)tabBarOrientation;

/**
 *	@brief	添加TabItem
 *
 *	@param 	tabItem
 */
- (void)addTabItem:(NSMeapTabItem *)tabItem;

/**
 *	@brief	删除TabItem
 */
- (void)removeItemAtIndex:(NSInteger)index;

/**
 *	@brief	设置Items数组
 *
 *	@param 	tabItems
 */
- (void)setTabItems:(NSMutableArray *)tabItems;

/**
 *	@brief  设置TabBar的方向
 *
 *	@param 	tabBarOrientation
 */
- (void)setTabBarOrientation:(NSMEAP_TABBAR_ORIENTATION)tabBarOrientation;

/**
 *	@brief	设置背景图片
 *
 *	@param 	backgroundImage 	背景图片
 */
- (void)setBackgroundImage:(UIImage *)backgroundImage;

/**
 *	@brief	绘制TabItems
 */
- (void)reloadTabItems;

@end

@protocol NSMeapTabBarDelegate<NSObject>
@optional
/**
 *	@brief	选择TabBar调用此代理方法
 *
 *	@param 	tabBar  tabBar
 *	@param 	index 	tabBar的index值
 */
- (void)tabBar:(NSMeapTabBar *)tabBar didSelectIndex:(NSInteger)index;

@end
