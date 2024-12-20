#include "core.h"


// 1) handling input

// KEYS

#define CONST_KEY_ENTER 13
#define CONST_KEY_BACKSPACE 127
#define CONST_KEY_ESC 27

void update_cursor(editor &ed)
{
	if (COLS < ed.get_x() || LINES < ed.get_y())
	{
		finish(-39);
	}
	wmove(stdscr, ed.get_y(), ed.get_x());
}

void render_editor(editor &ed)
{
	curs_set(0);
	move(0, 0);
	int y = 0;
	for (auto it = ed.text_container.begin(); it != ed.text_container.end(); it++)
	{
		y++;
		for (int i = 0; it->last_x > i; i++)
		{
			waddch(stdscr, it->str[i]);
		}
		wmove(stdscr, y, 0);
	}
	update_cursor(ed);
	curs_set(1);
	refresh();
}

void input_mode(editor &ed)
{
	ed.change_mode(mode::Insert);
	int ch;
	while (true)
	{
		update_cursor(ed);
		ch = getch();
		switch (ch)
		{
		case KEY_LEFT:
			ed.move(0, -1);
			break;
		case KEY_RIGHT:
			ed.move(0, 1);
			break;
		case KEY_UP:
			ed.move(-1, 0);
			break;
		case KEY_DOWN:
			ed.move(1, 0);
			break;
		case ERR:
			break;
		case CONST_KEY_ESC:
			return;
			break;
		case CONST_KEY_ENTER:
			ed.create_new_line();
			break;
		case CONST_KEY_BACKSPACE:
		case KEY_BACKSPACE:
			ed.delate_letter();
			render_editor(ed);
			break;
		default:
			ed.add_a_letter(ch);
			render_editor(ed);
			break;
		}
	}
}

void normal_mode(editor &ed)
{
	ed.change_mode(mode::Normal);
	std::vector<std::string> tab;
	while (true)
	{
		int ch = getch();
		switch (ch)
		{
		case 'q':
			finish(-1);
			break;
		case 'I':
			input_mode(ed);
			break;
		case 'T':
			break;
		case ':':
			handle_commands(ed);
			break;
		default:
			if (ch != -1)
				break;
		}
	}
}

void handle_commands(editor &ed)
{
	// char* buff = new char[256];
	// int i = 0;
	// char ch;
	// while(ch = getch()){
	// 	if(ch == _MY_ENTER_KEY){
	// 		break;
	// 	}
	// 	buff[i++] = ch;
	// }
	// if(buff == "w"){
	// 	finish(-69);
	// }
}

static void finish(int sig)
{
	endwin();
	printf("%d", sig);
	exit(0);
}
