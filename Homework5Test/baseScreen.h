//
// Created by nick on 12/1/16.
//

#ifndef HOMEWORK5_BASESCREEN_H
#define HOMEWORK5_BASESCREEN_H

#include "SFML/Graphics.hpp"

class baseScreen {
public:
    virtual int run(sf::RenderWindow &App) = 0;
};


#endif //HOMEWORK5_BASESCREEN_H
