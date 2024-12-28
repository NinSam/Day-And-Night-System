#include <Geode/Geode.hpp>
#include <Geode/modify/TutorialLayer.hpp>
#include "Utils/Utils.hpp"

using namespace geode::prelude;

class $modify(TutorialLayer) {

	bool init() {
		if (!TutorialLayer::init())
		return false;


	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);

	
		return true;
	}
};