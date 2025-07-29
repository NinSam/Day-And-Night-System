#include <Geode/Geode.hpp>
#include <Geode/modify/RateStarsLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(RateStarsLayer) {

	bool init(int p0, bool p1, bool p2) {
		if (!RateStarsLayer::init(p0, p1, p2))
		return false;

    	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay,106);

		return true;
	}
};