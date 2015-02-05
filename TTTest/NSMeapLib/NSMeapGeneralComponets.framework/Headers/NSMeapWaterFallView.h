//
//  NSMWaterFallView.h
//  NSMWaterFallView
//
//  Created by Guo Mingliang on 13-9-24.
//  Copyright (c) 2013年 Guo Mingliang. All rights reserved.
//

#import <UIKit/UIKit.h>
#define kTMQuiltViewDefaultColumns 2
#define kTMQuiltViewDefaultMargin 10.0f
#define kTMQuiltViewDefaultCellHeight 50.0f
@class NSMeapWaterFallViewCell;
@class NSMeapWaterFallView;

typedef enum {
    NSMWaterFallViewCellMarginTop,
    NSMWaterFallViewCellMarginLeft,
    NSMWaterFallViewCellMarginRight,
    NSMWaterFallViewCellMarginBottom,
    NSMWaterFallViewCellMarginColumns,
    NSMWaterFallViewCellMarginRows
} NSMWaterFallViewMarginType;

@protocol NSMeapWaterFallViewDataSource <NSObject>

- (NSInteger)waterFallViewNumberOfCells:(NSMeapWaterFallView *)waterFallView;
- (NSMeapWaterFallViewCell *)waterFallView:(NSMeapWaterFallView *)waterFallView cellAtIndexPath:(NSIndexPath*)indexPath;

@end

@protocol NSMeapWaterFallViewDelegate <UIScrollViewDelegate>

@optional

- (void)waterFallView:(NSMeapWaterFallView *)waterFallView didSelectCellAtIndexPath:(NSIndexPath *)indexPath;

// Must return a number of column greater than 0. Otherwise a default value is used.
- (NSInteger)waterFallViewNumberOfColumns:(NSMeapWaterFallView *)quiltView;

// Must return margins for all the possible values of TMQuiltViewMarginType. Otherwise a default value is used.
- (CGFloat)waterFallViewMargin:(NSMeapWaterFallView *)waterFallView marginType:(NSMWaterFallViewMarginType)marginType;

// Must return the height of the requested cell
- (CGFloat)waterFallView:(NSMeapWaterFallView *)waterFallView heightForCellAtIndexPath:(NSIndexPath *)indexPath;

@end

@interface NSMeapWaterFallView : UIScrollView

@property (nonatomic, assign) id<NSMeapWaterFallViewDataSource> dataSource;
@property (nonatomic, assign) id<NSMeapWaterFallViewDelegate> delegate;

// Returns the cell if it's visible and indexPath is valid. Returns nil otherwise
- (NSMeapWaterFallViewCell *)cellAtIndexPath:(NSIndexPath*)indexPath;

// Returns a cell from the reuse pool associated to reuseIdentifier. Return nil if the pool doesn't
// contain any cell.
- (NSMeapWaterFallViewCell *)dequeueReusableCellWithReuseIdentifier:(NSString *)reuseIdentifier;

// Returns an array with the visible cells
- (NSArray *)visibleCells;

// Reloads all the cells. You need to call this if the number of columns changes.
- (void)reloadData;

// Currently calling beginUpdates and endUpdates before and after row insertions and removals is required.
- (void)beginUpdates;
- (void)endUpdates;
- (void)insertCellAtIndexPath:(NSIndexPath *)indexPaths;
- (void)deleteCellAtIndexPath:(NSIndexPath *)indexPaths;
- (void)moveCellAtIndexPath:(NSIndexPath *)indexPath toIndexPath:(NSIndexPath *)newIndexPath;

// Returns the height of a cell
- (CGFloat)heightForCellAtIndexPath:(NSIndexPath *)indexPath;

// Returns the width of a cell
- (CGFloat)cellWidth;

// Returns the number of cells in the quilt
- (NSInteger)numberOfCells;

// Returns the number of columns in the quilt
- (NSInteger)numberOfColumns;

// Returns the number of cells in the specified column
- (NSInteger)numberOfCellsInColumn:(NSInteger)column;

@end