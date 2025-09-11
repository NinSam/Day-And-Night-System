#include <Geode/Geode.hpp>
#include <Geode/modify/EditLevelLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(EditLevelLayer) {

	bool init(GJGameLevel* p0) {
		if (!EditLevelLayer::init(p0))
		return false;

		auto screenSize = CCDirector::sharedDirector()->getWinSize();

		auto DayAndNightSystem = DayAndNightSystem::create();
		DayAndNightSystem->setID("Events"_spr);
		this->addChild(DayAndNightSystem,-2);

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay,106);

		if (DayAndNightSystem::events == 1){

			if (Mod::get()->getSettingValue<bool>("enable-sunrise")){

				if (auto bg = this->getChildByID("background")){
					bg->setVisible(false);
				}
				if (auto bg_1 = this->getChildByID("level-name-background")){
					bg_1->setVisible(false);
				}
				if (auto bg_2 = this->getChildByID("description-background")){
					bg_2->setVisible(false);
				}

				auto cc9fix = CCScale9Sprite::create("square02b_small_fix.png"_spr);
				cc9fix->setPosition(screenSize / 2 + CCPoint {0,129.8f});
				cc9fix->setOpacity(90);
				cc9fix->setContentSize({365,40});
				cc9fix->setID("CC9Fix"_spr);
				this->addChild(cc9fix,-2);

				auto cc9fix2 = CCScale9Sprite::create("square02b_small_fix.png"_spr);
				cc9fix2->setPosition(screenSize / 2 + CCPoint {0,64.9f});
				cc9fix2->setOpacity(90);
				cc9fix2->setContentSize({365,60});
				cc9fix2->setID("CC9Fix2"_spr);
				this->addChild(cc9fix2,-2);

			}
		
		}
		else if (DayAndNightSystem::events == 2){

			if (Mod::get()->getSettingValue<bool>("enable-sunset")){

				if (auto bg = this->getChildByID("background")){
					bg->setVisible(false);
				}
				if (auto bg_1 = this->getChildByID("level-name-background")){
					bg_1->setVisible(false);
				}
				if (auto bg_2 = this->getChildByID("description-background")){
					bg_2->setVisible(false);
				}

				auto cc9fix = CCScale9Sprite::create("square02b_small_fix.png"_spr);
				cc9fix->setPosition(screenSize / 2 + CCPoint {0,129.8f});
				cc9fix->setOpacity(90);
				cc9fix->setContentSize({365,40});
				cc9fix->setID("CC9Fix"_spr);
				this->addChild(cc9fix,-2);

				auto cc9fix2 = CCScale9Sprite::create("square02b_small_fix.png"_spr);
				cc9fix2->setPosition(screenSize / 2 + CCPoint {0,64.9f});
				cc9fix2->setOpacity(90);
				cc9fix2->setContentSize({365,60});
				cc9fix2->setID("CC9Fix2"_spr);
				this->addChild(cc9fix2,-2);

			}
		
		}
		else if (DayAndNightSystem::events == 3){

			if (Mod::get()->getSettingValue<bool>("enable-night")){

				if (auto bg = this->getChildByID("background")){
					bg->setVisible(false);
				}
				if (auto sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-name-background"))){
					sprite->setColor(ccc3(0, 30, 125));
				}
				if (auto sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("description-background"))){
					sprite_1->setColor(ccc3(0, 30, 125));
				}

			}

		}
		else if (DayAndNightSystem::events == 4){
		
			if (Mod::get()->getSettingValue<bool>("enable-dark")){

				if (auto bg = this->getChildByID("background")){
					bg->setVisible(false);
				}
				if (auto sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-name-background"))){
					sprite->setColor(ccc3(0, 0, 50));
				}
				if (auto sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("description-background"))){
					sprite_1->setColor(ccc3(0, 0, 50));
				}

			}
			
		}
		return true;
	}
};