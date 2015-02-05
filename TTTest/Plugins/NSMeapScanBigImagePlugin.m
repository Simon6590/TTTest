//
//  NSMeapScanBigImagePlugin.m
//  Cordova_TEST
//
//  Created by 罗忠燕 on 13-10-31.
//
//

#import "NSMeapScanBigImagePlugin.h"
#import <NSMeap/GTMBase64.h>

@implementation NSMeapScanBigImagePlugin

- (void)scanBigImage:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    if ([arguments count] != 2)
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"NSMeapScanBigImagePlugin scanBigImage服务 参数数目不对!"];
        [self error:result callbackId:[arguments queueHead]];
        return;
    }
    
    NSString *imageBase64 = [arguments objectAtIndex:1];
    
    NSData *imageData = [GTMBase64 decodeString:imageBase64];
    
    UIView *bgView = [[[UIView alloc] initWithFrame:CGRectMake(0, 0, self.viewController.view.frame.size.width, self.viewController.view.frame.size.height)] autorelease];
    bgView.autoresizesSubviews = YES;
    bgView.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleBottomMargin;
    [self.viewController.view addSubview:bgView];
    
    UIImage *image = [UIImage imageWithData:imageData];
    UIImageView *imageView = [[UIImageView alloc] initWithImage:image];
    
    CGSize size = image.size;
    CGFloat scale = 1.0;
    if (size.width > 768 || size.height > 768)
    {
//        scale = size.width > size.height ? size.width/768
    }
    
    
}

@end
