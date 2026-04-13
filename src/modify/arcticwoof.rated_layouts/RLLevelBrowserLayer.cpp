#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/ObjectModify.hpp>
#include <cue/RepeatingBackground.hpp>
#include <cue/ListNode.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyRLLevelBrowserLayer, RLLevelBrowserLayer){

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

            if (auto gjListLayer = this->getChildByType<cue::ListNode>(0)){

                if (auto getScrollBar = gjListLayer->getChildByType<Scrollbar>(0)){

                    if (auto getScrollBarColor = getScrollBar->getChildByType<NineSlice>(0)){

                        getScrollBarColor->setColor(ccc3(0, 0, 140));
                        getScrollBarColor->setOpacity(255);

                    }

                }

            }

        }
        else if (DayAndNightSystem::events == 4){

            if (auto gjListLayer = this->getChildByType<cue::ListNode>(0)){

                if (auto getScrollBar = gjListLayer->getChildByType<Scrollbar>(0)){

                    if (auto getScrollBarColor = getScrollBar->getChildByType<NineSlice>(0)){

                        getScrollBarColor->setColor(ccc3(0, 0, 75));
                        getScrollBarColor->setOpacity(255);

                    }

                }

            }

        }
        
    }

};