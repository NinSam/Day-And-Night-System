#include <Geode/Geode.hpp>
#include <Geode/modify/TutorialLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(TutorialLayer) {

	bool init() {
		if (!TutorialLayer::init())
		return false;


	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay,106);

	
		return true;
	}
};