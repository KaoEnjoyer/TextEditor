#include <cstdlib>
#include <curses.h>
#include <signal.h>
#include <vector>
#include <string>
#include "editor.h"
#include <iostream>
//signals
static void finish(int sig);


//defines
#define LEFT 0,-1
#define RIGHT 0,1
#define DOWN -1,0
#define UP 1,0

//MACROS
//how to compile (i think so )
//g++ -Wall main.cpp editor.cpp bottom_menu.cpp -o rel -lncurses 


//TO DO:
/*
 zamień vector na array<strcut linia>
 struct line {char[] , int x last positio} //done teraz trylko przaepisac metody 

 render editor -> render changed line
 wwwwww
MAKE FILE
*/
void print_int(int a){
	char ch;
	while(a){
		ch = (a%10) + '0';
		a = a /10;
		addch(ch);
	}

}

void update_cursor(editor & ed){
	if(COLS < ed.get_x() || LINES < ed.get_y()){
		finish(-39);
	}	
	wmove(stdscr, ed.get_y() , ed.get_x()); 
}



void render_editor(editor& ed){
	curs_set(0);
	move(0,0);
	int y = 0 ;
	for(auto it = ed.text_container.begin(); it != ed.text_container.end() ; it++){
		y++;
		for(int i  = 0 ; it->last_x > i; i++){
			waddch(stdscr , it->str[i]);
		}
		wmove(stdscr , y,0);
	}
	update_cursor(ed);
	curs_set(1);
refresh();
}	


void input_mode(editor & ed){
	ed.change_mode(mode::Insert);
	int ch;
	while(true){
		update_cursor(ed);
		ch = getch();
		switch(ch){
			case ERR:
			break;
			case 27:
				return;
			break;
			case 13: //to jest enter
			ed.create_new_line();
			break;
			case KEY_LEFT:
				ed.move(0 , -1);
			break;
			case KEY_RIGHT:
				ed.move(0 , 1);
			break;

			case KEY_UP:
				ed.move(-1 , 0);
			break;
			case KEY_DOWN:
				ed.move(1 , 0);
			break;
			case 127:
			case KEY_BACKSPACE:
				ed.move(0,-1);
				ed.replace_letter(' ');
				render_editor(ed);	
			break;
			default:
			ed.add_a_letter(ch);
			render_editor(ed);
			break;

		}

	}
}

void normal_mode(editor& ed){ 
	int ch = getch();
	ed.change_mode(mode::Normal);
	std::vector<std::string>tab;
	switch (ch)
	{
	case 'q':
		finish(-1);
		break;
	case 'I':
		input_mode(ed);
		break;
	case 'T':
	print_int(222);	
		break;
	default:
	if(ch != -1)
	std::cout << ch;
		// print_int(ch);
		 break;
	}

}



void init(){
	(void)signal(SIGINT, finish);
	(void)initscr();
	keypad(stdscr, true);
	(void)nonl();
	(void)raw();
	(void)noecho();
	notimeout(stdscr , TRUE);
	(void)nodelay(stdscr , TRUE);
}

int main()
{
	init();
	editor* main_editor = new editor();
	bottom_menu* bot_menu = new bottom_menu();

	//main loop
	while(true){
		normal_mode(*main_editor);
	}
}  



static void finish(int sig)
{
	endwin();
	printf("%d" , sig);
	exit(0);
}
