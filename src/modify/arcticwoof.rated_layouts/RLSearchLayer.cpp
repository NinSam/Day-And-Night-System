#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/ObjectModify.hpp>
#include <cue/RepeatingBackground.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyRLSearchLayer, RLSearchLayer){

    void modify(){

		auto DayAndNightSystem = DayAndNightSystem::create();
		DayAndNightSystem->setID("events"_spr);
		this->addChild(DayAndNightSystem, -2);

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
                            
                sprite->setVisible(false);

				auto nineSliceFix = NineSlice::create("square02b_small.png");
				nineSliceFix->setPosition(sprite->getPosition());
				nineSliceFix->setContentSize(sprite->getContentSize());
                nineSliceFix->setColor(ccc3(0, 0, 140));
				nineSliceFix->setID("nine-slice-fix"_spr);
				this->addChild(nineSliceFix, -1);
            }
			if (auto sprite2 = getChildByType<NineSlice>(1)){
                            
                sprite2->setVisible(false);

				auto nineSliceFix2 = NineSlice::create("square02b_small.png");
				nineSliceFix2->setPosition(sprite2->getPosition());
				nineSliceFix2->setContentSize(sprite2->getContentSize());
                nineSliceFix2->setColor(ccc3(0, 0, 140));
				nineSliceFix2->setID("nine-slice-fix-2"_spr);
				this->addChild(nineSliceFix2, -1);
            }
            if (auto searchInputMenu = this->getChildByID("search-input-menu")){

				if (auto searchInputMenuBG = typeinfo_cast<NineSlice*>(searchInputMenu->getChildByIndex(0))){
					searchInputMenuBG->setVisible(false);
				}

                auto nineSliceInput = NineSlice::create("square02b_small.png");
				nineSliceInput->setPosition(searchInputMenu->getPosition());
				nineSliceInput->setContentSize(searchInputMenu->getContentSize());
                nineSliceInput->setColor(ccc3(0, 0, 140));
				nineSliceInput->setID("nine-slice-input-fix"_spr);
				this->addChild(nineSliceInput, -1);
                    
		    }
		}
		else if (DayAndNightSystem::events == 4){

			if (auto sprite = getChildByType<NineSlice>(0)){
                            
                sprite->setVisible(false);

				auto nineSliceFix = NineSlice::create("square02b_small.png");
				nineSliceFix->setPosition(sprite->getPosition());
				nineSliceFix->setContentSize(sprite->getContentSize());
                nineSliceFix->setColor(ccc3(0, 0, 75));
				nineSliceFix->setID("nine-slice-fix"_spr);
				this->addChild(nineSliceFix, -1);
            }
			if (auto sprite2 = getChildByType<NineSlice>(1)){
                            
                sprite2->setVisible(false);

				auto nineSliceFix2 = NineSlice::create("square02b_small.png");
				nineSliceFix2->setPosition(sprite2->getPosition());
				nineSliceFix2->setContentSize(sprite2->getContentSize());
                nineSliceFix2->setColor(ccc3(0, 0, 75));
				nineSliceFix2->setID("nine-slice-fix-2"_spr);
				this->addChild(nineSliceFix2, -1);
            }
            if (auto searchInputMenu = this->getChildByID("search-input-menu")){

				if (auto searchInputMenuBG = typeinfo_cast<NineSlice*>(searchInputMenu->getChildByIndex(0))){
					searchInputMenuBG->setVisible(false);
				}

                auto nineSliceInput = NineSlice::create("square02b_small.png");
				nineSliceInput->setPosition(searchInputMenu->getPosition());
				nineSliceInput->setContentSize(searchInputMenu->getContentSize());
                nineSliceInput->setColor(ccc3(0, 0, 75));
				nineSliceInput->setID("nine-slice-input-fix"_spr);
				this->addChild(nineSliceInput, -1);
                    
		    }
			
		}
    }
};