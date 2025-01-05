#include <Geode/Geode.hpp>
#include <Geode/modify/MenuGameLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(MenuGameLayer) {

	bool init() {
		if (!MenuGameLayer::init())
		return false;

	auto DayAndNightSystem = DayAndNightSystem::create();
	DayAndNightSystem->setZOrder(101);
	DayAndNightSystem->setID("Events"_spr);
	this->addChild(DayAndNightSystem);

		return true;
	}
};