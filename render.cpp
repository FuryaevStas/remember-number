#include	"render.h"

coord_t play_win_sizes = { .x = 10, .y = 6 };

WINDOW*	mainwin			(NULL);
WINDOW*	list			(NULL);
WINDOW*	summary			(NULL);
WINDOW*	menu			(NULL);

void init () {
	if ((mainwin = initscr()) == NULL)
	{
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(EXIT_FAILURE);	//Exit if couldn't initialize curses
	}
	
	start_color();			//Allow colors
	use_default_colors();	//Allow window transperency
	
	noecho();				//Disable output when any key is pressed
	keypad(stdscr, true);	//Allow using functional keys
	curs_set(false);		//Disable cursor
	
	refresh ();
}

void finish (int _exit) {
	endwin ();
	exit (EXIT_SUCCESS);
}

sighandler_t resize_h (int _signum) {

}