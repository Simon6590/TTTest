//
//  MeapNetWorkStatus.h
//  MeapSDK
//
//  Created by 罗忠燕 on 13-8-21.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *	@brief	检测网络状态枚举
 */
typedef enum
{
    NSMEAP_NETWORK_NONE,  //!< 无网络 */
    NSMEAP_NETWORK_WIFI,  //!< wifi网络 */
    NSMEAP_NETWORK_3G,    //!< 移动3G网络 */
}NSMEAP_NETWORK_STATUS;

/// 网络连接类型检测
@interface NSMeapNetWorkStatus : NSObject

/**
 *	@brief	网络检测
 *
 *	@return	网络状态Meap_NetWork_Status
 */
+ (NSMEAP_NETWORK_STATUS)checkNetWork;

@end
