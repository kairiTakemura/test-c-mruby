#include <ncurses.h>
#include <string.h>

#include "mruby.h"
#include "mruby/proc.h"
#include "mruby/compile.h"
#include "stdio.h"
#include "locale.h"

/*
mrb_value cursor_move(mrb_state *mrb, mrb_value self){
  mrb_value a, b;
  mrb_get_args(mrb, "oo", &a, &b);
  mrb_int x = mrb_fixnum(a);
  mrb_int y = mrb_fixnum(b);
  move(y, x);
}
*/

int main()
{
  char *str;

  mrb_state* mrb;
  int n;
  FILE* f;
  mrb_value ret;
  int key='q';

  mrb = mrb_open();
  f = fopen("test.rb", "r");
  mrb_load_file(mrb, f);
  fclose(f);

  initscr();
  key = getch();
  ret = mrb_funcall(mrb, mrb_top_self(mrb), "evaluate", 1, mrb_fixnum_value(key) );
  str = mrb_string_value_ptr(mrb, ret);
  printf("%s\n", str);
  //ret = mrb_funcall(mrb, mrb_top_self(mrb), "test", 1, mrb_fixnum_value(20) );
  
  //mrb_define_method(mrb, mrb->kernel_module, "cursor_move", cursor_move, MRB_ARGS_REQ(2));
//------------------------------------------
/*
  int  x, y;
  initscr();
  keypad(stdscr, TRUE);

  setlocale(LC_ALL, "");
/*
  key = getch();
    ret = mrb_funcall(mrb, mrb_top_self(mrb), "evaluate", 1, mrb_fixnum_value(key) );
    str = mrb_string_value_ptr(mrb, ret);
    addstr(str);

  x = 0;
  y = 0;
*/
/*
  while (1) {
    key = getch();
    ret = mrb_funcall(mrb, mrb_top_self(mrb), "evaluate", 1, mrb_fixnum_value(key) );
    str = mrb_string_value_ptr(mrb, ret);
    addstr(str);
    if (key == 'q') break;
    switch (key) {
      case KEY_UP: y--; break;
      case KEY_DOWN: y++; break;
      case KEY_LEFT: x--; break;
      case KEY_RIGHT: x++; break;
      default : mvprintw(y, x++, "%c", key); break;
    }
    move(y, x);
    //mrb_load_string(mrb,"cursor_move(x, y);");
  }
*/
  endwin();
  mrb_close(mrb);
  return (0);
}

