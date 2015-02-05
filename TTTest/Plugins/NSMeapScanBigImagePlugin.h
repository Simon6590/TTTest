//
//  NSMeapScanBigImagePlugin.h
//  Cordova_TEST
//
//  Created by 罗忠燕 on 13-10-31.
//
//

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

@interface NSMeapScanBigImagePlugin : CDVPlugin

- (void)scanBigImage:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

@end
