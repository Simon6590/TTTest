//
//  LockViewController.m
//  ADSS
//
//  Created by Simon on 14-3-18.
//  Copyright (c) 2014年 Simon. All rights reserved.
//

#import "LockViewController.h"
#import "MJPasswordView.h"

@interface LockViewController ()<MJPasswordDelegate>
@property (retain, nonatomic) IBOutlet MJPasswordView *loclView;
@property (retain, nonatomic) IBOutlet UILabel *titleLable;
@property (retain, nonatomic) IBOutlet UIButton *clearPassWordButton;
@property (retain,nonatomic) UIButton *forgetBtn;
@property (nonatomic,assign) ePasswordSate state;

@property (nonatomic, retain) NSString *firstPsd;
@property (nonatomic, retain) NSString* secondPsd;
@end

@implementation LockViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.loclView.delegate = self;
    self.titleLable.text = @"请滑动九宫格，设置密码";
//    [self updateInfoLabel];
  
}
- (IBAction)cleanPassword
{
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (void)dealloc
{
    [_loclView release];
    [_titleLable release];
    [_clearPassWordButton release];
    [_forgetBtn release];
    [_firstPsd release];
    [_secondPsd release];
    [super dealloc];
}
- (void)passwordView:(MJPasswordView*)passwordView withPassword:(NSString*)password
{
    if (self.firstPsd)
    {
        // 第二次
        if ([self.firstPsd isEqualToString:password])
        {
            if (_delegate && [_delegate respondsToSelector:@selector(lockViewPassWord:)])
            {
                [_delegate lockViewPassWord:password];
                
            }
            [self dismissViewControllerAnimated:YES completion:nil];
        }
        else
        {
            self.titleLable.text = @"两次输入不一致,请重新输入密码!";
            self.firstPsd = nil;
            self.secondPsd = nil;
        }
    }
    else
    {
        // 第一次
        self.firstPsd = password;
        self.titleLable.text = @"请再次输入密码!";
    }
}

@end
