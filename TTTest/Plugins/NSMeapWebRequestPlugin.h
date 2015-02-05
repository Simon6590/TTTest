//
//  NSMeapWebRequest.h
//  Cordova_TEST
//
//  Created by yalin on 13-7-15.
//
//

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

@interface NSMeapWebRequestPlugin : CDVPlugin

- (void)httpRequest:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

@end
