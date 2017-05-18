#include "Laser.h"

Laser::Laser() {

}


bool Laser::load(const std::string& filename) {
	if (m_texture.loadFromFile(filename)) {
		m_filename = filename;
		sf::IntRect rectSprite(Lstate * 64.f, 0, 64.f, 64.f);
		sf::Sprite sprite(m_texture, rectSprite);
		m_sprite = sprite;
		m_valid = true;
		return true;
	}
	return false;
}


void Laser::draw(sf::RenderWindow& window) {
	if (m_valid)
		window.draw(m_sprite);
}


void Laser::move() {
	if (Lstate < 0.5f) {
		m_sprite.move(sf::Vector2f(0, -10));
	}
	else if (Lstate < 1.5f) {
		m_sprite.move(sf::Vector2f(-10, 0));
	}
	else if (Lstate < 2.5f) {
		m_sprite.move(sf::Vector2f(0, 10));
	}
	else if (Lstate < 3.5f) {
		m_sprite.move(sf::Vector2f(10, 0));
	}
}

/*
void Laser::move() {
	if (Lstate < 0.5f) {
		ypos = yori + moveClock.getElapsedTime().asSeconds() * -100.f;
	}
	else if (Lstate < 1.5f) {
		xpos = xori + moveClock.getElapsedTime().asSeconds() * -100.f;
	}
	else if (Lstate < 2.5f) {
		ypos = yori + moveClock.getElapsedTime().asSeconds() * 100.f;
	}
	else if (Lstate < 3.5f) {
		xpos = xori + moveClock.getElapsedTime().asSeconds() * 100.f;
	}
	m_sprite.setPosition(sf::Vector2f(xpos, ypos));
}
*/

void Laser::setPosition(float x, float y) {
	if (m_valid) {
		m_sprite.setPosition(x, y);
		yori = y;
		xori = x;
		ypos = y;
		xpos = x;
	}
}

sf::Vector2f Laser::getPosition() const {
	if (m_valid)
		return m_sprite.getPosition();
	else
		return sf::Vector2f(0, 0);
}

void Laser::setScale(float scale) {
	if (m_valid)
		m_sprite.setScale(scale, scale);
}

void Laser::setState(float state) {
	Lstate = state;
	sf::IntRect rectSprite(state * 64.f, 0, 64.f, 64.f);
	sf::Sprite sprite(m_texture, rectSprite);
	m_sprite = sprite;
}