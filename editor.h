
#include <vector>
#include <string>



class editor{
    public:
        editor();
        void add_a_letter(char ch);
        std::vector<std::string>text;
        void create_new_line();
        void delate_letter();
        void add_string(const std::string &str);
        void move(size_t y , size_t x);
        const size_t& get_x();
        const size_t& get_y();

    private:
        void delate_line();
        //text handling        
        //cursos data
        size_t x;
        size_t y;
};


