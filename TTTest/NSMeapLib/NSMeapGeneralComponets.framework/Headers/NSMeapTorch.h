//
//  MeapTorch.h
//  MeapSDK
//
//  Created by Guo Mingliang on 13-9-22.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface NSMeapTorch : NSObject

CLASS_SINGLETON_INTERFACE(NSMeapTorch)

/**
 *	@brief	打开手电筒
 */
- (void)meapTorchOn;
/**
 *	@brief	关闭手电筒
 */
- (void)meapTorchOff;
@end
