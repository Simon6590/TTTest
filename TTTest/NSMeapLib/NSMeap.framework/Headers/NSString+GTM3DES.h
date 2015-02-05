//
//  NSString+GTM3DES.h
//  NSMeap
//
//  Created by 罗忠燕 on 13-10-16.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTMBase64.h"
#import <CommonCrypto/CommonCryptor.h>

@interface NSString (GTM3DES)

+ (NSString *)TripleDES:(NSString *)plainText encryptOrDecrypt: (CCOperation)encryptOrDecrypt key:(NSString *)key;

+ (NSString *)TripleDES2:(NSData *)plainText encryptOrDecrypt: (CCOperation)encryptOrDecrypt key:(NSString *)key;

+ (NSData *)TripleDES3:(NSData *)plainText encryptOrDecrypt: (CCOperation)encryptOrDecrypt key:(NSString *)key;

+ (NSString *)encrypt:(NSString *)plainText;
+ (NSString *)decrypt:(NSString *)encryptText;
@end
