#include "../game.h"
#include "../terminal.h"

#include <ctype.h>

Board *Board_new(int rows) {
    Board *board = malloc(sizeof(Board) + rows * sizeof(Colored_Letter[DEFAULT_COLUMNS]));

    board->rows = rows;


    Colored_Letter empty_field;
    empty_field.letter_color = LETTER_COLOR_BLACK;
    empty_field.letter = '_';

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < DEFAULT_COLUMNS; j++)
            board->board_matrix[i][j] = empty_field;


    return board;
}

void Board_draw(Board *board) {
    for (int i = 0; i < board->rows; i++)
        for (int j = 0; j < DEFAULT_COLUMNS; j++)
            terminal_colored_mprint(j * 2, i * 2, board->board_matrix[i][j].letter_color, "%c ",
                                    board->board_matrix[i][j].letter);

}

int Board_append(Board *board, char letter, int current_row) {
    for (int i = 0; i < DEFAULT_COLUMNS; i++) {
        if (board->board_matrix[current_row][i].letter == '_') {
            board->board_matrix[current_row][i].letter = letter;
            return i;
        }
    }
    return -1;
}

int Board_backspace(Board *board, int current_row) {
    for (int i = DEFAULT_COLUMNS - 1; i >= 0; i--) {
        if (board->board_matrix[current_row][i].letter != '_') {
            board->board_matrix[current_row][i].letter = '_';
            return i;
        }
    }
    return 0;
}

Check_Status Board_check(Board *board, char *word, int current_row) {
    if (board->board_matrix[current_row][DEFAULT_COLUMNS - 1].letter == '_')
        return NOT_A_WORD;
    int is_green = 1;
    //CHECK IF ITS A VALID WORD FROM LIST
    for (int i = 0; i < DEFAULT_COLUMNS; i++) {
        if (tolower(board->board_matrix[current_row][i].letter) == word[i]) {
            board->board_matrix[current_row][i].letter_color = LETTER_COLOR_GREEN;
        } else {
            is_green = 0;
            for (int j = 0; j < DEFAULT_COLUMNS; j++) {
                if (board->board_matrix[current_row][j].letter_color == LETTER_COLOR_BLACK &&
                    tolower(board->board_matrix[current_row][j].letter) == word[i]) {
                    board->board_matrix[current_row][j].letter_color = LETTER_COLOR_YELLOW;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < DEFAULT_COLUMNS; i++) {
        if (board->board_matrix[current_row][i].letter_color == LETTER_COLOR_BLACK) {
            board->board_matrix[current_row][i].letter_color = LETTER_COLOR_GRAY;
        }
    }

    if (is_green)
        return CORRECT;
    return INCORRECT;
}