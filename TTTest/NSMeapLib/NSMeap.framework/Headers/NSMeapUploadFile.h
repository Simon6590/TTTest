//
//  MeapUploadFile.h
//  MeapDataControl
//
//  Created by yangyalin on 13-3-28.
//  Copyright (c) 2013年 yangyalin. All rights reserved.
//

/**
 * @file        NSMeapUploadFile.h
 * @brief       文件断点上传组件.
 * @version     1.0
 * @date        2013-7-23
 *
 * [2013-06-07] <杨亚霖> v1.0
 *
 * + v1.0版发布.
 *
 */

#import "NSMeapFileModel.h"

/// 上传状态
typedef enum 
{
    MEAP_NO_UPLOAD = 1,     //!< 没有上传 */
    MEAP_UPLOADING,         //!< 正在上传 */
    MEAP_UPLOAD_PAUSE,      //!< 上传暂停中 */
    MEAP_UPLOAD_FINISHED,   //!< 上传完成 */
}MEAP_UPLOAD_STATUS;

#pragma mark - NSMeapUploadFile 文件断点上传组件
@protocol NSMeapUploadFileDelegate;

/// 文件断点上传组件
@interface NSMeapUploadFile : NSObject

CLASS_SINGLETON_INTERFACE(NSMeapUploadFile)

/**
 *	@brief	单例调用的宏方法
 */
#define NSMeapUploadFileEngine [NSMeapUploadFile shareNSMeapUploadFile]

/**
 *	@brief	获取所有断点续传的文件信息
 *
 *	@return	文件信息的数组 元素是：NSMeapFileModel
 */
- (NSArray *)getResumeUploadingFilesInfo;

/**
 *	@brief	开始上传一个文件
 *
 *	@param 	fileName 	文件名字
 *	@param 	filePath 	文件路径
 *	@param 	delegate 	文件上传的回调代理
 */
- (void)uploadFileWithFileName:(NSString *)fileName filePath:(NSString *)filePath delegate:(id)delegate;

/**
 *	@brief	给一个上传的设置代理
 *
 *	@param 	fileName 	文件名字
 *	@param 	filePath 	文件路径
 *	@param 	delegate 	文件上传的回调代理
 */
- (void)addDelegateForFileName:(NSString *)fileName filePath:(NSString *)filePath delegate:(id)delegate;

/**
 *	@brief	停此上传一个文件
 *
 *	@param 	fileName 	文件名字
 *	@param 	filePath 	文件路径  
 */
- (void)stopUploadFileWithFileName:(NSString *)fileName filePath:(NSString *)filePath;

/**
 *	@brief	停此所有的文件上传
 */
- (void)stopAllFileUpload;

/**
 *	@brief	取消一个文件上传
 *
 *	@param 	fileName 	文件名
 *	@param 	filePath 	文件路径    
 */
- (void)removeFileUploadWithFileName:(NSString *)fileName filePath:(NSString *)filePath;

/**
 *	@brief	取消所有文件上传
 */
- (void)removeAllFileUpload;

/**
 *	@brief	返回进度
 *
 *	@param 	fileName 	文件名
 *	@param 	filePath 	文件路径
 *
 *	@return	进度
 */
- (float)progressForFileWithFileName:(NSString *)fileName filePath:(NSString *)filePath;

/**
 *	@brief	返回文件的大小
 *
 *	@param 	fileName 	文件名
 *	@param 	filePath 	文件路径
 *
 *	@return	文件的大小
 */
- (float)fileSizeForFileWithFileName:(NSString *)fileName filePath:(NSString *)filePath;

/**
 *	@brief	获取文件的上传状态
 *
 *	@param 	fileName 	文件名字
 *	@param 	filePath 	文件的路径
 *
 *	@return NO_UPLOAD:没有上传  UPLOADING:正在上传  UPLOAD_PAUSE:上传暂停中
 */
- (MEAP_UPLOAD_STATUS)uploadStatusForFileName:(NSString *)fileName filePath:(NSString *)filePath;

@end

#pragma mark - MeapUploadFileDelegate
/// MeapUploadFileDelegate 文件断点上传的回调代理方法
@protocol NSMeapUploadFileDelegate <NSObject>
@optional

/**
 *	@brief	开始上传
 *
 *	@param 	fileName 	文件名
 *	@param 	filePath 	文件路径    
 */
- (void)startUploadWithFileName:(NSString *)fileName filePath:(NSString *)filePath;

/**
 *	@brief	上传中
 *
 *	@param 	fileName 	文件名
 *	@param 	filePath 	文件路径
 *	@param 	progress 	上传进度
 */
- (void)uploadingWithFileName:(NSString *)fileName filePath:(NSString *)filePath progress:(float)progress speed:(float)speed;

/**
 *	@brief	上传完成
 *
 *	@param 	fileName 	文件名
 *	@param 	filePath 	文件路径
 */
- (void)uploadFinishedWithFileName:(NSString *)fileName filePath:(NSString *)filePath;

/**
 *	@brief	上传失败
 *
 *	@param 	fileName 	文件名
 *	@param 	filePath 	文件路径
 *	@param 	error 	失败错误信息
 */
- (void)uploadFailedWithFileName:(NSString *)fileName filePath:(NSString *)filePath error:(NSError *)error;

@end



