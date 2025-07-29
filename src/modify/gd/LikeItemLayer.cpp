#include <Geode/Geode.hpp>
#include <Geode/modify/LikeItemLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(LikeItemLayer) {

	bool init(LikeItemType p0, int p1, int p2) {
		if (!LikeItemLayer::init(p0, p1, p2))
		return false;

    	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay,106);

		return true;
	}
};