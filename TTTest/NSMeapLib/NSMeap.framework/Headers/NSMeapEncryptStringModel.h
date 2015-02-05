//
//  NSMeapEncryptStringModel.h
//  NSMeap
//
//  Created by 罗忠燕 on 13-11-6.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMeapEncryptStringModel : NSObject

/// 区名
@property (nonatomic, strong) NSString  *stringSectionName;
/// 字符串Id
@property (nonatomic, strong) NSString  *stringId;
/// 字符串（加密的或明文的）
@property (nonatomic, strong) NSString  *stringValue;
/// 字符串的加密状态 YES：加密的 NO：解密的
@property (nonatomic, assign) BOOL      stringStatus;

@end
