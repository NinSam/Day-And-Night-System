#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/ObjectModify.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyGYSettingSelectLayer, GYSettingSelectLayer){

    void modify(){

        auto DayAndNightSystem = DayAndNightSystem::create();
        DayAndNightSystem->setID("events"_spr);
        this->addChild(DayAndNightSystem, -2);
        
        auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
        DayAndNightSystemOverlay->setID("screen-overlay"_spr);
        this->addChild(DayAndNightSystemOverlay, 106);
        
        if (DayAndNightSystem::events > 0.99f){
            if (auto bg = this->getChildByID("background")){
			    bg->setVisible(false);
		    }
        }

        if (DayAndNightSystem::events == 3){

            if (auto sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("content-box"))){
				sprite->setColor(ccc3(0, 0, 140));
				sprite->setOpacity(255);
			}

        }
        else if (DayAndNightSystem::events == 4){

            if (auto sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("content-box"))){
				sprite->setColor(ccc3(0, 0, 75));
				sprite->setOpacity(255);
			}

        }
        
    }

};