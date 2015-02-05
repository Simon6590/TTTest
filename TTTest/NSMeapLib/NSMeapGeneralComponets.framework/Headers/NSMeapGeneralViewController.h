//
//  NSMeapGeneralViewController.h
//  NSMeapGeneralComponents
//
//  Created by yalin on 13-10-29.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *	@brief	视图控制器类型
 */
typedef enum
{
    HELP_VIEW_CONTROLLER_TYPE = 1,      //!< 帮助界面 */
    ABOUT_VIEW_CONTROLLER_TYPE,     //!< 关于界面 */
    GUIDE_VIEW_CONTROLLER_TYPE,     //!< 向导界面 */
}NSMEAP_VIEW_CONTROLLER_TYPE;

/**
 *	@brief	向导界面的视图代理
 */
@protocol NSMeapGuideControllerDataSource <NSObject>

/**
 *	@brief	页数数据源
 *
 *	@return	页数
 */
- (NSInteger)pagesCounts;

/**
 *	@brief	每一页的视图
 *
 *	@param 	index 	视图下标
 *
 *	@return	视图
 */
- (UIView *)viewWithIndex:(NSInteger)index;

@end

/**
 *	@brief	定义常用视图控制器
 */
@interface NSMeapGeneralViewController : UIViewController

/// 向导数据源
@property (nonatomic, assign) id <NSMeapGuideControllerDataSource> guideDataSource;

/// 向导pagecontrol
@property (nonatomic, retain) UIPageControl     *pageControl;

/// 视图控制器类型
@property (nonatomic, assign) NSMEAP_VIEW_CONTROLLER_TYPE   controllerType;

/// 帮助或者关于的时候显示的message
@property (nonatomic, retain) NSString  *message;

/**
 *	@brief	初始化
 *
 *	@param 	controllerType      视图控制器类型
 *	@param 	message             帮助或者关于的时候显示的message
 *	@param 	guideDataSource 	向导界面的时候的数据源
 *
 *	@return	当前对象
 */
- (id)initWithControllerType:(NSMEAP_VIEW_CONTROLLER_TYPE)controllerType message:(NSString *)message guideDataSource:(id<NSMeapGuideControllerDataSource>)guideDataSource;

@end
