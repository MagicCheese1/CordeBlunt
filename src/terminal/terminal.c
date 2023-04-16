#include <stdlib.h>
#include "../terminal.h"
#include "curses.h"

void terminal_init() {
    initscr();
    raw();
    noecho();

    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
    start_color();
    init_pair(LETTER_COLOR_BLACK, COLOR_WHITE, COLOR_BLACK);
    init_pair(LETTER_COLOR_GRAY, COLOR_BLACK, COLOR_WHITE);
    init_pair(LETTER_COLOR_YELLOW, COLOR_BLACK, COLOR_YELLOW);
    init_pair(LETTER_COLOR_GREEN, COLOR_BLACK, COLOR_GREEN);

}

void terminal_colored_vprint(Letter_Color letter_color, const char *text, va_list valist) {
    attron(COLOR_PAIR(letter_color));
    vw_printw(stdscr, text, valist);
    attroff(COLOR_PAIR(letter_color));
}

void terminal_colored_print(Letter_Color letter_color, const char *text, ...) {
    va_list args;
    va_start(args, text);
    terminal_colored_vprint(letter_color, text, args);
    va_end(args);
}

void terminal_colored_mprint(float x, float y, Letter_Color letter_color, const char *text, ...) {
    mvinch(y, x);
    va_list args;
    va_start(args, text);
    terminal_colored_vprint(letter_color, text, args);
    va_end(args);
}