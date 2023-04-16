#include <string.h>
#include "../game.h"

Letter_Tracker *Letter_Tracker_new(char *allowed_letters) {
    int size = strlen(allowed_letters);

    Letter_Tracker *letter_tracker = malloc(sizeof(Letter_Tracker) + sizeof(Colored_Letter[size]));

    letter_tracker->size = size;

    for (int i = 0; i < size; i++) {
        Colored_Letter letter;
        letter.letter = allowed_letters[i];
        letter.letter_color = LETTER_COLOR_BLACK;
        letter_tracker->letters[i] = letter;
    }

    return letter_tracker;
}

int Letter_Tracker_contains(Letter_Tracker *letter_tracker, char letter) {
    int size = letter_tracker->size;

    for (int i = 0; i < size; i++) {
        if(letter_tracker->letters[i].letter == letter)
            return 1;
    }

    return 0;
}

