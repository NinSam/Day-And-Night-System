#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(LevelSearchLayer) {

	bool init(int p0) {
		if (!LevelSearchLayer::init(p0))
		return false;

		auto DayAndNightSystem = DayAndNightSystem::create();
		DayAndNightSystem->setID("Events"_spr);
		this->addChild(DayAndNightSystem, -3);

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay, 106);

		if (auto bg = this->getChildByID("background")){
            if (DayAndNightSystem::events > 0.99f){
				bg->setVisible(false);
			}
		}

    	if ((DayAndNightSystem::events == 1) || (DayAndNightSystem::events == 2)){
			
			if (auto bg_1 = this->getChildByID("level-search-bg")){
				bg_1->setVisible(false);

				auto cc9fix = NineSlice::create("square02_001.png");
				cc9fix->setPosition(bg_1->getPosition());
				cc9fix->setOpacity(90);
				cc9fix->setContentSize(bg_1->getContentSize());
				cc9fix->setID("CC9Fix"_spr);
				this->addChild(cc9fix,-2);
			}
			if (auto bg_2 = this->getChildByID("difficulty-filters-bg")){
				bg_2->setVisible(false);

				auto cc9fix2 = NineSlice::create("square02_001.png");
				cc9fix2->setPosition(bg_2->getPosition());
				cc9fix2->setOpacity(90);
				cc9fix2->setContentSize(bg_2->getContentSize());
				cc9fix2->setID("CC9Fix2"_spr);
				this->addChild(cc9fix2,-2);
			}
			if (auto bg_3 = this->getChildByID("length-filters-bg")){
				bg_3->setVisible(false);

				auto cc9fix3 = NineSlice::create("square02_001.png");
				cc9fix3->setPosition(bg_3->getPosition());
				cc9fix3->setOpacity(90);
				cc9fix3->setContentSize(bg_3->getContentSize());
				cc9fix3->setID("CC9Fix3"_spr);
				this->addChild(cc9fix3,-2);
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