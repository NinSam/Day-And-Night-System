#include <Geode/Geode.hpp>
#include <Geode/modify/DailyLevelPage.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(DailyLevelPage) {

	bool init(GJTimedLevelType p0) {
		if (!DailyLevelPage::init(p0))
		return false;

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay,106);

		return true;
	}
};