#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(LevelSearchLayer) {

	bool init(int p0) {
		if (!LevelSearchLayer::init(p0))
		return false;

		auto DayAndNightSystem = DayAndNightSystem::create();
		DayAndNightSystem->setID("events"_spr);
		this->addChild(DayAndNightSystem, -3);

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("screen-overlay"_spr);
		this->addChild(DayAndNightSystemOverlay, 106);

		if (DayAndNightSystem::events > 0.99f){
			if (auto bg = this->getChildByID("background")){
				bg->setVisible(false);
			}
		}

    	if ((DayAndNightSystem::events == 1) || (DayAndNightSystem::events == 2)){
			
			if (auto bg1 = this->getChildByID("level-search-bg")){
				bg1->setVisible(false);

				auto cc9Fix = NineSlice::create("square02_001.png");
				cc9Fix->setPosition(bg1->getPosition());
				cc9Fix->setOpacity(90);
				cc9Fix->setContentSize(bg1->getContentSize());
				cc9Fix->setID("cc-9-fix"_spr);
				this->addChild(cc9Fix, -2);
			}
			if (auto bg2 = this->getChildByID("difficulty-filters-bg")){
				bg2->setVisible(false);

				auto cc9Fix2 = NineSlice::create("square02_001.png");
				cc9Fix2->setPosition(bg2->getPosition());
				cc9Fix2->setOpacity(90);
				cc9Fix2->setContentSize(bg2->getContentSize());
				cc9Fix2->setID("cc-9-fix-2"_spr);
				this->addChild(cc9Fix2, -2);
			}
			if (auto bg3 = this->getChildByID("length-filters-bg")){
				bg3->setVisible(false);

				auto cc9Fix3 = NineSlice::create("square02_001.png");
				cc9Fix3->setPosition(bg3->getPosition());
				cc9Fix3->setOpacity(90);
				cc9Fix3->setContentSize(bg3->getContentSize());
				cc9Fix3->setID("cc-9-fix-3"_spr);
				this->addChild(cc9Fix3, -2);
			}
			if (auto sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bar-bg"))){
				sprite->setColor(ccc3(0, 0, 0));
				sprite->setOpacity(80);
			}
			if (auto sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("quick-search-bg"))){
				sprite_1->setColor(ccc3(0, 0, 0));
				sprite_1->setOpacity(80);
			}
		
		}
		else if (DayAndNightSystem::events == 3){

			if (auto sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bg"))){
				sprite->setColor(ccc3(0, 0, 140));
			}
			if (auto sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("quick-search-bg"))){
				sprite_1->setColor(ccc3(0, 0, 140));
			}
			if (auto sprite_2 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("difficulty-filters-bg"))){
				sprite_2->setColor(ccc3(0, 0, 140));
			}
			if (auto sprite_3 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("length-filters-bg"))){
				sprite_3->setColor(ccc3(0, 0, 140));
			}
			if (auto sprite_4 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bar-bg"))){
				sprite_4->setColor(ccc3(0, 0, 80));
			}

		}
		else if (DayAndNightSystem::events == 4){

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
		return true;
	}
};