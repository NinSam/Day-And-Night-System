#include <Geode/Geode.hpp>
#include <Geode/modify/StarInfoPopup.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(StarInfoPopup) {

	bool init(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, bool p9) {
		if (!StarInfoPopup::init(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9))
		return false;

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

	
		return true;
	}
};