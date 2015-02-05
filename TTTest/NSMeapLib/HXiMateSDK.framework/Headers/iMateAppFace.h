//
//  iMateAppFace.h
//  iMateAppFaceTest
//
//  Created by Mac Pro on 12-10-17.
//  Copyright (c) 2012年 Mac Pro. All rights reserved.
//

/*
 HXiMateSDK使用说明：
 1、初始化(必须）
 在AppDelegate中添加以下代码，用于初始化iMateFaceApp实例，并建立连接Session，改段代码需要添加在didFinishLaunchingWithOptions的顶部。
 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
 {
 iMateAppFace *iMateFace = [iMateAppFace sharedController];
 [iMateFace openSession];
 ...
 
 2、进入后台时关闭Session(必须）
 在AppDelegate中添加以下代码，该段代码需要添加到applicationDidEnterBackground的底部位置。
 - (void)applicationDidEnterBackground:(UIApplication *)application
 {
 ...
 
 [[iMateAppFace sharedController] closeSession];
 
 3、App从后台进入前台之前，重新建立Session(必须）
 在AppDelegate中添加以下代码，该段代码需要添加到applicationDidEnterBackground的顶部位置。
 - (void)applicationWillEnterForeground:(UIApplication *)application
 {
 [[iMateAppFace sharedController] openSession];
 ...
 
 4、UI View中使用iMateFaceApp
 a) 在viewWillAppear中添加以下代码，来获取iMateAppFace的指针以及设置delegate。（必须）, 检查session是否正常。（可选）
 - (void)viewWillAppear:(BOOL)animated
 {
 [super viewWillAppear:animated];
 
 //获取iMateAppFace的实例, 该步骤也可以放在viewDidLoad中做
 _imateAppFace = [iMateAppFace sharedController];
 
 //如果使用delegate协议，需要将delegate设置为self，必须在进入view之前设置。 （重要!!）
 _imateAppFace.delegate = self;
 
 if ( ![_imateAppFace connectingTest] ) {
 NSLog(@"iMate未连接!");
 return;
 }
 NSLog(@"iMate已连接!");
 ...
 b) 在viewWillDisappear中添加以下代码，来取消尚未响应上次请求。（可选）
 - (void)viewWillDisappear:(BOOL)animated
 {
 [_imateAppFace cancel];
 
 [super viewWillDisappear:animated];
 ...
 
 c) 在UI View中实现iMateAppFae的delegate，并调用相关接口。（略）
 
 5、关于在App使用过程中重新关闭和打开iMate
 如果在App使用过程中，iMate关闭电源，iMateAppFace将通过iMateDelegateConnectStatus通知session的状态。
 重新打开iMate后，iMateAppFace又将通过iMateDelegateConnectStatus通知session的状态。
 以上两个过程中，App的用户代码不需要做任何操作，iMateAppFace将自动重新建立或关闭session。
 */

#import <Foundation/Foundation.h>

struct structIssData {
	char szPan[19+1];			// 12-19
	int  iPanSerialNo;			// 0-9, -1表示无
	char szExpireDate[6+1];		// YYMMDD
	char szHolderName[45+1];	// Len>=2
	int  iHolderIdType;			// 0:身份证 1:军官证 2:护照 3:入境证 4:临时身份证 5:其它
	char szHolderId[40+1];
	char szDefaultPin[12+1];	// 4-12
    
	char szAid[32+1];			// OneTwo之后的
	char szLabel[16+1];			// 1-16
	int  iCaIndex;				// 0-255
	int  iIcRsaKeyLen;			// 64-192
	long lIcRsaE;				// 3 or 65537
	int  iCountryCode;			// 1-999
	int  iCurrencyCode;			// 1-999
};

// 打印机状态
#define PRINTER_OK                      0
#define PRINTER_CONNECTED               1
#define PRINTER_NOT_CONNECTED           2
#define PRINTER_OUT_OF_PAPER            3
#define PRINTER_OFFLINE                 4

@protocol iMateAppFaceDelegate <NSObject>

@optional

// 当iMate蓝牙连接连通或者中断时，该方法被调用，通知目前的蓝牙连接状态
- (void)iMateDelegateConnectStatus:(BOOL)isConnecting;

// iMate请求超时或无法执行时，该方法被调用，通知出错信息
- (void)iMateDelegateNoResponse:(NSString *)error;

// iMate响应报文格式错误，该方法被调用
- (void)iMateDelegateResponsePackError;

// 刷卡操作执行结束后，该方法被调用，返回结果
- (void)iMateDelegateSwipeCard:(NSInteger)returnCode
                        track2:(NSString*)track2
                        track3:(NSString *)track3
                         error:(NSString *)error;

// IC卡复位操作执行结束后，该方法被调用，返回结果
- (void)iMateDelegateICResetCard:(NSInteger)returnCode
                       resetData:(NSData *)resetData
                             tag:(NSInteger)tag
                           error:(NSString *)error;

