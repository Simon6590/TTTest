//
//  NSMTabulation.h
//  TableViewTest
//
//  Created by 罗忠燕 on 13-9-3.
//  Copyright (c) 2013年 罗忠燕. All rights reserved.
//

#import <UIKit/UIKit.h>

/// 画表格的类
@interface NSMeapTabulation : UIView

/**
 *	@brief	创建表格
 *
 *	@param 	classModel 	用来创建表格的模型对象
 *	@param 	frame       表格的布局
 *
 *	@return
 */
+ (NSMeapTabulation *)creatTable:(Class)classModel withFrame:(CGRect)frame data:(NSArray *)objectArray;

/**
 *	@brief	创建表格
 *
 *	@param 	titlesArray 	字段数组
 *	@param 	frame 	表格的布局
 *
 *	@return
 */
+ (NSMeapTabulation *)creatTable:(NSArray *)titlesArray withFrame:(CGRect)frame;

/**
 *	@brief	根据模型对象类名设置表字段
 *
 *	@param 	classModel 	模型对象类名
 */
- (void)setTable:(Class)classModel;

/**
 *	@brief  更新数据
 *
 *	@param 	objectArray 	新的数据对象模型
 */
- (void)reloadTable:(NSArray *)objectArray;

/**
 *	@brief	插入表格
 *
 *	@param 	object 	添加一个模型对象，绘制一行表格
 */
- (void)insertTableWithObject:(NSObject *)object;

/**
 *	@brief	删除表格
 *
 *	@param 	object 	删除一个模型对象
 */
- (void)deleteTableWithObject:(NSObject *)object;

/**
 *	@brief	清除所有数据
 */
- (void)clearTable;

@end
