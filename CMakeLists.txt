cmake_minimum_required(VERSION 3.17)
project(Cluedo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cluedo main.cpp HEADER/enveloppe.h CORE/enveloppe.cpp HEADER/cards.h CORE/cards.cpp
        HEADER/utilitaire.h CORE/utilitaire.cpp CORE/cluedo.cpp HEADER/cluedo.h HEADER/libraries.h
        CORE/cell.cpp HEADER/cell.h CORE/board.cpp HEADER/board.h HEADER/dice.h CORE/dice.cpp CORE/player.cpp
        HEADER/player.h CORE/button.cpp HEADER/button.h CORE/menu.cpp HEADER/menu.h HEADER/hypothesis.h
        CORE/hypothesis.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/libs/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/libs/SFML/SFML-2.5.1/include)
target_link_libraries(Cluedo sfml-system sfml-window sfml-graphics sfml-audio)