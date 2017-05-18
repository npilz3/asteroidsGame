#pragma once
#include <SFML/Graphics.hpp>

class Laser {
public:
	Laser();

	bool load(const std::string& filename);

	void draw(sf::RenderWindow& window);

	void setPosition(float x, float y);

	void move();

	sf::Vector2f getPosition() const;

	void setScale(float scale);

	void setState(float state);

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	std::string m_filename;
	bool m_valid = false;

	float xori;
	float yori;
	float xpos;
	float ypos;
	float Lstate;
	sf::Clock moveClock;
};