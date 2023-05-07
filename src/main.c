#include <stdio.h>
#include <curses.h>
#include <ctype.h>

#include "terminal.h"
#include "game.h"


int main() {
    terminal_init();
    Board *board = Board_new(6);
    bool playing = 1;
    Letter_Tracker *letter_tracker = Letter_Tracker_new("qwertyuiopasdfghjklzxcvbnm");
    int current_row = 0, current_column = 0;
    while (current_column <= 6 && playing) {
        Board_draw(board);
        mvinch(current_row * 2, current_column * 2);
        int input = getch();
        terminal_colored_mprint(0, 14, LETTER_COLOR_BLACK, "%i   ", input); //DEBUG
        char *keyString = keyname(input);
        if (keyString[1] == '\0' && Letter_Tracker_contains(letter_tracker, tolower(keyString[0]))) {
            int new_column = Board_append(board, toupper(keyString[0]), current_row) + 1;
            if(new_column > 0) {
                current_column = new_column;
            }
        } else if (input == 8) {
            current_column = Board_backspace(board, current_row);
        } else if (input == 13) {
            Check_Status status = Board_check(board, "apply", current_row);
            if(status == INCORRECT) {
                current_row++;
            current_column = 0;
            } else if (status == CORRECT) {
                playing = 0;
            }
        }
        if(current_column == DEFAULT_COLUMNS) {
            curs_set(0);
        } else {
            curs_set(1);
        }
    }
    free(board);
    clear();
    endwin();
    return 0;
}
