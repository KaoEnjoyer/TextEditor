#include "editor.h"

editor::editor(){
    //this->current_mode = mode::Normal;
    this->x = 0;
    this->y = 0;
    this->lines = _LINE_BASE_SIZE;
    this->text_container = std::vector<line>(lines);
}


editor::editor(size_t len){
    //this->current_mode = mode::Normal;
    this->x = 0;
    this->y = 0;
    this->lines = len;
    this->text_container = std::vector<line>(lines);
}


void editor::create_new_line(){
    move(1 , 0);    
    set_x(0);
    bot_menu.update(this->current_mode , y, x);
    text_container[y][x] = ' ';
}

line::line(){
    str = new char[_LINE_BASE_SIZE]();
    size = _LINE_BASE_SIZE;
    for(int i = 0 ; i < size; i++)str[i]=' ';
}

line::line(size_t const& size){
    str = new char[size]();
    this->size = size;
    for(int i = 0 ; i < this->size; i++)str[i]=' ';
}

void line::resize(size_t const & n){
    char * temp = new char[n];
    for(int i = 0 ; i < this->size;i++){
        temp[i] = str[i];
    }
    str = temp;
    for(int i = 0 ; i < size; i++)str[i]=' ';
    delete[] temp;
}

void editor::replace_letter(const char & ch){
    text_container[y].str[x] = ch;
}

bool editor::is_in_window(size_t y, size_t x){
    if(y >= 0 && y < this->lines){
        if(x >= 0 && x < this->text_container[y].size){
            return true;
        }
    }
    return false;
}

void editor::move(size_t y , size_t x){
    this->x += x;
    this->y += y;
    if(!is_in_window(this->y ,this->x )){
    this->x -= x;
    this->y -= y;
    }
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

    if(x == text_container[y].last_x){
    this->text_container[y][x] = ch;
    }
    else{
    move(0 ,1);
        for(int i = text_container[y].last_x; i > x;i--){
            text_container[y][i + 1] = text_container[y][i];
        }
    this->text_container[y][x] = ch;
    }
    this->text_container[y].last_x++;
    //abMcd
}



void editor::set_x(const size_t & x){
    this->x=x;
}

void editor::set_y(const size_t & y){
    this->y=y;
}

void editor::delate_letter(){
    int temp = 0;
    for(int i = 0; i < text_container[y].last_x; i++){
        if(i == x-1){
            text_container[y][i] = text_container[y][i+1] ;
            continue;
        }else{
        text_container[y][temp++]  = text_container[y][i];
        }
    }
    move(0,-1);
    //abcd();
}

const size_t& editor::get_x(){
    return this->x;
}

const size_t& editor::get_y(){
    return this->y;
}