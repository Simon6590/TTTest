//
//  NSMeapGeneralComponetsVersion.h
//  NSMeapGeneralComponents
//
//  Created by yalin on 13-10-16.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//


/*****更新日志：*****
 V0.1： 内部测试版
 
 *********************/

#define NSMEAP_GENERAL_COMPONENTS_VERSION   @"0.1"
CG_INLINE UIImage* getImage(NSString *imageName)
{
    NSBundle *bundle = [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"NSMeapGeneralComponets" ofType:@"bundle"]];
    NSString * path = [bundle pathForResource:imageName ofType:@"png"];
    UIImage *image = [UIImage imageWithContentsOfFile:path];
    return  image;
}