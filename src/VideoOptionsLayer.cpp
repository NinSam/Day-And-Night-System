#include <Geode/Geode.hpp>
#include <Geode/modify/VideoOptionsLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(VideoOptionsLayer) {

	bool init() {
		if (!VideoOptionsLayer::init())
		return false;


	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

	
		return true;
	}
};