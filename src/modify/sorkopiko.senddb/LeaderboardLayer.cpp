#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/ObjectModify.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyLeaderboardLayer, LeaderboardLayer){

    void modify(){

        auto screenSize = CCDirector::sharedDirector()->getWinSize();

        auto DayAndNightSystem = DayAndNightSystem::create();
        DayAndNightSystem->setID("events"_spr);
        this->addChild(DayAndNightSystem, -1);
        
        auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
        DayAndNightSystemOverlay->setID("screen-overlay"_spr);
        this->addChild(DayAndNightSystemOverlay, 106);

        if (DayAndNightSystem::events > 0.99f){

            if (auto shaderBg = this->getChildByID("trending-background")){
			    shaderBg->setPositionY(99999);
		    }
            if (auto shaderBg2 = this->getChildByID("background-shader")){
		    	shaderBg2->setPositionY(99999);
		    }
            if (auto bg = this->getChildByID("background")){
		    	bg->setVisible(false);
		    }

        }
        
        if (auto listBg = this->getChildByID("level-list")){

            if ((DayAndNightSystem::events == 1) || (DayAndNightSystem::events == 2)){

                if (auto shaderBg = this->getChildByID("background-shader")){

                    auto ccColorFix = CCLayerColor::create(ccc4(0, 0, 0, 100), screenSize.width, screenSize.height);
				    ccColorFix->setContentSize(listBg->getContentSize());
				    ccColorFix->setID("cc-layer-color-fix"_spr);
				    listBg->addChild(ccColorFix, -2);
                    
		        }
                
			}
            else if (DayAndNightSystem::events == 3){

                if (auto shaderBg = this->getChildByID("background-shader")){

                    auto ccColorFix = CCLayerColor::create(ccc4(0, 30, 255, 150), screenSize.width, screenSize.height);
				    ccColorFix->setContentSize(listBg->getContentSize());
				    ccColorFix->setID("cc-layer-color-fix"_spr);
				    listBg->addChild(ccColorFix, -2);
                    
		        }
                
			}
            else if (DayAndNightSystem::events == 4){

                if (auto shaderBg = this->getChildByID("background-shader")){

                    auto ccColorFix = CCLayerColor::create(ccc4(0, 0, 255, 150), screenSize.width, screenSize.height);
				    ccColorFix->setContentSize(listBg->getContentSize());
				    ccColorFix->setID("cc-layer-color-fix"_spr);
				    listBg->addChild(ccColorFix, -2);
                    
		        }
                
			}
		}
    }

};