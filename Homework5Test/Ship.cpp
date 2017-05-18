#include "ship.h"

Ship::Ship() {

}

bool Ship::load(const std::string& filename) {
	if (m_texture.loadFromFile(filename)) {
		m_filename = filename;
		sf::IntRect rectSprite(0, 0, 64, 64);
		sf::Sprite sprite(m_texture, rectSprite);
		m_sprite = sprite;
		m_valid = true;
		return true;
	}
	return false;
}

void Ship::draw(sf::RenderWindow& window) {
	if (m_valid)
		window.draw(m_sprite);
}

void Ship::move(sf::Vector2f loc) {
	if (m_valid)
		m_sprite.move(loc);
}

void Ship::setPosition(float x, float y) {
	if (m_valid)
		m_sprite.setPosition(x, y);
}

sf::Vector2f Ship::getPosition() const {
	if (m_valid)
		return m_sprite.getPosition();
	else
		return sf::Vector2f(0, 0);
}

void Ship::animate() {
	if (clockShip.getElapsedTime().asSeconds() > 0.2f) {
		if (phase >= 320.f) {
			phase = 0.f;
		}
		else {
			phase += 64.f;
		}
		clockShip.restart();
	}
	float state = currentState * 64;
	sf::IntRect rectSprite(state, phase, 64, 64);
	m_sprite.setTextureRect(rectSprite);
}

void Ship::setState(float num) {
	currentState = num;
}

void Ship::setScale(float scale) {
	if (m_valid)
		m_sprite.setScale(scale, scale);
}

float Ship::returnCurrentState() {
	return currentState;
}

bool Ship::isDead() {
	return isDeadBool;
}

void Ship::setDead() {
	isDeadBool = true;
}

void Ship::playDead() {
	if (deathClock.getElapsedTime().asSeconds() > 0.5f) {
		if (phase < 384.f) {
			phase = 384.f;
		}
		else {
			phase += 64.f;
		}
		deathClock.restart();
	}
	float state = currentState * 64;
	sf::IntRect rectSprite(state, phase, 64, 64);
	m_sprite.setTextureRect(rectSprite);
}