#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/ObjectModify.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyGlobalListLayer, GlobalListLayer){

    void modify(){

        auto DayAndNightSystem = DayAndNightSystem::create();
        DayAndNightSystem->setID("events"_spr);
        this->addChild(DayAndNightSystem, -2);
        
        auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
        DayAndNightSystemOverlay->setID("screen-overlay"_spr);
        this->addChild(DayAndNightSystemOverlay, 106);

        if (DayAndNightSystem::events > 0.99f){
            if (auto bg = this->getChildByID("gdl-backgrownd")){
			    bg->setVisible(false);	
		    }
        }

        if ((DayAndNightSystem::events == 1) || (DayAndNightSystem::events == 2)){

            if (auto listLayer = typeinfo_cast<GJListLayer*>(this->getChildByID("GJListLayer"))){
                listLayer->setColor(ccc3(0, 0, 0));
            }

        }
        else if (DayAndNightSystem::events > 2.99f){

            if (auto listLayer = typeinfo_cast<GJListLayer*>(this->getChildByID("GJListLayer"))){

                listLayer->setOpacity(255);
                listLayer->setColor(ccc3(0, 0, 0));
                
            }

        }

    }

};