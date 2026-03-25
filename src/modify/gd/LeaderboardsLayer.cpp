
#include <Geode/Geode.hpp>
#include <Geode/modify/LeaderboardsLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(LeaderboardsLayer) {

	bool init(LeaderboardType p0, LeaderboardStat p1) {
		if (!LeaderboardsLayer::init(p0, p1))
		return false;

		auto DayAndNightSystem = DayAndNightSystem::create();
		DayAndNightSystem->setID("events"_spr);
		this->addChild(DayAndNightSystem, -2);

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("screen-overlay"_spr);
		this->addChild(DayAndNightSystemOverlay, 106);

		if (DayAndNightSystem::events > 0.99f){
			if (auto bg = this->getChildByID("background")){
				bg->setVisible(false);
			}
		}

	
		return true;
	}
};