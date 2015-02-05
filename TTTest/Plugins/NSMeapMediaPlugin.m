//
//  NSMeapMediaPlugin.m
//  Cordova_TEST
//
//  Created by 十九 on 13-8-7.
//
//

#import "NSMeapMediaPlugin.h"
#import <NSMeapGeneralComponets/NSMeapCamera.h>
#import <NSMeapGeneralComponets/NSMeapPhotoLibray.h>
#import <NSMeapGeneralComponets/NSMeapAudio.h>
@interface  NSMeapMediaPlugin ()<NSMeapCameraDelegate,NSMeapPhotoLibrayDelegate>

@property (nonatomic, retain) NSString *currentCallBackID;
@property (nonatomic, copy) NSString *fileName;

@end

@implementation NSMeapMediaPlugin

-(void)dealloc
{
    self.currentCallBackID = nil;
    self.fileName = nil;
    [[NSNotificationCenter defaultCenter]removeObserver:self name:NSMeapAudioPlayerDidFinishPlaying object:nil];
    [[NSNotificationCenter defaultCenter]removeObserver:self name:NSMeapAudioRecorderDidFinishRecording object:nil];
    [[NSNotificationCenter defaultCenter]removeObserver:self name:NSMeapAudioRecorderOrPlayerError object:nil];
    [super dealloc];
}
/**
 *	@brief	调用媒体库
 *
 *	@param 	arguments 	参数数组 参数:id,action 调用服务方法名(camera 调用照相机 picture 调用图库 video 调用录像 audio 录音),filename 保存文件时文件名，(可以缺省)
 *	@param 	options 	无
 */
