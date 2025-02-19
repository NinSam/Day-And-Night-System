#include <Geode/Geode.hpp>
#include <Geode/modify/ShareLevelLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(ShareLevelLayer) {

	bool init(GJGameLevel* p0) {
		if (!ShareLevelLayer::init(p0))
		return false;


	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay,106);

	
		return true;
	}
};