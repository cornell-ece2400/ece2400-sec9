//========================================================================
// SListIObj.cc
//========================================================================
// Implementation for ListIObj

#include <cstdio>
#include <cassert>
#include "SListIObj.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// SListIObj Default Constructor
//------------------------------------------------------------------------

SListIObj::SListIObj()
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement constructor
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  m_head_p = nullptr;
}

//------------------------------------------------------------------------
// SListIObj Destructor
//------------------------------------------------------------------------

SListIObj::~SListIObj()
{
  clear();
}

//------------------------------------------------------------------------
// SListIObj Copy Constructor
//------------------------------------------------------------------------

SListIObj::SListIObj( const SListIObj& lst )
{
  m_head_p = nullptr;
  copy(lst);
}

//------------------------------------------------------------------------
// SListIObj Overloaded Assignment Operator
//------------------------------------------------------------------------

SListIObj& SListIObj::operator=( const SListIObj& lst )
{
  clear();
  copy(lst);
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
  Node* new_node_p   = new Node;
  new_node_p->obj_p  = v.clone();
  new_node_p->next_p = m_head_p;
  m_head_p           = new_node_p;
}

//------------------------------------------------------------------------
// SListIObj::at
//------------------------------------------------------------------------

const IObject& SListIObj::at( size_t idx ) const
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement at
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  Node*  curr_p   = m_head_p;
  size_t curr_idx = 0;

  while ( curr_p != nullptr ) {
    if ( curr_idx == idx )
      return *(curr_p->obj_p);
    curr_idx += 1;
    curr_p   = curr_p->next_p;
  }

  throw ece2400::OutOfRange( "VectorIObj::at: index out of bound!" );
}

//------------------------------------------------------------------------
// SListIObj::reverse
//------------------------------------------------------------------------

void SListIObj::reverse()
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement reverse
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  size_t size   = 0;
  Node*  curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    size   += 1;
    curr_p = curr_p->next_p;
  }

  IObject** tmp = new IObject*[size];

  size_t i = 0;
  curr_p   = m_head_p;
  while ( curr_p != nullptr ) {
    tmp[i++] = curr_p->obj_p;
    curr_p = curr_p->next_p;
  }

  size_t j = size-1;
  curr_p   = m_head_p;
  while ( curr_p != nullptr ) {
    curr_p->obj_p = tmp[j--];
    curr_p = curr_p->next_p;
  }

  delete[] tmp;
}

//------------------------------------------------------------------------
// SListIObj::print
//------------------------------------------------------------------------

void SListIObj::print() const
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement print
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  Node* curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    curr_p->obj_p->print();
    std::printf( " " );
    curr_p = curr_p->next_p;
  }
  std::printf( "\n" );
}

//------------------------------------------------------------------------
// SListIObj::copy
//------------------------------------------------------------------------

void SListIObj::copy( const SListIObj& lst )
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement copy
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  Node* curr_p = lst.m_head_p;
  while ( curr_p != nullptr ) {
    push_front( *(curr_p->obj_p) );
    curr_p = curr_p->next_p;
  }
  reverse();
}

//------------------------------------------------------------------------
// SListIObj::clear
//------------------------------------------------------------------------

void SListIObj::clear()
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement clear
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  while ( m_head_p != nullptr ) {
    Node* temp_p = m_head_p->next_p;
    delete m_head_p->obj_p;
    delete m_head_p;
    m_head_p = temp_p;
  }
}

