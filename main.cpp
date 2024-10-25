#include <cstdlib>
#include <curses.h>
#include <signal.h>
#include <vector>
#include <string>
static void finish(int sig);

#define LEFT 0,-1
#define RIGHT 0,1
#define DOWN -1,0
#define UP 1,0

#define RETURN_TO_NORMAL_MODE() return;
#define MOVE() move(*y_pos , *x_pos)


// void INIT_TEXT_ARRAY(int col , int len){
	
// }

// void MOVE(int *x_pos , int *y_pos, int delta_x , int delta_y){

// }


//repair input handeling 
//
void INPUT_MODE(int *x_pos , int *y_pos , WINDOW* win , std::vector<std::string>&text_array){
	int c ;
	while(1){
		c = getch();
		switch (c)
		{
		case 27:
			c = getchar();
			printw("WYCHODZIMY!!");
			if(c == -1){
				RETURN_TO_NORMAL_MODE();
			}
			break;
		case KEY_BACKSPACE:
			text_array[*y_pos][*x_pos] = ' ';
			x_pos--;
			MOVE();
			printw("USUWAMY!!");

		case '!':
			return;
			break;
		break;
		default:
			break;
		}
		refresh();
	}

}

void NORMAL_MODE(WINDOW* win ,  std::vector<std::string>& text_array){
		int x = 0, y = 0 ;
		int *x_pos , *y_pos ;
		x_pos = &x;
		y_pos = &y;
		int row , col;
		getmaxyx(win , row , col);
		refresh();
		int c = getch();

		

			noecho();
			while(true){
			c = getch();
			switch (c)
			{
			case 'h':
				if (*x_pos <= -1)
					break;
				x_pos--;
				MOVE();
				break;
			case 'j':
				if (*y_pos <= 0)
					break;
				y_pos--;
				MOVE();
				break;
			case 'k':
				y_pos++;
				MOVE();
				break;
			case 'l':
				x_pos++;
				MOVE();
				break;

			case 'I':
				echo();
				INPUT_MODE(x_pos , y_pos , win ,text_array);
				break;
			default:
				break;
			}

			if (c == (int)'~')
			{
				finish(0);
			}
			}
		
		if (c == (int)'~')
		{
			finish(0);
		}

	}





int main()
{
	std::vector<std::string>text_array;

	//init 
	(void)signal(SIGINT, finish);
	(void)initscr();
	keypad(stdscr, true);
	(void)nonl();
	(void)raw();
	(void)echo();

	// if (has_colors())
	// {
	// 	start_color();
	// 	init_pair(1, COLOR_RED, COLOR_BLACK);
	// 	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	// 	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	// 	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	// 	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	// 	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	// 	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	// }
	
	
	for (;;)
	{
		NORMAL_MODE(stdscr , text_array);
	finish(0);
	}
}  

static void finish(int sig)
{
	endwin();
	printf("wwwww");
	exit(0);
}
