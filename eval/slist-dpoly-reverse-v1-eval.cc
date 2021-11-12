//========================================================================
// slist-dpoly-reverse-v1-eval.cc
//========================================================================
// This program evalutes the performance of SListIObj::push_front and
// SListIObj::reverse by running multiple trials and averaging the elapsed
// run times.
//

#include <stdio.h>
#include <stdlib.h>
#include "SListIObj.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// print_help
//------------------------------------------------------------------------
// Helper function to print the help message.

void print_help()
{
  printf(
    "usage: ./slist-int-reverse-v1-eval <size>\n\n"
    "Evaluation program for SListIObj::push_front and SListIObj::reverse_v1\n\n"
    "positional arguments:\n"
    "  size   Size of the input array. It has to be within (0, 50000].\n"
  );
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  int size;

  // Check command line arguments

  if ( argc != 2 ) {
    printf("Invalid command line arguments!\n\n");
    print_help();
    return 1;
  }
  else {
    size = atoi( argv[1] );

    // Check size
    if ( size < 1 || size > 50000 ) {
      printf("Invalid size: %d\n\n", size );
      print_help();
      return 1;
    }
  }

  // We first try a single trial and verify the result before running the
  // actual experiment.

  SListIObj lst_verify;
  for ( int i = 0; i < size; i++ )
    lst_verify.push_front( Integer(i) );

  // Reverse list

  lst_verify.reverse_v1();

  int ref = 0;
  for ( int i = 0; i < size; i++ ) {
    if ( !(*lst_verify.at(i) == Integer(ref) ) ) {
      printf( "Error: List not reversed correctly!\n" );
      return 1;
    }
    ref += 1;
  }

  printf("Verfication passed\n");

  // Run many trials so we can average the run times. Within each trial,
  // run enough subtrials so as to avoid precision issues with
  // gettimeofday().

  const int ntrials    = 5;
  const int nsubtrials = 1001;

  double elapsed;
  double elapsed_total = 0.0;

  printf( "Fill and reverse with size %d\n", size );

  // Timing loop

  for ( int i = 0; i < ntrials; i++ ) {

    // Start tracking time

    ece2400::timer_reset();

    // Execute nsubtrails

    for ( int j = 0; j < nsubtrials; j++ ) {

      // Fill list with decreasing values

      SListIObj lst;
      for ( int i = 0; i < size; i++ )
        lst.push_front( Integer(i) );

      // Reverse list

      lst.reverse_v1();
    }

    // Stop tracking time

    elapsed = ece2400::timer_get_elapsed();

    // Accumulate result

    elapsed_total += elapsed;

    printf( "Trial %d: elapsed time = %f second\n", i, elapsed );
  }

  // Calculate average elapsed time and peak heap usage

  double elapsed_avg = elapsed_total / ntrials;

  printf( "Average: elapsed time = %f second\n", elapsed_avg );

  return 0;
}
