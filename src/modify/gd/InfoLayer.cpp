#include <Geode/Geode.hpp>
#include <Geode/modify/InfoLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(InfoLayer) {

	bool init(GJGameLevel * p0, GJUserScore * p1, GJLevelList * p2) {
		if (!InfoLayer::init(p0, p1, p2))
		return false;

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay,106);

		return true;
	}
};