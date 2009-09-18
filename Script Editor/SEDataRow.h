/*
 *     Generated by class-dump 3.1.
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2005 by Steve Nygard.
 */

#import "NSObject.h"

@class NSMutableArray, SEDataSource;

@interface SEDataRow : NSObject
{
    SEDataSource *_dataSource;
    NSMutableArray *_cells;
    NSObject *_representedObject;
}

+ (id)rowForDataSource:(id)fp8;
- (id)initForDataSource:(id)fp8;
- (id)init;
- (void)dealloc;
- (id)dataSource;
- (void)setDataSource:(id)fp8;
- (id)columns;
- (id)cells;
- (id)representedObject;
- (void)setRepresentedObject:(id)fp8;
- (id)cellWithName:(id)fp8;
- (int)compareDataRow:(id)fp8;
- (void)addInCells:(id)fp8;
- (void)insertInCells:(id)fp8 atIndex:(unsigned int)fp12;
- (void)removeFromCellsAtIndex:(unsigned int)fp8;
- (void)replaceInCells:(id)fp8 atIndex:(unsigned int)fp12;
- (void)insertInColumns:(id)fp8 atIndex:(unsigned int)fp12;
- (void)removeFromColumnsAtIndex:(unsigned int)fp8;
- (void)replaceInColumns:(id)fp8 atIndex:(unsigned int)fp12;

@end

