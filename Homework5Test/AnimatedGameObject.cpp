#include "AnimatedGameObject.h"
#include <SFML/Graphics.hpp>

AnimatedGameObject::AnimatedGameObject() {

}

bool AnimatedGameObject::load(const std::string& filename) {
	if (m_texture.loadFromFile(filename)) {
		m_filename = filename;
		m_sprite.setTexture(m_texture);
		m_valid = true;
		return true;
	}
	return false;
}

void AnimatedGameObject::animate(float x_ori, float y_ori, float x_win, float y_win) {
	//Sets the border for the Sprite Sheet
	sf::IntRect rectSourceSprite(x_ori, y_ori, x_win, y_win);
	sf::Sprite sprite(m_texture, rectSourceSprite);
	m_sprite = sprite;
}

void AnimatedGameObject::draw(sf::RenderWindow& window) {
	if (m_valid)
		window.draw(m_sprite);
}

void AnimatedGameObject::move(sf::Vector2f loc) {
	if (m_valid)
		m_sprite.move(loc);
}

void AnimatedGameObject::setPosition(float x, float y) {
	if (m_valid)
		m_sprite.setPosition(x, y);
}

sf::Vector2f AnimatedGameObject::getPosition() const {
	if (m_valid)
		return m_sprite.getPosition();
	else
		return sf::Vector2f(0, 0);
}

float AnimatedGameObject::getHeight() const {
	return m_sprite.getLocalBounds().height;
}

float AnimatedGameObject::getWidth() const {
	return m_sprite.getLocalBounds().width;
}

void AnimatedGameObject::setScale(float scale) {
	if (m_valid)
		m_sprite.setScale(scale, scale);
}