/*
 * ui.c
 *
 */

#include <ncurses.h>

#include "ui.h"

void ui_init(void)
{
  int     x;
  int     y;

  (void)x;
  (void)y;
  initscr();
  raw();
  curs_set(0);
  noecho();
  halfdelay(5);
  getmaxyx(stdscr, y, x);
}
