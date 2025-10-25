#include <Geode/Geode.hpp>
#include <Geode/modify/EditLevelLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(EditLevelLayer) {

	bool init(GJGameLevel* p0) {
		if (!EditLevelLayer::init(p0))
		return false;

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
				if (auto bg_2 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("description-background"))){
					bg_2->setColor(ccc3(0, 0, 0));
					bg_2->setOpacity(90);
				}
				if (auto nameInput = this->getChildByID("level-name-input")){

					auto cc9fix = CCScale9Sprite::create("square02b_small_fix.png"_spr);
					cc9fix->setOpacity(90);
					cc9fix->setContentSize({365,40});
					cc9fix->setID("CC9Fix"_spr);
					nameInput->addChild(cc9fix,-2);

				}

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
				if (auto bg_2 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("description-background"))){
					bg_2->setColor(ccc3(0, 0, 0));
					bg_2->setOpacity(90);
				}
				if (auto nameInput = this->getChildByID("level-name-input")){

					auto cc9fix = CCScale9Sprite::create("square02b_small_fix.png"_spr);
					cc9fix->setOpacity(90);
					cc9fix->setContentSize({365,40});
					cc9fix->setID("CC9Fix"_spr);
					nameInput->addChild(cc9fix,-2);
					
				}

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
					sprite->setColor(ccc3(0, 0, 75));
				}
				if (auto sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("description-background"))){
					sprite_1->setColor(ccc3(0, 0, 75));
				}

			}
			
		}
		return true;
	}
};