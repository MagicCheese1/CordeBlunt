#ifndef CORDLEBLUNT_COLORED_LETTER_H
#define CORDLEBLUNT_COLORED_LETTER_H

typedef enum letter_color {
    LETTER_COLOR_BLACK = 0,
    LETTER_COLOR_GRAY = 1,
    LETTER_COLOR_YELLOW = 2,
    LETTER_COLOR_GREEN = 3
} Letter_Color;

typedef struct {
    char letter;
    Letter_Color letter_color;
} Colored_Letter;

#endif //CORDLEBLUNT_COLORED_LETTER_H
