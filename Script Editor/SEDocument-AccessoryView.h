/*
 *     Generated by class-dump 3.1.
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2005 by Steve Nygard.
 */

#import "SEDocument.h"

@interface SEDocument (AccessoryView)
- (void)_addItemsToPopUpButton:(id)fp8 fromArray:(id)fp12 enabled:(BOOL)fp16;
- (void)_adjustViewForDocumentType:(id)fp8;
- (BOOL)prepareSavePanel:(id)fp8;
- (id)accessoryView;
- (id)fileFormatPopUpButton;
- (id)lineEndingsPopUpButton;
- (id)runOnlyButton;
- (id)stayOpenButton;
- (id)showStartupScreenButton;
- (id)requiresClassicButton;
- (void)changeFileFormat:(id)fp8;
- (void)changeLineEndings:(id)fp8;
- (void)changeRunOnly:(id)fp8;
- (void)changeStayOpen:(id)fp8;
- (void)changeShowStartupScreen:(id)fp8;
- (void)changeRequiresClassic:(id)fp8;
@end

