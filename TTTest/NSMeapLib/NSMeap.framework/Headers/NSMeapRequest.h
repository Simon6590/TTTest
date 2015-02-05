//
//  MeapHttp.h
//  MEAPServer
//
//  Created by yangyalin on 13-3-13.
//  Copyright (c) 2013年 yangyalin. All rights reserved.
//

/**
 * @file        NSMeapRequest.h
 * @brief       网络通讯组件.
 * @version     1.0
 * @date        2013-3-13
 *
 * [2013-06-07] <杨亚霖> v1.0
 *
 * + v1.0版发布.
 *
 */

/// 客户端与服务器沟通时用到的类.

#import <Foundation/Foundation.h>
#import "NSMeap.h"

/**
 * 后台请求需要添加到任务调度
 * 后台请求任务调度类型
 */
typedef enum
{
    TASK_QUEUE_WAIT_TYPE,       //!< 排队等待 default */
    TASK_PRIOIRTY_WAIT_TYPE,    //!< 优先等待 */
	TASK_PRIORITY_TYPE          //!< 任务优先 */
}TASK_MANAGER_TYPE ;

/**
 *	@brief	数据传输加密方式
 */
typedef enum
{
    DATA_NO_ENCRYPT,    //!< 无加密,明文传输 */
	DATA_3DES_ENCRYPT,  //!< 3DES加密 */
	DATA_RSA_ENCRYPT    //!< RSA加密 */
}DATA_ENCRYPT_TYPE;

/**
 *	@brief	数据传输的报文格式
 */
typedef enum
{
    JSON_FORMAT,        //!< json格式报文 */
	XML_FORMAT,         //!< xml格式报文 */
}DATA_SEND_FORMAT;

@class NSMeapDataTree,NSMeapTaskManager,NSMeapRequest;

/**
 *	@brief	http请求代理.
 */
@protocol NSMeapRequestDelegate;

#if NS_BLOCKS_AVAILABLE
/**
 *	@brief	请求成功时调用block.
 *
 *	@param 	request 	当前请求对象.
 *	@param 	headTree 	请求成功后生成的headtree对象.
 *	@param 	bodyTree 	请求成功后生成的bodytree对象.
 */
typedef void (^NSMeapRequestSuccess)(NSMeapRequest *request ,NSMeapDataTree *headTree, NSMeapDataTree *bodyTree);

/**
 *	@brief	请求失败时调用的block.
 *
 *	@param 	request 	当前请求对象.
 *	@param 	headTree 	请求失败后生成的headtree对象.
 *	@param 	bodyTree 	请求失败后生成的bodytree对象.
 */
typedef void (^NSMeapRequestFailed)(NSMeapRequest *request ,NSMeapDataTree *headTree, NSMeapDataTree *bodyTree);

/**
 *	@brief	请求返回非标准报文 调用的block.
 *
 *	@param 	request 	当前请求对象.
 *	@param 	dataTree    返回非标准报文.
 */
typedef void (^NSMeapRequestNonStandard)(NSMeapRequest *request ,NSString *dataStr);
#endif

/**
 *	@brief	Meap平台 网络请求类.
 */
@interface NSMeapRequest : NSObject

#pragma mark - 参数配置
/**
 *	@brief	调用方法接口. (必填)
 */
@property (nonatomic, retain) NSString      *interface;

/**
 *	@brief	调用方法名.
 */
@property (nonatomic, retain) NSString      *method;

/**
 *	@brief	调用版本号.
 */
@property (nonatomic, retain) NSString      *version;

/**
 *  @brief  服务组名
 */
@property (nonatomic, retain) NSString      *group;

/**
 *	@brief	数据加密方式(默认不加密).
 */
@property (nonatomic, assign) DATA_ENCRYPT_TYPE encryptType;

/**
 *	@brief	数据报文格式(默认JSON_FORMAT).
 */
@property (nonatomic, assign) DATA_SEND_FORMAT  sendFormat;

/**
 *	@brief	是否需要https.
 */
@property (nonatomic) BOOL                  isHttps;

/**
 *	@brief	双向认证设置证书.
 *  证书为P12.
 *
 *	@param 	cerFilePath 	证书路径.
 *  @param  cerPassword     证书密码.
 */
- (void)setHttpsBidirectionalAuthCertificateFilePath:(NSString *)cerFilePath cerPassword:(NSString *)cerPassword;

/**
 *	@brief	请求的URL是否带盐.
 */
@property (nonatomic) BOOL                  hasHttpSalt;

/**
 *	@brief	是否需要压缩.
 */
@property (nonatomic, assign) BOOL          isZip;

/**
 *	@brief	是否必须上网上网请求,默认为NO.
 */
@property (nonatomic) BOOL                  mustHttp;

/**
 *	@brief	是否需要存入数据库,默认是存入数据库.
 */
@property (nonatomic) BOOL                  isCaches;

/**
 *	@brief	临时数据 不会带去储存.
 */
@property (nonatomic, retain) id            userInfo;

/**
 *	@brief	请求代理.
 */
@property (nonatomic, assign) id <NSMeapRequestDelegate> httpDelegate;

/**
 *	@brief	长连接参数配置,YES为长连接请求,NO为普通短连接.(默认为http短连接)
 */
@property (nonatomic, assign) BOOL          isSocketRequest;

/**
 *	@brief	超时时间,默认15秒
 */
@property (assign) NSTimeInterval           timeOutSeconds;

/**
 *	@brief	返回请求对象的headBean对象.
 *
 *	@return	返回headBean对象.
 */
- (NSMeapDataBean *)getHeadBean;

/**
 *	@brief	返回请求对象的BodyBean对象.
 *
 *	@return	返回BodyBean对象.
 */
- (NSMeapDataBean *)getBodyBean;

