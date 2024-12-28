#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(MenuLayer) {

	bool init() {
		if (!MenuLayer::init())
		return false;

	auto bg = this->getChildByID("main-menu-bg");
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