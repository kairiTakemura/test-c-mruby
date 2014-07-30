#include "mruby.h"
#include "mruby/proc.h"
#include "mruby/compile.h"
#include "stdio.h"
//#include "ncurses.h"
#include <ncurses.h>
#include <string.h>
//#include "locale.h"

int main ()
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

//----------------------------------------------------------------
  char buf[BUFSIZ];
//  setlocale(LC_ALL, "");

//window初期化?screen初期化
  initscr();
  noecho();
  cbreak();

  int key;
  int x = 0;
  int y = 0;

  char *str="Hello World";

  move(x, y);

//特殊キーを有効化
  keypad(stdscr, TRUE);

  //addstr("abc\ndef\nghi");


  while(1){
    erase();
    move(y, x);
    addstr(str);
    refresh();
    key = getch();
    if (key == 'q') break;
    switch(key){
      case KEY_UP: x--; break;
      case KEY_DOWN: x++; break;
      case KEY_LEFT: y--; break;
      case KEY_RIGHT: y++; break;
      default : addch(key); break;
    }


    //ret = mrb_funcall(mrb, mrb_top_self(mrb), "evaluate", 3, mrb_str_new_cstr(mrb, &key), mrb_fixnum_value(x), mrb_fixnum_value(y) );
  }

//window終了
  endwin();

  printf("%d\n",x);
  printf("%d\n",y);


  return 0;
}

