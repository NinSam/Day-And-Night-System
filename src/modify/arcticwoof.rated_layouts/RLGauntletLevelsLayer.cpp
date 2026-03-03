#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/ObjectModify.hpp>
#include <cue/RepeatingBackground.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyRLGauntletLevelsLayer, RLGauntletLevelsLayer){

    void modify(){

        auto DayAndNightSystem = DayAndNightSystem::create();
        DayAndNightSystem->setID("Events"_spr);
        this->addChild(DayAndNightSystem, -1);
        
        auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
        DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
        this->addChild(DayAndNightSystemOverlay, 106);

        if (auto rBG = getChildByType<cue::RepeatingBackground>(0)){
            if (DayAndNightSystem::events > 0.99f){
                rBG->setVisible(false);
            }
        }
        
    
    }

};