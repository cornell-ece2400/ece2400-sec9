//========================================================================
// types-dpoly.cc
//========================================================================
// Definitions for misc types

#include "types-dpoly.h"
#include <cstdio>

//------------------------------------------------------------------------
// Overloaded operators
//------------------------------------------------------------------------

bool operator==( const IObject& lhs, const IObject& rhs )
{
  return lhs.eq(rhs);
}

bool operator<( const IObject& lhs, const IObject& rhs )
{
  return lhs.lt(rhs);
}

//------------------------------------------------------------------------
// Integer Constructors / Destructors
//------------------------------------------------------------------------

Integer::Integer()                   : m_data(0)        {}
Integer::Integer( int data )         : m_data(data)     {}
Integer::~Integer()                                     {}

//------------------------------------------------------------------------
// Integer::clone
//------------------------------------------------------------------------

Integer* Integer::clone() const
{
  return new Integer( *this );
}

//------------------------------------------------------------------------
// Integer::eq
//------------------------------------------------------------------------

bool Integer::eq( const IObject& rhs ) const
{
  const Integer* rhs_p = dynamic_cast<const Integer*>( &rhs );
  if ( rhs_p == nullptr ) return false;
  else                    return ( m_data == rhs_p->m_data );
}

//------------------------------------------------------------------------
// Integer::lt
//------------------------------------------------------------------------

bool Integer::lt( const IObject& rhs ) const
{
  const Integer* rhs_p = dynamic_cast<const Integer*>( &rhs );
  if ( rhs_p == nullptr ) return false;
  else                    return ( m_data < rhs_p->m_data );
}

//------------------------------------------------------------------------
// Integer::print
//------------------------------------------------------------------------

void Integer::print() const
{
  std::printf( "%d", m_data );
}

//------------------------------------------------------------------------
// Integer overloaded assignment operator
//------------------------------------------------------------------------

Integer& Integer::operator=( const IObject& rhs )
{
  const Integer* rhs_p = dynamic_cast<const Integer*>( &rhs );
  if ( rhs_p != nullptr )
    m_data = rhs_p->m_data;
  return *this;
}

//------------------------------------------------------------------------
// Double Constructors / Destructors
//------------------------------------------------------------------------

Double::Double()                  : m_data(0.0)      {}
Double::Double( double data     ) : m_data(data)     {}
Double::~Double()                                    {}

//------------------------------------------------------------------------
// Double::clone
//------------------------------------------------------------------------

Double* Double::clone() const
{
  return new Double( *this );
}

//------------------------------------------------------------------------
// Double::eq
//------------------------------------------------------------------------

bool Double::eq( const IObject& rhs ) const
{
  const Double* rhs_p = dynamic_cast<const Double*>( &rhs );
  if ( rhs_p == nullptr ) return false;
  else                    return ( m_data == rhs_p->m_data );
}

//------------------------------------------------------------------------
// Double::lt
//------------------------------------------------------------------------

bool Double::lt( const IObject& rhs ) const
{
  const Double* rhs_p = dynamic_cast<const Double*>( &rhs );
  if ( rhs_p == nullptr ) return false;
  else                    return ( m_data < rhs_p->m_data );
}

//------------------------------------------------------------------------
// Double::print
//------------------------------------------------------------------------

void Double::print() const
{
  std::printf( "%f", m_data );
}

//------------------------------------------------------------------------
// Double overloaded assignment operator
//------------------------------------------------------------------------

Double& Double::operator=( const IObject& rhs )
{
  printf("here\n");
  const Double* rhs_p = dynamic_cast<const Double*>( &rhs );
  if ( rhs_p != nullptr )
    m_data = rhs_p->m_data;
  return *this;
}

//------------------------------------------------------------------------
// Complex Constructors / Destructors
//------------------------------------------------------------------------

Complex::Complex()                           : m_real(0.0),  m_imag(0.0)  {}
Complex::Complex( double real, double imag ) : m_real(real), m_imag(imag) {}
Complex::~Complex()                                                       {}

//------------------------------------------------------------------------
// Complex::clone
//------------------------------------------------------------------------

Complex* Complex::clone() const
{
  return new Complex( *this );
}

//------------------------------------------------------------------------
// Complex::eq
//------------------------------------------------------------------------

bool Complex::eq( const IObject& rhs ) const
{
  const Complex* rhs_p = dynamic_cast<const Complex*>( &rhs );
  if ( rhs_p == nullptr )
    return false;
  else
    return ( m_real == rhs_p->m_real ) && ( m_imag == rhs_p->m_imag );
}

//------------------------------------------------------------------------
// Complex::lt
//------------------------------------------------------------------------

bool Complex::lt( const IObject& rhs ) const
{
  const Complex* rhs_p = dynamic_cast<const Complex*>( &rhs );
  if ( rhs_p == nullptr )
    return false;
  else
    return ( m_real < rhs_p->m_real ) && ( m_imag < rhs_p->m_imag );
}


//------------------------------------------------------------------------
// Complex::print
//------------------------------------------------------------------------

void Complex::print() const
{
  std::printf( "%f + %fi", m_real, m_imag );
}

//------------------------------------------------------------------------
// Complex overloaded assignment operator
//------------------------------------------------------------------------

Complex& Complex::operator=( const IObject& rhs )
{
  const Complex* rhs_p = dynamic_cast<const Complex*>( &rhs );
  if ( rhs_p != nullptr ) {
    m_real = rhs_p->m_real;
    m_imag = rhs_p->m_imag;
  }
  return *this;
}

