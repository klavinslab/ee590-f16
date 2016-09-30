#include <stdio.h>
#include "fsm.h"

#define ACCEPT 2
#define REJECT 3
#define NUM_RULES 3

int main ( int argc, char * argv[] ) {

  /* Input alphabet */
  char alphabet[] = "abc";

  /*
     Example Regular Expression: ab*c
     0 -a-> 1                2 = ACCEPT
     1 -b-> 1                3 = REJECT
     1 -c-> 2
   */

  /* Matrix implementation */
  int rules[3][NUM_RULES] = {
    /* a */ { 1,      REJECT, REJECT }, /* In state 0, if you get an 'a', goto state 1 */
    /* b */ { REJECT, 1,      REJECT },
    /* c */ { REJECT, ACCEPT, REJECT }
  };

  /* Check the input string */
  char * input = argv[1];
  if ( fsm(alphabet,NUM_RULES,rules,input) == ACCEPT ) {
    printf ( "accept\n");
  } else {
    printf ( "reject\n");
  }

}
