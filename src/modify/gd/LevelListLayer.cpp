#include <Geode/Geode.hpp>
#include <Geode/modify/LevelListLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(LevelListLayer) {

	bool init(GJLevelList* p0) {
		if (!LevelListLayer::init(p0))
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

		if ((DayAndNightSystem::events == 1) || (DayAndNightSystem::events == 2)) {

			if (auto bg2 = this->getChildByID("title-background")){
				bg2->setVisible(false);

				auto cc9Fix = NineSlice::create("square02_001.png");
				cc9Fix->setOpacity(90);
				cc9Fix->setPosition(bg2->getPosition());
				cc9Fix->setContentSize(bg2->getContentSize());
				cc9Fix->setID("cc-9-fix"_spr);
				this->addChild(cc9Fix, -2);
			}
		
		}
		else if (DayAndNightSystem::events == 3){

			if (auto sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("title-background"))){
				sprite->setColor(ccc3(0, 0, 140));
			}

		}
		else if (DayAndNightSystem::events == 4){
		
			if (auto sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("title-background"))){
				sprite->setColor(ccc3(0, 0, 75));
			}
			
		}
	
		return true;
	}
};