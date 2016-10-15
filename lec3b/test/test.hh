#define SUCCEED return 0
#define FAIL return -1
#define ASSERT(_cond_) if ( (_cond_) ) { SUCCEED; } else { FAIL; }
