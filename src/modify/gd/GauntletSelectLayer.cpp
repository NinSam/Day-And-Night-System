#include <Geode/Geode.hpp>
#include <Geode/modify/GauntletSelectLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(GauntletSelectLayer) {
    
    bool init(int p0) {
        if (!GauntletSelectLayer::init(p0)) 
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