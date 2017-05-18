//
// Created by nick on 12/1/16.
//

#include "deadScreen.h"
#include <SFML\Graphics.hpp>

#include <thread>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "Winmm.lib")

int deadScreen::run(sf::RenderWindow &App) {

	std::thread thd(&deadScreen::threadFunction, this);

	background.load("resources/background.jpg");
	//thd.join();

	sf::Font font;
	sf::Text urDead;
	sf::Text replay;

	font.loadFromFile("resources/Endless Boss Battle.ttf");

	urDead.setFont(font);
	urDead.setCharacterSize(30);
	urDead.setString("\t\tGame Over!\nShip Destroyed\n\t\t\t\t\t  :(");
	urDead.setPosition({ 400.f, 250.f });
	urDead.setFillColor(sf::Color::White);

	replay.setFont(font);
	replay.setCharacterSize(30);
	replay.setString("to replay, press b\n\tto end, press a");
	replay.setPosition({ 400.f, 420.f });
	replay.setFillColor(sf::Color::White);

    int returnValue = 0;
	sf::Clock flashingDead;
	int flashing = 0;
	thd.join();
    while (returnValue != -1 && returnValue != 1){//either exit or go back to game for now
        sf::Event event;

		//if (flashingDead.getElapsedTime().asSeconds() >= 0.5f) {

		//	if (flashing == 0) {
		//		replay.setFillColor(sf::Color::Black);
		//		flashing = 1;
		//	}
		//	else if (flashing == 1) {
		//		replay.setFillColor(sf::Color::White);
		//		flashing = 0;
		//	}
		//	flashingDead.restart();
		//}
		
        while(App.pollEvent(event)){

            switch (event.type) {
                case sf::Event::KeyPressed:
                    //handle key down here
                    returnValue = handlePlayerInput(event.key.code);
                    break;
                case sf::Event::KeyReleased:
                    returnValue = handlePlayerInput(event.key.code);
                    break;

                case sf::Event::Closed:
                    App.close();
                    break;
            }
        }
        App.clear();
		background.draw(App);
        //dead.draw(App);
		App.draw(urDead);
		App.draw(replay);
        App.display();

    }
	
    return returnValue;

}

int deadScreen::handlePlayerInput(sf::Keyboard::Key key) {
    if(key == sf::Keyboard::A)
        return -1;
	if (key == sf::Keyboard::B) {
		PlaySound(NULL, GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);
		return 1;
	}
    return 0;

}

void deadScreen::threadFunction() {
	PlaySound("resources/gameOverMinorKey.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}