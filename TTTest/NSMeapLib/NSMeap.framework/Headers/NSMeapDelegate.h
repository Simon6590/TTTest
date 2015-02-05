//
//  MeapDelegate.h
//  MeapSDK
//
//  Created by yalin on 13-8-25.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *	@brief	html小版本升级代理
 */
@protocol NSMeapCheckHybridUpdateDeleagte <NSObject>

@optional

/**
 *	@brief	html小版本是否更新
 *
 *	@param 	needUpdate 	是否更新 YES:更新  NO:不需要更新
 */
-(void)htmlNeedUpdate:(BOOL)needUpdate;

/**
 *	@brief	检测html小版本更新出错
 *
 *	@param 	error 	检测html小版本更新的错误
 */
-(void)checkHtmlUpdateError:(NSString *)error;

/**
 *	@brief	检测html小版本更新成功
 */
-(void)checkHtmlUpdateSuccess;

@end


/**
 *	@brief	App更新代理
 */
@protocol NSMeapCheckAppUpdateDelegate <NSObject>
@optional

/**
 *	@brief	App是否需要更新
 *
 *	@param 	needUpdate 	是否需要更新
 */
-(void)appNeedUpdate:(BOOL)needUpdate;

/**
 *	@brief	检测更新错误
 *
 *	@param 	error 	错误信息
 */
-(void)checkAppUpdateError:(NSString *)error;
@end


