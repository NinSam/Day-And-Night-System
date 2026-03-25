#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/ObjectModify.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyModsLayer, ModsLayer){

    void modify(){
        
        auto DayAndNightSystem = DayAndNightSystem::create();
        DayAndNightSystem->setID("events"_spr);
        this->addChild(DayAndNightSystem, -2);
        
        auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
        DayAndNightSystemOverlay->setID("screen-overlay"_spr);
        this->addChild(DayAndNightSystemOverlay, 106);

        if (DayAndNightSystem::events > 0.99f){

            if (auto bg = this->getChildByID("SwelvyBG")){
			    bg->setVisible(false);
		    }
            else if (auto bg2 = this->getChildByID("bg")){
			    bg2->setVisible(false);
		    }

        }

    }

};