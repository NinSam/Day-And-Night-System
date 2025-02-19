#include <Geode/Geode.hpp>
#include <Geode/modify/LeaderboardsLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(LeaderboardsLayer) {

	bool init(LeaderboardState p0) {
		if (!LeaderboardsLayer::init(p0))
		return false;

	if (auto bg = this->getChildByID("background")){
		
		bg->setZOrder(-3);
	}

	auto DayAndNightSystem = DayAndNightSystem::create();
	DayAndNightSystem->setID("Events"_spr);
	this->addChild(DayAndNightSystem,-2);

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay,106);

	
		return true;
	}
};