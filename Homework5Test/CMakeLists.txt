cmake_minimum_required(VERSION 3.0)
project(Homework5)

#define EXECUTABLE NAME HERE
set(EXECUTABLE_NAME "h5")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})

set(SOURCE_FILES
        main.cpp
        Game.cpp Game.h GameObject.cpp GameObject.h RegularGameObject.cpp RegularGameObject.h AnimatedGameObject.cpp AnimatedGameObject.h baseScreen.cpp baseScreen.h introScreen.cpp introScreen.h gameScreen.cpp gameScreen.h deadScreen.cpp deadScreen.h)

#copy file to where my executable is
file(COPY "content/Mario.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content/bird.png" DESTINATION  "${CMAKE_BINARY_DIR}")
file(COPY "content//torchic.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content//seth_paladin_sword.gif" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content//zelda.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content//pokemonTrainer.png" DESTINATION "${CMAKE_BINARY_DIR}")

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
