#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/NodeModding.h>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyMoreLeaderboards, MoreLeaderboards){

    void modify(){

        auto DayAndNightSystem = DayAndNightSystem::create();
        DayAndNightSystem->setID("Events"_spr);
        this->addChild(DayAndNightSystem,-1);
        
        auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
        DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
        this->addChild(DayAndNightSystemOverlay,106);

    }

};