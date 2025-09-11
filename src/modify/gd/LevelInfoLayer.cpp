#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(LevelInfoLayer) {

	bool init(GJGameLevel* p0, bool p1) {
		if (!LevelInfoLayer::init(p0, p1))
		return false;
		
		auto DayAndNightSystem = DayAndNightSystem::create();
		DayAndNightSystem->setID("Events"_spr);
		this->addChild(DayAndNightSystem,-1);

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay,106);

		if (auto bg = this->getChildByID("background")){
			if (DayAndNightSystem::events > 1){
				bg->setVisible(false);
			}
		}

		return true;
	}
};