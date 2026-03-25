#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/ObjectModify.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyRandomLayer, RandomLayer) {

    void modify(){

		auto DayAndNightSystem = DayAndNightSystem::create();
		DayAndNightSystem->setID("events"_spr);
		this->addChild(DayAndNightSystem, -2);

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("screen-overlay"_spr);
		this->addChild(DayAndNightSystemOverlay, 106);
        
        if (DayAndNightSystem::events > 0.99f){
            if (auto sprite = getChildByType<CCSprite>(-1)){
			    sprite->setVisible(false);
		    }
        }
		
    	if ((DayAndNightSystem::events == 1) || (DayAndNightSystem::events == 2)){
			
            for (int i = 0; i < 4; ++i){
                if (auto sprite = getChildByType<NineSlice>(i)){

                    sprite->setColor(ccc3(0, 0, 0));
                    sprite->setOpacity(90);
                }

            }			
		
		}
		else if (DayAndNightSystem::events == 3){

            for (int i = 0; i < 4; ++i){
                if (auto sprite = getChildByType<NineSlice>(i)){

                    sprite->setColor(ccc3(0, 0, 140));
                }

            }

		}
		else if (DayAndNightSystem::events == 4){

            for (int i = 0; i < 4; ++i){
                if (auto sprite = getChildByType<NineSlice>(i)){
                            
                    sprite->setColor(ccc3(0, 0, 75));
                }

            }

		}
    }
};