cmake_minimum_required(VERSION 3.24)
project(cordleblunt C)

set(CMAKE_C_STANDARD 23)

include_directories(include)
add_executable(cordleblunt src/main.c src/io.h src/terminal.h src/terminal/terminal.c src/text/colored_letter.c src/colored_letter.h src/game/board.c src/game/letter_tracker.c src/game/game.c src/game.h)
target_link_libraries(cordleblunt ${CMAKE_SOURCE_DIR}/lib/pdcurses.a)
