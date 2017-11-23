#import "node.h"

@implementation node

-(instancetype) init{
  self = [super init];
    if (self) {
      self.next = nil;
    }
  return self;
}

-(instancetype) initVal: (int) x{
  self = [super init];
    if (self) {
      self.value = x;
      self.next = nil;
    }
  return self;
}

@end