- (void)media:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    
    self.currentCallBackID=[arguments objectAtIndex:0];
    if ([arguments count]<=2) {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"NSMeapMedia 参数数目不对!"];
        [self error:result callbackId:self.currentCallBackID];
    }
    else
    {
        NSString *action=[arguments objectAtIndex:1];
        NSString *name=[[arguments objectAtIndex:2] isKindOfClass:[NSNull class]] ? MD5FromString([[NSDate date] description]) : [arguments objectAtIndex:2];
        self.fileName = name;
        if ([action isEqualToString:@"camera"]||[action isEqualToString:@"video"])
        {
            // 文件名不能以.开头
            if (self.fileName!=nil && [self.fileName hasPrefix:@"."])
            {
                CDVPluginResult *result = nil;
                result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"文件名无效"];
                [self error:result callbackId:self.currentCallBackID];
                return;
            }
            // 文件名不能包含:或/特殊字符串
            if (self.fileName!=nil && ([self.fileName rangeOfString:@"/"].location!=NSNotFound || [self.fileName rangeOfString:@":"].location!=NSNotFound))
            {
                CDVPluginResult *result = nil;
                result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"文件名无效"];
                [self error:result callbackId:self.currentCallBackID];
                return;
            }
            
        }
        if ([action isEqualToString:@"camera"])
        {
            NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask, YES);
            NSString *documentsDirectory = [paths objectAtIndex:0];
            NSString *directoryPath=[documentsDirectory stringByAppendingPathComponent:@"CameraImage"];
            // 创建文件夹
            if ([[NSFileManager defaultManager]fileExistsAtPath:directoryPath])
            {
                NSString *tempName=self.fileName;
                if (![tempName hasSuffix:@".PNG"])
                {
                    tempName = [tempName stringByAppendingString:@".PNG"];
                }
                // 获取文件路径路径
                if ([[NSFileManager defaultManager]fileExistsAtPath:[directoryPath stringByAppendingPathComponent:tempName]]) {
                    CDVPluginResult *result = nil;
                    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"文件已存在"];
                    [self error:result callbackId:self.currentCallBackID];
                    
                    return;
                }
            }
            [[NSMeapCamera shareNSMeapCamera]setDelegate:self];
            [[NSMeapCamera shareNSMeapCamera] takePhotoWithController:self.viewController];
        }
        else if ([action isEqualToString:@"picture"])
        {
            [[NSMeapPhotoLibray shareNSMeapPhotoLibray]setDelegate:self];
            [[NSMeapPhotoLibray shareNSMeapPhotoLibray]getPhotos:self.viewController];
        }
        else if ([action isEqualToString:@"video"])
        {
            NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask, YES);
            NSString *documentsDirectory = [paths objectAtIndex:0];
            NSString *directoryPath=[documentsDirectory stringByAppendingPathComponent:@"CameraVideo"];
            // 获取文件夹路径
            if ([[NSFileManager defaultManager] fileExistsAtPath:directoryPath])
            {
                NSString *tempName=self.fileName;
                if (![tempName hasSuffix:@".MOV"])
                {
                    tempName=[tempName stringByAppendingString:@".MOV"];
                }
                // 判断文件是否存在
                if ([[NSFileManager defaultManager]fileExistsAtPath:[directoryPath stringByAppendingPathComponent:tempName]]) {
                    CDVPluginResult *result = nil;
                    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"文件已存在"];
                    [self error:result callbackId:self.currentCallBackID];
                    return;
                }
            }
            [[UIApplication sharedApplication]setStatusBarStyle:UIStatusBarStyleBlackOpaque];
            [[NSMeapCamera shareNSMeapCamera]setDelegate:self];
            [[NSMeapCamera shareNSMeapCamera] takeVideoWithController:self.viewController];
        }
        else if ([action isEqualToString:@"audio"])
        {
            //防止多次添加监听，先移除再添加
            [[NSNotificationCenter defaultCenter]removeObserver:self name:NSMeapAudioPlayerDidFinishPlaying object:nil];
            [[NSNotificationCenter defaultCenter]removeObserver:self name:NSMeapAudioRecorderDidFinishRecording object:nil];
            [[NSNotificationCenter defaultCenter]removeObserver:self name:NSMeapAudioRecorderOrPlayerError object:nil];
            
            [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(recorderDidFinishRecording:) name:NSMeapAudioRecorderDidFinishRecording object:nil];
            [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(playerDidFinishPlaying:) name:NSMeapAudioPlayerDidFinishPlaying object:nil];
            [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(recorderOrPlayerError:) name:NSMeapAudioRecorderOrPlayerError object:nil];
            [[NSMeapAudio shareNSMeapAudio]recordAudio:name controller:self.viewController];
        }
        else if ([action isEqualToString:@"playaudio"])
        {
            
            [[NSMeapAudio shareNSMeapAudio]playAudio:name];
            
        }
    }
    
}
#pragma mark NSMeapCameraDelegate
-(void)cameraDidFinishPickingMediaWithInfo:(NSDictionary *)info
{
    NSString *mediaType = [info objectForKey:UIImagePickerControllerMediaType];
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,     NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    if ([mediaType isEqualToString:@"public.image"])
    {
        
        NSString *directoryPath=[documentsDirectory stringByAppendingPathComponent:@"CameraImage"];
        if (![[NSFileManager defaultManager]fileExistsAtPath:directoryPath])
        {
            BOOL  isCreate = [[NSFileManager defaultManager] createDirectoryAtPath:directoryPath withIntermediateDirectories:YES attributes:nil error:nil];
            if (!isCreate)
            {
                CDVPluginResult *result = nil;
                result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"文件写入失败"];
                [self error:result callbackId:self.currentCallBackID];
                return;
            }
        }
        NSString *path=@"";
        NSCharacterSet *whitespace=[NSCharacterSet whitespaceAndNewlineCharacterSet];
        if (_fileName&&[_fileName stringByTrimmingCharactersInSet:whitespace].length>0&&![_fileName hasPrefix:@"."])
        {
            path =  [directoryPath stringByAppendingPathComponent:[_fileName stringByAppendingString:@".PNG"]];
        }
        else
        {
            NSDateFormatter *dateFormatter=[[NSDateFormatter alloc]init];
            [dateFormatter setDateFormat:@"yyyy-MM-dd HH-mm-ss"];
            NSString *dateString = [dateFormatter stringFromDate:[NSDate date]];
            [dateFormatter release];
            dateString = [dateString stringByAppendingString:@".PNG"];
            path = [directoryPath stringByAppendingPathComponent:dateString];
        }
        //线程保存
        UIImage *image=[info objectForKey:@"UIImagePickerControllerOriginalImage"];
        if (image != nil)
        {
            UIImageWriteToSavedPhotosAlbum(image, nil, nil, nil);
            NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
            const char* queueName = [[[NSDate date] description] UTF8String];
            dispatch_queue_t myQueue = dispatch_queue_create(queueName, NULL);
            dispatch_queue_t mainQueue = dispatch_get_main_queue();
            
            
            dispatch_async(myQueue, ^{
                //新线程中要操作的（例如数据库的读取，存储等）
                NSData *imageData = UIImagePNGRepresentation(image);
                BOOL success=[imageData writeToFile:path atomically:YES];
                dispatch_async(mainQueue, ^{
                    if (success) {
                        [self cameraFinishedSucceedWithPath:path];
                    }
                    
                    else
                    {
                        [self cameraFinishedFailedWithMessage:@"文件保存失败"];
                    }
                    //主线程中要操作的（例如UI页面刷新）
                    
                    
                });
            });
            
            dispatch_release(myQueue);
            dispatch_release(mainQueue);
            [pool drain];
        }
    }
    else if ([mediaType isEqualToString:@"public.movie"])
    {
        // 录像
        NSURL *mediaUrl=[info valueForKey:UIImagePickerControllerMediaURL];
        if (mediaUrl)
        {
            NSCharacterSet *whitespace=[NSCharacterSet whitespaceAndNewlineCharacterSet];
            NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,     NSUserDomainMask, YES);
            NSString *documentsDirectory = [paths objectAtIndex:0];
            NSString *directoryPath=[documentsDirectory stringByAppendingPathComponent:@"CameraVideo"];
            // 创建文件夹
            if (![[NSFileManager defaultManager]fileExistsAtPath:directoryPath])
            {
                BOOL  isCreate = [[NSFileManager defaultManager] createDirectoryAtPath:[documentsDirectory stringByAppendingPathComponent:@"CameraVideo"] withIntermediateDirectories:YES attributes:nil error:nil];
                if (!isCreate)
                {
                    CDVPluginResult *result = nil;
                    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"文件写入失败"];
                    [self error:result callbackId:self.currentCallBackID];
                    return;
                }
            }
            // 文件路径
            NSString *path=@"";
            if (self.fileName && [self.fileName stringByTrimmingCharactersInSet:whitespace].length>0&&![self.fileName hasPrefix:@"."])
            {
                path=  [directoryPath stringByAppendingPathComponent:[self.fileName stringByAppendingString:@".MOV"]];
            }
            else
            {
                NSDateFormatter *dateFormatter=[[NSDateFormatter alloc]init];
                [dateFormatter setDateFormat:@"yyyy-MM-dd HH-mm-ss"];
                NSString *dateString = [dateFormatter stringFromDate:[NSDate date]];
                [dateFormatter release];
                dateString = [dateString stringByAppendingString:@".MOV"];
                path=[directoryPath stringByAppendingPathComponent:dateString];
            }
            NSFileManager *fileManger = [NSFileManager defaultManager];
            NSError *error=nil;
            if ([fileManger fileExistsAtPath:path])
            {
                [fileManger removeItemAtPath:path error:nil];
            }
            [fileManger moveItemAtURL:mediaUrl toURL:[NSURL fileURLWithPath:path] error:&error];
            UISaveVideoAtPathToSavedPhotosAlbum(path, nil, nil, nil);
            if (error==nil)
            {
                [self cameraFinishedSucceedWithPath:path];
            }
            else
            {
                NSString *errorMessage=@"文件写入失败";
                if ([[error domain]rangeOfString:@"File exists"].location!=NSNotFound) {
                    errorMessage=@"文件已存在";
                }
                
                [self cameraFinishedFailedWithMessage:errorMessage];
                
            }
        }
    }
}
-(void)cameraFinishedSucceedWithPath:(NSString *)path
{
    CDVPluginResult *result = nil;
    NSString *returnStr=path;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:returnStr];
    [self success:result callbackId:self.currentCallBackID];
   
}
-(void)cameraFinishedFailedWithMessage:(NSString *)message
{
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:message];
    [self error:result callbackId:self.currentCallBackID];
   
}
#pragma mark NSMeapPhotoLibrayDelegate
-(void)getPhotoSucceedInfo:(NSDictionary *)info
{
    if(info)
    {
        NSMutableDictionary *jsonInfo=[NSMutableDictionary dictionaryWithDictionary:info];
        if ([jsonInfo objectForKey:@"mediaImage"])
        {
            [jsonInfo removeObjectForKey:@"mediaImage"];
        }
        if ([info objectForKey:@"movURL"])
        {
            [jsonInfo setObject:[[info objectForKey:@"movURL"] absoluteString] forKey:@"movURL"];
        }
        NSError *error;
        NSData *jsonData = [NSJSONSerialization dataWithJSONObject:jsonInfo options:0 error:&error];
        
        NSString *jsonString = nil;
        if (! jsonData) {
            NSLog(@"Got an error: %@", error);
        } else {
            jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
        }
        CDVPluginResult *result = nil;
       
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:jsonString];
        [self success:result callbackId:self.currentCallBackID];
        [jsonString release];
    }
    else
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"图片数据获取失败"];
        [self error:result callbackId:self.currentCallBackID];
    }
}

