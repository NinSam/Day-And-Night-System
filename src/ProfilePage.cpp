#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(ProfilePage) {

	bool init(int p0, bool p1) {
		if (!ProfilePage::init(p0, p1))
		return false;

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

		return true;
	}
};