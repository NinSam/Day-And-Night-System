#include <Geode/Geode.hpp>
#include <Geode/modify/MessagesProfilePage.hpp>
#include "Utils/Utils.hpp"

using namespace geode::prelude;

class $modify(MessagesProfilePage) {

	bool init(bool p0) {
		if (!MessagesProfilePage::init(p0))
		return false;


	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

		return true;
	}
};