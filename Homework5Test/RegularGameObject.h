#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class RegularGameObject : public GameObject {
public:
	RegularGameObject();

	bool load(const std::string& filename);

	void draw(sf::RenderWindow& window);

	void update(float deltaT) {}

	void setPosition(float x, float y);

	void move(sf::Vector2f);

	sf::Vector2f getPosition() const;

	float getHeight() const;

	float getWidth() const;

	void setScale(float scale);

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	std::string m_filename;
	bool m_valid = false;

};


