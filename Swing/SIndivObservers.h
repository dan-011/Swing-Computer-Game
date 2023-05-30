#ifndef __SINDIVOBSERVERS_H
#define __SINDIVOBSERVERS_H

#include "SAbstractObserver.h"
#include "SView.h"
#include "SController.h"

class SCloseWindowObserver : public SAbstractObserver {
public:
	SCloseWindowObserver(SView& vw);
	~SCloseWindowObserver();
	virtual void Update() override;

private:
	SView& view;
};

// make an observer for spacebar to apply jump to controller
class SJumpObserver : public SAbstractObserver {
public:
	SJumpObserver(SView& vw, SController& controller);
	~SJumpObserver();
	virtual void Update() override;

private:
	SView& view;
	SController& ctrl;
};


// make an observer for gravity that listens to elapsed time - controller will tell if anything should be done (if we are in the air)
class STickObserver : public SAbstractObserver {
public:
	STickObserver(SView& vw, SController& controller);
	~STickObserver();
	virtual void Update() override;

private:
	SView& view;
	SController& ctrl;
	sf::Time deltaT;
	sf::Time currentTime;
};

class SRightObserver : public SAbstractObserver {
public:
	SRightObserver(SView& vw, SController& controller);
	~SRightObserver();
	virtual void Update() override;

private:
	SView& view;
	SController& ctrl;
};

class SLeftObserver : public SAbstractObserver {
public:
	SLeftObserver(SView& vw, SController& controller);
	~SLeftObserver();
	virtual void Update() override;

private:
	SView& view;
	SController& ctrl;
};
#endif