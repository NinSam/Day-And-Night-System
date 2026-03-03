#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/ObjectModify.hpp>
#include <cue/RepeatingBackground.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyRLSearchLayer, RLSearchLayer){

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

        if ((DayAndNightSystem::events == 1) || (DayAndNightSystem::events == 2)){
			
			for (int i = 0; i < 2; ++i){
                if (auto sprite = getChildByType<NineSlice>(i)){

                    sprite->setZOrder(1);
                }

            }
			for (int i = 6; i < 7; ++i){
                if (auto menu = getChildByType<CCMenu>(i)){
                            
                    menu->setZOrder(4);
                }

            }

			if (auto sideBottomLeft = this->getChildByID("side-art-bottom-left")){
                    
				sideBottomLeft->setZOrder(3); 
		    }
			if (auto sideBottomRight = this->getChildByID("side-art-bottom-right")){
                    
				sideBottomRight->setZOrder(3); 
		    }
            if (auto toggleMenu = this->getChildByID("demon-toggle-menu")){
                    
				toggleMenu->setZOrder(2); 
		    }
            if (auto optionsMenu = this->getChildByID("options-menu")){
                    
				optionsMenu->setZOrder(2);
		    }
            if (auto filterMenu = this->getChildByID("difficulty-filter-menu")){
                    
				filterMenu->setZOrder(2);
		    }
		
		}
		else if (DayAndNightSystem::events == 3){

			for (int i = 0; i < 2; ++i){
                if (auto sprite = getChildByType<NineSlice>(i)){

                    sprite->setVisible(false);
                }

            }
			for (int i = 6; i < 7; ++i){
                if (auto menu = getChildByType<CCMenu>(i)){
                            
                    menu->setZOrder(4);
                }

            }

			if (auto sideBottomLeft = this->getChildByID("side-art-bottom-left")){
                    
				sideBottomLeft->setZOrder(3); 
		    }
			if (auto sideBottomRight = this->getChildByID("side-art-bottom-right")){
                    
				sideBottomRight->setZOrder(3); 
		    }
            if (auto toggleMenu = this->getChildByID("demon-toggle-menu")){
                    
				toggleMenu->setZOrder(2); 
		    }
            if (auto toggleFilterMenu = this->getChildByID("demon-filter-menu")){
                    
				toggleFilterMenu->setZOrder(2); 
		    }
            if (auto searchInputMenu = this->getChildByID("search-input-menu")){

                auto nineSliceInput = NineSlice::create("square02b_small.png");
				nineSliceInput->setPosition(searchInputMenu->getPosition());
				nineSliceInput->setContentSize(searchInputMenu->getContentSize());
                nineSliceInput->setColor(ccc3(0, 50, 200));
				nineSliceInput->setID("nineSliceInput"_spr);
				this->addChild(nineSliceInput,-1);
                    
		    }
            if (auto optionsMenu = this->getChildByID("options-menu")){
                    
				optionsMenu->setZOrder(2);

                auto nineSliceFix = NineSlice::create("square02b_small.png");
				nineSliceFix->setPosition(optionsMenu->getPosition());
				nineSliceFix->setContentSize(optionsMenu->getContentSize());
                nineSliceFix->setColor(ccc3(0, 30, 125));
				nineSliceFix->setID("nineSliceFix"_spr);
				this->addChild(nineSliceFix,1);

		    }
            if (auto filterMenu = this->getChildByID("difficulty-filter-menu")){
                   
				filterMenu->setZOrder(2);

                auto nineSliceFix2 = NineSlice::create("square02b_small.png");
				nineSliceFix2->setPosition(filterMenu->getPosition());
				nineSliceFix2->setContentSize(filterMenu->getContentSize());
                nineSliceFix2->setColor(ccc3(0, 30, 125));
				nineSliceFix2->setID("nineSliceFix2"_spr);
				this->addChild(nineSliceFix2,1);

		    }
		}
		else if (DayAndNightSystem::events == 4){

			for (int i = 0; i < 2; ++i){
                if (auto sprite = getChildByType<NineSlice>(i)){
                            
                    sprite->setVisible(false);
                }

            }
			for (int i = 6; i < 7; ++i){
                if (auto menu = getChildByType<CCMenu>(i)){
                            
                    menu->setZOrder(4);
                }

            }

			if (auto sideBottomLeft = this->getChildByID("side-art-bottom-left")){
                    
				sideBottomLeft->setZOrder(3); 
		    }
			if (auto sideBottomRight = this->getChildByID("side-art-bottom-right")){
                    
				sideBottomRight->setZOrder(3); 
		    }
            if (auto toggleMenu = this->getChildByID("demon-toggle-menu")){
                    
				toggleMenu->setZOrder(2); 
		    }
            if (auto toggleFilterMenu = this->getChildByID("demon-filter-menu")){
                    
				toggleFilterMenu->setZOrder(2); 
		    }
            if (auto searchInputMenu = this->getChildByID("search-input-menu")){

                auto nineSliceInput = NineSlice::create("square02b_small.png");
				nineSliceInput->setPosition(searchInputMenu->getPosition());
				nineSliceInput->setContentSize(searchInputMenu->getContentSize());
                nineSliceInput->setColor(ccc3(0, 0, 120));
				nineSliceInput->setID("nineSliceInput"_spr);
				this->addChild(nineSliceInput,-1);
                    
		    }
            if (auto optionsMenu = this->getChildByID("options-menu")){
                    
				optionsMenu->setZOrder(2);

                auto nineSliceFix2 = NineSlice::create("square02b_small.png");
				nineSliceFix2->setPosition(optionsMenu->getPosition());
				nineSliceFix2->setContentSize(optionsMenu->getContentSize());
                nineSliceFix2->setColor(ccc3(0, 0, 75));
				nineSliceFix2->setID("nineSliceFix2"_spr);
				this->addChild(nineSliceFix2,1);
		    }
            if (auto filterMenu = this->getChildByID("difficulty-filter-menu")){
                   
				filterMenu->setZOrder(2);

                auto nineSliceFix = NineSlice::create("square02b_small.png");
				nineSliceFix->setPosition(filterMenu->getPosition());
				nineSliceFix->setContentSize(filterMenu->getContentSize());
                nineSliceFix->setColor(ccc3(0, 0, 75));
				nineSliceFix->setID("nineSliceFix"_spr);
				this->addChild(nineSliceFix,1);
		    }
			
		}
    }
};