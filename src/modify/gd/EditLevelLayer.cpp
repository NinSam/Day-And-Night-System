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
		this->addChild(DayAndNightSystem, -2);

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay, 106);
		
		if (auto bg = this->getChildByID("background")){
            if (DayAndNightSystem::events > 0.99f){
				bg->setVisible(false);
			}
		}

		if ((DayAndNightSystem::events == 1) || (DayAndNightSystem::events == 2)){

			if (auto bg_1 = this->getChildByID("level-name-background")){
				bg_1->setVisible(false);

				if (auto nameInput = this->getChildByID("level-name-input")){

					auto cc9fix = NineSlice::create("square02_001.png");
					cc9fix->setOpacity(90);
					cc9fix->setContentSize(bg_1->getContentSize());
					cc9fix->setID("CC9Fix"_spr);
					nameInput->addChild(cc9fix, -2);

				}
			}
			if (auto bg_2 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("description-background"))){
				bg_2->setColor(ccc3(0, 0, 0));
				bg_2->setOpacity(90);
			}
		
		}
		else if (DayAndNightSystem::events == 3){

			if (auto sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-name-background"))){
				sprite->setColor(ccc3(0, 30, 125));
			}
			if (auto sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("description-background"))){
				sprite_1->setColor(ccc3(0, 30, 125));
			}

		}
		else if (DayAndNightSystem::events == 4){
		
			if (auto sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-name-background"))){
				sprite->setColor(ccc3(0, 0, 75));
			}
			if (auto sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("description-background"))){
				sprite_1->setColor(ccc3(0, 0, 75));
			}
			
		}
		return true;
	}
};