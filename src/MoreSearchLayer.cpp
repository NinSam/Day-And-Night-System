#include <Geode/Geode.hpp>
#include <Geode/modify/MoreSearchLayer.hpp>
#include "Utils/Utils.hpp"

using namespace geode::prelude;

class $modify(MoreSearchLayer) {

	bool init() {
		if (!MoreSearchLayer::init())
		return false;

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

	
		return true;
	}
};