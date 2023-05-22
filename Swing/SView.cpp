#include "SView.h"

SView::SView() : viewWidth(600), viewHeight(600), window(sf::VideoMode(600, 600), "Swing", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize) {

}
SView::~SView() {}
void SView::Show() {
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			Notify();
			if (!window.isOpen()) break;
		}
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