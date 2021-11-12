//========================================================================
// SListInt.cc
//========================================================================
// Implementation for ListInt

#include <cstdio>
#include <cassert>
#include "SListInt.h"

//------------------------------------------------------------------------
// SListInt Default Constructor
//------------------------------------------------------------------------

SListInt::SListInt()
{
  m_head_p = nullptr;
}

//------------------------------------------------------------------------
// SListInt Destructor
//------------------------------------------------------------------------

SListInt::~SListInt()
{
  while ( m_head_p != nullptr ) {
    Node* temp_p = m_head_p->next_p;
    delete m_head_p;
    m_head_p = temp_p;
  }
}

//------------------------------------------------------------------------
// SListInt Copy Constructor
//------------------------------------------------------------------------

SListInt::SListInt( const SListInt& lst )
{
  // We must make sure head pointer is initialized correctly, otherwise
  // push_front will not work correctly.

  m_head_p = nullptr;

  // Iterate through each element of the given lst and use push_front to
  // add it to this list.

  Node* curr_p = lst.m_head_p;
  while ( curr_p != nullptr ) {
    push_front( curr_p->value );
    curr_p = curr_p->next_p;
  }

  // We now have all elements in this list, but they are in the reverse
  // order, so we can call reverse to ensure that this list is an exact
  // copy of the given list.

  reverse_v1();
}

//------------------------------------------------------------------------
// SListInt Overloaded Assignment Operator
//------------------------------------------------------------------------

SListInt& SListInt::operator=( const SListInt& lst )
{
  // Handle self-assignment correctly!

  if ( this == &lst )
    return *this;

  // Delete all nodes in this list.

  while ( m_head_p != nullptr ) {
    Node* temp_p = m_head_p->next_p;
    delete m_head_p;
    m_head_p = temp_p;
  }

  // Iterate through each element of the given lst and use push_front
  // to add it to this list.

  Node* curr_p = lst.m_head_p;
  while ( curr_p != nullptr ) {
    push_front( curr_p->value );
    curr_p = curr_p->next_p;
  }

  // We now have all elements in this list, but they are in the reverse
  // order, so we can call reverse to ensure that this list is an exact
  // copy of the given list.

  reverse_v1();

  return *this;
}

//------------------------------------------------------------------------
// SListInt::push_front
//------------------------------------------------------------------------

void SListInt::push_front( int v )
{
  Node* new_node_p   = new Node;
  new_node_p->value  = v;
  new_node_p->next_p = m_head_p;
  m_head_p           = new_node_p;
}

//------------------------------------------------------------------------
// SListInt::size
//------------------------------------------------------------------------

int SListInt::size() const
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
// SListInt::at
//------------------------------------------------------------------------

int* SListInt::at( int idx ) const
{
  Node* curr_p = m_head_p;
  for ( int i = 0; i < idx; i++ )
    curr_p = curr_p->next_p;

  return &curr_p->value;
}

//------------------------------------------------------------------------
// SListInt::reverse_v1
//------------------------------------------------------------------------

void SListInt::reverse_v1()
{
  int n = size();

  for ( int i = 0; i < n/2; i++ ) {
    int lo = i;
    int hi = (n-1) - i;

    // swap lo and hi elements
    int tmp = *at(lo);
    *at(lo) = *at(hi);
    *at(hi) = tmp;
  }
}

//------------------------------------------------------------------------
// SListInt::reverse_v2
//------------------------------------------------------------------------

void SListInt::reverse_v2()
{
  // 1. Get the number of items in list

  int n = size();

  // 2. Allocate a new array of integers on the heap with size items

  int* tmp = new int[n];

  // 3. Iterate through the list and copy each item to the array

  int idx = 0;
  Node* curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    tmp[idx] = curr_p->value;
    curr_p   = curr_p->next_p;
    idx++;
  }

  // 4. Iterate through list and copy each item from array in reverse

  idx    = 0;
  curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    curr_p->value = tmp[n-idx-1];
    curr_p        = curr_p->next_p;
    idx++;
  }

  // 5. Delete the temporary array

  delete[] tmp;
}

//------------------------------------------------------------------------
// SListInt::print
//------------------------------------------------------------------------

void SListInt::print() const
{
  Node* curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    std::printf( "%d ", curr_p->value );
    curr_p = curr_p->next_p;
  }
  std::printf( "\n" );
}

