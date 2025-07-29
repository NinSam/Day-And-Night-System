#include <Geode/Geode.hpp>
#include <Geode/modify/MoreVideoOptionsLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(MoreVideoOptionsLayer) {

	bool init() {
		if (!MoreVideoOptionsLayer::init())
		return false;

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay,106);
	
		return true;
	}
};