#include "window.h"

WIN::WIN(int height, int width, int x, int y){
    m_height = height;
    m_width = width;
    int x = x;
    int y = y;
    m_window = newwin(width, height, y, x);
    box(m_window, 0 ,0);
}

WIN::WIN(int height, int width, int x, int y, WINDOW* window){
    m_height = height;
    m_width = width;
    int x = x;
    int y = y;
    m_window = window;
}

void WIN::set_border(bool set){
    if(set == true){
        box(m_window, 0, 0);
    }else{
    
    }
}

