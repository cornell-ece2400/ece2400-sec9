//========================================================================
// SListInt.h
//========================================================================
// Declarations for SListInt

#ifndef SLIST_INT_H
#define SLIST_INT_H

class SListInt
{
  //----------------------------------------------------------------------
  // Constructor and destructor
  //----------------------------------------------------------------------

 public:

  SListInt();
  ~SListInt();

  //----------------------------------------------------------------------
  // Copy constructor, swap, assignment operator
  //----------------------------------------------------------------------

 public:

  SListInt( const SListInt& lst );
  void swap( SListInt& lst );
  SListInt& operator=( const SListInt& lst );

  //----------------------------------------------------------------------
  // Member functions
  //----------------------------------------------------------------------

 public:

  void push_front( int v );
  int  size() const;
  int  at( int idx ) const;
  int& at( int idx );
  void reverse_v1();
  void reverse_v2();
  void print() const;

  //----------------------------------------------------------------------
  // Private member functions and fields
  //----------------------------------------------------------------------

 private:

  struct Node
  {
    int   value;
    Node* next_p;
  };

  Node* m_head_p;

};

#endif /* SLIST_INT_H */

