#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct {
  double * value;
  int rows;
  int columns;
} Matrix;

/* allocation and setup */
Matrix * matrix_new ( int rows, int columns );
void matrix_destroy ( Matrix * M );
Matrix * matrix_random ( int rows, int columns );
Matrix * matrix_from_file ( const char filename[] );

/* Getters and setters */
double matrix_get ( Matrix * M, int row, int column );
void matrix_set ( Matrix * M, int row, int column, double value );

/* print */
void matrix_print ( Matrix * M );

/* operations */
Matrix * matrix_add ( Matrix * A, Matrix * B );
Matrix * matrix_minor ( Matrix * M, int n );
double matrix_det ( Matrix * M );

/* utilities */
#define ASSERT(_cond_) {                                                          \
  if ( ! ( _cond_ ) ) {                                                           \
    fprintf (stderr, "Internal error: assertion '%s' failed at %s, line %d\n",    \
                   #_cond_ , __FILE__, __LINE__);                                 \
    exit ( -1 );                                                                  \
  }                                                                               \
}

#define NL printf ( "\n" );

#endif
