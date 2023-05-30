#ifndef __SCONTROLLER_H
#define __SCONTROLLER_H

#include "SModel.h"

class SController {
public:
	SController(SModel& mdl);
	~SController();

	void Jump();
	void JumpTick(sf::Time deltaT);

	void GoRight(); // stop going right if they're on the ground and D is released OR if they're in the air and touch the ground
	void GoLeft();

	// sf::Time GetJumpTime();

private:
	SModel& model;
	// sf::Time jumpTime;

	sf::Vector2f gravity;
	sf::Vector2f velocity;

	int tick = 0;
};

#endif