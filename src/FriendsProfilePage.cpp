#include <Geode/Geode.hpp>
#include <Geode/modify/FriendsProfilePage.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(FriendsProfilePage) {

	bool init(UserListType p0) {
		if (!FriendsProfilePage::init(p0))
		return false;

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay,106);

		return true;
	}
};