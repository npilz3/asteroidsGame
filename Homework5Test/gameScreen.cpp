#include <iostream>
#include "gameScreen.h"
#include <thread>
#include <windows.h>
#include <SFML\Audio.hpp>

int gameScreen::run(sf::RenderWindow &App) {

	std::thread thd(&gameScreen::thread_function, this);
	//laser sound
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("resources/laser.wav"))
		std::cout << "you messed up" << std::endl;
	sf::Sound sound;
	sound.setBuffer(buffer);

	//collision sound
	sf::SoundBuffer collision;
	if (!collision.loadFromFile("resources/bump blowup.wav"))
		std::cout << "collision messed up" << std::endl;
	sf::Sound collide;
	collide.setBuffer(collision);
////////////////////////////////////////////////////////////////////////////////
	//reset
	met = {};
	met2 = {};
	laserVector = {};
	currentScore = 0;
	if (newship.isDead()) {
		delete &newship;
	}
	Ship newship;
	Menu2.setString("               \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
	

////////////////////////////////////////////////////////////////////////////////
	//ClOCK
	sf::Clock meteorclock;
	//victor
	sf::Clock clock;
	sf::Clock clock2;
	sf::Clock laserMoveClock;
	sf::Clock amIdead;
	sf::Clock scoreClock;
////////////////////////////////////////////////////////////////////////////////
	if (!font.loadFromFile("resources/Endless Boss Battle.ttf")) {
		std::cout << "Error loading arial.ttf" << std::endl;
	}
	//current score
	Menu1.setFont(font);
	Menu1.setCharacterSize(20);
	Menu1.setPosition({ 0.f, 690.f });
	Menu1.setFillColor(sf::Color::White);
	//////////////////////////////////
	//////////////////////////////////
	//high score
	Menu2.setFont(font);
	Menu2.setCharacterSize(20);
	Menu2.setPosition({0.0f, 650.0f });
	Menu2.setFillColor(sf::Color::White);
///////////////////////////////////////////////////////////////////////
	//victor
	newship.load("resources/Spaceship Blue.png");
	newship.setPosition(608.f, 328.f);
	newLaser.load("resources/Laser.png");

	int returnValue = 0;
	thd.join();
    while (returnValue != 2) {
		
        sf::Event event;

		//destruction
		int ldes = 0;
		int mdes = 0;
		int mdes2 = 0;
		bool checkdes = true;
		while (ldes < laserVector.size()) {

			checkdes = true;
			int mdes = 0;
			int mdes2 = 0;

			//destroy destructables
			while (mdes < met2.size() && checkdes) {
				//std::cout << ldes << std::endl;

				//laser
				float xval = laserVector[ldes].getPosition().x;
				float yval = laserVector[ldes].getPosition().y;

				//meteor
				float xval2 = met2[mdes].getPosition().x;
				float yval2 = met2[mdes].getPosition().y;

				if (abs(xval - xval2) < 64 && abs(yval - yval2) < 64) {
					laserVector.erase(laserVector.begin() + ldes);
					met2.erase(met2.begin() + mdes);
					checkdes = false;
					collide.play();
				}
				else {
					++mdes;
				}
			}

			//destroy on indestructables
			while (mdes2 < met.size() && checkdes) {
				//laser
				float xval = laserVector[ldes].getPosition().x;
				float yval = laserVector[ldes].getPosition().y;
				//meteor
				float xval2 = met[mdes2].getPosition().x;
				float yval2 = met[mdes2].getPosition().y;

				if (abs(xval - xval2) < 64 && abs(yval - yval2) < 64) {
					laserVector.erase(laserVector.begin() + ldes);
					checkdes = false;
					collide.play();
				}
				else {
					++mdes2;
				}
			}

			//std::cout << "mdes out" << std::endl;
			++ldes;
			//std::cout << ldes << std::endl;
		}
		
		// ship collision
		if (!newship.isDead()) {
			int csdes = 0;
			int csdes2 = 0;
			bool csCheck = true;
			while (csdes < met2.size() && csCheck) {
				//ship
				float xval = newship.getPosition().x;
				float yval = newship.getPosition().y;
				//meteor
				float xval2 = met2[csdes].getPosition().x;
				float yval2 = met2[csdes].getPosition().y;

				if (abs(xval - xval2) < 64 && abs(yval - yval2) < 64) {
					newship.setDead();
					csCheck = false;
					collide.play();
				}
				else {
					++csdes;
				}
			}

			while (csdes2 < met.size() && csCheck) {
				//ship
				float xval = newship.getPosition().x;
				float yval = newship.getPosition().y;
				//meteor
				float xval2 = met[csdes2].getPosition().x;
				float yval2 = met[csdes2].getPosition().y;

				if (abs(xval - xval2) < 64 && abs(yval - yval2) < 64) {
					newship.setDead();
					csCheck = false;
					collide.play();
				}
				else {
					++csdes2;
				}
			}
		}
		



		//Victor start
		// for creating new laser with cooldown
		if (!newship.isDead()) {
			if (m_space && loaded) {
				loaded = false;
				clock2.restart();
				newLaser.setState(newship.returnCurrentState());
				newLaser.setPosition(newship.getPosition().x, newship.getPosition().y);
				laserVector.push_back(newLaser);
				sound.play();

			}
			if (clock2.getElapsedTime().asSeconds() > 0.25) {
				loaded = true;
			}
		}

		// memory manager for laser
		int i = 0;
		while (i < laserVector.size()) {
			float xval = laserVector[i].getPosition().x;
			float yval = laserVector[i].getPosition().y;
			if (xval < -64.f || xval > 1344.f || yval < -64.f || yval > 784.) {
				laserVector.erase(laserVector.begin() + i);
			}
			else {
				++i;
			}
		}

		//memory manager for meteorsNB
		int j = 0;
		while (j < met.size()) {
			float xval = met[j].getPosition().x;
			float yval = met[j].getPosition().y;
			if (xval < -64.f || xval > 1344.f || yval < -64.f || yval > 784.) {
				met.erase(met.begin() + j);
			}
			else {
				++j;
			}
		}

		//memory manager for meteorsBreak
		int k = 0;
		while (k < met2.size()) {
			float xval = met2[k].getPosition().x;
			float yval = met2[k].getPosition().y;
			if (xval < -64.f || xval > 1344.f || yval < -64.f || yval > 784.) {
				met2.erase(met2.begin() + k);
			}
			else {
				++k;
			}
		}

		// control death and alive animation
		if (!newship.isDead()) {
			newship.animate();
			amIdead.restart();
		}
		else {
			newship.playDead();
		}
		
		if (newship.isDead() && amIdead.getElapsedTime().asSeconds() > 5) {
			PlaySound(NULL, GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);
			return 2;
		}
		
		sf::Time deltaT = clock.restart();
		//victor end

        while (App.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyPressed:
                    //handle key down here
                    returnValue = handlePlayerInput(event.key.code, true);
                    break;
                case sf::Event::KeyReleased:
                    returnValue = handlePlayerInput(event.key.code, false);
                    break;

                case sf::Event::Closed:
                    App.close();
                    break;
            }
        }
        App.clear();

		
		//Victor Start
		if (!newship.isDead()) {
			//std::cout << m_speed << std::endl;
			sf::Vector2f movement(0.0f, 0.0f);
			if (m_up) {
				movement.y -= m_speed;
				newship.setState(0);
			}
			if (m_down) {
				movement.y += m_speed;
				newship.setState(2);
			}
			if (m_left) {
				movement.x -= m_speed;
				newship.setState(1);
			}
			if (m_right) {
				movement.x += m_speed;
				newship.setState(3);
			}

			newship.move(movement * deltaT.asSeconds());

			bool needAdjust = false;

			if (newship.getPosition().x + 70.0f < 0) {
				//movement.x = App.getSize().x - 3.0f;
				movement.x = App.getSize().x + newship.getPosition().x + 140.0f;
				needAdjust = true;
			} else if (newship.getPosition().x > App.getSize().x) {
				movement.x = 3.0f - App.getSize().x - 70.0f;
				needAdjust = true;
			} 
			if (newship.getPosition().y + 70.0f < 0) {
				//movement.y = App.getSize().y - 3.0f;
				movement.y = App.getSize().y + newship.getPosition().y + 140.0f;
				needAdjust = true;
			}
			else if (newship.getPosition().y > App.getSize().y) {
				movement.y = 3.0f - App.getSize().y - 70.0f;
				needAdjust = true;
			}
			if (needAdjust) {
				newship.move(movement);
			}
			
		}

		std::vector<Laser>::iterator LasIter;
		if (laserMoveClock.getElapsedTime().asSeconds() > 0.01) {
			laserMoveClock.restart();
			for (LasIter = laserVector.begin(); LasIter != laserVector.end(); LasIter++) {
				(LasIter)->move();
			}
		}
		//victor end

		if (meteorclock.getElapsedTime().asSeconds()>1) {
			meteorclock.restart();
			if (rand() % 3 == 0) {
				MeteorNB bob;
				met.push_back(bob);
			}
			else {
				MeteorNB bob;
				met2.push_back(bob);
			}
		}
		
		newship.draw(App);

		for (auto vecItr = met.begin(); vecItr != met.end(); vecItr++) {
			//std::cout << (*vecItr == nullptr) << std::endl;
			(vecItr)->load("resources/GrayAsteroid.png");
			(vecItr)->setScale(1.f);
		}

		for (auto vecItr = met2.begin(); vecItr != met2.end(); vecItr++) {
			//std::cout << (*vecItr == nullptr) << std::endl;
			(vecItr)->load("resources/Asteroid spin.png");
			(vecItr)->setScale(1.f);
		}

		//met[0]->draw(App);
		for (auto vecItr = met.begin(); vecItr != met.end(); vecItr++) {
			//std::cout << (*vecItr == nullptr) << std::endl;
			(vecItr)->move();
			(vecItr)->draw(App);
		}

		for (auto vecItr = met2.begin(); vecItr != met2.end(); vecItr++) {
			//std::cout << (*vecItr == nullptr) << std::endl;
			(vecItr)->move();
			(vecItr)->draw(App);
		}

		for (LasIter = laserVector.begin(); LasIter != laserVector.end(); LasIter++) {
			(LasIter)->draw(App);
		}
		if (!newship.isDead()) {
			currentScore = scoreClock.getElapsedTime().asSeconds();
			currentScoreS = std::to_string(currentScore);
			Menu1.setString("current score:\t" + currentScoreS);

			if (currentScore > highScore) {
				highScore = currentScore;
			}
			highScoreS = std::to_string(highScore);
		}
		Menu2.setString("high score:\t" + highScoreS);
		//std::cout << "high score:\t" + highScoreS << std::endl;
		App.draw(Menu1);
		App.draw(Menu2);
        App.display();

    }
    return returnValue;
}

int gameScreen::handlePlayerInput(sf::Keyboard::Key key, bool isDown) {
	if (key == sf::Keyboard::BackSpace) {
		return 2;
	}
	if (key == sf::Keyboard::Left) {
		m_left = isDown;
	}
	if (key == sf::Keyboard::Right) {
		m_right = isDown;
	}
	if (key == sf::Keyboard::Up) {
		m_up = isDown;
	}
	if (key == sf::Keyboard::Down) {
		m_down = isDown;
	}
	if (key == sf::Keyboard::Space) {
		m_space = isDown;
	}
    return 0;
}


void gameScreen::thread_function() {
	std::cout << "hello from thread" << std::endl;
	PlaySound("resources/Arena.wav", GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);
	//music.play();
}

