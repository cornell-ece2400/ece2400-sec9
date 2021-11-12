//========================================================================
// types-dpoly.h
//========================================================================
// Declarations for misc types

#ifndef TYPES_DPOLY_H
#define TYPES_DPOLY_H

#include <iostream>

//------------------------------------------------------------------------
// IObject
//------------------------------------------------------------------------

class IObject
{
 public:
  virtual ~IObject(){};
  virtual IObject* clone()                  const = 0;
  virtual bool     eq( const IObject& rhs ) const = 0;
  virtual bool     lt( const IObject& rhs ) const = 0;
  virtual void     print()                  const = 0;
  virtual IObject& operator=( const IObject& rhs ) = 0;
};

bool operator==( const IObject& lhs, const IObject& rhs );
bool operator< ( const IObject& lhs, const IObject& rhs );

//------------------------------------------------------------------------
// Integer
//------------------------------------------------------------------------

class Integer : public IObject
{
 public:
  Integer();
  Integer( int data );
  ~Integer();

  Integer* clone()                  const;
  bool     eq( const IObject& rhs ) const;
  bool     lt( const IObject& rhs ) const;
  void     print()                  const;

  Integer& operator=( const IObject& rhs );

 private:
  int m_data;
};

//------------------------------------------------------------------------
// Double
//------------------------------------------------------------------------

class Double : public IObject
{
 public:
  Double();
  Double( double data     );
  ~Double();

  Double& operator=( const IObject& rhs );

  Double*  clone()                  const;
  bool     eq( const IObject& rhs ) const;
  bool     lt( const IObject& rhs ) const;
  void     print()                  const;

 private:
  double m_data;
};


//------------------------------------------------------------------------
// Complex
//------------------------------------------------------------------------

class Complex : public IObject
{
 public:
  Complex();
  Complex( double real, double imag );
  ~Complex();

  Complex& operator=( const IObject& rhs );

  Complex* clone()                  const;
  bool     eq( const IObject& rhs ) const;
  bool     lt( const IObject& rhs ) const;
  void     print()                  const;

 private:
  double m_real;
  double m_imag;
};

#endif // TYPES_DPOLY_H

