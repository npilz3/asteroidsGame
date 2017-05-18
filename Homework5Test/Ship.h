#pragma once
#include <SFML/Graphics.hpp>

class Ship {
public:
	Ship();

	bool load(const std::string& filename);

	void draw(sf::RenderWindow& window);

	void setPosition(float x, float y);

	void move(sf::Vector2f);

	sf::Vector2f getPosition() const;

	void animate();

	void setState(float num);

	void setScale(float scale);

	float returnCurrentState();

	bool isDead();

	void setDead();

	void playDead();

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	std::string m_filename;
	bool m_valid = false;
	bool isDeadBool = false;

	sf::Clock clockShip;
	sf::Clock deathClock;
	float currentState = 0;
	float phase = 0;

};
	