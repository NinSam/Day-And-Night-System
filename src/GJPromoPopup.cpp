#include <Geode/Geode.hpp>
#include <Geode/modify/GJPromoPopup.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(GJPromoPopup) {

	#ifdef GEODE_IS_INTEL_MAC

	bool init(gd::string p0) {
		if (!GJPromoPopup::init(p0))
		return false;


	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay,106);

	
		return true;
	}
	#endif
	#ifdef GEODE_IS_WINDOWS
	bool init(gd::string p0) {
		if (!GJPromoPopup::init(p0))
		return false;


	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay,106);

	
		return true;
	}
	#endif
	#ifdef GEODE_IS_ANDROID
	bool init(gd::string p0) {
		if (!GJPromoPopup::init(p0))
		return false;


	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay,106);

	
		return true;
	}
	#endif
};