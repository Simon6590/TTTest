//
//  NSMWaterFallViewCell.h
//  NSMWaterFallView
//  Created by Guo Mingliang on 13-9-24.
//  Copyright (c) 2013年 Guo Mingliang. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSMeapWaterFallViewCell : UIView

@property (nonatomic, readonly) NSString *reuseIdentifier;
@property (nonatomic, assign) BOOL selected;

- (id)initWithReuseIdentifier:(NSString *)reuseIdentifier;

@end
