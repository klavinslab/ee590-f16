#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix * matrix_add ( Matrix * A, Matrix * B ) {

  ASSERT ( A->rows == B->rows && A->columns == B->columns );

  Matrix * C = matrix_new ( A->rows, A->columns );

  for ( int i=0; i<A->rows; i++ ) {
    for ( int j=0; j<A->columns; j++ ) {
      matrix_set(C, i, j, matrix_get(A,i,j) + matrix_get(B,i,j) );
    }
  }

  return C;

}

Matrix * matrix_minor ( Matrix * M, int n ) {

  ASSERT ( 0 <= n && n < M->columns );

  Matrix * P = matrix_new ( M->rows - 1, M->columns - 1 );

  for ( int i=1; i<M->rows; i++ ) {
    for ( int j=0; j<n; j++ ) {
      matrix_set(P,i-1,j,matrix_get(M,i,j));
    }
  }

  for ( int i=1; i<M->rows; i++ ) {
    for ( int j=n+1; j<M->columns; j++ ) {
      matrix_set(P,i-1,j-1,matrix_get(M,i,j));
    }
  }

  return P;

}

double matrix_det ( Matrix * M ) {

  if ( M->rows == 1 && M->columns == 1 ) {

    return matrix_get(M,0,0);

  } else {

    double sign = 1,
           sum = 0;

    for ( int i=0; i<M->columns; i++ ) {
      Matrix * P = matrix_minor ( M, i );
      sum += sign * matrix_get(M,0,i) * matrix_det(P);
      sign *= -1;
      matrix_destroy ( P );
    }

    return sum;

  }


}
