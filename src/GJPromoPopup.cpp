#include <Geode/Geode.hpp>
#include <Geode/modify/GJPromoPopup.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(GJPromoPopup) {

	bool init(gd::string p0) {
		if (!GJPromoPopup::init(p0))
		return false;


	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay,106);

	
		return true;
	}
};