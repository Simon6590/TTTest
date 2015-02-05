//
//  NSMeapOfficeShow.h
//  MeapSDK
//
//  Created by 十九 on 13-8-5.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <Foundation/Foundation.h>

/// office展示组件代理
@protocol NSMeapOfficeShowDelegate;

/// office展示组件
@interface NSMeapOfficeShow : NSObject

/// office展示组件代理 	NSMeapOfficeShowDelegate
@property (nonatomic,assign) id<NSMeapOfficeShowDelegate> delegate;


/**
 *	@brief	加载文档
 *
 *	@param 	url 	文档URL
 *	@param 	webView 	文档展示的webview
 */
-(void)loadDocument:(NSURL *)url inView:(UIWebView *)webView;

@end

@protocol NSMeapOfficeShowDelegate <NSObject>

@optional
/**
 *	@brief	文档开始加载
 *
 *	@param 	webView 	加载文档的webView
 */
- (void)documentDidStartLoad:(UIWebView *)webView;
/**
 *	@brief	文档加载完成
 *
 *	@param 	webView 	加载文档的webView
 */
- (void)documentDidFinishLoad:(UIWebView *)webView;
/**
 *	@brief	文档加载失败
 *
 *	@param 	webView 	加载文档的webView
 *	@param 	error 	错误信息
 */
- (void)documentFailedLoad:(UIWebView *)webView WithError:(NSError *)error;

@end