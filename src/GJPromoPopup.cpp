#include <Geode/Geode.hpp>
#include <Geode/modify/GJPromoPopup.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(GJPromoPopup) {

	bool init(gd::string p0) {
		if (!GJPromoPopup::init(p0))
		return false;


	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

	
		return true;
	}
};