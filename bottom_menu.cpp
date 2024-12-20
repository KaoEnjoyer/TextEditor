#include "bottom_menu.h"

bottom_menu::bottom_menu(){
    this->height = 1;
    this->length = COLS;
    this->canva = newwin( height, COLS , LINES-1,0);
    update(mode::Normal , 0 , 0);
}


void bottom_menu::print(int ln , int col ){
    wclear(canva);
    switch(current_mode){
        case Normal:
        waddstr(canva , "normal_mode");
        break;
        case Insert:
        waddstr(canva, "insert_mode");
        break;
    }
    wprintw(canva , "   Ln: %d, Col: %d " , ln , col );
    // kocham piwo
}
void bottom_menu::change_mode(const mode const & m){
    this->current_mode = m;
}

void bottom_menu::update( int ln , int col){
        print(current_mode , ln , col);
        wrefresh(canva);
}
