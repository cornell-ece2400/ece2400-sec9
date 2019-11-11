//========================================================================
// SListIObj.h
//========================================================================
// Declarations for SListIObj

#ifndef SLIST_IOBJ_H
#define SLIST_IOBJ_H

#include "types-dpoly.h"
#include <cstddef>

class SListIObj
{
  //----------------------------------------------------------------------
  // Constructor and destructor
  //----------------------------------------------------------------------

 public:

  SListIObj();
  ~SListIObj();

  //----------------------------------------------------------------------
  // Copy constructor and assignment operator
  //----------------------------------------------------------------------

 public:

  SListIObj( const SListIObj& lst );
  SListIObj& operator=( const SListIObj& lst );

  //----------------------------------------------------------------------
  // Member functions
  //----------------------------------------------------------------------

 public:

  void           push_front( const IObject& v );
  const IObject& at( size_t idx ) const;
  void           reverse();
  void           print() const;

  //----------------------------------------------------------------------
  // Private member functions and fields
  //----------------------------------------------------------------------

 private:

  struct Node                // nested struct declaration
  {
    IObject* obj_p;
    Node*    next_p;
  };

  Node* m_head_p;            // member field

};

//------------------------------------------------------------------------
// Include inline definitions
//------------------------------------------------------------------------

#include "SListIObj.inl"

#endif /* SLIST_IOBJ_H */

