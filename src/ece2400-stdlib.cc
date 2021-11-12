//========================================================================
// ece2400-stdlib.c
//========================================================================
// Utility functions to support memory and performance profiling.
//
// Note:
//
// DO NOT CHANGE THE FOLLOWING CODE!
//
// Author: Yanghui Ou, Peitian Pan
//   Date: Oct 13, 2020

#include "ece2400-stdlib.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sys/time.h>

//------------------------------------------------------------------------
// Global variables
//------------------------------------------------------------------------

/* Memory management and timing global variables */

size_t mem_usage  = 0;
size_t peak_usage = 0;

struct timeval start_time;
struct timeval end_time;

const double MILLION = 1000000.0;

/* ECE2400_CHECK_* global variables */

// Initial value of __n should be > 0 so that debug info is not suppressed
// in *-adhoc.c files.
int    __n                 = 1;
int    __failed            = 0;
int    __failure_condition = 0;
int    __int_expr0         = 0;
int    __int_expr1         = 0;
double __double_expr0      = 0.0;
double __double_expr1      = 0.0;

namespace ece2400 {

//------------------------------------------------------------------------
// distance_int
//------------------------------------------------------------------------
// Return the distance between the two given integers.

uint_t distance_int( int a, int b )
{
  if ( a > b )
    return a - b;
  else
    return b - a;
}

//------------------------------------------------------------------------
// print_array
//------------------------------------------------------------------------
// Prints the contents in an integer array.

void print_array( int* a, size_t size )
{
  if ( size > 0 )
    std::printf( "%d", a[0] );
  for ( size_t i = 1; i < size; i++ )
    std::printf( ", %d", a[i] );
  std::printf( "\n" );
}

//------------------------------------------------------------------------
// less_than
//------------------------------------------------------------------------
// Comparison function for qsort.

int less_than( const void* a_p, const void* b_p )
{
  int left  = *(const int*)a_p;
  int right = *(const int*)b_p;

  if ( left > 0 && right < 0 )
    return 1;
  else if ( left < 0 && right > 0 )
    return -1;
  else
    return left - right;
}

//------------------------------------------------------------------------
// sort
//------------------------------------------------------------------------
// A reference sorting function that sorts an array of integer in
// ascending order.

void sort( int* a, size_t size )
{
  std::qsort( (void*)a, size, sizeof( int ), less_than );
}

//------------------------------------------------------------------------
// mem_reset
//------------------------------------------------------------------------

void mem_reset()
{
  mem_usage  = 0;
  peak_usage = 0;
}

//------------------------------------------------------------------------
// mem_get_usage
//------------------------------------------------------------------------
// Return the amount of heap space that has been allocated so far in a
// program.

size_t mem_get_usage()
{
  return mem_usage;
}

//------------------------------------------------------------------------
// mem_get_peak
//------------------------------------------------------------------------
// Return the peak heap usage.

size_t mem_get_peak()
{
  return peak_usage;
}

//------------------------------------------------------------------------
// timer_reset
//------------------------------------------------------------------------
// Resets the timer.

void timer_reset()
{
  gettimeofday( &start_time, NULL );
}

//------------------------------------------------------------------------
// ece2400_timer_get_elapsed
//------------------------------------------------------------------------
//  Return the elapased time in seconds.

double timer_get_elapsed()
{
  gettimeofday( &end_time, NULL );
  double elapsed_time = ( end_time.tv_sec - start_time.tv_sec ) +
                        ( end_time.tv_usec - start_time.tv_usec ) / MILLION;
  return elapsed_time;
}

}

//************************************************************************
// DO NOT DIRECTLY CALL THE FUNCTIONS BELOW!
//************************************************************************
// The functions implemented below are helper functions that should only
// be called in ECE2400_CHECK_* macros.

//------------------------------------------------------------------------
// __ece2400_get_file_name
//------------------------------------------------------------------------
// Return file name extracted from a __FILE__ string.

const char* __ece2400_get_file_name( const char* full_path )
{
  int len = strlen( full_path ), start_pos = 0;

  for ( int i = len-1; i >= 0; i-- )
    if ( full_path[i] == '/' ) {
      start_pos = i+1;
      break;
    }

  return full_path + start_pos;
}

//------------------------------------------------------------------------
// __ece2400_fail
//------------------------------------------------------------------------

void __ece2400_fail( const char* file, int lineno, char *expr )
{
  file = __ece2400_get_file_name( file );
  if ( __n < 0 ) std::printf( "\n" );
  std::printf(" - [ " RED "FAILED" RESET " ] File %s:%d:  %s\n", file, lineno, expr );
  __failed = 1;
}

//------------------------------------------------------------------------
// __ece2400_check_and_print_uniop
//------------------------------------------------------------------------

void __ece2400_check_and_print_uniop( const char* file, int lineno, const char* expr )
{
  file = __ece2400_get_file_name( file );
  if ( __failure_condition ) {
    if ( __n < 0 ) std::printf( "\n" );
    std::printf(" - [ " RED "FAILED" RESET " ] File %s:%d:  %s (%d)\n", file, lineno, expr, __int_expr0 );
    __failed = 1;
  } else if ( __n > 0 ) {
    std::printf(" - [ " GREEN "passed" RESET " ] File %s:%d:  %s (%d)\n", file, lineno, expr, __int_expr0 );
  } else if ( __n < 0 ) {
    std::printf( GREEN "." RESET );
  }
}

//------------------------------------------------------------------------
// __ece2400_check_and_print_int_binop
//------------------------------------------------------------------------

void __ece2400_check_and_print_int_binop( const char* file, int lineno, const char* expr1, const char* expr2 )
{
  file = __ece2400_get_file_name( file );
  if ( __failure_condition ) {
    if ( __n < 0 ) std::printf( "\n" );
    std::printf(" - [ " RED "FAILED" RESET " ] File %s:%d:  %s != %s (%d != %d)\n",
           file, lineno, expr1, expr2, __int_expr0, __int_expr1 );
    __failed = 1;
  } else if ( __n > 0 ) {
    std::printf(" - [ " GREEN "passed" RESET " ] File %s:%d:  %s == %s (%d == %d)\n",
           file, lineno, expr1, expr2, __int_expr0, __int_expr1 );
  } else if ( __n < 0 ) {
    std::printf( GREEN "." RESET );
  }
}

//------------------------------------------------------------------------
// __ece2400_check_and_print_double_binop
//------------------------------------------------------------------------

void __ece2400_check_and_print_double_binop( const char* file, int lineno, const char* expr1, const char* expr2 )
{
  file = __ece2400_get_file_name( file );
  if ( __failure_condition ) {
    if ( __n < 0 ) std::printf( "\n" );
    std::printf(" - [ " RED "FAILED" RESET " ] File %s:%d:  %s != %s (%.10e != %.10e)\n",
           file, lineno, expr1, expr2, __double_expr0, __double_expr1 );
    __failed = 1;
  } else if ( __n > 0 ) {
    std::printf(" - [ " GREEN "passed" RESET " ] File %s:%d:  %s == %s (%.10e == %.10e)\n",
           file, lineno, expr1, expr2, __double_expr0, __double_expr1 );
  } else if ( __n < 0 ) {
    std::printf( GREEN "." RESET );
  }
}
