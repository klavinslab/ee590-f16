#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "matrix.h"

Matrix * matrix_new ( int rows, int columns ) {

  Matrix * M = malloc( sizeof ( Matrix ));
  M->rows = rows;
  M->columns = columns;
  M->value = (double *) malloc ( rows * columns * sizeof( double ) );

  return M;

}

void matrix_destroy ( Matrix * M ) {
  free ( M );
}

double matrix_get ( Matrix * M, int row, int column ) {
  ASSERT ( 0 <= row && row < M->rows && 0 <= column && column < M->columns );
  return M->value[row + column * M->columns];
}

void matrix_set ( Matrix * M, int row, int column, double value ) {
  ASSERT ( 0 <= row && row < M->rows && 0 <= column && column < M->columns );
  M->value[row + column * M->columns] = value;
}

void matrix_print ( Matrix * M ) {

  for ( int i=0; i<M->rows; i++ ) {
    for ( int j=0; j<M->columns; j++ ) {
      printf ( "%lf\t", matrix_get ( M, i, j ) );
    }
    printf("\n" );
  }

}

Matrix * matrix_random ( int rows, int columns ) {

  Matrix * M = matrix_new(rows,columns);

  time_t t;
  srand((unsigned) time(&t));

  for ( int i=0; i<M->rows; i++ ) {
    for ( int j=0; j<M->columns; j++ ) {
      matrix_set ( M, i, j, rand()%3 - 1 );
    }
  }

  return M;

}
