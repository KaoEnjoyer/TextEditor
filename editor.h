
#include <array>
#include <string>
#include "bottom_menu.h"


const size_t _LINE_BASE_SIZE = (2<<8);

struct line{
    char str[_LINE_BASE_SIZE];
    size_t last_x = 0;
    size_t endof_line = 1;
    char & operator[](size_t id);  
    line();    
};



class editor{
    public:
        editor(WINDOW * win);
        void add_a_letter(char ch);
        void create_new_line();
        void delate_letter();
        void add_string(const line &str);
        void move(size_t y , size_t x);
        void change_mode(const mode& m );
        void delate_line();
        void replace_letter(const char &ch);
        void render_current_line(WINDOW * win);
        bottom_menu bot_menu;

            
        void set_x(const size_t &x);
        void set_y(const size_t &y);

        WINDOW * win;
        const size_t& get_x();
        const size_t& get_y();
        std::array<line, _LINE_BASE_SIZE>text_container;

        mode current_mode;
        //text handling        
        //cursos data
        size_t x;
        size_t y;
};


