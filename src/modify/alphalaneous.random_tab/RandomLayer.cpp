#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/NodeModding.h>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyRandomLayer, RandomLayer) {

    void modify(){

		auto screenSize = CCDirector::sharedDirector()->getWinSize();

		auto DayAndNightSystem = DayAndNightSystem::create();
		DayAndNightSystem->setID("Events"_spr);
		this->addChild(DayAndNightSystem,-2);

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay,106);
		
    	if (DayAndNightSystem::events == 1){
			
			if (Mod::get()->getSettingValue<bool>("enable-sunrise")){

				if (auto sprite = getChildByType<CCSprite>(-1)){
					sprite->setVisible(false);	
				}
                for (int i = 0; i < 4; ++i){
                    if (auto sprite = getChildByType<CCScale9Sprite>(i)){

                        sprite->setVisible(false);	
                    }
                    else{
                        // no sprite found
                    }

                }
				auto cc9fix = CCSprite::create("CCScale9Sprite_fix_random_tab.png"_spr); // texture overlapping (rated levels)
				cc9fix->setScale(0.895f);
				cc9fix->setOpacity(90);
				cc9fix->setPosition(screenSize / 2 + CCPoint {0,-30});
				cc9fix->setID("cc9fix_randomtab"_spr);
				this->addChild(cc9fix,-2);

			}
		
		}
		else if (DayAndNightSystem::events == 2){

			if (Mod::get()->getSettingValue<bool>("enable-sunset")){

				if (auto sprite = getChildByType<CCSprite>(-1)){
					sprite->setVisible(false);	
				}
                for (int i = 0; i < 4; ++i){
                    if (auto sprite = getChildByType<CCScale9Sprite>(i)){

                        sprite->setVisible(false);
                    }
                    else{
                        // no sprite found
                    }

                }
				auto cc9fix = CCSprite::create("CCScale9Sprite_fix_random_tab.png"_spr); // texture overlapping (rated levels)
				cc9fix->setScale(0.895f);
				cc9fix->setOpacity(90);
				cc9fix->setPosition(screenSize / 2 + CCPoint {0,-30});
				cc9fix->setID("cc9fix_randomtab"_spr);
				this->addChild(cc9fix,-2);

			}
		
		}
		else if (DayAndNightSystem::events == 3){

			if (Mod::get()->getSettingValue<bool>("enable-night")){

				if (auto sprite = getChildByType<CCSprite>(-1)){
					sprite->setVisible(false);	
				}
                for (int i = 0; i < 4; ++i){
                    if (auto sprite = getChildByType<CCScale9Sprite>(i)){

                        sprite->setColor(ccc3(0, 30, 125));
                    }
                    else{
                        // no sprite found
                    }

                }

			}
		}
		else if (DayAndNightSystem::events == 4){

			if (Mod::get()->getSettingValue<bool>("enable-dark")){

				if (auto sprite = getChildByType<CCSprite>(-1)){
					sprite->setVisible(false);	
				}
                for (int i = 0; i < 4; ++i){
                    if (auto sprite = getChildByType<CCScale9Sprite>(i)){
                            
                        sprite->setColor(ccc3(0, 0, 50));
                    }
                    else{
                        // no sprite found
                    }

                }

			}
		}
    }
};