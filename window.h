#include <curses.h>
#include "vec.h"
class WIN{
    WINDOW* m_window;
    
    char name[128];
    int m_height;
    int m_width;
    int m_x;
    int m_y;
    
    vec<WIN>subwindows;
    
    public:
    WIN(int height, int width, int x, int y);
    WIN(int height, int width, int x, int y , WINDOW* window);
    
    WIN* add_window(int height, int width, int x, int y);
    WIN* update();
    
    void set_border(bool set);
    
    //getters
    char* name();
    int height();
    int width();
    int x();
    int y();
    
    
};
