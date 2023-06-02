#include "SIndivObservers.h"

SCloseWindowObserver::SCloseWindowObserver(SView& vw) : view(vw) {
	view.AddObserver(this);
}
SCloseWindowObserver::~SCloseWindowObserver() {}
void SCloseWindowObserver::Update() {
	if ((view.GetEventReceived() && view.GetEvent().type == sf::Event::Closed) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		view.GetWindow().close();
	}
}

SJumpObserver::SJumpObserver(SView& vw, SController& controller): view(vw), ctrl(controller) {
	view.AddObserver(this);
}
SJumpObserver::~SJumpObserver() {}
#include <iostream>
using namespace std;
void SJumpObserver::Update() {
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && !view.GetModel().GetPlayer()->GetIsJumping()) {
		ctrl.Jump();
	}
}


// make an observer for gravity that listens to elapsed time - controller will tell if anything should be done (if we are in the air)
STickObserver::STickObserver(SView& vw, SController& controller) : view(vw), ctrl(controller), deltaT(sf::milliseconds(25)), currentTime(sf::microseconds(0)) {
	view.AddObserver(this);
}

// delta t = 25
STickObserver::~STickObserver() {}
void STickObserver::Update() {
	if (view.GetModel().GetPlayer()->GetIsJumping() && currentTime == sf::milliseconds(0)) { // if jumping has been initiated and we have not recorded start time
		currentTime = view.GetElapsedTime();
	}
	else if (!view.GetModel().GetPlayer()->GetIsJumping()) { // if jumping has finished
		currentTime = sf::milliseconds(0);
	}
	if (view.GetElapsedTime() - currentTime >= deltaT) { // if we are currently jumping
		ctrl.JumpTick(deltaT);
		currentTime = view.GetElapsedTime();
	}
}
SRightObserver::SRightObserver(SView& vw, SController& controller): view(vw), ctrl(controller) {
	view.AddObserver(this);
}
SRightObserver::~SRightObserver() {}
void SRightObserver::Update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		ctrl.GoRight();
	}
}

SLeftObserver::SLeftObserver(SView& vw, SController& controller) : view(vw), ctrl(controller) {
	view.AddObserver(this);
}
SLeftObserver::~SLeftObserver() {}
void SLeftObserver::Update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		ctrl.GoLeft();
	}
}