-(void)getPhotoFailedInfo:(NSString *)errorInfo
{
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:errorInfo];
    [self error:result callbackId:self.currentCallBackID];
}

#pragma mark NSMeapAudioDelegate
-(void)recorderDidFinishRecording:(NSNotification *)notification
{
    BOOL success = [[[notification userInfo]objectForKey:@"flag"]boolValue];
    NSString *filePath=[[notification userInfo]objectForKey:NSMeapAudioFilePath];
    if (success)
    {
        CDVPluginResult *result = nil;
        
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:filePath];
        [self success:result callbackId:self.currentCallBackID];
    }
    else
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"录音结束失败"];
        [self error:result callbackId:self.currentCallBackID];
    }
}
-(void)playerDidFinishPlaying:(NSNotification *)notification
{
    BOOL success = [[[notification userInfo]objectForKey:@"flag"]boolValue];
    if (success)
    {
        CDVPluginResult *result = nil;
        
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"播放结束"];
        [self success:result callbackId:self.currentCallBackID];
    }
    else
    {
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"播放结束失败"];
        [self error:result callbackId:self.currentCallBackID];
    }
}
-(void)recorderOrPlayerError:(NSNotification *)notification
{
    NSString *errorMessage=[[notification userInfo]objectForKey:NSMeapAudioErrorMessage];
    CDVPluginResult *result = nil;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:errorMessage];
    [self error:result callbackId:self.currentCallBackID];
}
@end
