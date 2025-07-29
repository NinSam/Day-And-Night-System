#include <Geode/Geode.hpp>
#include <Geode/modify/RateDemonLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(RateDemonLayer) {

	bool init(int p0) {
		if (!RateDemonLayer::init(p0))
		return false;

    	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay,106);

		return true;
	}
};  