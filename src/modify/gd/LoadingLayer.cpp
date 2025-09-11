#include <Geode/Geode.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(LoadingLayer) {

	bool init(bool p0) {
		if (!LoadingLayer::init(p0))
		return false;

		auto path = dirs::getModRuntimeDir() / Mod::get()->getID() / "resources"; // ty alphalaneous
    	CCFileUtils::get()->addSearchPath(path.string().c_str());

		auto DayAndNightSystem = DayAndNightSystem::create();
		DayAndNightSystem->setID("Events"_spr);
		this->addChild(DayAndNightSystem,-1);

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay,106);

		if (auto bg = this->getChildByID("bg-texture")){
			bg->setZOrder(-2);
			if (DayAndNightSystem::events > 1){
				bg->setVisible(false);
			}
		}

		return true;
	}
};