/**
 *	@brief	通过headBean和bodyBean初始化方法.
 *
 *	@param 	headBean 	headBean对象.
 *	@param 	bodyBean 	bodyBean对象.
 *
 *	@return	返回MeapHttp对象.
 */
- (id)initWithHeadBean:(NSMeapDataBean *)headBean bodyBean:(NSMeapDataBean *)bodyBean;

/**
 *	@brief	设置请求头部参数.
 *
 *	@param 	parma 	参数名.
 *	@param 	data_type 	参数数据类型.
 *	@param 	value 	参数数据值.
 */
- (void)setHeadParma:(NSString *)parma dataType:(DATA_TYPE)data_type value:(NSString *)value;

/**
 *	@brief	添加请求body参数.
 *
 *	@param 	parma 	参数名.
 *	@param 	data_type 	参数数据类型.
 *	@param 	value 	参数数据值.
 */
- (void)appendBodyParma:(NSString *)parma dataType:(DATA_TYPE)data_type value:(NSString *)value;

/**
 *	@brief	添加请求参数.
 *
 *	@param 	bean 	参数数据值,参数值是一个NSMeapDataBean对象.
 */
- (void)appendBodyBeanValue:(NSMeapDataBean *)bean;

/**
 *	@brief	添加请求body 文件参数.
 *
 *	@param 	parma 	参数名.
 *	@param 	fileName 	文件名.
 *	@param 	fileType 	文件数据类型.
 *	@param 	fileData 	文件数据.
 */
- (void)appendFileParma:(NSString *)parma fileName:(NSString *)fileName fileType:(NSString *)fileType fileData:(NSData *)fileData;

/**
 *	@brief	添加请求body 文件参数.
 *
 *	@param 	parma 	参数名.
 *	@param 	fileAtt 	文件.
 */
- (void)appendFileParma:(NSString *)parma fileAtt:(NSMeapDataAttFile *)fileAtt;


#pragma mark - block机制支持
/**
 *	@brief	设置回调block
 *
 *	@param 	successBlock 	成功block
 *	@param 	failedBlock 	失败block
 *	@param 	nonStandardBlock 	非标准成功block
 */
- (void)setSuccessBlock:(NSMeapRequestSuccess)successBlock failedBlock:(NSMeapRequestFailed)failedBlock nonStandardBlock:(NSMeapRequestNonStandard)nonStandardBlock;

#pragma mark - 普通请求队列
/**
 *	@brief	在后台请求.
 *
 *	@param 	task_type 	后台请求准备，将添加到任务调度.
 */
- (void)prepareAsynchronous:(TASK_MANAGER_TYPE)task_type;


#pragma mark - 上传提交离线请求
/**
 *	@brief	离线请求支持.
 *
 *	@param 	weight              请求的权重:1为加急请求;2为较急请求;3为普通请求.
 *	@param 	expireTime          持久化过期时间.
 *	@param 	isPersistent        是否需要持久化.
 *	@param 	isCancel            请求从持久化队列插入到请求队列的时候是否删除请求.
 *	@param 	isUpdate            是否更新数据库或队列中相同的请求对象.
 *	@param 	notificationName 	消息通知名称,调用成功后会发送的通知名.
 */
- (void)prepareOfflineRequestWithWeight:(int)weight expireTime:(NSTimeInterval)expireTime isPersistent:(BOOL)isPersistent isCancel:(BOOL)isCancel isUpdate:(BOOL)isUpdate notificationName:(NSString *)notificationName;

/**
 *	@brief	取消掉离线队列和普通队列的所有请求.
 */
+ (void)cancelAllRequest;

/**
 *	@brief	把离线情况下存到数据库的提交请求同步到队列里面.
 */
+ (void)syncOfflineRequestQueue;

#pragma mark - 无队列
/**
 *	@brief	直接请求.
 *
 *	@return	同步请求，直接返回数据.
 */
- (NSMeapDataTree *)startSynchronous;

/**
 *	@brief 异步请求.
 *
 *	@return	异步请求，直接返回数据.
 */
- (void)startAsynchronous;

/**
 *	@brief	取消异步请求.
 */
- (void)cancel;

/**
 *	@brief	判断请求是否结束.
 *
 *	@return	BOOL 值.
 */
- (BOOL)isFinished;


/**
 *	@brief	返回请求的Tree对象
 *
 *	@return	返回请求用的Tree对象
 */
- (NSMeapDataTree *)perpareData;

@end

/**
 *	@brief	http请求代理
 */
@protocol NSMeapRequestDelegate <NSObject>
@optional
/**
 *	@brief	请求成功时调用方法.
 *
 *	@param 	request 	当前请求对象.
 *	@param 	headTree 	请求成功后生成的headtree对象.
 *	@param 	bodyTree 	请求成功后生成的bodytree对象.
 */
- (void)meapHttp:(NSMeapRequest *)request requestSuccessHeadTree:(NSMeapDataTree *)headTree bodyTree:(NSMeapDataTree *)bodyTree;

/**
 *	@brief	请求成功时 code为0 是调用的方法.
 *
 *	@param 	request 	当前请求对象.
 *	@param 	headTree 	请求失败后生成的headtree对象.
 *	@param 	bodyTree 	请求失败后生成的bodytree对象.
 */
- (void)meapHttp:(NSMeapRequest *)request requestFailedHeadTree:(NSMeapDataTree *)headTree bodyTree:(NSMeapDataTree *)bodyTree;

/**
 *	@brief	请求返回非标准报文 调用的方法.
 *
 *	@param 	request 	当前请求对象.
 *	@param 	dataStr     非标准报文字符串.
 */
- (void)meapHttp:(NSMeapRequest *)request requestNonStandardDataStr:(NSString *)dataStr;

@end