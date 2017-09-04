#include	"core.h"

loop_t loop;

void resize_h (int _signum) {
	
}

int main (int argc, char *argv[]) {
	signal (SIGWINCH, resize_h);
	srand (time (0));
	loop.begin ();
	exit (EXIT_SUCCESS);
}