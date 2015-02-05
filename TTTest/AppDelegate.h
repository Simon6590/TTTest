//
//  AppDelegate.h
//  TTTest
//
//  Created by Simon on 14-3-31.
//  Copyright (c) 2014年 Simon. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "CDVViewController.h"
@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (nonatomic, strong) IBOutlet CDVViewController* viewController;
@end
