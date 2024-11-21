#include "editor.h"

editor::editor(){
    this->current_mode = mode::Normal;
    this->x = 0;
    this->y = 0;
}

void editor::create_new_line(){
    move(1 , 0);    
    set_x(0);
    text_container[y][x] = ' ';
}

line::line(){
    for(int i = 0 ; i < _LINE_BASE_SIZE; i++)str[i]=' ';
}

void editor::replace_letter(const char & ch){
    text_container[y].str[x] = ch;
}

void editor::move(size_t y , size_t x){
    this->x += x;
    this->y += y;
    this->bot_menu.update(current_mode , this->y , this->x);
}


char & line::operator[](size_t id){
    return this->str[id];
}

// void editor::add_string(const std::string &str){
//     for(int i = 0 ; i < str.size(); i++){

//     }
// }

void editor::add_a_letter(char ch){
    //dodaj waruneczek wiktorze
    //if(text[y].size() < x){
    this->text_container[y][x] = ch;
    this->text_container[y].last_x++;
    move(0 ,1);
    //}
}

void editor::change_mode(const mode& m){
    this->current_mode = m;
    bot_menu.update(m ,y ,x);
}

void editor::set_x(const size_t & x){
    this->x=x;
}

void editor::set_y(const size_t & y){
    this->y=y;
}

const size_t& editor::get_x(){
    return this->x;
}

const size_t& editor::get_y(){
    return this->y;
}