//
//  SnippetController.m
//  CodeSnippets
//
//  Created by Grayson Hansard on 8/14/06.
//  Copyright 2006 From Concentrate Software. All rights reserved.
//

#import "SnippetController.h"

@implementation FCSSnippetController

+ (void)pluginDidLoad:(NSBundle *)bundle
{
	[[FCSSnippetController alloc] initWithBundle:bundle];
}

-(id)initWithBundle:(NSBundle *)bundle
{
	self = [super init];
	if (!self) return nil;
	
	[self setBundle:bundle];
	NSNotificationCenter *center = [NSNotificationCenter defaultCenter];
	[center addObserver:self selector:@selector(appFinishedLaunching:) 
				   name:NSApplicationDidFinishLaunchingNotification object:nil];
	[center addObserver:self selector:@selector(windowLostFocus:) name:NSWindowDidResignKeyNotification object:nil];
	[center addObserver:self selector:@selector(windowWillClose:) name:NSWindowWillCloseNotification object:nil];
	[center addObserver:self selector:@selector(appWillTerminate:) name:NSApplicationWillTerminateNotification 
				 object:nil];
	
	return self;
}

-(void)awakeFromNib
{
	NSMutableArray *snippets = [NSMutableArray array];
	NSEnumerator *e = [[[NSUserDefaults standardUserDefaults] objectForKey:@"FCSSnippets"] objectEnumerator];
	NSDictionary *d = nil;
	while (d = [e nextObject]) [snippets addObject:[[d mutableCopy] autorelease]];
	[self setSnippets:snippets];

	// Setup menu item
	NSMenu *m = [[[NSApp menu] itemWithTitle:NSLocalizedString(@"Window", @"")] submenu];
	NSMenuItem *mi = [m insertItemWithTitle:@"Code Snippets" action:@selector(showWindow:) keyEquivalent:@"C" 
									atIndex:[m indexOfItemWithTitle:NSLocalizedString(@"Library", @"")]];
	[mi setTarget:self];
	[mi setKeyEquivalentModifierMask:NSAlternateKeyMask | NSCommandKeyMask];
	
	// Setup toolbar
	NSToolbar *tb = [[[NSToolbar alloc] initWithIdentifier:@"com.fcs.codesnippets.toolbar"] autorelease];
	[tb setDisplayMode:NSToolbarDisplayModeIconOnly];
	[tb setSizeMode:NSToolbarSizeModeSmall];
	[tb setDelegate:self];
	[window setToolbar:tb];
}

#pragma mark -
#pragma mark Getters/Setters

-(NSBundle *)bundle { return _bundle; }
-(void)setBundle:(NSBundle *)bundle
{
	if (bundle && bundle != _bundle)
	{
		[_bundle release];
		_bundle = [bundle retain];
	}
}

-(NSMutableArray *)snippets { return _snippets; }
-(void)setSnippets:(NSArray *)snippets
{
	if (snippets && snippets != _snippets)
	{
		[_snippets release];
		_snippets = [snippets mutableCopy];
		[[NSUserDefaults standardUserDefaults] setObject:_snippets forKey:@"FCSSnippets"];
	}
}

#pragma mark -
#pragma mark IBActions

-(IBAction)add:(id)sender
{
	NSString *snippet = @"";
	if (_lastDocument)
	{
		NSTextView *tv = [_lastDocument scriptView];
		snippet = [[tv attributedSubstringFromRange:[tv selectedRange]] string];
	}
	
	NSDictionary *d = [NSMutableDictionary dictionaryWithObjectsAndKeys:snippet, @"code", @"<title>", @"title", nil];
	[SnippetsArrayController addObject:d];
	[SnippetsArrayController setSelectedObjects:[NSArray arrayWithObject:d]];
	[tableView editColumn:0 row:[[SnippetsArrayController content] indexOfObject:d] withEvent:nil select:YES];
}

-(IBAction)delete:(id)sender
{	// Routed through here for interface validation and FirstResponder support
	int choice = NSRunAlertPanel(@"Confirm deletion", @"Deleting the selected snippet cannot be undone.  Are you sure you want to delete it?", @"Delete", @"Cancel", nil);
	if(choice != NSAlertDefaultReturn) return;
	
	[SnippetsArrayController remove:sender];
}

-(IBAction)copy:(id)sender
{
	if ([[tableView selectedRowIndexes] count] == 0) return;
	NSPasteboard *pb = [NSPasteboard generalPasteboard];
	[pb declareTypes:[NSArray arrayWithObject:NSStringPboardType] owner:nil];
	[pb setString:[[SnippetsArrayController selection] valueForKey:@"code"] forType:NSStringPboardType];
}

- (IBAction)export:(id)sender
{
	NSOpenPanel *openPanel = [NSOpenPanel openPanel];
	if (![openPanel runModalForTypes:[NSArray arrayWithObjects:@"snippets", nil]]) return;
	NSString *filePath = [openPanel filename];
	[[SnippetsArrayController content] writeToFile:filePath atomically:YES];
}

