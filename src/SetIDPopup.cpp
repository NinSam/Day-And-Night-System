#include <Geode/Geode.hpp>
#include <Geode/modify/SetIDPopup.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(SetIDPopup) {

	bool init(int current, int begin, int end, gd::string title, gd::string button, bool p5, int p6, float p7, bool p8, bool p9) {
		if (!SetIDPopup::init(current, begin, end, title, button, p5, p6, p7, p8, p9))
		return false;

	// This also gets SetFolderPopup

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

	
		return true;
	}
};