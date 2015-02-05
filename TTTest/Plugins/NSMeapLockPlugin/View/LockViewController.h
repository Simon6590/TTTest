//
//  LockViewController.h
//  ADSS
//     
//  Created by Simon on 14-3-18.
//  Copyright (c) 2014年 Simon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MJPasswordView.h"
@protocol LockViewDelegate <NSObject>

- (void) lockViewPassWord:(NSString *)passWord;
- (void) forgetPassword;

@end

@interface LockViewController : UIViewController<MJPasswordDelegate>

@property (nonatomic, retain) id <LockViewDelegate> delegate;

@end
