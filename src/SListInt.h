//========================================================================
// SListInt.h
//========================================================================
// Declarations for SListInt

#ifndef SLIST_INT_H
#define SLIST_INT_H

#include <cstddef>

class SListInt
{
  //----------------------------------------------------------------------
  // Constructor and destructor
  //----------------------------------------------------------------------

 public:

  SListInt();
  ~SListInt();

  //----------------------------------------------------------------------
  // Copy constructor and assignment operator
  //----------------------------------------------------------------------

 public:

  SListInt( const SListInt& lst );
  SListInt& operator=( const SListInt& lst );

  //----------------------------------------------------------------------
  // Member functions
  //----------------------------------------------------------------------

 public:

  void push_front( int v );
  int  at( size_t idx ) const;
  void reverse();
  void print() const;

  //----------------------------------------------------------------------
  // Private member functions and fields
  //----------------------------------------------------------------------

 private:

  struct Node                // nested struct declaration
  {
    int   value;
    Node* next_p;
  };

  Node* m_head_p;            // member field

};

//------------------------------------------------------------------------
// Include inline definitions
//------------------------------------------------------------------------

#include "SListInt.inl"

#endif /* SLIST_INT_H */

