#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/ObjectModify.hpp>
#include <cue/RepeatingBackground.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyLevelGrindLayer, LevelGrindLayer){

    void modify(){

        auto DayAndNightSystem = DayAndNightSystem::create();
        DayAndNightSystem->setID("Events"_spr);
        this->addChild(DayAndNightSystem, -2);
        
        auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
        DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
        this->addChild(DayAndNightSystemOverlay, 106);

        if (auto bg = this->getChildByID("bg")){
            if (DayAndNightSystem::events > 0.99f){
				bg->setVisible(false);
			}
		}
        if (auto rBG = getChildByType<cue::RepeatingBackground>(0)){
            if (DayAndNightSystem::events > 0.99f){
                rBG->setVisible(false);
            }
        }

        if (auto versionsPanel = this->getChildByID("versions-panel")){
            if (DayAndNightSystem::events > 2.99f){
				versionsPanel->setVisible(false);
			}
		}
        if (auto optionsPanel = this->getChildByID("options-panel-first")){
            if (DayAndNightSystem::events > 2.99f){
				optionsPanel->setVisible(false);
			}
		}
        if (auto optionsPanel2 = this->getChildByID("options-panel-second")){
            if (DayAndNightSystem::events > 2.99f){
				optionsPanel2->setVisible(false);
			}
		}
        if (auto demonsPanel = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("demons-panel"))){
            if (DayAndNightSystem::events > 2.99f){
				demonsPanel->setOpacity(0);
			}
		}

        if (DayAndNightSystem::events == 3){

            if (auto optionsPanel_ = this->getChildByID("options-panel-first")){

                auto nineSliceFix2 = NineSlice::create("square02b_small.png");
				nineSliceFix2->setPosition(optionsPanel_->getPosition());
				nineSliceFix2->setContentSize(optionsPanel_->getContentSize());
                nineSliceFix2->setColor(ccc3(0, 30, 125));
				nineSliceFix2->setID("nineSliceFix2"_spr);
				this->addChild(nineSliceFix2, -1);
                
		    }
            if (auto optionsPanel2_ = this->getChildByID("options-panel-second")){

                auto nineSliceFix = NineSlice::create("square02b_small.png");
				nineSliceFix->setPosition(optionsPanel2_->getPosition());
				nineSliceFix->setContentSize(optionsPanel2_->getContentSize());
                nineSliceFix->setColor(ccc3(0, 30, 125));
				nineSliceFix->setID("nineSliceFix"_spr);
				this->addChild(nineSliceFix, -1);
                
		    }
            if (auto versionsPanel_ = this->getChildByID("versions-panel")){

                auto nineSliceFix3 = NineSlice::create("square02b_small.png");
				nineSliceFix3->setPosition(versionsPanel_->getPosition());
				nineSliceFix3->setContentSize(versionsPanel_->getContentSize());
                nineSliceFix3->setColor(ccc3(0, 30, 125));
				nineSliceFix3->setID("nineSliceFix3"_spr);
				this->addChild(nineSliceFix3, -1);
                
		    }
            if (auto demonsPanel_ = this->getChildByID("demons-panel")){

                auto nineSliceFix4 = NineSlice::create("square02b_small.png");
				nineSliceFix4->setPosition(15, 69.5f);
				nineSliceFix4->setContentSize(demonsPanel_->getContentSize());
                nineSliceFix4->setColor(ccc3(0, 30, 125));
				nineSliceFix4->setID("nineSliceFix4"_spr);
				demonsPanel_->addChild(nineSliceFix4, -1);
                
		    }

        }
        else if (DayAndNightSystem::events == 4){

            if (auto optionsPanel_ = this->getChildByID("options-panel-first")){

                auto nineSliceFix2 = NineSlice::create("square02b_small.png");
				nineSliceFix2->setPosition(optionsPanel_->getPosition());
				nineSliceFix2->setContentSize(optionsPanel_->getContentSize());
                nineSliceFix2->setColor(ccc3(0, 0, 75));
				nineSliceFix2->setID("nineSliceFix2"_spr);
				this->addChild(nineSliceFix2, -1);
                
		    }
            if (auto optionsPanel2_ = this->getChildByID("options-panel-second")){

                auto nineSliceFix = NineSlice::create("square02b_small.png");
				nineSliceFix->setPosition(optionsPanel2_->getPosition());
				nineSliceFix->setContentSize(optionsPanel2_->getContentSize());
                nineSliceFix->setColor(ccc3(0, 0, 75));
				nineSliceFix->setID("nineSliceFix"_spr);
				this->addChild(nineSliceFix, -1);
                
		    }
            if (auto versionsPanel_ = this->getChildByID("versions-panel")){

                auto nineSliceFix3 = NineSlice::create("square02b_small.png");
				nineSliceFix3->setPosition(versionsPanel_->getPosition());
				nineSliceFix3->setContentSize(versionsPanel_->getContentSize());
                nineSliceFix3->setColor(ccc3(0, 0, 75));
				nineSliceFix3->setID("nineSliceFix3"_spr);
				this->addChild(nineSliceFix3, -1);
                
		    }
            if (auto demonsPanel_ = this->getChildByID("demons-panel")){

                auto nineSliceFix4 = NineSlice::create("square02b_small.png");
				nineSliceFix4->setPosition(15, 69.5f);
				nineSliceFix4->setContentSize(demonsPanel_->getContentSize());
                nineSliceFix4->setColor(ccc3(0, 0, 75));
				nineSliceFix4->setID("nineSliceFix4"_spr);
				demonsPanel_->addChild(nineSliceFix4, -1);
                
		    }

        }

    }

};