// IC卡APDU操作执行结束后，该方法被调用，返回结果
- (void)iMateDelegateICApdu:(NSInteger)returnCode
               responseApdu:(NSData*)responseApdu
                      error:(NSString *)error;

// 读身份证操作执行结束后，该方法被调用，返回结果。可调用processIdCardInfo对information拆分成数组
- (void)iMateDelegateIDReadMessage:(NSInteger)returnCode
                       information:(NSData *)information
                             photo:(NSData*)photo
                             error:(NSString *)error;

// 获取电池电量操作执行结束后，该方法被调用，返回结果，level取值在0-100之间
- (void)iMateDelegateBatteryLevel:(NSInteger)returnCode
                            level:(NSInteger)level
                            error:(NSString *)error;

// 读取扩展内存操作执行结束后，该方法被调用，返回结果
- (void)iMateDelegateXmemRead:(NSInteger)returnCode
                         data:(NSData *)data
                        error:(NSString *)error;

// 写扩展内存操作执行结束后，该方法被调用，返回结果
- (void)iMateDelegateXmemWrite:(NSInteger)returnCode
                         error:(NSString *)error;


// 读PBOC卡信息操作执行结束后，该方法被调用，返回结果。cardInfo中的数据用","间隔
- (void)iMateDelegatePbocReadInfo:(NSInteger)returnCode
                           cardInfo:(NSString *)cardInfo
                              error:(NSString *)error;

// 读PBOC卡日志操作执行结束后，该方法被调用，返回结果。cardLog为NSString数组的方式。
- (void)iMateDelegatePbocReadLog:(NSInteger)returnCode
                         cardLog:(NSArray *)cardLog
                            error:(NSString *)error;

// Pboc发卡操作执行结束后，该方法被调用，返回结果。
- (void)iMateDelegatePbocIssCard:(NSInteger)returnCode
                           error:(NSString *)error;

// 卡片操作状态信息
- (void)iMateDelegateRuningStatus:(NSString *)statusString;

/*
 打印机有关Delegate
 */
// 当打印机蓝牙连接连通或者中断时，该方法被调用，通知目前的蓝牙连接状态
- (void)printerDelegateStatusResponse:(NSInteger)status;

@end

@interface iMateAppFace : NSObject

@property (strong, nonatomic) id<iMateAppFaceDelegate> delegate;

// 获取iMateFace实例
+ (iMateAppFace *)sharedController;

// 该方法对身份证信息进行拆分
+ (NSArray *)processIdCardInfo:(NSData *)information;

// 打开与iMate的连接会话，返回YES会话建立成功
- (BOOL)openSession;

// 关闭与iMate的连接会话
- (void)closeSession;

// 检测蓝牙连接是否正常，返回YES表示连接正常
- (BOOL)connectingTest;

// 检测iMate是否在工作状态，返回YES表示正在工作中。
- (BOOL)isWorking;

// 刷卡请求，timeout是刷卡的最长等待时间(秒)
- (void)swipeCard:(NSInteger)timeout;

// 等待IC插入，并对IC卡进行复位请求，slot＝0为用户插槽，tag将被传递给iMateDelegateICResetCard，
// 可做为后续执行操作的标示，timeout为IC卡插入读卡槽的最长等待时间(秒)，
- (void)icResetCard:(NSInteger)slot tag:(NSInteger)tag timeout:(NSInteger)timeout;

// IC卡APDU操作请求，slot＝0为用户插槽
- (void)icApdu:(NSInteger)slot commandApdu:(NSData *)commandApdu;

// 读二代身份证操作请求，timeout为身份证放到读卡位置的最长等待时间(秒)
- (void)idReadMessage:(NSInteger)timeout;

// 读取电池电量的操作请求
- (void)batteryLevel;

// 读取扩展内存的操作请求
- (void)xmemRead:(NSInteger)offset length:(NSInteger)length;

// 写扩展内存的操作请求
- (void)xmemWrite:(NSInteger)offset data:(NSData*)data;

// 读取PBOC卡信息的操作请求，该操作需执行之前成功执行了icResetCard操作
- (void)pbocReadInfo;

// 读取PBOC卡日志的操作请求，该操作需执行之前成功执行了icResetCard操作
- (void)pbocReadLog;

// PBOC发卡操作请求，该操作需执行之前成功执行了icResetCard操作, issData内容参考structIssData 
- (void)pbocIssCard:(NSData *)issData;

// 中断操作，仅对swipeCard，icResetCard，idReadMessage操作有效
- (void)cancel;

/*
 打印机有关操作
 */
// 查询打印机蓝牙是否连接
- (BOOL)printerConnectingTest;

// 查询打印机状态, 打印机的状态通过Delegate获取
- (void)printerStatus;

// 打印数据，\n结束
- (void)print:(NSString *)printString;

+ (NSData *)twoOneData:(NSString *)sourceString;
+ (NSString *)oneTwoData:(NSData *)sourceData;

@end
