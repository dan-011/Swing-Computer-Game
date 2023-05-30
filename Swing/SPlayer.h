#ifndef __SPLAYER_H
#define __SPLAYER_H

#include "SAsset.h"
#include <SFML/Graphics.hpp>

class SPlayer : public SAsset {
public:
	SPlayer();
	SPlayer(sf::Vector2f position);
	~SPlayer();
	void SetPosition(sf::Vector2f newPos);
	sf::Vector2f GetPosition();
	sf::Vector2f GetDimensions();
	virtual void Draw(sf::RenderWindow& window) override;

	void SetIsJumping(bool jumping);
	bool GetIsJumping();

private:
	sf::CircleShape body;
	sf::Color fillColor;
	sf::Vector2f pos;
	bool isJumping;
};

#endif