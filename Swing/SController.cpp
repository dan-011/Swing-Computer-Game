#include "SController.h"

#include <iostream>
using namespace std;

SController::SController(SModel& mdl) : model(mdl), gravity(0, .01), velocity(0, 0) {}
SController::~SController() {}


void SController::Jump() {
	model.GetPlayer()->SetIsJumping(true);
	velocity.y = -2;
}

void SController::JumpTick(sf::Time deltaT) { // after changing position set x velocity to 0
	bool playerIsJumping = model.GetPlayer()->GetIsJumping();
	sf::Int32 dt = deltaT.asMilliseconds();

	int horizontalTravelOffset = 1;
	if (playerIsJumping) horizontalTravelOffset = 50;

	sf::Vector2f pos = model.GetPlayer()->GetPosition();
	pos.x = pos.x + (dt * velocity.x * horizontalTravelOffset);
	pos.y = pos.y + (dt * velocity.y); // update position

	velocity.y = velocity.y + (dt * gravity.y); // update velocity

	if (pos.y >= 500 - model.GetPlayer()->GetDimensions().y) {
		pos.y = 500 - model.GetPlayer()->GetDimensions().y;
		velocity = sf::Vector2f(0, 0);
		model.GetPlayer()->SetIsJumping(false);
		horizontalTravelOffset = 1;
	}
	model.GetPlayer()->SetPosition(pos);
}

/*
p' = p + dt*V
V' = V + dt*G
*/

void SController::GoRight() {
	velocity.x = .01;
}

void SController::GoLeft() {
	velocity.x = -.01;
}