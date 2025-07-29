#include <Geode/Geode.hpp>
#include <Geode/modify/GJAccountSettingsLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(GJAccountSettingsLayer) {

	bool init(int p0) {
		if (!GJAccountSettingsLayer::init(p0))
		return false;

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay,106);

		return true;
	}
};