#include <cstdlib>
#include <curses.h>
#include <signal.h>

static void finish(int sig);

int main()
{
	int num = 0;

	(void)signal(SIGINT, finish);

	(void)initscr();
	keypad(stdscr, true);
	//(void)nonl();
	(void)cbreak;
	(void)echo();

	if (has_colors())
	{
		start_color();
		init_pair(1, COLOR_RED, COLOR_BLACK);
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
		init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(4, COLOR_CYAN, COLOR_BLACK);
		init_pair(5, COLOR_BLUE, COLOR_BLACK);
		init_pair(6, COLOR_YELLOW, COLOR_BLACK);
		init_pair(7, COLOR_WHITE, COLOR_BLACK);
	}
	int last_c = 0;
	SCREEN *test = NULL;
	FILE *f1, *f2;
	f1 = fopen("test.txt", "r");
	int x = 0, y = 0;
	move(x, y);
	for (;;)
	{

		refresh();
		int c = getch();

		if (c == 27)
		{

			noecho();
			
			while(c != (int)('I')){
			c = getch();
			switch (c)
			{
			case int('h'):
				if (x <= -1)
					break;
				x--;
				move(y, x);
				break;
			case int('j'):
				if (y <= 0)
					break;
				y--;
				move(y, x);
				break;
			case int('k'):
				y++;
				move(y, x);
				break;
			case int('l'):
				x++;
				move(y, x);
				break;

			default:
				break;
			}

			if (c == (int)'~')
			{
				finish(0);
			}
			}
		echo();
		}
		if (c == (int)'~')
		{
			finish(0);
		}

		attrset(COLOR_PAIR(num % 8));
		num++;
		last_c = c;
	}

	finish(0);
}

static void finish(int sig)
{
	endwin();

	exit(0);
}
