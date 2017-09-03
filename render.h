#ifndef	_RENDER_H_
#define	_RENDER_H_

#include	"core.h"

struct coord_t {
	int x: 16;
	int y: 16;
};

void init ();
void finish (int _exit);

sighandler_t resize_h (int _signum);

#endif