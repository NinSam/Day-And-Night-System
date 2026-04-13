#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/ObjectModify.hpp>
#include <cue/RepeatingBackground.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyRLMenuLayer, RLMenuLayer){

    void modify(){
        
        auto DayAndNightSystem = DayAndNightSystem::create();
        DayAndNightSystem->setID("events"_spr);
        this->addChild(DayAndNightSystem, -1);
        
        auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
        DayAndNightSystemOverlay->setID("screen-overlay"_spr);
        this->addChild(DayAndNightSystemOverlay, 106);

        if (DayAndNightSystem::events > 0.99f){

            if (auto rBG = getChildByType<cue::RepeatingBackground>(0)){
                rBG->setVisible(false); 
            }
            else if (auto bg = this->getChildByID("bg")){
			    bg->setVisible(false);
		    }

        }

        if (DayAndNightSystem::events == 3){

            
            if (auto sprite = getChildByType<NineSlice>(0)){

                sprite->setOpacity(0);

                auto nineSliceFix = NineSlice::create("square02b_small.png");
				nineSliceFix->setPosition(sprite->getPosition());
				nineSliceFix->setContentSize(sprite->getContentSize());
                nineSliceFix->setColor(ccc3(0, 0, 140));
				nineSliceFix->setID("nine-slice-fix"_spr);
				this->addChild(nineSliceFix, 9);
            }
            

        }
        else if (DayAndNightSystem::events == 4){

            
            if (auto sprite = getChildByType<NineSlice>(0)){

                sprite->setOpacity(0);

                auto nineSliceFix = NineSlice::create("square02b_small.png");
				nineSliceFix->setPosition(sprite->getPosition());
				nineSliceFix->setContentSize(sprite->getContentSize());
                nineSliceFix->setColor(ccc3(0, 0, 75));
				nineSliceFix->setID("nine-slice-fix"_spr);
				this->addChild(nineSliceFix, 9);
            }
            

        }
    }

};