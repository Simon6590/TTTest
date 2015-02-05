//
//  NSMeapFileManager.h
//  Cordova_TEST
//
//  Created by Guo Mingliang on 13-8-12.
//
//

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

@interface NSMeapFileManagerPlugin : CDVPlugin

/**
 *	@brief	文件上传
 *
 *	@param 	arguments 	参数数组
 *  0:id
 *  1:filePath
 *  2:fileName
 *	@param 	options 	参数字典
 */
- (void)uploadFile:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

/**
 *	@brief	文件下载
 *
 *	@param 	arguments 	参数数组
 *  0:id
 *  1:url
 *	@param 	options 	参数字典
 */
- (void)downloadFile:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;
/**
 *	@brief	文件删除
 *
 *	@param 	arguments 	参数数组
 *  0:id
 *  1:filePath
 *	@param 	options 	参数字典
 */
- (void)removeFile:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;
/**
 *	@brief	文件移动
 *
 *	@param 	arguments 	参数数组
 *  0:id
 *  1:fileName 路径
 *  2:newPath
 *  3:newName  
 *	@param 	options 	参数字典
 */
- (void)moveFile:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;
@end
