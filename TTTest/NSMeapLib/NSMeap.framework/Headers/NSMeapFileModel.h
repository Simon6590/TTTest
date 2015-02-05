//
//  NSMeapFileModel.h
//  NSMeap
//
//  Created by 罗忠燕 on 13-11-8.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMeapFileModel : NSObject

/// 文件的名字
@property (nonatomic, retain) NSString  *fileName;
/// 要下载的文件的路径、要上传的文件的路径
@property (nonatomic, retain) NSString  *fileUrl;

@end
