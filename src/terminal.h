#ifndef CORDLEBLUNT_TERMINAL_H
#define CORDLEBLUNT_TERMINAL_H

#include <stdarg.h>
#include "colored_letter.h"

void terminal_init();

void terminal_colored_vprint(Letter_Color letter_color, const char *text, va_list valist);
void terminal_colored_print(Letter_Color letter_color, const char *text, ...);
void terminal_colored_mprint(float x, float y, Letter_Color letter_color, const char *text, ...);


#endif //CORDLEBLUNT_TERMINAL_H
