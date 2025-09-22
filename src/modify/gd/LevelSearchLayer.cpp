#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(LevelSearchLayer) {

	bool init(int p0) {
		if (!LevelSearchLayer::init(p0))
		return false;
	
		auto screenSize = CCDirector::sharedDirector()->getWinSize();

		auto DayAndNightSystem = DayAndNightSystem::create();
		DayAndNightSystem->setID("Events"_spr);
		this->addChild(DayAndNightSystem,-3);

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay,106);

    	if (DayAndNightSystem::events == 1){
			
			if (Mod::get()->getSettingValue<bool>("enable-sunrise")){
				
				if (auto bg = this->getChildByID("background")){
					bg->setVisible(false);
				}
				if (auto bg_1 = this->getChildByID("level-search-bg")){
					bg_1->setVisible(false);
				}
				if (auto bg_2 = this->getChildByID("difficulty-filters-bg")){
					bg_2->setVisible(false);
				}
				if (auto bg_3 = this->getChildByID("length-filters-bg")){
					bg_3->setVisible(false);
				}
				if (auto sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bar-bg"))){
					sprite->setColor(ccc3(0, 0, 0));
					sprite->setOpacity(80);
				}
				if (auto sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("quick-search-bg"))){
					sprite_1->setColor(ccc3(0, 0, 0));
					sprite_1->setOpacity(80);
				}

				auto cc9fix = CCScale9Sprite::create("square02b_small_fix.png"_spr);
				cc9fix->setPosition(screenSize / 2 + CCPoint {0,129.8f});
				cc9fix->setOpacity(90);
				cc9fix->setContentSize({365,40});
				cc9fix->setID("CC9Fix"_spr);
				this->addChild(cc9fix,-2);

				auto cc9fix2 = CCScale9Sprite::create("square02b_small_fix.png"_spr);
				cc9fix2->setPosition(screenSize / 2 + CCPoint {0,-77.2f});
				cc9fix2->setOpacity(90);
				cc9fix2->setContentSize({365,50});
				cc9fix2->setID("CC9Fix2"_spr);
				this->addChild(cc9fix2,-2);
				
				auto cc9fix3 = CCScale9Sprite::create("square02b_small_fix.png"_spr);
				cc9fix3->setPosition(screenSize / 2 + CCPoint {0,-128});
				cc9fix3->setOpacity(90);
				cc9fix3->setContentSize({365,35});
				cc9fix3->setID("CC9Fix3"_spr);
				this->addChild(cc9fix3,-2);

			}
		
		}
		else if (DayAndNightSystem::events == 2){

			if (Mod::get()->getSettingValue<bool>("enable-sunset")){

				if (auto bg = this->getChildByID("background")){
					bg->setVisible(false);
				}
				if (auto bg_1 = this->getChildByID("level-search-bg")){
					bg_1->setVisible(false);
				}
				if (auto bg_2 = this->getChildByID("difficulty-filters-bg")){
					bg_2->setVisible(false);
				}
				if (auto bg_3 = this->getChildByID("length-filters-bg")){
					bg_3->setVisible(false);
				}
				if (auto sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bar-bg"))){
					sprite->setColor(ccc3(0, 0, 0));
					sprite->setOpacity(80);
				}
				if (auto sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("quick-search-bg"))){
					sprite_1->setColor(ccc3(0, 0, 0));
					sprite_1->setOpacity(80);
				}

        		auto cc9fix = CCScale9Sprite::create("square02b_small_fix.png"_spr);
				cc9fix->setPosition(screenSize / 2 + CCPoint {0,129.8f});
				cc9fix->setOpacity(90);
				cc9fix->setContentSize({365,40});
				cc9fix->setID("CC9Fix"_spr);
				this->addChild(cc9fix,-2);

				auto cc9fix2 = CCScale9Sprite::create("square02b_small_fix.png"_spr);
				cc9fix2->setPosition(screenSize / 2 + CCPoint {0,-77.2f});
				cc9fix2->setOpacity(90);
				cc9fix2->setContentSize({365,50});
				cc9fix2->setID("CC9Fix2"_spr);
				this->addChild(cc9fix2,-2);
				
				auto cc9fix3 = CCScale9Sprite::create("square02b_small_fix.png"_spr);
				cc9fix3->setPosition(screenSize / 2 + CCPoint {0,-128});
				cc9fix3->setOpacity(90);
				cc9fix3->setContentSize({365,35});
				cc9fix3->setID("CC9Fix3"_spr);
				this->addChild(cc9fix3,-2);

			}
		
		}
		else if (DayAndNightSystem::events == 3){

			if (Mod::get()->getSettingValue<bool>("enable-night")){

				if (auto bg = this->getChildByID("background")){
					bg->setVisible(false);
				}
				if (auto sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bg"))){
					sprite->setColor(ccc3(0, 30, 125));
				}
				if (auto sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("quick-search-bg"))){
					sprite_1->setColor(ccc3(0, 30, 125));
				}
				if (auto sprite_2 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("difficulty-filters-bg"))){
					sprite_2->setColor(ccc3(0, 30, 125));
				}
				if (auto sprite_3 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("length-filters-bg"))){
					sprite_3->setColor(ccc3(0, 30, 125));
				}
				if (auto sprite_4 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bar-bg"))){
					sprite_4->setColor(ccc3(0, 0, 75));
				}

			}

		}
		else if (DayAndNightSystem::events == 4){

			if (Mod::get()->getSettingValue<bool>("enable-dark")){

				if (auto bg = this->getChildByID("background")){
					bg->setVisible(false);
				}
				if (auto sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bg"))){
					sprite->setColor(ccc3(0, 0, 75));
				}
				if (auto sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("quick-search-bg"))){
					sprite_1->setColor(ccc3(0, 0, 75));
				}
				if (auto sprite_2 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("difficulty-filters-bg"))){
					sprite_2->setColor(ccc3(0, 0, 75));
				}
				if (auto sprite_3 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("length-filters-bg"))){
					sprite_3->setColor(ccc3(0, 0, 75));
				}
				if (auto sprite_4 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bar-bg"))){
					sprite_4->setColor(ccc3(0, 0, 25));
				}

			}

		}
		return true;
	}
};