#include "SSubject.h"

SSubject::~SSubject() {}
void SSubject::AddObserver(SAbstractObserver* observer) {
	observers.push_back(observer);
}
void SSubject::Notify() {
	for (auto obs : observers) {
		obs->Update();
	}
}
