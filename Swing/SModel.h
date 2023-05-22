#ifndef __SMODEL_H
#define __SMODEL_H

#include <vector>
#include "SAsset.h"
#include "SPlayer.h"

using namespace std;

class SModel {
public:
	SModel();
	~SModel();
	void DrawAssets(sf::RenderWindow& window);
	SPlayer* GetPlayer();

private:
	vector<SAsset*> assets;
	SPlayer* player;
};

#endif