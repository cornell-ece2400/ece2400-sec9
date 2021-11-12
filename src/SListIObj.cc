//========================================================================
// SListIObj.cc
//========================================================================
// Implementation for ListIObj

#include <cstdio>
#include "SListIObj.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// SListIObj Default Constructor
//------------------------------------------------------------------------

SListIObj::SListIObj()
{
  m_head_p = nullptr;
}

//------------------------------------------------------------------------
// SListIObj Destructor
//------------------------------------------------------------------------

SListIObj::~SListIObj()
{
  while ( m_head_p != nullptr ) {
    Node* temp_p = m_head_p->next_p;

    //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''
    // Delete the node
    //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

    m_head_p = temp_p;
  }
}

//------------------------------------------------------------------------
// SListIObj Copy Constructor
//------------------------------------------------------------------------

SListIObj::SListIObj( const SListIObj& lst )
{
  // We must make sure head pointer is initialized correctly, otherwise
  // push_front will not work correctly.

  m_head_p = nullptr;

  // Iterate through each element of the given lst and use push_front to
  // add it to this list.

  Node* curr_p = lst.m_head_p;
  while ( curr_p != nullptr ) {
    push_front( *curr_p->obj_p );
    curr_p = curr_p->next_p;
  }

  // We now have all elements in this list, but they are in the reverse
  // order, so we can call reverse to ensure that this list is an exact
  // copy of the given list.

  reverse_v1();
}

//------------------------------------------------------------------------
// SListIObj Overloaded Assignment Operator
//------------------------------------------------------------------------

SListIObj& SListIObj::operator=( const SListIObj& lst )
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Handle self-assignment correctly!
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  // Delete all nodes in this list.

  while ( m_head_p != nullptr ) {
    Node* temp_p = m_head_p->next_p;
    delete m_head_p->obj_p;
    delete m_head_p;
    m_head_p = temp_p;
  }

  // Iterate through each element of the given lst and use push_front
  // to add it to this list.

  Node* curr_p = lst.m_head_p;
  while ( curr_p != nullptr ) {
    push_front( *curr_p->obj_p );
    curr_p = curr_p->next_p;
  }

  // We now have all elements in this list, but they are in the reverse
  // order, so we can call reverse to ensure that this list is an exact
  // copy of the given list.

  reverse_v1();

  return *this;
}

//------------------------------------------------------------------------
// SListIObj::push_front
//------------------------------------------------------------------------

void SListIObj::push_front( const IObject& v )
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement push_front
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
}

//------------------------------------------------------------------------
// SListIObj::size
//------------------------------------------------------------------------

int SListIObj::size() const
{
  int   size   = 0;
  Node* curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    size++;
    curr_p = curr_p->next_p;
  }

  return size;
}

//------------------------------------------------------------------------
// SListIObj::at
//------------------------------------------------------------------------

IObject* SListIObj::at( int idx ) const
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement at
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  return nullptr;
}

//------------------------------------------------------------------------
// SListIObj::reverse_v1
//------------------------------------------------------------------------
// Pseudocode for this algorithm:
//
//  def reverse( x, n ):
//    for i in 0 to n/2:
//      lo = i
//      hi = (n-1) - i
//      swap( x[lo], x[hi] )
//

void SListIObj::reverse_v1()
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement reverse_v1
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
}

//------------------------------------------------------------------------
// SListIObj::reverse_v2
//------------------------------------------------------------------------
// Steps for this algorithm:
//
//  1. Use the size member function to find number items in list
//  2. Allocate a new array of integers on the heap with size items
//  3. Iterate through list and copy each item to the array
//  4. Iterate through list and copy each item from array in reverse order
//  5. Delete temporary array
//

void SListIObj::reverse_v2()
{
  // 1. Get the number of items in list

  int n = size();

  // 2. Allocate a new array of IObject pointers on the heap with size items

  IObject** tmp = new IObject*[n];

  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement step 3
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  // 4. Iterate through list and copy each item from array in reverse

  int   idx1    = 0;
  Node* curr1_p = m_head_p;
  while ( curr1_p != nullptr ) {
    curr1_p->obj_p = tmp[n-idx1-1];
    curr1_p        = curr1_p->next_p;
    idx1++;
  }

  // 5. Delete the temporary array

  delete[] tmp;
}

//------------------------------------------------------------------------
// SListIObj::print
//------------------------------------------------------------------------

void SListIObj::print() const
{
  Node* curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    curr_p->obj_p->print();
    printf(" ");
    curr_p = curr_p->next_p;
  }
  printf("\n");
}

