#include <Geode/Geode.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(LevelBrowserLayer) {

	bool init(GJSearchObject* p0) {
		if (!LevelBrowserLayer::init(p0))
		return false;

	auto bg = this->getChildByID("background");
	bg->setZOrder(-2);

	auto DayAndNightSystem = DayAndNightSystem::create();
	DayAndNightSystem->setZOrder(-1);
	DayAndNightSystem->setID("Events"_spr);
	this->addChild(DayAndNightSystem);

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

	
		return true;
	}
};