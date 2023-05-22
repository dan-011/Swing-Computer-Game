#include "SPlayer.h"

SPlayer::SPlayer() : body(30), fillColor(0, 0, 255), pos(0, 0) {
	body.setFillColor(fillColor);
	body.setPosition(pos);
}
SPlayer::SPlayer(sf::Vector2f position) : body(30), fillColor(0, 0, 255), pos(position) {
	body.setFillColor(fillColor);
	body.setPosition(pos);
}
SPlayer::~SPlayer() {

}
void SPlayer::SetPosition(sf::Vector2f newPos) {
	pos = newPos;
	body.setPosition(pos);
}
sf::Vector2f SPlayer::GetPosition() {
	return pos;
}
sf::Vector2f SPlayer::GetDimensions() {
	return sf::Vector2f(body.getRadius() * 2, body.getRadius() * 2);
}
void SPlayer::Draw(sf::RenderWindow& window) {
	window.draw(body);
}