//
//  NSMeapQRView.h
//  NSMeapQRCode
//
//  Created by yalin on 13-11-9.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSMeapQRView : UIView

@property (nonatomic, retain) NSMutableArray*  points;
@property (nonatomic, assign) BOOL oneDMode;
@property (nonatomic, assign) CGRect cropRect;
@property (nonatomic, copy) NSString *displayedMessage;
@property (nonatomic, retain) NSString *cancelButtonTitle;
@property (nonatomic, assign) BOOL cancelEnabled;


- (void)setPoint:(CGPoint)point;

@end
