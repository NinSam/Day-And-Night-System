#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/NodeModding.h>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyModsLayer, ModsLayer){

    void modify(){

        if (auto bg = this->getChildByID("SwelvyBG")){
			bg->setZOrder(-3);
		}
        if (auto bg2 = this->getChildByID("bg")){
			bg2->setZOrder(-3);
		}
        
        auto DayAndNightSystem = DayAndNightSystem::create();
        DayAndNightSystem->setID("Events"_spr);
        this->addChild(DayAndNightSystem,-2);
        
        auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
        DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
        this->addChild(DayAndNightSystemOverlay,106);

    }

};