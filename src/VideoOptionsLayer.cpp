#include <Geode/Geode.hpp>
#include <Geode/modify/VideoOptionsLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(VideoOptionsLayer) {

	bool init() {
		if (!VideoOptionsLayer::init())
		return false;


	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay,106);

	
		return true;
	}
};