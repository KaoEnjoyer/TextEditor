#include <curses.h>
enum mode{
            Insert,
            Normal
        };

class bottom_menu{
    WINDOW* canva;
    size_t height;
    size_t length;
    void print(const mode& m , int ln , int col);
    public:
    bottom_menu();
    void update(const mode& m , int ln , int col);
};

