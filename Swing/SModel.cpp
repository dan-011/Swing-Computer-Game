#include "SModel.h"
#include "SPlayer.h"
#include "SPlatform.h"

SModel::SModel() : player(new SPlayer()) {
	SPlatform* platform = new SPlatform(sf::Vector2f(400, 50), sf::Vector2f(50, 500), sf::Color(0, 0, 0));
	player->SetPosition(sf::Vector2f(200, platform->GetPosition().y - player->GetDimensions().y));

	assets.push_back(platform);
	assets.push_back(player);
}
SModel::~SModel() {
	for (auto asset : assets) {
		delete asset;
	}
}
void SModel::DrawAssets(sf::RenderWindow& window) {
	for (auto asset : assets) {
		asset->Draw(window);
	}
}

SPlayer* SModel::GetPlayer() {
	return player;
}