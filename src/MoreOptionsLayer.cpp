#include <Geode/Geode.hpp>
#include <Geode/modify/MoreOptionsLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(MoreOptionsLayer) {

	bool init() {
		if (!MoreOptionsLayer::init())
		return false;

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay,106);

		return true;
	}
};