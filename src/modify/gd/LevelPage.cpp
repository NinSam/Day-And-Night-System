#include <Geode/Geode.hpp>
#include <Geode/modify/LevelPage.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(LevelPage) {

	bool init(GJGameLevel* level) {
		if (!LevelPage::init(level))
		return false;

		if (DayAndNightSystem::events > 0.99f){

			if (auto levelButton = m_levelMenu->getChildByID("level-button")){

				if (auto whiteSprite = levelButton->getChildByID("white-sprite")){

					auto cc9Fix = NineSlice::create("square02b_001.png");
                	cc9Fix->setPosition(whiteSprite->getPosition());
					cc9Fix->setContentSize(levelButton->getContentSize());
					cc9Fix->setID("cc-9-fix-1"_spr);
					levelButton->addChild(cc9Fix, -1);

				}

			}	
				
		}

		if (DayAndNightSystem::events > 2.99f){

			if (auto levelbgButton = typeinfo_cast<CCSpriteBatchNode*>(this->getChildByIDRecursive("background"))){
				levelbgButton->setVisible(false);
			}
			if (auto normalProgressBar = typeinfo_cast<CCSprite*>(this->getChildByIDRecursive("normal-progress-bar"))){

                auto normalProgressBarOutline = NineSlice::create("GJ_progressBar_001.png");
                normalProgressBarOutline->setPosition(170, 10);
				normalProgressBarOutline->setContentSize({343, 23});
				normalProgressBarOutline->setID("normal-progress-bar-outline"_spr);
				normalProgressBar->addChild(normalProgressBarOutline, -1);
				
                normalProgressBar->setOpacity(255);
			}
            if (auto practiceProgressBar = typeinfo_cast<CCSprite*>(this->getChildByIDRecursive("practice-progress-bar"))){

                auto practiceProgressBarOutline = NineSlice::create("GJ_progressBar_001.png");
                practiceProgressBarOutline->setPosition(170, 10);
				practiceProgressBarOutline->setContentSize({343, 23});
				practiceProgressBarOutline->setID("practice-progress-bar-outline"_spr);
				practiceProgressBar->addChild(practiceProgressBarOutline, -1);

                practiceProgressBar->setOpacity(255);
			}

			if (auto levelProgressDisplay = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-progress-display"))){
				levelProgressDisplay->setOpacity(0);
			}
			if (auto levelAchievementsDisplay = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-achievements-display"))){
				levelAchievementsDisplay->setOpacity(0);
			}

		}

        if (DayAndNightSystem::events == 3){

            if (auto levelButton = m_levelMenu->getChildByID("level-button")){

				if (auto whiteSprite = levelButton->getChildByID("white-sprite")){

					if (auto levelProgressDisplay = this->getChildByID("level-progress-display")){

						auto cc9Fix2 = NineSlice::create("square02b_001.png");
                		cc9Fix2->setPosition(130, 35);
						cc9Fix2->setContentSize(levelProgressDisplay->getContentSize());
						cc9Fix2->setID("cc-9-fix-2"_spr);
                		cc9Fix2->setColor(ccc3(0, 0, 140));
						levelProgressDisplay->addChild(cc9Fix2, -1);

					}
					if (auto levelAchievementsDisplay = this->getChildByID("level-achievements-display")){

						auto cc9Fix3 = NineSlice::create("square02b_001.png");
                		cc9Fix3->setPosition(130, 65);
						cc9Fix3->setContentSize(levelAchievementsDisplay->getContentSize());
						cc9Fix3->setID("cc-9-fix-3"_spr);
                		cc9Fix3->setColor(ccc3(0, 0, 140));
						levelAchievementsDisplay->addChild(cc9Fix3, -1);

					}
					if (auto getcc9Fix = typeinfo_cast<NineSlice*>(levelButton->getChildByID("ninsam.day_and_night_system/cc-9-fix-1"))){
						getcc9Fix->setColor(ccc3(0, 0, 140));
					}

				}

            }

		}
		else if (DayAndNightSystem::events == 4){

            if (auto levelButton = m_levelMenu->getChildByID("level-button")){

                if (auto whiteSprite = levelButton->getChildByID("white-sprite")){

					if (auto levelProgressDisplay = (this->getChildByID("level-progress-display"))){

						auto cc9Fix2 = NineSlice::create("square02b_001.png");
                		cc9Fix2->setPosition(130, 35);
						cc9Fix2->setContentSize(levelProgressDisplay->getContentSize());
						cc9Fix2->setID("cc-9-fix-2"_spr);
                		cc9Fix2->setColor(ccc3(0, 0, 75));
						levelProgressDisplay->addChild(cc9Fix2, -1);
						
					}
					if (auto levelAchievementsDisplay = this->getChildByID("level-achievements-display")){

						auto cc9Fix3 = NineSlice::create("square02b_001.png");
                		cc9Fix3->setPosition(130, 65);
						cc9Fix3->setContentSize(levelAchievementsDisplay->getContentSize());
						cc9Fix3->setID("cc-9-fix-3"_spr);
                		cc9Fix3->setColor(ccc3(0, 0, 75));
						levelAchievementsDisplay->addChild(cc9Fix3, -1);
						
					}
					if (auto getcc9Fix = typeinfo_cast<NineSlice*>(levelButton->getChildByID("ninsam.day_and_night_system/cc-9-fix-1"))){
						getcc9Fix->setColor(ccc3(0, 0, 75));
					}
					
				}
            }
			
		}

		if (auto levelButton = m_levelMenu->getChildByID("level-button")){

			if (auto getcc9Fix = typeinfo_cast<NineSlice*>(levelButton->getChildByID("ninsam.day_and_night_system/cc-9-fix-1"))){
				if ((DayAndNightSystem::events == 1) || (DayAndNightSystem::events == 2)){
					getcc9Fix->setVisible(false);
				}
				if (auto isOverChargedEnabled = (this->getChildByID("level-progress-display"))){
					getcc9Fix->setColor(ccc3(0, 0, 0));
					getcc9Fix->setVisible(true);
				}
			}

		}

		return true;
	}
};