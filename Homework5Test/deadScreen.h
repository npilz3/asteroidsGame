//
// Created by nick on 12/1/16.
//

#ifndef HOMEWORK5_DEADSCREEN_H
#define HOMEWORK5_DEADSCREEN_H

#include "SFML/Graphics.hpp"
#include "baseScreen.h"
#include "RegularGameObject.h"

class deadScreen: public baseScreen {
public:
    virtual int run(sf::RenderWindow &App);
private:
	RegularGameObject background;

    int handlePlayerInput(sf::Keyboard::Key key);
	void threadFunction();
};


#endif //HOMEWORK5_DEADSCREEN_H
