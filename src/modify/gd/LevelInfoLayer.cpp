#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(LevelInfoLayer) {

	bool init(GJGameLevel* p0, bool p1) {
		if (!LevelInfoLayer::init(p0, p1))
		return false;
		
		auto DayAndNightSystem = DayAndNightSystem::create();
		DayAndNightSystem->setID("Events"_spr);
		this->addChild(DayAndNightSystem, -1);

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay, 106);

		if (DayAndNightSystem::events > 0.99f){
			if (auto bg = this->getChildByID("background")){
				bg->setVisible(false);
			}
		}
		

		if (DayAndNightSystem::events > 2.99f){

			if (auto normalBar = typeinfo_cast<CCSprite*>(this->getChildByID("normal-mode-bar"))){

                auto cc9fix = NineSlice::create("GJ_progressBar_001.png");
                cc9fix->setPosition(170, 10);
				cc9fix->setContentSize({343, 23});
				cc9fix->setID("CC9Fix"_spr);
				normalBar->addChild(cc9fix, -1);
				
                normalBar->setOpacity(255);
			}
            if (auto practiceBar = typeinfo_cast<CCSprite*>(this->getChildByID("practice-mode-bar"))){

                auto cc9fix2 = NineSlice::create("GJ_progressBar_001.png");
                cc9fix2->setPosition(170, 10);
				cc9fix2->setContentSize({343, 23});
				cc9fix2->setID("CC9Fix2"_spr);
				practiceBar->addChild(cc9fix2, -1);

                practiceBar->setOpacity(255);
			}

		}

		return true;
	}
};