#include <Geode/Geode.hpp>
#include <Geode/modify/MoreOptionsLayer.hpp>
#include "Utils/Utils.hpp"

using namespace geode::prelude;

class $modify(MoreOptionsLayer) {

	bool init() {
		if (!MoreOptionsLayer::init())
		return false;

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

		return true;
	}
};