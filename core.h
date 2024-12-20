#include "editor.h"
#include "bottom_menu.h"

static void finish(int sig);

void update_cursor(editor & ed);
void render_editor(editor& ed);

void input_mode(editor & ed);
void normal_mode(editor& ed);

void handle_commands(editor & ed);