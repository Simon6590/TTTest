//
//  NSMeapZipPlugin.m
//  Cordova_TEST
//
//  Created by yalin yang on 14-3-27.
//
//

#import "NSMeapZipPlugin.h"
#import <NSMeap/ZipArchive.h>

@interface NSMeapZipPlugin () <ZipArchiveDelegate>

@property (nonatomic, strong) ZipArchive    *zip;
@property (nonatomic, strong) ZipArchive    *unZip;

@end

@implementation NSMeapZipPlugin

/**
 *  获取屏幕分辨率
 *
 *  @param arguments 传参 [未压缩的文件路径]
 *  @param options   配置
 */
- (void)zipCompression:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    NSString *callBackID = [arguments objectAtIndex:0];
    NSString *zipFilePath = [arguments objectAtIndex:1];
    
    NSString *zipFileName = [zipFilePath lastPathComponent];
    
    NSString *compressionPath = [[NSHomeDirectory() stringByAppendingPathComponent:@"Documents/zip"] stringByAppendingPathComponent:zipFileName];
    
    if (![[NSFileManager defaultManager] fileExistsAtPath:[NSHomeDirectory() stringByAppendingPathComponent:@"Documents/zip"]])
    {
        [[NSFileManager defaultManager] createDirectoryAtPath:[NSHomeDirectory() stringByAppendingPathComponent:@"Documents/zip"] withIntermediateDirectories:NO attributes:nil error:nil];
    }
    
    // 避免重名
    int i = 1;
    while (YES)
    {
        if ([[NSFileManager defaultManager] fileExistsAtPath:[compressionPath stringByAppendingString:@".zip"]])
        {
            compressionPath = [compressionPath stringByAppendingString:[NSString stringWithFormat:@" %d",i]];
            i++;
        }
        else
        {
            break;
        }
    }
    
    NSString *compressionCachePath = [compressionPath stringByAppendingString:@".zip"];
    
    self.zip = [[ZipArchive alloc] init];
    self.zip.delegate = self;
    [self.zip CreateZipFile2:compressionCachePath];
    [self.zip addFileToZip:zipFilePath newname:[zipFilePath lastPathComponent]];
    BOOL success = [self.zip CloseZipFile2];
    
    NSLog(@"%@",compressionCachePath);
    if (success)
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:compressionCachePath];
        [self success:result callbackId:callBackID];
    }
    else
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:compressionCachePath];
        [self error:result callbackId:callBackID];
    }
}

/**
 *  获取屏幕分辨率
 *
 *  @param arguments 传参 [压缩文件路径]
 *  @param options   配置
 */
- (void)zipDecompression:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    NSString *callBackID = [arguments objectAtIndex:0];
    NSString *zipFilePath = [arguments objectAtIndex:1];
    
    NSString *zipFileName = [zipFilePath lastPathComponent];
    if ([zipFileName hasSuffix:@"zip"])
    {
        zipFileName = [zipFileName stringByReplacingOccurrencesOfString:@".zip" withString:@""];
    }
    
    NSString *unCompressionPath = [[NSHomeDirectory() stringByAppendingPathComponent:@"Documents/zip"] stringByAppendingPathComponent:zipFileName];
    
    if (![[NSFileManager defaultManager] fileExistsAtPath:[NSHomeDirectory() stringByAppendingPathComponent:@"Documents/zip"]])
    {
        [[NSFileManager defaultManager] createDirectoryAtPath:[NSHomeDirectory() stringByAppendingPathComponent:@"Documents/zip"] withIntermediateDirectories:NO attributes:nil error:nil];
    }
    
    // 避免重名
    int i = 1;
    NSString *tempPath = unCompressionPath;
    while (YES)
    {
        if ([[NSFileManager defaultManager] fileExistsAtPath:tempPath])
        {
            tempPath = [unCompressionPath stringByAppendingString:[NSString stringWithFormat:@" %d",i]];
            i++;
        }
        else
        {
            break;
        }
    }
    
    self.unZip = [[ZipArchive alloc] init];
    self.unZip.delegate = self;
    [self.unZip UnzipOpenFile:zipFilePath];
    [self.unZip UnzipFileTo:tempPath overWrite:NO];
    BOOL success = [self.unZip UnzipCloseFile];
    
    
    NSLog(@"%@",tempPath);
    if (success)
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:tempPath];
        [self success:result callbackId:callBackID];
    }
    else
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:tempPath];
        [self error:result callbackId:callBackID];
    }
}

-(void) ErrorMessage:(NSString*) msg
{
    NSLog(@"error : %@",msg);
}

-(BOOL) OverWriteOperation:(NSString*) file
{
    NSLog(@"over : %@",file);
    return YES;
}

@end
