#include	"core.h"

int main (int argc, char *argv[]) {
	signal (SIGWINCH, resize_h ());
	init ();

	finish (EXIT_SUCCESS);	
}