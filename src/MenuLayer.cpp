#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(MenuLayer) {

	bool init() {
		if (!MenuLayer::init())
		return false;

	if (auto bg = this->getChildByID("main-menu-bg")){

		bg->setZOrder(-2);
	}

	auto DayAndNightSystem = DayAndNightSystem::create();
	DayAndNightSystem->setID("Events"_spr);
	this->addChild(DayAndNightSystem,-1);

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay,106);

		return true;
	}
};