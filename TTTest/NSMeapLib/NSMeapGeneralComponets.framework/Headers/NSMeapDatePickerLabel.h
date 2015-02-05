//
//  NSMDatePickerLabel.h
//  MeapSDK
//
//  Created by 罗忠燕 on 13-9-26.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        NSMeapDatePickerLabel.h
 * @brief       日期/时间选择器组件.
 * @version     1.0
 * @date        2013-9-26
 *
 * [2013-06-07] <罗忠燕> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <UIKit/UIKit.h>

/// 日期、时间选择器UILabel的样式
typedef enum
{
    NSMEAP_DATEPICKERLABEL_DATE,        //!< 日期选择器 */
    NSMEAP_DATEPICKERLABEL_DATETIME,    //!< 日期和时间选择器 */
    NSMEAP_DATEPICKERLABEL_TIME,        //!< 时间选择器 */
    NSMEAP_DATEPICKERLABEL_CHINESE,     //!< 农历选择器 */
    
}NSMEAP_DATEPICKERLABEL_SHOWTYPE;

/// 日期、时间选择器UILabel
@interface NSMeapDatePickerLabel : UILabel

/// 日期、时间选择器UILabel的样式
@property (nonatomic, assign) NSMEAP_DATEPICKERLABEL_SHOWTYPE showType;

@end
