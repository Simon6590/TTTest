//
//  NSMeapTabBarController.h
//  NSMeapTabBarController
//
//  Created by 韩立娜 on 13-9-22.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NSMeapTabBar.h"
#import "NSMeapTabItem.h"

@protocol NSMeapTabBarControllerDelegate;
@interface NSMeapTabBarController : UIViewController <NSMeapTabBarDelegate>

@property (nonatomic, strong) UIView            *transitionView;
///	选中的controller
@property (nonatomic, readonly) UIViewController *selectedViewController;

///	controller的总数
@property (nonatomic) NSInteger controllersCount;

///	选中的index值
@property (nonatomic) NSInteger selectedIndex;

///	获取NSMeapTabBar,只读
@property (nonatomic, readonly) NSMeapTabBar *tabBar;

///	NSMeapTabBarControllerDelegate
@property (nonatomic, assign) id<NSMeapTabBarControllerDelegate> delegate;

///	tabBar下面是否可以有内容
@property (nonatomic, readonly) BOOL tabBarTransparent;

/// navigationController
//@property (nonatomic, strong) UINavigationController *navigationController;

/**
 *	@brief	初始化视图
 *
 *	@param 	controllers 	视图控制器数组
 *	@param 	frame 	tabBar的frame
 *	@param 	tabItems 	tabItems数组
 *	@param 	tabBarOrientation 	tabBar的方向
 *	@param 	tabBarTransparent 	tabBar下面是否可以有内容
 *
 *	@return NSMeapTabBarController
 */
- (id)initWithViewControllers:(NSArray *)controllers tabBarFrame:(CGRect)frame tabItems:(NSArray *)tabItems tabBarOrientation:(NSMEAP_TABBAR_ORIENTATION)tabBarOrientation tabBarTransparent:(BOOL)tabBarTransparent;

/**
 *	@brief	添加tabItem和对应的Controller
 *
 *	@param 	controller 	视图
 *	@param 	tabItem 	标签
 */
- (void)addViewController:(UIViewController *)controller tabItem:(NSMeapTabItem *)tabItem;

/**
 *	@brief	删除Controller
 *
 *	@param 	index 	Controller所在的下标
 */
- (void)removeControllerAtIndex:(NSInteger)index;

/**
 *	@brief	隐藏TabBar
 *
 *	@param 	animated 	是否加动画
 */
- (void)hiddenTabBarAnimated:(BOOL)animated;

/**
 *	@brief	显示TabBar
 *
 *	@param 	animated 	是否加动画
 */
- (void)showTabBarAnimated:(BOOL)animated;

@end


@protocol NSMeapTabBarControllerDelegate <NSObject>
@optional

/**
 *	@brief	设置viewController对应的tabBar是否可以点击
 *
 *	@param 	tabBarController tabBarController
 *	@param 	viewController   viewController
 *
 *	@return	
 */
- (BOOL)tabBarController:(NSMeapTabBarController *)tabBarController shouldSelectViewController:(UIViewController *)viewController;

/**
 *	@brief	点击tabBar回调该方法
 *
 *	@param 	tabBarController 	tabBarController
 *	@param 	viewController      viewController
 */
- (void)tabBarController:(NSMeapTabBarController *)tabBarController didSelectViewController:(UIViewController *)viewController;

@end

@interface UIViewController (NSMeapTabBarControllerSupport)

@property(nonatomic, strong, readonly) NSMeapTabBarController *NSMeapTabBarController;

@end

