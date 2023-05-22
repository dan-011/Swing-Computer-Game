#ifndef __SPLATFORM_H
#define __SPLATFORM_H

#include "SAsset.h"

class SPlatform : public SAsset {
public:
	SPlatform(sf::Vector2f dimensions, sf::Vector2f position, sf::Color color);
	~SPlatform();
	virtual void Draw(sf::RenderWindow& window) override;
	sf::Vector2f GetPosition();
	sf::Vector2f GetDimensions();

public:
	sf::RectangleShape body;
	sf::Vector2f pos;
	sf::Vector2f dim;
	sf::Color fillColor;
};

#endif