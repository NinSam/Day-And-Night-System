#include <Geode/Geode.hpp>
#include <Geode/modify/RateDemonLayer.hpp>
#include "Utils/Utils.hpp"

using namespace geode::prelude;

class $modify(RateDemonLayer) {

	bool init(int p0) {
		if (!RateDemonLayer::init(p0))
		return false;

    auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

		return true;
	}
};  