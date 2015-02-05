//
//  NSMeapEncryptFileModel.h
//  NSMeap
//
//  Created by 罗忠燕 on 13-11-6.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMeapEncryptFileModel : NSObject

/// 区名
@property (nonatomic, strong) NSString  *fileSectionName;
/// 文件Id
@property (nonatomic, strong) NSString  *fileId;
/// 文件名
@property (nonatomic, strong) NSString  *fileName;
/// 文件路径
@property (nonatomic, strong) NSString  *filePath;
/// 文件的加密状态 YES：加密的 NO：解密的
@property (nonatomic, assign) BOOL      fileStatus;

@end
