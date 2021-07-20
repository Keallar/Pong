cmake_minimum_required(VERSION 3.5)

project(Pong LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(thirdParty/include src)

link_directories(thirdParty/lib)

set (PROJECT_LIBS sfml-graphics-d.lib
    sfml-window-d.lib
    sfml-audio-d.lib
    sfml-system-d.lib)

link_libraries(${PROJECT_LIBS})

file(GLOB PROJECT_SOURCES src/*.cpp src/*.h data/*.txt data/*.json)

add_executable(Pong ${PROJECT_SOURCES})

add_custom_command(TARGET Pong PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/thirdParty/bin $<TARGET_FILE_DIR:Pong>)
