#include <cstdlib>
#include <curses.h>
#include <signal.h>
#include <vector>
#include <string>
#include "core.h"
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
//g++ -Wall main.cpp editor.cpp bottom_menu.cpp core.cpp -o rel -lncurses 


//TO DO:
/*
 zamień vector na array<strcut linia>
 struct line {char[] , int x last positio} //done teraz trylko przaepisac metody 

 render editor -> render changed line
 wwwwww
MAKE FILE
*/

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
