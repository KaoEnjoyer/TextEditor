#include "bottom_menu.h"

bottom_menu::bottom_menu(){
    this->height = 122;
    this->length = COLS-1;
    this->canva = newwin(height , length , 1 , 1);
    this->current_mode = mode::Normal;
    update();
	wborder(canva, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	
}

void bottom_menu::update(){
    box(canva , 0 ,0);

    for(int i = 0 ; i < length; i++){
        waddch(canva , 'a');
        wrefresh(canva);
    }
}
