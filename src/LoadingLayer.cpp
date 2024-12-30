/* 
#include <Geode/Geode.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include "Utils.hpp"

// CCSprites crash for some reason

using namespace geode::prelude;

class $modify(LoadingLayer) {

	bool init(bool p0) {
		if (!LoadingLayer::init(p0))

        return false;

	if (auto bg = this->getChildByID("bg-texture")){

	bg->setZOrder(-2);
	
	}

	auto DayAndNightSystem = DayAndNightSystem::create();
	DayAndNightSystem->setZOrder(-1);
	DayAndNightSystem->setID("Events"_spr);
	this->addChild(DayAndNightSystem);

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);
	
		return true;
	}
};
*/