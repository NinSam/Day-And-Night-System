#include <Geode/Geode.hpp>
#include <Geode/modify/FriendsProfilePage.hpp>
#include "Utils/Utils.hpp"

using namespace geode::prelude;

class $modify(FriendsProfilePage) {

	bool init(UserListType p0) {
		if (!FriendsProfilePage::init(p0))
		return false;

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

		return true;
	}
};