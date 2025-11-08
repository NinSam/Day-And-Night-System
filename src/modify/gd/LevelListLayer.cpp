#include <Geode/Geode.hpp>
#include <Geode/modify/LevelListLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(LevelListLayer) {

	bool init(GJLevelList* p0) {
		if (!LevelListLayer::init(p0))
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
				if (auto bg_2 = this->getChildByID("title-background")){
					bg_2->setVisible(false);
				}
				if (auto titleLabel = typeinfo_cast<CCTextInputNode*>(this->getChildByID("title-label"))){

					auto cc9fix = CCScale9Sprite::create("square02b_small_fix.png"_spr);
					cc9fix->setOpacity(90);
					cc9fix->setContentSize({365,40});
					cc9fix->setID("CC9Fix"_spr);
					titleLabel->addChild(cc9fix,-2);
					
				}

			}
		
		}
		else if (DayAndNightSystem::events == 2){

			if (Mod::get()->getSettingValue<bool>("enable-sunset")){

				if (auto bg = this->getChildByID("background")){
					bg->setVisible(false);
				}
				if (auto bg_2 = this->getChildByID("title-background")){
					bg_2->setVisible(false);
				}
				if (auto titleLabel = typeinfo_cast<CCTextInputNode*>(this->getChildByID("title-label"))){

					auto cc9fix = CCScale9Sprite::create("square02b_small_fix.png"_spr);
					cc9fix->setOpacity(90);
					cc9fix->setContentSize({365,40});
					cc9fix->setID("CC9Fix"_spr);
					titleLabel->addChild(cc9fix,-2);

				}

			}
		
		}
		else if (DayAndNightSystem::events == 3){

			if (Mod::get()->getSettingValue<bool>("enable-night")){

				if (auto bg = this->getChildByID("background")){
					bg->setVisible(false);
				}
				if (auto sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("title-background"))){
					sprite->setColor(ccc3(0, 30, 125));
				}

			}

		}
		else if (DayAndNightSystem::events == 4){
		
			if (Mod::get()->getSettingValue<bool>("enable-dark")){

				if (auto bg = this->getChildByID("background")){
					bg->setVisible(false);
				}
				if (auto sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("title-background"))){
					sprite->setColor(ccc3(0, 0, 75));
				}

			}
			
		}
	
		return true;
	}
};