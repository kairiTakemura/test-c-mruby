#include <ncurses.h>
#include <string.h>

#include "mruby.h"
#include "mruby/proc.h"
#include "mruby/compile.h"
#include "stdio.h"

int main()
{

  mrb_state* mrb;
  int n;
  FILE* f;
  mrb_value ret;

  mrb = mrb_open();
  f = fopen("test.rb", "r");
  mrb_load_file(mrb, f);
  fclose(f);

  ret = mrb_funcall(mrb, mrb_top_self(mrb), "test", 1, mrb_fixnum_value(20) );

//------------------------------------------

  int  x, y;
  int key=' ';
  char ch;
  initscr();
  keypad(stdscr, TRUE);
  noecho();

  x = 0;
  y = 0;

  while (1) {
    key = getch();
    ch = key;
    if (key == 'q') break;
    switch (key) {
      case KEY_UP: y--; break;
      case KEY_DOWN: y++; break;
      case KEY_LEFT: x--; break;
      case KEY_RIGHT: x++; break;
      default : mvprintw(y, x++, "%c", ch); break;
    }
    move(y, x);
  }
  endwin();
  return (0);
}

