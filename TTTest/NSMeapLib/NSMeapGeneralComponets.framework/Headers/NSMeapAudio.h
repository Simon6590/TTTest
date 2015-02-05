//
//  NSMeapAudio.h
//  MeapSDK
//
//  Created by 十九 on 13-8-8.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

/**
 * @file        NSMeapAudio.h
 * @brief       媒体库组件.
 * @version     1.0
 * @date        2013-8-8
 *
 * [2013-06-07] <罗忠燕> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <Foundation/Foundation.h>

///播放完成通知 常量
extern NSString *const NSMeapAudioPlayerDidFinishPlaying;
///录音完成通知 常量
extern NSString *const NSMeapAudioRecorderDidFinishRecording;
///录音播放失败通知 常量
extern NSString *const NSMeapAudioRecorderOrPlayerError;
///录音振幅更新通知 常量
extern NSString *const NSMeapAudioRecorderUpdateMeters;
///失败信息key 常量
extern NSString *const NSMeapAudioErrorMessage;
///文件路径key 常量
extern NSString *const NSMeapAudioFilePath;
///文件数据key 常量
extern NSString *const NSMeapAudioData;

/// 音频模型
@interface NSMeapAudioInfo: NSObject
/// 音频文件名
@property (nonatomic, retain) NSString *audioName;
/// 音频路径
@property (nonatomic, retain) NSString *audioPath;
/// 音频大小
@property (nonatomic) NSInteger   audioSize;

@end

/// 音频组件
@interface NSMeapAudio : NSObject

CLASS_SINGLETON_INTERFACE(NSMeapAudio)

/// 是否正在录制音频
@property(nonatomic,assign)         BOOL isRecording;
/// 是否正在播放音频
@property(nonatomic,assign)         BOOL isPlaying;
/// 播放音频暂停中
@property (nonatomic,assign)        BOOL isPlayPause;
/// 是否是听筒播放
@property (nonatomic, assign)       BOOL isReceiver;


/**
 *	@brief	录音
 *
 *	@param 	fileName 	文件名称
 *	@param 	superController 	调用录音的UIViewController
 */
-(void)recordAudio:(NSString *)fileName controller:(UIViewController *)superController;

/**
 *	@brief	录音 不传文件名，以当前时间命名
 *
 *	@param 	superController 	调用录音的UIViewController
 */
-(void)recordAudioInController:(UIViewController *)superController;

- (void)prepareRecord;

/**
 *	@brief	开始录音
 */
-(void)startRecord;
/**
 *	@brief	暂停录音
 */
-(void)pauseRecord;
/**
 *	@brief	停止录音
 */
-(void)stopRecord;
/**
 *	@brief	播放录音
 *
 *	@param 	filePath 	文件路径
 */
-(void)playAudio:(NSString *)filePath;

/**
 *	@brief	播放录音
 *
 *	@param 	data 	语音数据
 */
- (void)playAudioWithData:(NSData *)data;

/**
 *	@brief	开始播放
 */
-(void)startPlay;
/**
 *	@brief	暂停播放
 */
-(void)pausePlay;
/**
 *	@brief	停止播放
 */
-(void)stopPlay;
/**
 *	@brief	获取录音文件路径
 *
 *	@param 	fileName 	文件名称
 *
 *	@return	文件路径
 */
-(NSString *)getAudioPath:(NSString *)fileName;

/**
 *	@brief	删除录音音频
 *
 *	@param 	fileName 	文件名称
 *
 *	@return	文件路径
 */
- (void)removeAudio:(NSString *)fileName;

/**
 *	@brief	获取录音文件信息
 *
 *	@param 	fileName 	文件名
 *
 *	@return	文件信息NSMeapAudioInfo
 */
- (NSMeapAudioInfo *)getAudioInfo:(NSString *)fileName;

/**
 *	@brief	获取录音列表
 *
 *	@return	所有录音文件名称 数组
 */
-(NSArray *)getAudioList;

/**
 *	@brief	获取录音列表
 *
 *	@return 所有录音文件信息NSMeapAudioInfo 数组
 */
- (NSArray *)getAudioInfoList;

/**
 *	@brief	获取音频文件的大小
 *
 *	@param 	fileName 	文件名
 *
 *	@return	多少秒
 */
- (NSTimeInterval)getAudioDuration:(NSString *)fileName;

/**
 *	@brief	获取音频播放的duration
 *
 *	@return	NSTimeInterval类型
 */
-(NSTimeInterval)playerDuration;

@end



