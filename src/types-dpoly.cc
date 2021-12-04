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
// Integer
//------------------------------------------------------------------------

Integer::Integer()
{
  m_data = 0;
}

Integer::Integer( int data )
{
  m_data = data;
}

Integer* Integer::clone() const
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement clone
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  return new Integer( *this );
}

bool Integer::eq( const IObject& rhs ) const
{
  const Integer* rhs_p = dynamic_cast<const Integer*>( &rhs );
  if ( rhs_p == nullptr ) return false;
  else                    return ( m_data == rhs_p->m_data );
}

bool Integer::lt( const IObject& rhs ) const
{
  const Integer* rhs_p = dynamic_cast<const Integer*>( &rhs );
  if ( rhs_p == nullptr ) return false;
  else                    return ( m_data < rhs_p->m_data );
}

void Integer::print() const
{
  std::printf( "%d", m_data );
}

//------------------------------------------------------------------------
// Double
//------------------------------------------------------------------------

Double::Double()
{
  m_data = 0.0;
}

Double::Double( double data )
{
  m_data = data;
}

Double* Double::clone() const
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement clone
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  return new Double( *this );
}

bool Double::eq( const IObject& rhs ) const
{
  const Double* rhs_p = dynamic_cast<const Double*>( &rhs );
  if ( rhs_p == nullptr ) return false;
  else                    return ( m_data == rhs_p->m_data );
}

bool Double::lt( const IObject& rhs ) const
{
  const Double* rhs_p = dynamic_cast<const Double*>( &rhs );
  if ( rhs_p == nullptr ) return false;
  else                    return ( m_data < rhs_p->m_data );
}

void Double::print() const
{
  std::printf( "%f", m_data );
}

//------------------------------------------------------------------------
// Complex
//------------------------------------------------------------------------

Complex::Complex()
{
  m_real = 0.0;
  m_imag = 0.0;
}

Complex::Complex( double real, double imag )
{
  m_real = real;
  m_imag = imag;
}

Complex* Complex::clone() const
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement clone
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  return new Complex( *this );
}

bool Complex::eq( const IObject& rhs ) const
{
  const Complex* rhs_p = dynamic_cast<const Complex*>( &rhs );
  if ( rhs_p == nullptr )
    return false;
  else
    return ( m_real == rhs_p->m_real ) && ( m_imag == rhs_p->m_imag );
}

bool Complex::lt( const IObject& rhs ) const
{
  const Complex* rhs_p = dynamic_cast<const Complex*>( &rhs );
  if ( rhs_p == nullptr )
    return false;
  else
    return ( m_real < rhs_p->m_real ) && ( m_imag < rhs_p->m_imag );
}

void Complex::print() const
{
  std::printf( "%f+%fi", m_real, m_imag );
}

