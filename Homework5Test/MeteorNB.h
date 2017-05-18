#pragma once

#include <SFML/Graphics.hpp>
#include "Meteor.h"

class MeteorNB: public Meteor {
public:
	MeteorNB();

	MeteorNB(float p1, float p2, float v1, float v2);

	virtual bool load(const std::string& filename);

	virtual void draw(sf::RenderWindow& window);

	virtual void update(float deltaT) {}

	virtual void setPosition(float x, float y);

	virtual void move();

	virtual void move(sf::Vector2f);

	virtual sf::Vector2f getPosition() const;

	virtual float getHeight() const;

	virtual float getWidth() const;

	virtual void setScale(float scale);

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
	int side;
};