#include "SPlatform.h"

SPlatform::SPlatform(sf::Vector2f dimensions, sf::Vector2f position, sf::Color color) : dim(dimensions), pos(position), fillColor(color), body(dimensions) {
	body.setFillColor(fillColor);
	body.setPosition(pos);
}
SPlatform::~SPlatform() {}
void SPlatform::Draw(sf::RenderWindow& window) {
	window.draw(body);
}
sf::Vector2f SPlatform::GetPosition() {
	return body.getPosition();
}
sf::Vector2f SPlatform::GetDimensions() {
	return dim;
}