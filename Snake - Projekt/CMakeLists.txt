




cmake_minimum_required(VERSION 3.1)
# Proszę zmienić wymaganą wersję CMake na niższą - w zupełności wystarczy 3.1

project(Snake2)

set(CMAKE_CXX_STANDARD 14)
add_executable(Snake2 main.cpp SBoard.cpp SBoard.h Snake.cpp Snake.h SnakeDisplay.cpp SnakeDisplay.h SFMLView.cpp SFMLView.h SFMLController.cpp SFMLController.h WelcomeScreen.cpp WelcomeScreen.h Score.cpp Score.h ScoreScreen.cpp ScoreScreen.h)

add_compile_options(-Wall -Wextra)

# ustawienia SFML-a dla Linuksa/MacOS i Windows - proszę zostawić obie konfiguracje,
# CMake automatycznie użyje właściwej
if (UNIX)
    # proszę nie modyfkować pierwszego wpisu, można dopisać kolejne katalogi
    # pierwszy wpis powinien poprawnie skonfigurować SFML-a dla wszystkich
    # Debianopodobnych dystrybucji
    set ( CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})

    # czy ktoś używa MacOS ? Co tam trzeba wpisać ?

endif(UNIX)

if (WIN32)

    set( SFML_STATIC_LIBRARIES TRUE )


    set ( SFML_DIR "C:/cpp/SFML-2.5.1/lib/cmake/SFML/")
endif(WIN32)

find_package(SFML 2 COMPONENTS graphics audio REQUIRED)


target_link_libraries(Snake2 sfml-graphics sfml-audio)
