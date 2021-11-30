# CMakeList.txt: Projekt CMake pro piskworkz, sem přidejte logiku zdrojového
# kódu a definic specifickou pro projekt.
#
cmake_minimum_required (VERSION 3.8)

# Přidejte zdrojový kód ke spustitelnému souboru tohoto projektu.
add_executable (piskworkz "piskworkz.cpp" "piskworkz.h" "game_setup.cpp" "game_setup.h" "file_f.cpp" "basic_f.cpp" "basic_f.h" "array_f.cpp" "array_f.h" "game_is_win.cpp" "game_is_win.h" "game_start.cpp" "game_start.h" "menu_about.cpp" "menu_about.h" "menu_leaderboard.cpp" "menu_leaderboard.h" )

# TODO: V případě potřeby přidejte testy a cíle instalace.
