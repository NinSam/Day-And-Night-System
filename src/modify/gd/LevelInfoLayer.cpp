#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(LevelInfoLayer) {

	bool init(GJGameLevel* p0, bool p1) {
		if (!LevelInfoLayer::init(p0, p1))
		return false;
		
		auto DayAndNightSystem = DayAndNightSystem::create();
		DayAndNightSystem->setID("events"_spr);
		this->addChild(DayAndNightSystem, -1);

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("screen-overlay"_spr);
		this->addChild(DayAndNightSystemOverlay, 106);

		if (DayAndNightSystem::events > 0.99f){
			if (auto bg = this->getChildByID("background")){
				bg->setVisible(false);
			}
		}
		

		if (DayAndNightSystem::events > 2.99f){

			if (auto normalBar = typeinfo_cast<CCSprite*>(this->getChildByID("normal-mode-bar"))){

                auto normalProgressBarOutline = NineSlice::create("GJ_progressBar_001.png");
                normalProgressBarOutline->setPosition(170, 10);
				normalProgressBarOutline->setContentSize({343, 23});
				normalProgressBarOutline->setID("normal-progress-bar-outline"_spr);
				normalBar->addChild(normalProgressBarOutline, -1);
				
                normalBar->setOpacity(255);
			}
            if (auto practiceBar = typeinfo_cast<CCSprite*>(this->getChildByID("practice-mode-bar"))){

                auto practiceProgressBarOutline = NineSlice::create("GJ_progressBar_001.png");
                practiceProgressBarOutline->setPosition(170, 10);
				practiceProgressBarOutline->setContentSize({343, 23});
				practiceProgressBarOutline->setID("practice-progress-bar-outline"_spr);
				practiceBar->addChild(practiceProgressBarOutline, -1);

                practiceBar->setOpacity(255);
			}

		}

		return true;
	}
};