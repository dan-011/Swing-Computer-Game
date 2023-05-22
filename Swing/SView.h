#ifndef SVIEW_H
#define SVIEW_H

#include <SFML/Graphics.hpp>
#include "SSubject.h"
#include "SModel.h"

class SView : public SSubject {
public:
	SView();
	~SView();
	void Show();
	sf::Event GetEvent();
	sf::RenderWindow& GetWindow();
	sf::Time GetElapsedTime();
	SModel& GetModel();

private:
	unsigned int viewWidth;
	unsigned int viewHeight;
	sf::Event event;
	sf::RenderWindow window;
	SModel model;

	sf::Clock clock;

};

#endif