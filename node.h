#import <Foundation/NSObject.h>

@interface node : NSObject

@property int value;

@property node* next;

-(instancetype) initVal: (int) x;

@end
