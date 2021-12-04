//========================================================================
// types-dpoly-directed-test.cc
//========================================================================
// This file contains directed tests for DPoly types

#include "types-dpoly.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// test_case_1_integer
//------------------------------------------------------------------------
// A simple test case for integers

void test_case_1_integer()
{
  std::printf( "\n%s\n", __func__ );

  Integer a(42);
  Integer b(42);
  ECE2400_CHECK_TRUE( a == b );
}

//------------------------------------------------------------------------
// test_case_2_integer_lt
//------------------------------------------------------------------------
// A simple test case for integer less than operator

void test_case_2_integer_lt()
{
  std::printf( "\n%s\n", __func__ );

  Integer a(42);
  Integer b(84);
  ECE2400_CHECK_TRUE( a < b );
}

//------------------------------------------------------------------------
// test_case_3_integer_clone
//------------------------------------------------------------------------
// A simple test case for integer clone

void test_case_3_integer_clone()
{
  std::printf( "\n%s\n", __func__ );

  Integer  a(42);
  Integer* a_p = a.clone();
  ECE2400_CHECK_TRUE( a == *(a_p) );

  Integer  b(13);
  IObject* b0_obj_p = &b;
  IObject* b1_obj_p = b0_obj_p->clone();
  ECE2400_CHECK_TRUE( b == *(b0_obj_p) );
}

//------------------------------------------------------------------------
// test_case_4_integer_copy
//------------------------------------------------------------------------
// A simple test case for integer copy

void test_case_4_integer_copy()
{
  std::printf( "\n%s\n", __func__ );

  Integer a(42);
  Integer b = a;
  ECE2400_CHECK_TRUE( a == b );
}

//------------------------------------------------------------------------
// test_case_5_double
//------------------------------------------------------------------------
// A simple test case for doubles

void test_case_5_double()
{
  std::printf( "\n%s\n", __func__ );

  Double a(4.2);
  Double b(4.2);
  ECE2400_CHECK_TRUE( a == b );
}

//------------------------------------------------------------------------
// test_case_6_double_lt
//------------------------------------------------------------------------
// A simple test case for double less than operator

void test_case_6_double_lt()
{
  std::printf( "\n%s\n", __func__ );

  Double a(4.2);
  Double b(8.4);
  ECE2400_CHECK_TRUE( a < b );
}

//------------------------------------------------------------------------
// test_case_7_double_clone
//------------------------------------------------------------------------
// A simple test case for double clone

void test_case_7_double_clone()
{
  std::printf( "\n%s\n", __func__ );

  Double  a(4.2);
  Double* a_p = a.clone();
  ECE2400_CHECK_TRUE( a == *(a_p) );

  Double  b(1.3);
  IObject* b0_obj_p = &b;
  IObject* b1_obj_p = b0_obj_p->clone();
  ECE2400_CHECK_TRUE( b == *(b0_obj_p) );
}

//------------------------------------------------------------------------
// test_case_8_double_copy
//------------------------------------------------------------------------
// A simple test case for double copy

void test_case_8_double_copy()
{
  std::printf( "\n%s\n", __func__ );

  Double a(4.2);
  Double b = a;
  ECE2400_CHECK_TRUE( a == b );
}

//------------------------------------------------------------------------
// test_case_9_complex
//------------------------------------------------------------------------
// A simple test case for complexs

void test_case_9_complex()
{
  std::printf( "\n%s\n", __func__ );

  Complex a(4.2,1.3);
  Complex b(4.2,1.3);
  ECE2400_CHECK_TRUE( a == b );
}

//------------------------------------------------------------------------
// test_case_10_complex_lt
//------------------------------------------------------------------------
// A simple test case for complex less than operator

void test_case_10_complex_lt()
{
  std::printf( "\n%s\n", __func__ );

  Complex a(4.2,1.3);
  Complex b(8.4,2.6);
  ECE2400_CHECK_TRUE( a < b );
}

//------------------------------------------------------------------------
// test_case_11_complex_clone
//------------------------------------------------------------------------
// A simple test case for complex clone

void test_case_11_complex_clone()
{
  std::printf( "\n%s\n", __func__ );

  Complex  a(4.2,1.3);
  Complex* a_p = a.clone();
  ECE2400_CHECK_TRUE( a == *(a_p) );

  Complex  b(1.3,4.2);
  IObject* b0_obj_p = &b;
  IObject* b1_obj_p = b0_obj_p->clone();
  ECE2400_CHECK_TRUE( b == *(b0_obj_p) );
}

//------------------------------------------------------------------------
// test_case_12_complex_copy
//------------------------------------------------------------------------
// A simple test case for complex copy

void test_case_12_complex_copy()
{
  std::printf( "\n%s\n", __func__ );

  Complex a(4.2,1.3);
  Complex b = a;
  ECE2400_CHECK_TRUE( a == b );
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n <= 0 ) || ( __n == 1  ) ) test_case_1_integer();
  if ( ( __n <= 0 ) || ( __n == 2  ) ) test_case_2_integer_lt();
  if ( ( __n <= 0 ) || ( __n == 3  ) ) test_case_3_integer_clone();
  if ( ( __n <= 0 ) || ( __n == 4  ) ) test_case_4_integer_copy();

  if ( ( __n <= 0 ) || ( __n == 5  ) ) test_case_5_double();
  if ( ( __n <= 0 ) || ( __n == 6  ) ) test_case_6_double_lt();
  if ( ( __n <= 0 ) || ( __n == 7  ) ) test_case_7_double_clone();
  if ( ( __n <= 0 ) || ( __n == 8  ) ) test_case_8_double_copy();

  if ( ( __n <= 0 ) || ( __n == 9  ) ) test_case_9_complex();
  if ( ( __n <= 0 ) || ( __n == 10 ) ) test_case_10_complex_lt();
  if ( ( __n <= 0 ) || ( __n == 11 ) ) test_case_11_complex_clone();
  if ( ( __n <= 0 ) || ( __n == 12 ) ) test_case_12_complex_copy();

  return 0;
}
