cmake_minimum_required(VERSION 4.1)
project(TextEditor)
find_package(Curses REQUIRED)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lncurses")


add_executable(TextEditor main.cpp
        terminal.cpp
        terminal.h
        editor.cpp
        editor.h
)

target_include_directories(TextEditor PRIVATE ${CURSES_INCLUDE_DIR})
target_link_libraries(TextEditor PRIVATE ${CURSES_LIBRARIES})
