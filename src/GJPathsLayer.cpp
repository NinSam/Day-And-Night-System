#include <Geode/Geode.hpp>
#include <Geode/modify/GJPathsLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(GJPathsLayer) {

	bool init() {
		if (!GJPathsLayer::init())
		return false;

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

		return true;
	}
};