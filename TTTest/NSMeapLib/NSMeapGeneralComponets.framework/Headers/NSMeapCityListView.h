//
//  NSMeapCityListView.h
//  NSMeap
//
//  Created by 韩立娜 on 13-10-9.
//  Copyright (c) 2013年 韩立娜. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol NSMeapCityListViewDelegate;

@interface NSMeapCityListView : UIView

/**
 *	@brief	代理
 */
@property (nonatomic,weak) id<NSMeapCityListViewDelegate> delegate;

@end

@protocol NSMeapCityListViewDelegate <NSObject>

/**
 *	@brief	选择省市区的代理方法
 *
 *	@param 	selectedCity 	已选择的城市地址
 *	@param 	level 	0 代表省级 1代表市级 2代表区县级
 */
-(void)didSelectListItem:(NSString *)selectedCity level:(int)level;

@end