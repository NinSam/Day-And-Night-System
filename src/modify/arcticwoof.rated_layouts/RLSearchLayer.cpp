#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/ObjectModify.hpp>
#include <cue/RepeatingBackground.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyRLSearchLayer, RLSearchLayer){

    void modify(){

		auto DayAndNightSystem = DayAndNightSystem::create();
		DayAndNightSystem->setID("events"_spr);
		this->addChild(DayAndNightSystem, -1);

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("screen-overlay"_spr);
		this->addChild(DayAndNightSystemOverlay, 106);

		if (DayAndNightSystem::events > 0.99f){

			if (auto sideBottomLeft = this->getChildByID("side-art-bottom-left")){
				sideBottomLeft->setZOrder(3); 		
			}
			if (auto sideBottomRight = this->getChildByID("side-art-bottom-right")){
				sideBottomRight->setZOrder(3);   		
			}
			if (auto toggleMenu = this->getChildByID("demon-toggle-menu")){
				toggleMenu->setZOrder(2);   		
			}
			if (auto menu = getChildByType<CCMenu>(6)){  
				menu->setZOrder(4);           
        	}
			if (auto optionsMenu = this->getChildByID("options-menu")){ 
				optionsMenu->setZOrder(2);
			}
			if (auto filterMenu = this->getChildByID("difficulty-filter-menu")){
				filterMenu->setZOrder(2);
			}
			if (auto toggleFilterMenu = this->getChildByID("demon-filter-menu")){
				toggleFilterMenu->setZOrder(2); 
			}

			if (auto rBG = getChildByType<cue::RepeatingBackground>(0)){
            	rBG->setVisible(false);
        	}
			else if (auto bg = this->getChildByID("bg")){
			
				bg->removeFromParentAndCleanup(true); // there's a duplicate bg as of v0.4.3-beta-6

				if (auto bg2 = this->getChildByID("bg")){
					bg2->setVisible(false);
				}	
			
			}

		}

        if ((DayAndNightSystem::events == 1) || (DayAndNightSystem::events == 2)){
			
			for (int i = 0; i < 2; ++i){
                if (auto sprite = getChildByType<NineSlice>(i)){
                    sprite->setZOrder(1);
                }
            }
		
		}
		else if (DayAndNightSystem::events == 3){

			if (auto sprite = getChildByType<NineSlice>(0)){
                            
                sprite->setVisible(false);

				auto nineSliceFix = NineSlice::create("square02b_small.png");
				nineSliceFix->setPosition(sprite->getPosition());
				nineSliceFix->setContentSize(sprite->getContentSize());
                nineSliceFix->setColor(ccc3(0, 0, 140));
				nineSliceFix->setID("nine-slice-fix"_spr);
				this->addChild(nineSliceFix, 1);
            }
			if (auto sprite2 = getChildByType<NineSlice>(1)){
                            
                sprite2->setVisible(false);

				auto nineSliceFix2 = NineSlice::create("square02b_small.png");
				nineSliceFix2->setPosition(sprite2->getPosition());
				nineSliceFix2->setContentSize(sprite2->getContentSize());
                nineSliceFix2->setColor(ccc3(0, 0, 140));
				nineSliceFix2->setID("nine-slice-fix-2"_spr);
				this->addChild(nineSliceFix2, 1);
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
				this->addChild(nineSliceFix, 1);
            }
			if (auto sprite2 = getChildByType<NineSlice>(1)){
                            
                sprite2->setVisible(false);

				auto nineSliceFix2 = NineSlice::create("square02b_small.png");
				nineSliceFix2->setPosition(sprite2->getPosition());
				nineSliceFix2->setContentSize(sprite2->getContentSize());
                nineSliceFix2->setColor(ccc3(0, 0, 75));
				nineSliceFix2->setID("nine-slice-fix-2"_spr);
				this->addChild(nineSliceFix2, 1);
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