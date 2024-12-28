#include <Geode/Geode.hpp>
#include <Geode/modify/RewardsPage.hpp>
#include "Utils/Utils.hpp"

using namespace geode::prelude;

class $modify(RewardsPage) {

	bool init() {
		if (!RewardsPage::init())
		return false;

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

		return true;
	}
};