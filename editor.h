
#include <array>
#include <string>
#include "bottom_menu.h"


const size_t _LINE_BASE_SIZE = (2<<8);

struct line{
    char * str;
    size_t last_x = 0;
    size_t size = _LINE_BASE_SIZE;
    char & operator[](size_t id);  
    line();
    line(size_t const & size);  
    void resize(size_t const & n); 
};


class editor{
    public:
        editor();
        editor(size_t len);

        void add_a_letter(char ch);
        void create_new_line();
        void delate_letter();
        void erase_letter();
        void delate_line();
        void add_string(const line &str);

        void move(size_t y , size_t x);
        
        void change_mode(const mode& m );
        void replace_letter(const char &ch);
        bottom_menu bot_menu;

        

        void set_x(const size_t &x);
        void set_y(const size_t &y);


        const size_t& get_x();
        const size_t& get_y();
       
        std::vector<line>text_container;

        private:
        bool is_in_window(size_t y, size_t x);

        mode current_mode;
        //text handling        
        //cursos data
        size_t lines;
        size_t x;
        size_t y;
};


