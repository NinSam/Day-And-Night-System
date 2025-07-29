#include <Geode/Geode.hpp>
#include <Geode/modify/RewardsPage.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(RewardsPage) {

	bool init() {
		if (!RewardsPage::init())
		return false;

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay,106);

		return true;
	}
};