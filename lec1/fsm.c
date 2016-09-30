/*
 * FSM Functions
 */

/* Return the index of the first instance of the character c in str */
int indexOf(char str[], char c) {
  int i = 0;
  for ( i=0; str[i] != '\0'; i++ ) {
    if ( str[i] == c )
      return i;
  }
  return -1;
}

/* Walk through the given fsm for the given input file */
int fsm ( char alphabet[], int num_rules, int rules[3][num_rules], const char str[] ) {

  int i, j;
  int state = 0;

  for ( i=0; str[i] != '\0'; i++ ) {
    j =  indexOf(alphabet,str[i]);
    if ( j < 0 )
      break;
    state = rules[j][state];
    if ( state >= num_rules )
      break;
  }

  return state;

}
