#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(LevelSelectLayer) {

	bool init(int p0) {
		if (!LevelSelectLayer::init(p0))
		return false;

		auto DayAndNightSystem = DayAndNightSystem::create();
		DayAndNightSystem->setID("events"_spr);
		this->addChild(DayAndNightSystem, -1);

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("screen-overlay"_spr);
		this->addChild(DayAndNightSystemOverlay, 106);

		if (DayAndNightSystem::events > 0.99f){

			if (auto bg = this->getChildByID("background")){
				bg->setVisible(false);
			}
			if (auto ground = this->getChildByID("ground-layer")){
				ground->setVisible(false);
			}

		}

		return true;
	}
};