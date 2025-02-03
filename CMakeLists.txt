cmake_minimum_required(VERSION 3.10)

project(Proteus VERSION 3.0.1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCES
    src/main.c
    src/baseConversion.c
    src/notationConversion.c
    src/arithmetic_parser.tab.c
    src/notation_parser.tab.c
    src/lex.yy.c
)

set(HEADERS
    include/util.h
    include/notation.h
    include/parser.h
    include/arithmetic_parser.tab.h
    include/notation_parser.tab.h
)

add_library(ProteusLib SHARED ${SOURCES})

add_executable(Proteus ${SOURCES})

target_link_libraries(Proteus m ProteusLib)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(ArithmeticParser parser/arithmetic_parser.y ${CMAKE_CURRENT_BINARY_DIR}/src/arithmetic_parser.tab.c)
BISON_TARGET(NotationParser parser/notation_parser.y ${CMAKE_CURRENT_BINARY_DIR}/src/notation_parser.tab.c)
FLEX_TARGET(Lexer lexer/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/src/lex.yy.c)
ADD_FLEX_BISON_DEPENDENCY(Lexer ArithmeticParser)
ADD_FLEX_BISON_DEPENDENCY(Lexer NotationParser)

list(APPEND SOURCES ${BISON_ArithmeticParser_OUTPUTS} ${BISON_NotationParser_OUTPUTS} ${FLEX_Lexer_OUTPUTS})

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_custom_target(clean-all
  COMMAND ${CMAKE_COMMAND} -P ${CMAKE_BINARY_DIR}/cmake_clean.cmake
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
)
