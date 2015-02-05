//
//  NSM_SelectButton.h
//  TextActionSheet
//
//  Created by yalin on 13-9-25.
//
//

#import <UIKit/UIKit.h>

/// 选择框类型
typedef enum
{
    NSMEAP_CHECK_BOX,       //!< 多选框(默认) */
    NSMEAP_RADIO,           //!< 单选框 */
}NSMEAP_SELECT_BUTTON_TYPE;

/**
 *	@brief	选择框组件,支持多选框以及单选框.
 *  selected状态为选中状态,default状态为未选状态.
 */
@interface NSMeapSelectButton : UIButton

/**
 *	@brief	取得选择框按钮,得到值.
 *
 *	@param 	groupName 	选择框组名.
 *	@param 	type 	选择框类型.
 *
 *	@return	返回包含选中框的数组.
 */
+ (NSArray *)valuesWithGroupName:(NSString *)groupName type:(NSMEAP_SELECT_BUTTON_TYPE)type;

/// 设置选择框类型
@property (nonatomic, assign) NSMEAP_SELECT_BUTTON_TYPE     type;

/// 设置单选框在哪一组,不设置默认取当前时间字符串代替groupName.
@property (nonatomic, retain) NSString                  *groupName;

/// button所带的信息
@property (nonatomic, retain) id                        userInfo;

@end
