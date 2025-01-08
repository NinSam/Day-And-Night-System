#include <Geode/Geode.hpp>
#include <Geode/modify/SetTextPopup.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(SetTextPopup) {

	bool init(gd::string p0, gd::string p1, int p2, gd::string p3, gd::string p4, bool p5, float p6) {
		if (!SetTextPopup::init(p0, p1, p2, p3, p4, p5, p6))
		return false;


	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

	
		return true;
	}
};