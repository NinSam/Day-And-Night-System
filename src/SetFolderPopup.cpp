#include <Geode/Geode.hpp>
#include <Geode/modify/SetFolderPopup.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(SetFolderPopup) {

	bool init(int value, bool isCreated, gd::string title) {
		if (!SetFolderPopup::init(value, isCreated, title))
		return false;

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

	
		return true;
	}
};