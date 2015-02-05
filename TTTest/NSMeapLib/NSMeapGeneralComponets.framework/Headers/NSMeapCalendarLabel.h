//
//  NSMCalendarLabel.h
//  MeapSDK
//
//  Created by 罗忠燕 on 13-9-26.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        NSMeapCalendarLabel.h
 * @brief       日历组件.
 * @version     1.0
 * @date        2013-9-26
 *
 * [2013-06-07] <罗忠燕> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <UIKit/UIKit.h>

/// 日历显示的样式
typedef enum
{
    NSMEAP_CALENDARLABEL_POP,     //!< 公历日历，iPhone和iPad都以UIPopverView样式出现 */
    NSMEAP_CALENDARLABEL_AUTO,    //!< 公历和农历日历，iPhone以UIActionsheet样式出现，由下往上滑出；iPad以UIPopverView的样式出现 */
}NSMEAP_CALENDARLABEL_SHOWTYPE;

/// 日历UILabel
@interface NSMeapCalendarLabel : UILabel

/// 日历显示的样式
@property (nonatomic, assign) NSMEAP_CALENDARLABEL_SHOWTYPE showType;

@end
