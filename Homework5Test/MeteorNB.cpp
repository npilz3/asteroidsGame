#include "MeteorNB.h"

MeteorNB::MeteorNB() {
	srand(rand());
	side = rand() % 8;
	if (side == 0) { //top left side of map
		x_loc = rand() % 640 - 64;
		y_loc = -64.0f;
		x_vel = rand() % 15 + 10;
		y_vel = rand() % 15 + 10;
	}
	else if (side == 1) { //top right side of map
		x_loc = rand() % 640 + 640;
		y_loc = -64.0f;
		x_vel = rand() % 15 - 26;
		y_vel = rand() % 15 + 10;
	}
	else if (side == 2) { //bottom left side of map
		x_loc = rand() % 640 - 64;
		y_loc = 720.0f;
		x_vel = rand() % 15 + 10;
		y_vel = rand() % 15 - 26;
	}
	else if (side == 3) { //bottom right side of map
		x_loc = rand() % 640 + 640;
		y_loc = 720.0f;
		x_vel = rand() % 15 - 26;
		y_vel = rand() % 15 - 26;
	}
	else if (side == 4) { //right upper side of map
		x_loc = 1280.0f;
		y_loc = rand() % 360 - 64;
		x_vel = rand() % 15 - 26;
		y_vel = rand() % 15 + 10;
	}
	else if (side == 5) { //right lower side of map
		x_loc = 1280.0f;
		y_loc = rand() % 360 + 360;
		x_vel = rand() % 15 - 26;
		y_vel = rand() % 15 - 26;
	}
	else if (side == 6) { //left upper side of map
		x_loc = -64.0f;
		y_loc = rand() % 360 - 64;
		x_vel = rand() % 15 + 10;
		y_vel = rand() % 15 + 10;
	}
	else { //left lower side of map
		x_loc = -64.0f;
		y_loc = rand() % 360 + 360;
		x_vel = rand() % 15 + 10;
		y_vel = rand() % 15 - 26;
	}
	x_pos = x_loc;
	y_pos = y_loc;
}

MeteorNB::MeteorNB(float p1, float p2, float v1, float v2) {
	x_loc = p1;
	y_loc = p2;
	x_pos = p1;
	y_pos = p2;
	x_vel = v1;
	y_vel = v2;
	side = 0;
}

bool MeteorNB::load(const std::string& filename) {
	if (m_texture.loadFromFile(filename)) {
		m_filename = filename;
		sf::IntRect a(0, 0, 64, 64);
		m_sprite.setTexture(m_texture);
		m_sprite.setTextureRect(a);
		m_valid = true;
		return true;
	}
	return false;
}

void MeteorNB::draw(sf::RenderWindow& window) {
	if (m_valid)
		window.draw(m_sprite);
}

void MeteorNB::move() {
	x_pos = x_loc + x_vel * clock.getElapsedTime().asSeconds();
	y_pos = y_loc + y_vel * clock.getElapsedTime().asSeconds();
	if (m_valid)
		m_sprite.setPosition(x_pos, y_pos);
}

void MeteorNB::move(sf::Vector2f loc) {
	if (m_valid)
		m_sprite.move(loc);
}

void MeteorNB::setPosition(float x, float y) {
	if (m_valid)
		m_sprite.setPosition(x, y);
}

sf::Vector2f MeteorNB::getPosition() const {
	if (m_valid)
		return m_sprite.getPosition();
	else
		return sf::Vector2f(0, 0);
}

float MeteorNB::getHeight() const {
	return m_sprite.getLocalBounds().height;
}

float MeteorNB::getWidth() const {
	return m_sprite.getLocalBounds().width;
}

void MeteorNB::setScale(float scale) {
	if (m_valid)
		m_sprite.setScale(scale, scale);
}