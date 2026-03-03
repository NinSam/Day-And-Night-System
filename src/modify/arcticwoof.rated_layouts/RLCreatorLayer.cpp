#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/ObjectModify.hpp>
#include <cue/RepeatingBackground.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyRLCreatorLayer, RLCreatorLayer){

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

        if (DayAndNightSystem::events == 3){

            
            if (auto sprite = getChildByType<NineSlice>(0)){

                sprite->setOpacity(0);

                auto nineSliceFix = NineSlice::create("square02b_small.png");
				nineSliceFix->setPosition(sprite->getPosition());
				nineSliceFix->setContentSize(sprite->getContentSize());
                nineSliceFix->setColor(ccc3(0, 30, 125));
				nineSliceFix->setID("nineSliceFix"_spr);
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
				nineSliceFix->setID("nineSliceFix"_spr);
				this->addChild(nineSliceFix, 9);
            }
            

        }
    }

};