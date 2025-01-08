#include <Geode/Geode.hpp>
#include <Geode/modify/UploadActionPopup.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(UploadActionPopup) {

	bool init(UploadPopupDelegate* p0, gd::string str) {
		if (!UploadActionPopup::init(p0,str))
		return false;

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

		return true;
	}
};