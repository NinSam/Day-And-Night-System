#include <Geode/Geode.hpp>
#include <Geode/modify/MoreSearchLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(MoreSearchLayer) {

	bool init() {
		if (!MoreSearchLayer::init())
		return false;

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay,106);

		return true;
	}
};