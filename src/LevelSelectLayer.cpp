#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(LevelSelectLayer) {

	bool init(int p0) {
		if (!LevelSelectLayer::init(p0))
			return false;

	if (auto bg = this->getChildByID("background")){

		bg->setZOrder(-3);
	}
	if (auto ground = this->getChildByID("ground-layer")){

		ground->setZOrder(-2);
	}

	auto DayAndNightSystem = DayAndNightSystem::create();
	DayAndNightSystem->setID("Events"_spr);
	this->addChild(DayAndNightSystem,-1);

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay,106);

		return true;
	}
};