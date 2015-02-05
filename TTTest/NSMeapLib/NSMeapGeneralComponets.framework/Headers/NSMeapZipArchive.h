//
//  NSMZipArchive.h
//  MeapSDK
//
//  Created by Guo Mingliang on 13-8-23.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NSMeap/ZipArchive.h>

/// 数据压缩代理
@protocol NSMeapZipArchiveDelegate <NSObject>
@optional

/**
 *	@brief 压缩错误代理
 */
-(void) NSMErrorMessage:(NSString*) msg;
/**
 *	@brief	压缩文件代理
 *
 *	@return
 */
-(BOOL) NSMOverWriteOperation:(NSString*) file;

@end

/// 解压缩组件
@interface NSMeapZipArchive : NSObject
CLASS_SINGLETON_INTERFACE(NSMeapZipArchive)

/// 代理
@property (nonatomic, assign)id<NSMeapZipArchiveDelegate>delegate;

/**
 *	@brief	压缩文件
 *
 *  @param  zipFile     文件路径
 *
 *	@return	YES：压缩文件成功 NO：压缩文件失败
 */
-(BOOL) NSMCreateZipFile2:(NSString*)zipFile;
/**
 *	@brief	压缩并设置解压密码
 *  @param  zipFile     文件路径
 *  @param  password    解压密码
 *  
 *	@return	YES：压缩文件成功 NO：压缩文件失败
 */
-(BOOL) NSMCreateZipFile2:(NSString*)zipFile Password:(NSString*)password;

/**
 *	@brief	添加文件压缩
 *
 *	@param 	file 	要压缩的文件路径
 *	@param 	newname 	压缩后的压缩文件名字
 *
 *	@return	YES：压缩文件成功 NO：压缩文件失败
 */
-(BOOL) NSMaddFileToZip:(NSString*)file newname:(NSString*)newname;

/**
 *	@brief	关闭压缩文件
 *
 *	@return	YES：成功关闭 NO：关闭失败
 */
-(BOOL) NSMCloseZipFile2;

/**
 *	@brief	解压文件
 *
 *	@param 	zipFile 	解压的文件路径
 *
 *	@return	YES：解压文件成功 NO：解压文件失败
 */
-(BOOL) NSMUnzipOpenFile:(NSString*)zipFile;

/**
 *	@brief	解压文件
 *
 *	@param 	zipFile 	文件路径
 *	@param 	password 	解压密码
 *
 *	@return	YES：解压文件成功 NO：解压文件失败
 */
-(BOOL) NSMUnzipOpenFile:(NSString*)zipFile Password:(NSString*)password;

/**
 *	@brief	解压文件到新的路径
 *
 *	@param 	path 	新的文件路径
 *	@param 	overwrite 	写入新文件是否成功
 *
 *	@return	YES：解压文件成功 NO：解压文件失败
 */
-(BOOL) NSMUnzipFileTo:(NSString*)path overWrite:(BOOL)overwrite;

/**
 *	@brief	关闭解压文件
 *
 *	@return	YES：成功关闭 NO：关闭失败
 */
-(BOOL) NSMUnzipCloseFile;
@end
