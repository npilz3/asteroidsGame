#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class AnimatedGameObject : public GameObject {
public:
	AnimatedGameObject();

	bool load(const std::string& filename);

	void draw(sf::RenderWindow& window);

	void update(float deltaT) {}

	void setPosition(float x, float y);

	void move(sf::Vector2f);

	sf::Vector2f getPosition() const;

	float getHeight() const;

	float getWidth() const;

	void setScale(float scale);

	void animate(float x_ori, float y_ori, float x_win, float y_win);

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	std::string m_filename;
	bool m_valid = false;

};