
#include <vector>
#include <string>
#include "bottom_menu.h"


class editor{
    public:
        editor();
        void add_a_letter(char ch);
        void create_new_line();
        void delate_letter();
        void add_string(const std::string &str);
        void move(size_t y , size_t x);
        void change_mode(const mode& m );
        void delate_line();
        void replace_letter(const char &ch);
        bottom_menu bot_menu;

        const size_t& get_x();
        const size_t& get_y();
        std::vector<std::string>text;
    
        mode current_mode;
        //text handling        
        //cursos data
        size_t x;
        size_t y;
};


