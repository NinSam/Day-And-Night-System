#include <Geode/Geode.hpp>
#include <Geode/modify/MessagesProfilePage.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(MessagesProfilePage) {

	bool init(bool p0) {
		if (!MessagesProfilePage::init(p0))
		return false;

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay,106);

		return true;
	}
};