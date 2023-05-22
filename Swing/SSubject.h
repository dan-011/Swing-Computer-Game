#ifndef __SSUBJECT_H
#define __SSUBJECT_H

#include <vector>
#include "SAbstractObserver.h"

class SSubject {
public:
	virtual ~SSubject();
	void AddObserver(SAbstractObserver* observer);
	void Notify();

private:
	std::vector<SAbstractObserver*> observers;
};

#endif