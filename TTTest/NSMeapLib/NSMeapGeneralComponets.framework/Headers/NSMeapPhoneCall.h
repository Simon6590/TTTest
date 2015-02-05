//
//  NSMPhoneCall.h
//  MeapSDK
//
//  Created by 罗忠燕 on 13-7-19.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 打电话组件
@interface NSMeapPhoneCall : NSObject

/**
 *	@brief	打电话
 *
 *	@param 	phoneNum 	电话号码
 */
+ (void)callPhoneNumber:(NSString *)phoneNum;

@end
