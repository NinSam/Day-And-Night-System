#include <Geode/Geode.hpp>
#include <Geode/modify/GauntletLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(GauntletLayer) {

	bool init(GauntletType p0) {
        if (!GauntletLayer::init(p0)) 
        return false;

        auto DayAndNightSystem = DayAndNightSystem::create();
        DayAndNightSystem->setID("Events"_spr);
        this->addChild(DayAndNightSystem,-1);
        
        auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
        DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
        this->addChild(DayAndNightSystemOverlay,106);

        if (auto bg = this->getChildByID("background")){
			bg->setZOrder(-2);
            if (DayAndNightSystem::events > 1){
				bg->setVisible(false);
			}
		}
        
        return true;
    }
};