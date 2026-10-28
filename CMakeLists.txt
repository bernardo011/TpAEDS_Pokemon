cmake_minimum_required(VERSION 3.10)
project(PROJECT3 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(headers)

set(SOURCES
    main.c
    sources/function_call.c
    sources/PokeLista.c
    sources/Treinador.c
    sources/Pokemon.c
    sources/CentroPesquisa.c
)
add_executable(programa ${SOURCES})
target_link_libraries(programa m)
target_compile_options(programa PRIVATE -fsanitize=address -g)
target_link_options(programa PRIVATE -fsanitize=address)