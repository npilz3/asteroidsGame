#include "Meteor.h"

Meteor::Meteor() {
	float x_pos = 50;
	float y_pos = 50;
	float x_vel = 20;
	float y_vel = 20;
	sf::Clock clock;
}

Meteor::Meteor(float p1, float p2, float v1, float v2) {
	float x_pos = p1;
	float y_pos = p2;
	float x_vel = v1;
	float y_vel = v2;
	sf::Clock clock;
}

bool Meteor::load(const std::string& filename) {
	if (m_texture.loadFromFile(filename)) {
		m_filename = filename;
		m_sprite.setTexture(m_texture);
		m_valid = true;
		return true;
	}
	return false;
}

void Meteor::draw(sf::RenderWindow& window) {
	if (m_valid)
		window.draw(m_sprite);
}

void Meteor::move() {
	sf::Vector2f mov(x_pos, y_pos);
	mov.x += x_vel * clock.getElapsedTime().asSeconds();
	mov.y += y_vel * clock.getElapsedTime().asSeconds();
	if (m_valid)
		m_sprite.move(mov);
}

void Meteor::move(sf::Vector2f loc) {
	if (m_valid)
		m_sprite.move(loc);
}

void Meteor::setPosition(float x, float y) {
	if (m_valid)
		m_sprite.setPosition(x, y);
}

sf::Vector2f Meteor::getPosition() const {
	if (m_valid)
		return m_sprite.getPosition();
	else
		return sf::Vector2f(0, 0);
}

float Meteor::getHeight() const {
	return m_sprite.getLocalBounds().height;
}

float Meteor::getWidth() const {
	return m_sprite.getLocalBounds().width;
}

void Meteor::setScale(float scale) {
	if (m_valid)
		m_sprite.setScale(scale, scale);
}