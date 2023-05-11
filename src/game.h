#ifndef CORDLEBLUNT_GAME_H
#define CORDLEBLUNT_GAME_H

#include <malloc.h>
#include "colored_letter.h"

#define DEFAULT_COLUMNS 5

typedef struct {
    int rows;
    Colored_Letter board_matrix[][DEFAULT_COLUMNS];
} Board;

typedef struct {
    int size; // Allow for a variable amount of letters in case you want to use a different language
    Colored_Letter letters[];
} Letter_Tracker;

typedef enum check_status {
    NOT_A_WORD,
    INCORRECT,
    CORRECT
} Check_Status;

Board *Board_new(int rows);

void Board_draw(Board* board);
int Board_append(Board* board, char letter, int current_row);
int Board_backspace(Board* board, int current_row);
Check_Status Board_check(Board* board, char* word, int current_row);

Letter_Tracker *Letter_Tracker_new(char *allowed_letters);

int Letter_Tracker_contains(Letter_Tracker *letter_tracker, char letter);

#endif //CORDLEBLUNT_GAME_H