-(IBAction)insert:(id)sender
{
	NSTextView *tv = [_lastDocument scriptView];
	NSString *selected = [[tv attributedSubstringFromRange:[tv selectedRange]] string];
	NSString *snippet = [[SnippetsArrayController selection] valueForKey:@"code"];
	
	if (!selected) selected = @"";
	if ([snippet rangeOfString:@"%@"].location != NSNotFound) snippet = [NSString stringWithFormat:snippet, selected];
	
	[[tv textStorage] replaceCharactersInRange:[tv selectedRange] withString:snippet];
}

-(IBAction)paste:(id)sender
{
	NSPasteboard *pb = [NSPasteboard generalPasteboard];
	if (![[pb types] containsObject:NSStringPboardType]) return;

	NSString *snippet = [pb stringForType:NSStringPboardType];
	NSMutableArray *arr = [NSMutableArray arrayWithArray:[self snippets]];
	[arr addObject:[NSMutableDictionary dictionaryWithObjectsAndKeys:snippet, @"code", @"<title>", @"title", nil]];
	[self setSnippets:arr];	
}

-(IBAction)showWindow:(id)sender { [window makeKeyAndOrderFront:sender]; }

#pragma mark -
#pragma mark Delegate methods and notifications

-(void)appFinishedLaunching:(NSNotification *)notification
{
	[NSBundle loadNibNamed:@"Snippets" owner:self];
}

-(void)windowLostFocus:(NSNotification *)notification
{	// This method is a hack to make sure I can access the most recently used SEDocument when adding or inserting
	id doc = [[notification object] document];
	if (!doc) return;
	
	if ([doc isKindOfClass:[SEDocument class]])
		_lastDocument = doc;
}

-(void)windowWillClose:(NSNotification *)notification
{
	if (_lastDocument == nil) return;
	// Get rid of last doc when the window is closed lest we cause a segfault somewhere else
	if ([_lastDocument windowForSheet] == [notification object]) _lastDocument = nil; 
}

-(void)appWillTerminate:(NSNotification *)notification
{
	if ([window isKeyWindow]) [window makeFirstResponder:window]; // Save any changes to datasource
	[[NSUserDefaults standardUserDefaults] setObject:[SnippetsArrayController content] forKey:@"FCSSnippets"];
}

- (NSArray *)toolbarAllowedItemIdentifiers:(NSToolbar *)toolbar
{
	return [NSArray arrayWithObjects:@"add", @"remove", @"insert", NSToolbarFlexibleSpaceItemIdentifier, nil];
}

- (NSArray *)toolbarDefaultItemIdentifiers:(NSToolbar *)toolbar
{
	return [NSArray arrayWithObjects:@"add", @"remove", @"insert", NSToolbarFlexibleSpaceItemIdentifier, nil];
}


NSImage * fetchImage(NSString *name) {
	NSBundle *b = [NSBundle bundleWithIdentifier:@"com.fcs.CodeSnippets"];
	NSString *s = [b pathForResource:name ofType:@"pdf"];
	return [[[NSImage alloc] initByReferencingFile:s] autorelease];
};

- (NSToolbarItem *)toolbar:(NSToolbar *)toolbar itemForItemIdentifier:(NSString *)itemIdentifier 
 willBeInsertedIntoToolbar:(BOOL)flag
{
	NSToolbarItem *item = [[NSToolbarItem alloc] initWithItemIdentifier:itemIdentifier];
	
	NSWorkspace *ws = [NSWorkspace sharedWorkspace];
	NSString *pathToLibraryPluginResources = [[ws fullPathForApplication:@"Script Editor"] stringByAppendingString:@"/Contents/PlugIns/Library.seplugin/Contents/Resources/"];
	
	NSImage *img = nil;
	if ([itemIdentifier isEqualToString:@"add"])
	{
		[item setPaletteLabel:@"Add"];
		if (pathToLibraryPluginResources)
			img = [[[NSImage alloc] initByReferencingFile:[pathToLibraryPluginResources stringByAppendingPathComponent:@"SEPAddApplicationImage.tiff"]] autorelease];
		else img = fetchImage(@"plus");
		[item setAction:@selector(add:)];
	}
	else if ([itemIdentifier isEqualToString:@"remove"])
	{
		[item setPaletteLabel:@"Remove"];
		if (pathToLibraryPluginResources) 
			img = [[[NSImage alloc] initByReferencingFile:[pathToLibraryPluginResources stringByAppendingPathComponent:@"SEPRemoveApplicationImage.tiff"]] autorelease];
		else img = fetchImage(@"minus");
		[item setImage:img];
		[item setAction:@selector(delete:)];
	}
	else if ([itemIdentifier isEqualToString:@"insert"])
	{
		[item setPaletteLabel:@"Insert"];
		img = [ws iconForFileType:@"scpt"];
		[item setAction:@selector(insert:)];
	}
	[item setImage:img];;
	[item setTarget:self];

	return [item autorelease];
}

- (BOOL)validateUserInterfaceItem:(id <NSValidatedUserInterfaceItem>)anItem
{
	SEL action = [anItem action];
	
	if ( (((action == @selector(insert:) && _lastDocument != nil) ||
		   action == @selector(delete:)) ||
		   action == @selector(copy:)) &&
		   [[tableView selectedRowIndexes] count] == 0) return NO;
	else if (action == @selector(paste:))
		return [[[NSPasteboard generalPasteboard] types] containsObject:NSStringPboardType];
	
	return [self respondsToSelector:action];
}

@end
