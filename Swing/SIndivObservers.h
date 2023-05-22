#ifndef __SINDIVOBSERVERS_H
#define __SINDIVOBSERVERS_H

#include "SAbstractObserver.h"
#include "SView.h"

class SCloseWindowObserver : public SAbstractObserver {
public:
	SCloseWindowObserver(SView& vw);
	virtual void Update() override;

private:
	SView& view;
};

// make an observer for spacebar to apply jump to controller

// make an observer for gravity that listens to elapsed time - controller will tell if anything should be done (if we are in the air)

#endif