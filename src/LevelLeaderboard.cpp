#include <Geode/Geode.hpp>
#include <Geode/modify/LevelLeaderboard.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(LevelLeaderboard) {

	bool init(GJGameLevel * p0, LevelLeaderboardType p1, LevelLeaderboardMode p2) {
		if (!LevelLeaderboard::init(p0, p1, p2))
		return false;

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

		return true;
	}
};