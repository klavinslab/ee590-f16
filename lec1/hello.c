#include <stdio.h>

int main ( int argc, char * argv[] ) {

  int i;
  i = 0;
  double x[10], y[10];
  char s[] = "hello";

  s[0] = 'H';

  printf ( "%s\n", s );

  while ( i < argc && i < 10 ) {
    if ( i != 0 ) {
      printf ( "arg %d = %s\n", i, argv[i] );
    }
    i++;
  }

  return 0;

}
