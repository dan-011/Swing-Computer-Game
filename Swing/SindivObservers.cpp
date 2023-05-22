#include "SIndivObservers.h"

SCloseWindowObserver::SCloseWindowObserver(SView& vw) : view(vw) {
	view.AddObserver(this);
}
void SCloseWindowObserver::Update() {
	if (view.GetEvent().type == sf::Event::Closed) {
		view.GetWindow().close();
	}
}