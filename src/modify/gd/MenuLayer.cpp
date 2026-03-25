#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(MenuLayer) {

	bool init() {
		if (!MenuLayer::init())
		return false;

		auto DayAndNightSystem = DayAndNightSystem::create();
		DayAndNightSystem->setID("events"_spr);
		this->addChild(DayAndNightSystem, -1);

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("screen-overlay"_spr);
		this->addChild(DayAndNightSystemOverlay, 99);

		if (DayAndNightSystem::events > 0.99f){
			if (auto bg = this->getChildByID("main-menu-bg")){
				bg->setVisible(false);
			}
			if (auto bg2 = this->getChildByID("shader-background")){
				bg2->setVisible(false);
			}
		}

		return true;
	}
};