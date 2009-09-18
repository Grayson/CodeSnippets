//
//  SnippetController.h
//  CodeSnippets
//
//  Created by Grayson Hansard on 8/14/06.
//  Copyright 2006 From Concentrate Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "SEDocument.h"


@interface FCSSnippetController : NSObject {
	NSBundle *_bundle;
	NSMutableArray *_snippets;
	SEDocument *_lastDocument;
	
	IBOutlet NSWindow *window;
	IBOutlet NSTableView *tableView;
	IBOutlet NSArrayController *SnippetsArrayController;
}

+ (void)pluginDidLoad:(NSBundle *)bundle;

-(id)initWithBundle:(NSBundle *)bundle;

-(NSBundle *)bundle;
-(void)setBundle:(NSBundle *)bundle;

-(NSMutableArray *)snippets;
-(void)setSnippets:(NSArray *)snippets;

-(IBAction)add:(id)sender;
-(IBAction)delete:(id)sender;
- (IBAction)export:(id)sender;
-(IBAction)insert:(id)sender;
-(IBAction)copy:(id)sender;
-(IBAction)paste:(id)sender;
-(IBAction)showWindow:(id)sender;

@end
