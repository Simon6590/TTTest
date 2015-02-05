//
//  NSMeapEncryptDataModel.h
//  NSMeap
//
//  Created by 罗忠燕 on 13-11-6.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMeapEncryptDataModel : NSObject

/// 区名
@property (nonatomic, strong) NSString  *dataSectionName;
/// 数据Id
@property (nonatomic, strong) NSString  *dataId;
/// 数据
@property (nonatomic, strong) NSData    *dataValue;
/// 数据的加密状态 YES：加密的 NO：解密的
@property (nonatomic, assign) BOOL      dataStatus;

@end
