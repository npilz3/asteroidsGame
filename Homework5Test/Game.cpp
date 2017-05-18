//
// Created by bswenson3 on 11/9/16.
//

#include "Game.h"

Game::Game() :
    m_window(sf::VideoMode(640, 480), "Victor's Game")
{
    //load the player
    m_player.load("Mario.png");

    //size him.  trial and error to get correct values
    m_player.setScale(.1f);

	bird.load("bird.png");
	bird.setScale(0.5f);
	bird.setPosition(150, 300);
	
	torchic.load("torchic.png");
	torchic.setScale(0.5f);
	torchic.setPosition(300, 150);

	ani_player.load("seth_paladin_sword.gif");
	ani_player.animate(0, 0, 55, 65);
	ani_player.setPosition(100, 100);
	ani_player.setScale(2.0f);

	fire_fire.load("pokemon.png");
	fire_fire.animate(0, 0, 64, 64);
	fire_fire.setPosition(0.f, 300.f);

	allSprites.push_back(&m_player);
	allSprites.push_back(&ani_player);
	allSprites.push_back(&bird);
	allSprites.push_back(&torchic);
	allSprites.push_back(&fire_fire);
}

void Game::run() {
    sf::Clock clock;
	sf::Clock clock2;
	float x1 = 0;
	float x2 = 0;
    while(m_window.isOpen()) {
		sf::Vector2f current = ani_player.getPosition();
		sf::Vector2f current2 = fire_fire.getPosition();
		if (clock2.getElapsedTime().asSeconds() > 0.2f) {
			if (x1 >= 160.0f) {
				x1 = 0;
				ani_player.animate(x1, 0, 55, 65);
				ani_player.setPosition(current.x, current.y);
				ani_player.setScale(2.0f);
			}
			else {
				ani_player.animate(x1 += 57.f, 0, 55, 65);
				ani_player.setPosition(current.x, current.y);
				ani_player.setScale(2.0f);
			}
			
			if (x2 >= 192.0f) {
				x2 = 0;
				fire_fire.animate(x2, 0, 64, 64);
				fire_fire.setPosition(current2.x, current2.y);
			}
			else {
				fire_fire.animate(x2 += 64, 0, 64, 64);
				fire_fire.setPosition(current2.x, current2.y);
			}
			
			clock2.restart();
		}
        sf::Time deltaT = clock.restart();
        processEvents();
        update(deltaT);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while(m_window.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::KeyPressed:
            //handle key down here
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;

            case sf::Event::Closed:
                m_window.close();
                break;
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isDown) {
    if(key == sf::Keyboard::Left)
        m_left = isDown;
    if(key == sf::Keyboard::Right)
        m_right = isDown;
    if(key == sf::Keyboard::Up)
        m_up = isDown;
    if(key == sf::Keyboard::Down)
        m_down = isDown;
}

//use time since last update to get smooth movement
void Game::update(sf::Time deltaT) {
    //Look a vector class!
    sf::Vector2f movement(0.0f, 0.0f);
    if(m_up)
        movement.y -= m_speed;
    if(m_down)
        movement.y += m_speed;
    if(m_left)
        movement.x -= m_speed;
    if(m_right)
        movement.x += m_speed;

    m_player.move(movement * deltaT.asSeconds());
	ani_player.move(movement * deltaT.asSeconds());

}

void Game::render() {
    m_window.clear();

	std::vector<GameObject*>::iterator GOiter;
	for (GOiter = allSprites.begin(); GOiter != allSprites.end(); GOiter++) {
		(*GOiter)->draw(m_window);
	}

    m_window.display();
}