#include "bottom_menu.h"

bottom_menu::bottom_menu(){
    this->height = 1;
    this->length = COLS;
    this->canva = newwin( height, COLS , LINES-1,0);
    update(mode::Normal , 0 , 0);
}

static void print_int(WINDOW* w , int a){
    curs_set(0);
	char ch;
    int size = 0;
    int b = a;
    if(a == 0){
        waddch(w , '0');
        return;
    }
	while(a){
		a = a/10;
        size++;
	}
    a = b ;
    char str[] = "        ";
    for(int i = size-1 ; i >= 0 ; i--){
        if(a <= 0){
        str[i] = 0;
        }else{
        str[i] = (char)((a%10) + '0'); 
		a = a/10;
        }
    }
    waddstr(w , str);
    curs_set(1);

}

void bottom_menu::print(const mode& m , int ln , int col){
    wclear(canva);
    switch(m){
        case Normal:
        waddstr(canva , "normal_mode");
        break;
        case Insert:
        waddstr(canva, "insert_mode");
        break;
    }
    waddstr(canva, "     Ln ");
    print_int(canva , ln );
    waddstr(canva, ", Col ");
    print_int(canva , col );
    // kocham piwo
}

void bottom_menu::update(const mode& m , int ln , int col){
        print(m , ln , col);
        wrefresh(canva);
}
