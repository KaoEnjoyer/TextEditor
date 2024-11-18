#include "editor.h"

editor::editor(){
    this->text = std::vector<std::string>(1);
    this->x = 0;
    this->y = 0;
}

void editor::create_new_line(){
    std::string t = "";
    text.push_back(t);
    y++;
}

void editor::move(size_t y , size_t x){
    this->x += x;
    this->y += y;
}

void editor::add_string(const std::string &str){
    this->text.push_back(str);
}

void editor::add_a_letter(char ch){
    //if(text[y].size() < x){
    this->text[y].push_back(' ');
    this->text[y][x] = ch;
    this->x++;
    //}
}

const size_t& editor::get_x(){
    return this->x;
}

const size_t& editor::get_y(){
    return this->y;
}