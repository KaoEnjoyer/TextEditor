#include <curses.h>
#include "editor.h"
enum mode{
            Insert,
            Normal
        };

class bottom_menu{
    WINDOW* canva;
    size_t height;
    size_t length;
    mode current_mode;
    void print(editor & ed);
    public:
    bottom_menu();
    void change_mode(const mode& m);
    void update(editor & ed);
};

