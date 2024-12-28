#include <Geode/Geode.hpp>
#include <Geode/modify/ChallengesPage.hpp>
#include "Utils/Utils.hpp"

using namespace geode::prelude;

class $modify(ChallengesPage) {

	bool init() {
		if (!ChallengesPage::init())
		return false;

    auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

		return true;
	}
};