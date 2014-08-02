#include <ncurses.h>
#include <string.h>

#include "mruby.h"
#include "mruby/proc.h"
#include "mruby/compile.h"
#include "stdio.h"
#include "locale.h"


int main()
{
  int  x, y;
  int key=' ';
  initscr();
  keypad(stdscr, TRUE);

  setlocale(LC_ALL, "");

  x = 0;
  y = 0;

  while (1) {
    key = getch();
    if (key == 'q') break;
    switch (key) {
      case KEY_UP: y--; break;
      case KEY_DOWN: y++; break;
      case KEY_LEFT: x--; break;
      case KEY_RIGHT: x++; break;
      default : mvprintw(y, x++, "%c", key); break;
    }
    move(y, x);
  }
  endwin();
  return (0);
}

