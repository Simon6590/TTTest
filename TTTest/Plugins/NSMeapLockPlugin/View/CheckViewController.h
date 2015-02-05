//
//  CheckViewController.h
//  ADSS
//
//  Created by Simon on 14-3-26.
//  Copyright (c) 2014年 Simon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LockViewController.h"

@interface CheckViewController : UIViewController

@property (nonatomic, retain) id <LockViewDelegate> delegate;

@property (nonatomic, retain) NSString *password;

@end
