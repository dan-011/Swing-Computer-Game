#ifndef __SABSTRACTOBSERVER_H
#define __SABSTRACTOBSERVER_H

class SAbstractObserver {
public:
	virtual ~SAbstractObserver() {}
	virtual void Update() = 0;
};

#endif
