//========================================================================
// SListIObj.cc
//========================================================================
// Implementation for SListIObj

#include "SListIObj.h"
#include <cstdio>

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

    delete m_head_p->obj_p;
    delete m_head_p;

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
// SListIObj Swap
//------------------------------------------------------------------------

void SListIObj::swap( SListIObj& lst )
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement swap
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  Node* tmp_p  = m_head_p;
  m_head_p     = lst.m_head_p;
  lst.m_head_p = tmp_p;
}

//------------------------------------------------------------------------
// SListIObj Overloaded Assignment Operator
//------------------------------------------------------------------------

SListIObj& SListIObj::operator=( const SListIObj& lst )
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement operator=
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  SListIObj tmp( lst ); // create temporary copy of given list
  swap( tmp );          // swap this list with temporary list
  return *this;         // destructor called for temporary list
}

//------------------------------------------------------------------------
// SListIObj::push_front
//------------------------------------------------------------------------

void SListIObj::push_front( const IObject& v )
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement push_front
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  Node* new_node_p   = new Node;
  new_node_p->obj_p  = v.clone();
  new_node_p->next_p = m_head_p;
  m_head_p           = new_node_p;
}

//------------------------------------------------------------------------
// SListIObj::size
//------------------------------------------------------------------------

int SListIObj::size() const
{
  int n = 0;

  Node* curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    n++;
    curr_p = curr_p->next_p;
  }

  return n;
}

//------------------------------------------------------------------------
// SListIObj::at
//------------------------------------------------------------------------

IObject* SListIObj::at( int idx ) const
{
  Node* curr_p = m_head_p;
  for ( int i = 0; i < idx; i++ )
    curr_p = curr_p->next_p;

  return curr_p->obj_p;
}

//------------------------------------------------------------------------
// SListIObj::at
//------------------------------------------------------------------------

IObject*& SListIObj::at( int idx )
{
  Node* curr_p = m_head_p;
  for ( int i = 0; i < idx; i++ )
    curr_p = curr_p->next_p;

  return curr_p->obj_p;
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

  int n = size();
  for ( int i = 0; i < n/2; i++ ) {
    int lo = i;
    int hi = (n-1)-i;

    IObject* tmp = at(lo);
    at(lo)       = at(hi);
    at(hi)       = tmp;
  }
}

//------------------------------------------------------------------------
// SListIObj::reverse_v2
//------------------------------------------------------------------------
// Steps for this algorithm:
//
//  1. Create temporary singly linked list
//  2. Push front all values from this list onto temporary list
//  3. Swap this list with the temporary list
//

void SListIObj::reverse_v2()
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement reverse_v2
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  // Step 1. Create temporary list
  SListIObj lst;

  // Step 2. Push front all values from this list onto temporary list
  Node* curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    lst.push_front( *(curr_p->obj_p) );
    curr_p = curr_p->next_p;
  }

  // Step 3. Swap this list with temporary list
  swap( lst );
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

