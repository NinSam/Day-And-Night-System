#include <Geode/Geode.hpp>
#include <Geode/modify/ChallengesPage.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(ChallengesPage) {

	bool init() {
		if (!ChallengesPage::init())
		return false;

    auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay,106);

		return true;
	}
};