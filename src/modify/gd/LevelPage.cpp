#include <Geode/Geode.hpp>
#include <Geode/modify/LevelPage.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(LevelPage) {

	bool init(GJGameLevel* level) {
		if (!LevelPage::init(level))
		return false;

		if (DayAndNightSystem::events > 2.99f){

			if (auto normalProgressBar = typeinfo_cast<CCSprite*>(this->getChildByID("normal-progress-bar"))){

                auto cc9fix2 = NineSlice::create("GJ_progressBar_001.png");
                cc9fix2->setPosition(170, 10);
				cc9fix2->setContentSize({343, 23});
				cc9fix2->setID("CC9Fix2"_spr);
				normalProgressBar->addChild(cc9fix2, -1);
				
                normalProgressBar->setOpacity(255);
			}
            if (auto practiceProgressBar = typeinfo_cast<CCSprite*>(this->getChildByID("practice-progress-bar"))){

                auto cc9fix3 = NineSlice::create("GJ_progressBar_001.png");
                cc9fix3->setPosition(170, 10);
				cc9fix3->setContentSize({343, 23});
				cc9fix3->setID("CC9Fix3"_spr);
				practiceProgressBar->addChild(cc9fix3, -1);

                practiceProgressBar->setOpacity(255);
			}

		}

        if (DayAndNightSystem::events == 3){

            if (auto levelButton = m_levelMenu->getChildByID("level-button")){

                auto cc9fix = NineSlice::create("square02b_001.png");
                cc9fix->setPosition(170, 47.5f);
				cc9fix->setContentSize(levelButton->getContentSize());
				cc9fix->setID("CC9Fix"_spr);
                cc9fix->setColor(ccc3(0, 0, 255));
				levelButton->addChild(cc9fix, -1);
            }

		}
		else if (DayAndNightSystem::events == 4){

            if (auto levelButton = m_levelMenu->getChildByID("level-button")){

                auto cc9fix = NineSlice::create("square02b_001.png");
                cc9fix->setPosition(170, 47.5f);
				cc9fix->setContentSize(levelButton->getContentSize());
				cc9fix->setID("CC9Fix"_spr);
                cc9fix->setColor(ccc3(0, 0, 145));
				levelButton->addChild(cc9fix, -1);
            }
			
		}


		return true;
	}
};