//
// Created by nick on 12/1/16.
//

#ifndef HOMEWORK5_GAMESCREEN_H
#define HOMEWORK5_GAMESCREEN_H

#include "SFML/Graphics.hpp"
#include "baseScreen.h"
#include "RegularGameObject.h"
#include "Meteor.h"
#include "MeteorNB.h"
#include "Ship.h"
#include "Laser.h"

class gameScreen : public baseScreen {
public:
	virtual int run(sf::RenderWindow &App);
private:
	RegularGameObject m_player;
	int handlePlayerInput(sf::Keyboard::Key key, bool isDown);
	//void thread_function();
	std::vector<MeteorNB> met;
	std::vector<MeteorNB> met2;
	void thread_function();



	//vitcors shit
	void processEvents();
	//update the game objects
	void update(sf::Time deltaT);
	//draw the scene
	void render();

	sf::RenderWindow m_window;

	std::vector <Laser> laserVector;

	Ship newship;
	Laser newLaser;

	bool firstClockDeath = true;
	const float m_speed = 2 * 120.0f;
	bool m_left = false;
	bool m_right = false;
	bool m_up = false;
	bool m_down = false;
	bool m_space = false;
	bool loaded = true;

	RegularGameObject background;
	int currentScore = 0;
	int highScore = 0;
	std::string currentScoreS;
	std::string highScoreS;
	sf::Font font;
	sf::Text Menu1;
	sf::Text Menu2;

};


#endif //HOMEWORK5_GAMESCREEN_H
