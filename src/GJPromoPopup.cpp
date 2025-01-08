#include <Geode/Geode.hpp>
#include <Geode/modify/GJPromoPopup.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(GJPromoPopup) {

	#ifdef GEODE_IS_MACOS_INTEL

	bool init(gd::string p0) {
		if (!GJPromoPopup::init(p0))
		return false;


	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

	
		return true;
	}
	#endif
	#ifdef GEODE_IS_WINDOWS
	bool init(gd::string p0) {
		if (!GJPromoPopup::init(p0))
		return false;


	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

	
		return true;
	}
	#endif
	#ifdef GEODE_IS_ANDROID
	bool init(gd::string p0) {
		if (!GJPromoPopup::init(p0))
		return false;


	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

	
		return true;
	}
	#endif
};