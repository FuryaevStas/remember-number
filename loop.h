#ifndef	_LOOP_H_
#define	_LOOP_H_

#include	"core.h"

struct coord_t {
	int x: 16;
	int y: 16;
};

class loop_t {
private:

	WINDOW*	background;
	WINDOW* play_win;

	char *question;
	char *answer;

public:
	loop_t ();
	~loop_t ();
	void begin ();
	void finish (int _signum);
	void draw_play_win ();
	void draw_background ();

	char* generate ();
};

#endif