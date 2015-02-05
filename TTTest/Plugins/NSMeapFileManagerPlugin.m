//
//  NSMeapFileManager.m
//  Cordova_TEST
//
//  Created by Guo Mingliang on 13-8-12.
//
//

#import "NSMeapFileManagerPlugin.h"
#import <NSMeap/NSMeapUploadFile.h>
#import <NSMeap/NSMeapDownloadFile.h>

@interface NSMeapFileManagerPlugin ()<NSMeapUploadFileDelegate,NSMeapDownloadFileDelegate>
@property (nonatomic,copy)NSString *currentCallBackID;
@end
@implementation NSMeapFileManagerPlugin

- (void)uploadFile:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.currentCallBackID = [arguments objectAtIndex:0];
    NSString *filePath = [arguments objectAtIndex:1];
    NSString *fileName = [arguments objectAtIndex:2];
    
    [[NSMeapUploadFile shareNSMeapUploadFile] uploadFileWithFileName:fileName filePath:filePath delegate:self];
    
}
#pragma MeapUploadFile delegate
- (void)uploadFinishedWithFileName:(NSString *)fileName filePath:(NSString *)filePath
{
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"uploadFile success!"];
    [self success:result callbackId:self.currentCallBackID];
    
}
- (void)uploadFailedWithFileName:(NSString *)fileName filePath:(NSString *)filePath error:(NSError *)error{
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"uploadFile failed!"];
    [self success:result callbackId:self.currentCallBackID];
    
}

- (void)downloadFile:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.currentCallBackID = [arguments objectAtIndex:0];
    NSString *url = [arguments objectAtIndex:1];
    [[NSMeapDownloadFile shareNSMeapDownloadFile]downloadFileWithURLString:url delegate:self];
}
#pragma MeapDownloadFile delegate 
- (void)downloadFinishedWithURLString:(NSString *)urlString
{
    NSString *filePath = [[NSMeapDownloadFile shareNSMeapDownloadFile] downPathWithURLString:urlString];
    
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:filePath];
    [self success:result callbackId:self.currentCallBackID];
}
- (void)downloadFailedWithURLString:(NSString *)urlString error:(NSError *)error{
    
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:urlString];
    [self success:result callbackId:self.currentCallBackID];
}
#pragma 文件移除
- (void)removeFile:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options{
    self.currentCallBackID = [arguments objectAtIndex:0];
    NSString *filePath = [arguments objectAtIndex:1];
    NSFileManager *fm = [NSFileManager defaultManager];
    CDVPluginResult *result = nil;
    NSError *error;
    if ([fm removeItemAtPath:filePath error:&error]) {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"removeFile sussess"];
    }else{
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"removeFile failed"];
    }
    [self success:result callbackId:self.currentCallBackID];
}
#pragma 文件移动
- (void)moveFile:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options{
    self.currentCallBackID = [arguments objectAtIndex:0];
    NSString *fileName = [arguments objectAtIndex:1];
    NSString *newPath = [arguments objectAtIndex:2];
    NSString *newName = [arguments objectAtIndex:3];
    if (newName!=nil&&![newName isEqualToString:@""]&&![newName isEqualToString:@"null"])
    {
        newPath = [newPath stringByAppendingPathComponent:newName];
    }
    NSFileManager *fm = [NSFileManager defaultManager];
    
    NSString *path = [newPath stringByReplacingOccurrencesOfString:[newPath lastPathComponent] withString:@""];
    if (![fm fileExistsAtPath:path])
    {
        [fm createDirectoryAtPath:path withIntermediateDirectories:YES attributes:nil error:nil];
    }
    
    CDVPluginResult *result = nil;
    NSError *error;
    if ([fm moveItemAtPath:fileName toPath:newPath error:&error])
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"moveFile sussess"];
    }
    else
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"removeFile sussess"];
    }
    [self success:result callbackId:self.currentCallBackID];
}
- (void)dealloc{
    self.currentCallBackID = nil;
    [super dealloc];
}
@end
