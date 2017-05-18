#include <SFML/Graphics.hpp>
#include "Game.h"
#include "baseScreen.h"
#include "introScreen.h"
#include "gameScreen.h"
#include "deadScreen.h"
#include <iostream>

int main()
{
/*    Game game;
    game.run();
    return 0;*/

    sf::RenderWindow m_window(sf::VideoMode(1280, 720), "Cool Game");

    std::vector<baseScreen *> screens;

    introScreen welcome;
    gameScreen asteroid;
    deadScreen blown;

    screens = {&welcome, &asteroid, &blown};

    int screenNum = 0;

    while (screenNum >= 0 ) {
        screenNum = screens[screenNum]->run(m_window);
    }

    std::cout<< "done here" <<std::endl;
    m_window.close();
    return 0;

}