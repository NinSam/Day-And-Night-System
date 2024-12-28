#include <Geode/Geode.hpp>
#include <Geode/modify/FRequestProfilePage.hpp>
#include "Utils/Utils.hpp"

using namespace geode::prelude;

class $modify(FRequestProfilePage) {

	bool init(bool p0) {
		if (!FRequestProfilePage::init(p0))
		return false;

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);
	
		return true;
	}
};