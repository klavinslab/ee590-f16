#include <stdio.h>
#include <time.h>
#include <math.h>

#define SUCCEED return 0
#define FAIL return -1

#define ASSERT(_cond_) {                                                          \
  if ( ! ( _cond_ ) ) {                                                           \
    fprintf (stderr, "Internal error: assertion '%s' failed at %s, line %d\n",    \
                   #_cond_ , __FILE__, __LINE__);                                 \
    FAIL;                                                                         \
  }                                                                               \
}

#define SRAND {                 \
  time_t t;                     \
  srand((unsigned) time(&t));   \
}
