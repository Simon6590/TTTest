//
//  NSMeapCityPopView.h
//  NSMeapGeneralComponents
//
//  Created by 罗忠燕 on 13-10-28.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol NSMeapCityPopViewDelegate;

@interface NSMeapCityPopView : UIPopoverController

@property (nonatomic, assign) id <NSMeapCityPopViewDelegate> delegatePopView;

@end


@protocol NSMeapCityPopViewDelegate <NSObject>

/**
 *	@brief	选择城市的代理方法
 *
 *	@param 	selectedCity 	选择的城市地址
 */
-(void)didSelectCity:(NSString *)selectedCity;

@end