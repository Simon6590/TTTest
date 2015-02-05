//
//  CheckViewController.m
//  ADSS
//
//  Created by Simon on 14-3-26.
//  Copyright (c) 2014年 Simon. All rights reserved.
//

#import "CheckViewController.h"
#import "MJPasswordView.h"
@interface CheckViewController () <MJPasswordDelegate>

@property (retain, nonatomic) IBOutlet MJPasswordView *lockView;

@property (retain, nonatomic) IBOutlet UILabel *infoLabel;
@property (retain, nonatomic) IBOutlet UIButton *fotgetPassword;

@end

@implementation CheckViewController

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
    // Do any additional setup after loading the view from its nib.
    self.lockView.delegate = self;
    self.infoLabel.text = @"请滑动九宫格，输入密码";
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/** 密码输入完毕回调 */
- (void)passwordView:(MJPasswordView*)passwordView withPassword:(NSString*)password
{
    if ([password isEqualToString:self.password])
    {
        if (_delegate && [_delegate respondsToSelector:@selector(lockViewPassWord:)])
        {
            [_delegate lockViewPassWord:password];
        }
        [self dismissViewControllerAnimated:YES completion:nil];
    }
    else
    {
        self.infoLabel.text = @"密码错误,请重新输入!";
    }
}

- (IBAction)forgetPsdPressed:(id)sender
{
    [self dismissViewControllerAnimated:YES completion:nil];
    
    if (_delegate && [_delegate respondsToSelector:@selector(forgetPassword)])
    {
        [_delegate forgetPassword];
    }
}

- (void)dealloc
{
    [_infoLabel release];
    [_fotgetPassword release];
    [_lockView release];
    [super dealloc];
}
@end
