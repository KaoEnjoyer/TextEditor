#include "bottom_menu.h"

bottom_menu::bottom_menu(){
    this->height = 1;
    this->length = COLS;
    this->canva = newwin( height, COLS , LINES-1,0);
    update(mode::Normal , 0 , 0);
}


void bottom_menu::print(const mode& m , int ln , int col ){
    wclear(canva);
    switch(m){
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

void bottom_menu::update(const mode& m , int ln , int col){
        print(m , ln , col);
        wrefresh(canva);
}
