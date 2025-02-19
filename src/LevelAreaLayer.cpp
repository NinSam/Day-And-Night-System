#include <Geode/Geode.hpp>
#include <ctime>
#include <Geode/modify/LevelAreaLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(LevelAreaLayer) {

	bool init() {
		if (!LevelAreaLayer::init())
			return false;

	time_t now = time(0);
    tm* localTime = localtime(&now);

	const int hr = localTime->tm_hour;
    const int min = localTime->tm_min;

	const int endhrbugfix = 24;
	const int endminbugfix = 0;

	const int starthrbugfix = 0;
	const int startminbugfix = 0;


	auto startsunrisehr = Mod::get()->getSettingValue<int64_t>("start-sunrise-hr");
	auto startsunrisemin = Mod::get()->getSettingValue<int64_t>("start-sunrise-min");
	auto endsunrisehr = Mod::get()->getSettingValue<int64_t>("end-sunrise-hr");
	auto endsunrisemin = Mod::get()->getSettingValue<int64_t>("end-sunrise-min");

	auto startsunsethr = Mod::get()->getSettingValue<int64_t>("start-sunset-hr");
	auto startsunsetmin = Mod::get()->getSettingValue<int64_t>("start-sunset-min");
	auto endsunsethr = Mod::get()->getSettingValue<int64_t>("end-sunset-hr");
	auto endsunsetmin = Mod::get()->getSettingValue<int64_t>("end-sunset-min");

	auto startnighthr = Mod::get()->getSettingValue<int64_t>("start-night-hr");
	auto startnightmin = Mod::get()->getSettingValue<int64_t>("start-night-min");
	auto endnighthr = Mod::get()->getSettingValue<int64_t>("end-night-hr");
	auto endnightmin = Mod::get()->getSettingValue<int64_t>("end-night-min");

	auto startdarkhr = Mod::get()->getSettingValue<int64_t>("start-dark-hr");
	auto startdarkmin = Mod::get()->getSettingValue<int64_t>("start-dark-min");
	auto enddarkhr = Mod::get()->getSettingValue<int64_t>("end-dark-hr");
	auto enddarkmin = Mod::get()->getSettingValue<int64_t>("end-dark-min");

	
	auto DayAndNightSystem = DayAndNightSystem::create();
	DayAndNightSystem->setID("Events"_spr);
	this->addChild(DayAndNightSystem,-1);

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay,106);

	

	if ((hr > startsunrisehr || (hr == startsunrisehr && min >= startsunrisemin)) && (hr < endsunrisehr || (hr == endsunrisehr && min < endsunrisemin))){

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
	else if ((hr > startsunsethr || (hr == startsunsethr && min >= startsunsetmin)) && (hr < endsunsethr || (hr == endsunsethr && min < endsunsetmin))){

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
	else if ((hr > startnighthr || (hr == startnighthr && min >= startnightmin)) && (hr < endnighthr || (hr == endnighthr && min < endnightmin))){

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
        if ( auto sprite_3 = this->getChildByID("light-3")){

			sprite_3->setVisible(false);
		}
        if ( auto sprite_4 = this->getChildByID("light-4")){

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
	else if ((hr > startdarkhr || (hr == startdarkhr && min >= startdarkmin)) && (hr < endhrbugfix || (hr == endhrbugfix && min < endminbugfix))){

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
        if ( auto sprite_3 = this->getChildByID("light-3")){

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
	else if ((hr > starthrbugfix || (hr == starthrbugfix && min >= startminbugfix)) && (hr < enddarkhr || (hr == enddarkhr && min < enddarkmin))){
		
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
        if ( auto sprite_3 = this->getChildByID("light-3")){

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