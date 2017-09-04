#include	"loop.h"

coord_t play_win_sizes = { .x = 10, .y = 6 };

loop_t::loop_t () {
	if ((this->background = initscr ()) == 0)
	{
		fprintf (stderr, "Error initialising ncurses.\n");
		exit (EXIT_FAILURE);	//Exit if couldn't initialize curses
	}
	
	start_color ();			//Allow colors
	use_default_colors ();	//Allow window transperency
	
	noecho ();				//Disable output when any key is pressed
	keypad (stdscr, true);	//Allow using functional keys
	curs_set (false);		//Disable cursor
	
	refresh ();
}

loop_t::~loop_t () {
	endwin ();
}

void loop_t::begin () {
	char key (0);
	this->draw_background ();
	this->draw_play_win ();
	while ((key = getch ()) != 'q') {
		refresh ();
		switch (getch ()) {
			case 'q': case 'Q':
				this->~loop_t ();
				break;
		}
	}
}

void loop_t::draw_play_win () {
	if (this->play_win != 0)
		delwin (play_win);
	if ((this->play_win = subwin (this->background, play_win_sizes.x, play_win_sizes.y, 0, 0)) == 0)
	{
		fprintf (stderr, "Error initialising ncurses.\n");
		exit (EXIT_FAILURE);
	}

}

void loop_t::draw_background () {
	init_pair(1, COLOR_BLACK, COLOR_CYAN);
	wattron(background, COLOR_PAIR(1));
	mvwhline(background, 0, 0, ' ', 50);
	wattroff(background, COLOR_PAIR(1));
}

char* loop_t::generate () {
	size_t _size = 5 + (rand () % 4);
	this->question = new char[_size];
	for (size_t i; i < _size; i++)
		this->question[i] = '0' + (rand () % 10);
}