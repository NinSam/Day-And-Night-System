#include <Geode/Geode.hpp>
#include <Geode/modify/ShareLevelSettingsLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(ShareLevelSettingsLayer) {

	bool init(GJGameLevel* p0) {
		if (!ShareLevelSettingsLayer::init(p0))
		return false;


	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay,106);

	
		return true;
	}
};