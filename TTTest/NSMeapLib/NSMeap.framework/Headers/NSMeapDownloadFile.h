//
//  MeapDownloadFile.h
//  MeapSDK
//
//  Created by 罗忠燕 on 13-8-6.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        NSMeapDownloadFile.h
 * @brief       文件断点下载组件.
 * @version     1.0
 * @date        2013-7-23
 *
 * [2013-06-07] <杨亚霖> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <Foundation/Foundation.h>
#import "NSMeapFileModel.h"

/// 文件下载的各个状态
typedef enum 
{
    NSMEAP_DOWNLOAD_NO_REQUEST = 1,     //!< 没有下载过 */
    NSMEAP_DOWNLOADING,                 //!< 下载中 */
    NSMEAP_DOWNLOAD_FINISHED,           //!< 下载结束 */
    NSMEAP_DOWNLOAD_PAUSE,              //!< 暂停中 */
}NSMEAP_DOWNLOAD_STATUS;


#pragma mark - MeapDownloadFile
@class NSMeapDownloadFileDelegate;

/// 断点下载组件
@interface NSMeapDownloadFile : NSObject

CLASS_SINGLETON_INTERFACE(NSMeapDownloadFile)

/**
 *	@brief	下载单例调用的宏方法
 */
#define NSMeapDownloadFileEngine   [NSMeapDownloadFile shareNSMeapDownloadFile]

/**
 *	@brief	获取所有断点下载的文件信息
 *
 *	@return	文件信息的数组 元素是：NSMeapFileModel
 */
- (NSArray *)getResumeDowndingFilesInfo;

/**
 *	@brief	添加一个下载
 *
 *	@param 	urlString 	下载的文件的路径
 */
- (void)downloadFileWithURLString:(NSString *)urlString delegate:(id)delegate;

/**
 *	@brief	暂停一个下载
 *
 *	@param 	urlString 	下载的文件的路径
 */
- (void)pauseWithURLString:(NSString *)urlString;

/**
 *	@brief	暂停所有下载
 */
- (void)pauseAllRequest;

/**
 *	@brief	查看一个文件的状态
 *
 *	@param 	urlString 	下载的文件的路径
 *
 *	@return	返回文件的下载状态
 */
- (NSMEAP_DOWNLOAD_STATUS)statusWithFileUrl:(NSString *)urlString;

/**
 *	@brief	返回文件上传的进度
 *
 *	@param 	urlString 	下载路径
 *
 *	@return	下载的进度
 */
- (CGFloat)progressWithFileUrl:(NSString *)urlString;

/**
 *	@brief	获取文件的大小
 *
 *	@param 	urlString 	下载路径
 *
 *	@return	文件大小
 */
- (CGFloat)fileSizeWithFileUrl:(NSString *)urlString;

/**
 *	@brief	检查一个下载的代理delegate是否存在
 *
 *	@param 	urlString 	下载的文件的路径
 *	@param 	delegate 	下载回调代理
 *
 *	@return	YES：回调代理中存在delegate  NO：回调代理中不存在delegate
 */
- (BOOL)checkDelegateExistWithURLString:(NSString *)urlString delegate:(id)delegate;

/**
 *	@brief	添加一个delegate到一个下载上面
 *
 *	@param 	urlString 	下载的文件的路径
 *	@param 	delegate 	回调代理
 */
- (void)addDelegateToRequestWithURLString:(NSString *)urlString delegate:(id)delegate;

/**
 *	@brief	获取一个文件的存放路径
 *
 *	@param 	urlString 	下载的文件的路径
 *
 *	@return	返回下载的文件的下载后的存储路径
 */
- (NSString *)downPathWithURLString:(NSString *)urlString;

/**
 *	@brief	取消一个下载,需要删除数据库和下载的临时文件或下载好的文件
 *
 *	@param 	urlString 	下载的文件的路径
 */
- (void)removeRequestWithURLString:(NSString *)urlString;

/**
 *	@brief	取消所有下载,需要删除所有数据库和所有下载的临时文件或下载好的文件
 */
- (void)removeAllRequest;

/**
 *	@brief	移除一个未下载好的文件
 *
 *	@param 	urlString 	下载的文件的路径
 */
- (void)removeTemFileWithURLString:(NSString *)urlString;

/**
 *	@brief	移出一个下载好的文件
 *
 *	@param 	urlString 	下载的文件的路径
 */
- (void)removeFileWithURLString:(NSString *)urlString;

/**
 *	@brief	移除所有文件
 */
- (void)removeAllFile;

/**
 *	@brief	检查一个下载是否存在
 *
 *	@param 	urlString 	下载的文件的路径
 *
 *	@return	YES：下载已经存在 NO：下载不存在
 */
- (BOOL)checkIsExistWithURLString:(NSString *)urlString;

@end

#pragma mark - NSMeapDownloadFileDelegate
/// 断点下载组件的代理
@protocol NSMeapDownloadFileDelegate <NSObject>
@optional
/**
 *	@brief	开始请求下载的代理回调
 *
 *	@param 	urlString 	下载的文件的路径
 */
- (void)downloadStartedWithURLString:(NSString *)urlString;

/**
 *	@brief	下载过程中代理回调
 *
 *	@param 	urlString 	下载的文件的路径
 *	@param 	progress 	返回当前下载的进度
 */
- (void)downloadingWithURLString:(NSString *)urlString progress:(float)progress;

/**
 *	@brief	下载的速度
 *
 *	@param 	urlString 	下载的文件的路径
 *	@param 	speed 	下载速度，KB为单位
 */
- (void)downloadingWithURLString:(NSString *)urlString speed:(float)speed;

/**
 *	@brief	下载完成的代理回调
 *
 *	@param 	urlString 	下载的文件的路径
 */
- (void)downloadFinishedWithURLString:(NSString *)urlString;

/**
 *	@brief	下载失败的代理回调
 *
 *	@param 	urlString 	下载的文件的路径
 *	@param 	error 	下载失败返回的错误信息
 */
- (void)downloadFailedWithURLString:(NSString *)urlString error:(NSError *)error;

@end

