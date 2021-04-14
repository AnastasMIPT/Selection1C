cmake_minimum_required(VERSION 3.0)
project(Solitaire VERSION 1.0 LANGUAGES C CXX)


if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()


add_executable(main ./src/main.cpp ./src/Deck.cpp)


add_executable(DeckRead.test ./Tests/DeckRead.cpp ./src/Deck.cpp)

enable_testing()
add_test(NAME DeckRead.test COMMAND DeckRead.test)