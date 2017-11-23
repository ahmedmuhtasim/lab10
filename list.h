#import <Foundation/NSObject.h>
#import <stdio.h>
#import "node.h"

@interface list : NSObject

@property node* head;

@property node* tail;

-(void) insert: (int) x;
-(void) print;
-(void) delete;

@end
