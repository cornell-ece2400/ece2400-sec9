//========================================================================
// slist-iobj-adhoc.c
//========================================================================

#include "SListIObj.h"

int main( void )
{
  // Construct a list using default constructor

  SListIObj list;

  // Push front three items

  list.push_front( Integer(12) );
  list.push_front( Integer(11) );
  list.push_front( Integer(10) );

  // Push front three items of a different type

  list.push_front( Double(1.2) );
  list.push_front( Double(1.1) );
  list.push_front( Double(1.0) );

  // Print the list

  list.print();

  return 0;
}

