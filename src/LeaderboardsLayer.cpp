#include <Geode/Geode.hpp>
#include <Geode/modify/LeaderboardsLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(LeaderboardsLayer) {

	bool init(LeaderboardState p0) {
		if (!LeaderboardsLayer::init(p0))
		return false;

	auto bg = this->getChildByID("background");
	bg->setZOrder(-3);

	auto DayAndNightSystem = DayAndNightSystem::create();
	DayAndNightSystem->setZOrder(-2);
	DayAndNightSystem->setID("Events"_spr);
	this->addChild(DayAndNightSystem);

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

	
		return true;
	}
};