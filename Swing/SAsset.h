#ifndef __SASSET_H
#define __SASSET_H

#include <SFML/Graphics.hpp>

class SAsset {
public:
	virtual ~SAsset() {}
	virtual void Draw(sf::RenderWindow& window) = 0;
};

#endif