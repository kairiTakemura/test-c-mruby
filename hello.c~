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
  printf("ret=%d\n", mrb_fixnum(ret));
  int  x, y, w, h;
  char ch;
  int key;
  char str[BUFSIZ];

  initscr();
  echo();
  cbreak();
  keypad(stdscr, TRUE);

  x = 0;
  y = 0;

  while (key != 'q') {
    erase();
    move(y, x);
    refresh();
    key = getch();
    ret = mrb_funcall(mrb, mrb_top_self(mrb), "switch", 1, mrb_fixnum_value(key) );

/*    switch (key) {
      case KEY_UP: y--; break;
      case KEY_DOWN: y++; break;
      case KEY_LEFT: x--; break;
      case KEY_RIGHT: x++; break;
*/    }
  }
  endwin();
  return (0);
}

