#pragma once

#include <SFML/Graphics.hpp>

class Meteor{
public: 
	Meteor();

	Meteor(float p1, float p2, float v1, float v2);

	virtual bool load(const std::string& filename) = 0;

	virtual void draw(sf::RenderWindow& window) = 0;

	virtual void update(float deltaT) = 0 {}

	virtual void setPosition(float x, float y) = 0;

	virtual void move() = 0;

	virtual void move(sf::Vector2f) = 0;

	virtual sf::Vector2f getPosition() const = 0;

	virtual float getHeight() const = 0;

	virtual float getWidth() const = 0;

	virtual void setScale(float scale) = 0;

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	std::string m_filename;
	sf::Clock clock;
	bool m_valid = false;
	float x_pos;
	float y_pos;
	float x_vel;
	float y_vel;
	float x_loc;
	float y_loc;

};