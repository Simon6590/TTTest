//
//  NSMeapMediaPlugin.h
//  Cordova_TEST
//
//  Created by 十九 on 13-8-7.
//
//

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

@interface NSMeapMediaPlugin : CDVPlugin
/**
 *	@brief	调用媒体库
 *
 *	@param 	arguments 	参数数组 参数:id,
                                    action 调用服务方法名(camera 调用照相机 picture 调用图库 video 调用录像 audio 录音),
                                    filename 保存文件时文件名，(可以缺省)
 *	@param 	options 	无
 */
- (void)media:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

@end
