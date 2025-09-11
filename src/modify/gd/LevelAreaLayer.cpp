#include <Geode/Geode.hpp>
#include <Geode/modify/LevelAreaLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(LevelAreaLayer) {

	bool init() {
		if (!LevelAreaLayer::init())
		return false;

		auto DayAndNightSystem = DayAndNightSystem::create();
		DayAndNightSystem->setID("Events"_spr);
		this->addChild(DayAndNightSystem,-1);

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay,106);

		if (DayAndNightSystem::events == 1){

			if (Mod::get()->getSettingValue<bool>("enable-sunrise")){

				if (auto bg = this->getChildByID("background")){
					bg->setVisible(false);
				}
				if (auto sprite_7 = this->getChildByID("fade-left")){
					sprite_7->setVisible(false);
				}
				if (auto sprite_8 = this->getChildByID("fade-right")){
					sprite_8->setVisible(false);
				}
				if (auto sprite_9 = this->getChildByID("fade-bottom")){
					sprite_9->setVisible(false);
				}
        		if (auto layergrad = this->getChildByID("top-glow")){
					layergrad->setVisible(false);
				}

			}
		
		}
		else if (DayAndNightSystem::events == 2){

			if (Mod::get()->getSettingValue<bool>("enable-sunset")){

				if (auto bg = this->getChildByID("background")){
					bg->setVisible(false);
				}
				if (auto sprite_7 = this->getChildByID("fade-left")){
					sprite_7->setVisible(false);
				}
				if (auto sprite_8 = this->getChildByID("fade-right")){
					sprite_8->setVisible(false);
				}
				if (auto sprite_9 = this->getChildByID("fade-bottom")){
					sprite_9->setVisible(false);
				}	
        		if (auto layergrad = this->getChildByID("top-glow")){
					layergrad->setVisible(false);
				}

			}
		
		}
		else if (DayAndNightSystem::events == 3){

			if (Mod::get()->getSettingValue<bool>("enable-night")){

				if (auto bg = this->getChildByID("background")){
					bg->setVisible(false);
				}
				if (auto sprite = this->getChildByID("light-1")){
					sprite->setVisible(false);
				}
				if (auto sprite_2 = this->getChildByID("light-2")){
					sprite_2->setVisible(false);
				}
        		if (auto sprite_3 = this->getChildByID("light-3")){
					sprite_3->setVisible(false);
				}
        		if (auto sprite_4 = this->getChildByID("light-4")){
					sprite_4->setVisible(false);
				}
        		if (auto sprite_5 = this->getChildByID("light-5")){
					sprite_5->setVisible(false);
				}
       	 		if (auto sprite_6 = this->getChildByID("light-6")){
					sprite_6->setVisible(false);
				}
				if (auto sprite_7 = this->getChildByID("fade-left")){
					sprite_7->setVisible(false);	
				}
				if (auto sprite_8 = this->getChildByID("fade-right")){
					sprite_8->setVisible(false);
				}
				if (auto sprite_9 = this->getChildByID("fade-bottom")){
					sprite_9->setVisible(false);
				}
        		if (auto layergrad = this->getChildByID("top-glow")){
					layergrad->setVisible(false);
				}
        		if (auto particle = this->getChildByID("sparkle")){
					particle->setVisible(false);
				}

			}
		
		}
		else if (DayAndNightSystem::events == 4){

			if (Mod::get()->getSettingValue<bool>("enable-dark")){

				if (auto bg = this->getChildByID("background")){
					bg->setVisible(false);	
				}	
       	 		if (auto sprite = this->getChildByID("light-1")){
					sprite->setVisible(false);
				}
				if (auto sprite_2 = this->getChildByID("light-2")){
					sprite_2->setVisible(false);
				}
       	 		if (auto sprite_3 = this->getChildByID("light-3")){
					sprite_3->setVisible(false);			
				}
        		if (auto sprite_4 = this->getChildByID("light-4")){
					sprite_4->setVisible(false);
				}
        		if (auto sprite_5 = this->getChildByID("light-5")){
					sprite_5->setVisible(false);
				}
        		if (auto sprite_6 = this->getChildByID("light-6")){
					sprite_6->setVisible(false);
				}
				if (auto sprite_7 = this->getChildByID("fade-left")){
					sprite_7->setVisible(false);
				}
				if (auto sprite_8 = this->getChildByID("fade-right")){
					sprite_8->setVisible(false);
				}
				if (auto sprite_9 = this->getChildByID("fade-bottom")){
					sprite_9->setVisible(false);	
				}
        		if (auto layergrad = this->getChildByID("top-glow")){
					layergrad->setVisible(false);	
				}
        		if (auto particle = this->getChildByID("sparkle")){
					particle->setVisible(false);
				}
		
			}

		}
		return true;
	}
};