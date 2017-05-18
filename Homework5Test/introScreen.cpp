//
// Created by nick on 12/1/16.
//

#include "introScreen.h"
#include <iostream>

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include <thread>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "Winmm.lib")


int introScreen::run(sf::RenderWindow &App) {

	std::thread thd(&introScreen::thread_function, this);
	//thd.join();
	//thread_function();

	//load sprite

	backStory.load("resources/Story Screen.png");
	background.load("resources/background.jpg");
	tutorial.load("resources/tutorial screen.jpg");
	credit.load("resources/Credits page.jpg");


	//add fonts
	sf::Font font;
	sf::Text Menu1;
	sf::Text Menu2;


    if (!font.loadFromFile("resources/Endless Boss Battle.ttf")) {
		std::cout << "Error loading EBB.ttf" << std::endl;
	}

	Menu1.setFont(font);
	Menu1.setCharacterSize(50);
	Menu1.setString("Press space bar to begin");
	Menu1.setPosition({ 260.f, 280.f });
	Menu1.setFillColor(sf::Color::White);
	//////////////////////////////////
	//////////////////////////////////
	Menu2.setFont(font);
	Menu2.setCharacterSize(30);
	Menu2.setString("Press 1 for background");
	Menu2.setPosition({ 380.0f, 600.0f });
	Menu2.setFillColor(sf::Color::White);
	//load music
	//if (!music.openFromFile("C:\\Users\\Sheng Zhang\\Desktop\\GT16-17\\ECE2036\\Homework5Test\\Title Screen.wav"))
	//	std::cout << "Error" << std::endl; // error
	//music.play();

	thd.join();

	sf::Clock changeColor;
	int colorChoice = 0;
	int returnValue = 0;

    while(returnValue != 1){//waiting for player to start game with value of 1
		//std::cout << changeColor.getElapsedTime().asSeconds() << std::endl;
		if (changeColor.getElapsedTime().asSeconds() >= 0.5f) {

			if (colorChoice == 0) {
				Menu1.setFillColor(sf::Color::Black);
				colorChoice = 1;
			}
			else if (colorChoice == 1) {
				Menu1.setFillColor(sf::Color::White);
				colorChoice = 0;
			}
			changeColor.restart();
		}

        sf::Event event;

        while (App.pollEvent(event)) {
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


		if (displayBackStory) {
			Menu2.setString("\tPress 4 to go back");
			backStory.draw(App);
		} else if (displayTutorial) {
			Menu2.setString("\tPress 4 to go back");
			tutorial.draw(App);
		} else if (displayCredit) {
			Menu2.setString("\tPress 4 to go back");
			credit.draw(App);
		} else {
			Menu2.setString("Press 1 for background\n\t\t\tor 2 for tutorial\n\t\t\t\tor 3 for credit");
			background.draw(App);
			App.draw(Menu1);
		}
		App.draw(Menu2);
		App.display();

    }

    return returnValue;

}

int introScreen::handlePlayerInput(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::Space) {
		PlaySound(NULL, GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);
		//music.stop();
		return 1; //1 will bring us to the game screen
	} else if (key == sf::Keyboard::Num1) {
		displayBackStory = true;
		return 0;
	} else if (key == sf::Keyboard::Num2) {
		displayTutorial = true;
		return 0;
	} else if (key == sf::Keyboard::Num3) {
		displayCredit = true;
		return 0;
	} else if (key == sf::Keyboard::Num4) {
		displayBackStory = false;
		displayTutorial = false;
		displayCredit = false;
		return 0;
	}
	return 0;
}


void introScreen::thread_function() {
	std::cout << "hello from thread" << std::endl;
	PlaySound("resources/Title Screen.wav", GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);
	//music.play();
}
