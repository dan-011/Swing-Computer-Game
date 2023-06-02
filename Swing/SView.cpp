#include "SView.h"

SView::SView() : viewWidth(600), viewHeight(600), window(sf::VideoMode(1800, 900), "Swing", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize), eventReceived(false) {

}
SView::~SView() {}
void SView::Show() {	
	while (window.isOpen()) {
		eventReceived = window.pollEvent(event);
		Notify();
		window.clear(sf::Color(255, 255, 255));
		model.DrawAssets(window);
		window.display();
	}
}

sf::Event SView::GetEvent() {
	return event;
}

sf::RenderWindow& SView::GetWindow() {
	return window;
}

sf::Time SView::GetElapsedTime() {
	return clock.getElapsedTime();
}

SModel& SView::GetModel() {
	return model;
}

bool SView::GetEventReceived() {
	return eventReceived;
}