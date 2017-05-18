//
// Created by nick on 12/1/16.
//

#ifndef HOMEWORK5_INTROSCREEN_H
#define HOMEWORK5_INTROSCREEN_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "baseScreen.h"
#include "RegularGameObject.h"

class introScreen: public baseScreen {
public:
    virtual int run(sf::RenderWindow &App);
    //int processEvents();

private:
	RegularGameObject backStory;
	RegularGameObject background;
	RegularGameObject tutorial;
	RegularGameObject credit;
    int handlePlayerInput(sf::Keyboard::Key key);
	void thread_function();

	bool displayBackStory = false;
	bool displayTutorial = false;
	bool displayCredit = false;
	//sf::Music music;
    //void render();
    //sf::RenderWindow &m_window;
};


#endif //HOMEWORK5_INTROSCREEN_H
