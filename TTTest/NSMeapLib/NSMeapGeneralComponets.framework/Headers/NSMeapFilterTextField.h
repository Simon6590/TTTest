//
//  NSMFilterText.h
//  MeapSDK
//
//  Created by 罗忠燕 on 13-9-22.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        NSMeapFilterTextField.h
 * @brief       过滤文本框组件.
 * @version     1.0
 * @date        2013-9-22
 *
 * [2013-06-07] <罗忠燕> v1.0
 *
 * + v1.0版发布.
 *
 */

#import "NSMeapUITextField.h"

/// 过滤类型枚举
typedef enum 
{
    NSMEAP_FILTERTEXTFILED_AUTODEFINE,      //!< 自定义过滤的正则表达式 */
    NSMEAP_FILTERTEXTFILED_EMAIL,           //!< 邮箱过滤 */
    NSMEAP_FILTERTEXTFILED_TELPHONE,        //!< 电话过滤 */
    NSMEAP_FILTERTEXTFILED_MOBILPHONE,      //!< 手机号过滤 */
    NSMEAP_FILTERTEXTFILED_POSTCODE,        //!< 邮编过滤 */
    NSMEAP_FILTERTEXTFILED_IDCARD,          //!< 身份证号过滤 */
    
}NSMEAP_FILTERTEXTFILED_TYPE;

/// 过滤文本框组件
@interface NSMeapFilterTextField : NSMeapUITextField

/// 过滤类型
@property (nonatomic) NSMEAP_FILTERTEXTFILED_TYPE   filterType;

@property (nonatomic, retain) NSError           *filterError;

/**
 *	@brief	添加过滤正则表达式
 *
 *	@param 	regex 正则表达式
 */
- (void)addFilterRegex:(NSString *)regex;

@end
