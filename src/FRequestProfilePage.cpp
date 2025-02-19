#include <Geode/Geode.hpp>
#include <Geode/modify/FRequestProfilePage.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(FRequestProfilePage) {

	bool init(bool p0) {
		if (!FRequestProfilePage::init(p0))
		return false;

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay,106);
	
		return true;
	}
};