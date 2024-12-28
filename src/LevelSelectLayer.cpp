#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>
#include "Utils/Utils.hpp"

using namespace geode::prelude;

class $modify(LevelSelectLayer) {

	bool init(int p0) {
		if (!LevelSelectLayer::init(p0))
			return false;

	auto bg = this->getChildByID("background");
	bg->setZOrder(-3);

	auto ground = this->getChildByID("ground-layer");
	ground->setZOrder(-2);

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