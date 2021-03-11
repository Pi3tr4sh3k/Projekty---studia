cmake_minimum_required(VERSION 3.1)

project(PacMan2)
set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)
if (UNIX)
    set ( CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
endif(UNIX)
if (WIN32)

    set( SFML_STATIC_LIBRARIES TRUE )

    set ( SFML_DIR "C:/cpp/SFML-2.5.1/lib/cmake/SFML/")
endif(WIN32)

find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

add_executable(PacMan2 main.cpp PacManBoard.cpp PacManBoard.h Player.cpp Player.h TextDisplay.cpp TextDisplay.h EnemyUnits.cpp EnemyUnits.h SFMLView.cpp SFMLView.h SFMLController.h SFMLController.cpp GameStateController.cpp GameStateController.h HScore.cpp HScore.cpp Score.cpp Score.h WelcomeScreen.cpp WelcomeScreen.h)

target_link_libraries(PacMan2 sfml-graphics sfml-audio)

