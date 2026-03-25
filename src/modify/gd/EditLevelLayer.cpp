#include <Geode/Geode.hpp>
#include <Geode/modify/EditLevelLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(EditLevelLayer) {

	bool init(GJGameLevel* p0) {
		if (!EditLevelLayer::init(p0))
		return false;

		auto DayAndNightSystem = DayAndNightSystem::create();
		DayAndNightSystem->setID("events"_spr);
		this->addChild(DayAndNightSystem, -2);

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("screen-overlay"_spr);
		this->addChild(DayAndNightSystemOverlay, 106);

		if (DayAndNightSystem::events > 0.99f){
			if (auto bg = this->getChildByID("background")){ 
				bg->setVisible(false);
			}
		}

		if ((DayAndNightSystem::events == 1) || (DayAndNightSystem::events == 2)){

			if (auto bg1 = this->getChildByID("level-name-background")){
				bg1->setVisible(false);

				auto cc9Fix = NineSlice::create("square02_001.png");
				cc9Fix->setPosition(bg1->getPosition());
				cc9Fix->setOpacity(90);
				cc9Fix->setContentSize(bg1->getContentSize());
				cc9Fix->setID("cc-9-fix"_spr);
				this->addChild(cc9Fix, -2);
			}
			if (auto bg2 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("description-background"))){
				bg2->setColor(ccc3(0, 0, 0));
				bg2->setOpacity(90);
			}
		
		}
		else if (DayAndNightSystem::events == 3){

			if (auto sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-name-background"))){
				sprite->setColor(ccc3(0, 0, 140));
			}
			if (auto sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("description-background"))){
				sprite_1->setColor(ccc3(0, 0, 140));
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