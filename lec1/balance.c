#include <stdio.h>

int main ( int argc, char * argv[] ) {

  int i, s=0;
  char * input = argv[1];

  for ( i=0; input[i] != '\0'; i++ ) {
    if ( input[i] == '(' ) {
      s++;
    } else if ( input[i] == ')') {
      s--;
      if ( s < 0 ) {
        printf ( "unbalanced\n" );
        break;
      }
    } else {
      printf ( "unexpected character : %c\n", input[i] );
      break;
    }
  }

  if ( s == 0 ) {
   printf ( "balanced\n");
 } else {
   printf ( "unbalanced\n");
 }

  return 0;

}
