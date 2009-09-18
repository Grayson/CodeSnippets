/*
 *     Generated by class-dump 3.1.
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2005 by Steve Nygard.
 */

#import "NSObject.h"

@class NSArray, NSMutableArray, SEDataColumn;

@interface SEDataSource : NSObject
{
    NSMutableArray *_views;
    NSMutableArray *_columns;
    NSMutableArray *_rows;
    NSMutableArray *_items;
    NSArray *_sortedRows;
    BOOL _shouldUpdateViews;
    BOOL _sorted;
    BOOL _localizedSort;
    SEDataColumn *_sortColumn;
}

- (id)init;
- (void)dealloc;
- (void)encodeWithCoder:(id)fp8;
- (id)initWithCoder:(id)fp8;
- (id)views;
- (id)columns;
- (id)rows;
- (id)cells;
- (id)items;
- (id)sortedRows;
- (BOOL)shouldUpdateViews;
- (void)setShouldUpdateViews:(BOOL)fp8;
- (BOOL)sorted;
- (void)setSorted:(BOOL)fp8;
- (BOOL)localizedSort;
- (void)setLocalizedSort:(BOOL)fp8;
- (id)sortColumn;
- (void)setSortColumn:(id)fp8;
- (void)addView:(id)fp8;
- (void)removeView:(id)fp8;
- (void)removeAllViews;
- (void)updateViews;
- (BOOL)hasView:(id)fp8;
- (void)sort;
- (void)invalidateSort;
- (id)cellAtIndex:(unsigned int)fp8;
- (void)addInCells:(id)fp8;
- (void)insertInCells:(id)fp8 atIndex:(unsigned int)fp12;
- (void)removeCell:(id)fp8;
- (void)removeFromCellsAtIndex:(unsigned int)fp8;
- (void)removeAllCells;
- (void)replaceInCells:(id)fp8 atIndex:(unsigned int)fp12;
- (id)columnWithName:(id)fp8;
- (id)columnAtIndex:(unsigned int)fp8;
- (void)addInColumns:(id)fp8;
- (void)insertInColumns:(id)fp8 atIndex:(unsigned int)fp12;
- (void)removeColumn:(id)fp8;
- (void)removeFromColumnsAtIndex:(unsigned int)fp8;
- (void)removeAllColumns;
- (void)replaceInColumns:(id)fp8 atIndex:(unsigned int)fp12;
- (id)rowAtIndex:(unsigned int)fp8;
- (void)addInRows:(id)fp8;
- (void)insertInRows:(id)fp8 atIndex:(unsigned int)fp12;
- (void)removeRow:(id)fp8;
- (void)removeFromRowsAtIndex:(unsigned int)fp8;
- (void)removeAllRows;
- (void)replaceInRows:(id)fp8 atIndex:(unsigned int)fp12;
- (id)itemAtIndex:(unsigned int)fp8;
- (void)addInItems:(id)fp8;
- (void)insertInItems:(id)fp8 atIndex:(unsigned int)fp12;
- (void)removeItem:(id)fp8;
- (void)removeFromItemsAtIndex:(unsigned int)fp8;
- (void)removeItemsInRange:(struct _NSRange)fp8;
- (void)removeAllItems;
- (void)replaceInItems:(id)fp8 atIndex:(unsigned int)fp12;

@end
