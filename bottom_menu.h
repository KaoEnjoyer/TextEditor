#include <curses.h>

class bottom_menu{
    WINDOW* canva;
    size_t height;
    size_t length;
    public:
    enum mode{
        Insert,
        Normal
    };
    mode current_mode;
    bottom_menu();
    void change_mode(mode m);
    void update();
};

