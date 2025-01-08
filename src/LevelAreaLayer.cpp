#include <Geode/Geode.hpp>
#include <ctime>
#include <Geode/modify/LevelAreaLayer.hpp>

using namespace geode::prelude;

class $modify(LevelAreaLayer) {

	bool init() {
		if (!LevelAreaLayer::init())
			return false;

	time_t now = time(0);
    tm* localTime = localtime(&now);

	const int hr = localTime->tm_hour;
    const int min = localTime->tm_min;

	// bugfix (idk why it breaks past midnight)

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

	auto startdarkhr = Mod::get()->getSettingValue<int64_t>("start-sunset-hr");
	auto startdarkmin = Mod::get()->getSettingValue<int64_t>("start-dark-min");
	auto enddarkhr = Mod::get()->getSettingValue<int64_t>("end-dark-hr");
	auto enddarkmin = Mod::get()->getSettingValue<int64_t>("end-dark-min");

	if ((hr > startsunrisehr || (hr == startsunrisehr && min >= startsunrisemin)) && (hr < endsunrisehr || (hr == endsunrisehr && min < endsunrisemin))){

		if (Mod::get()->getSettingValue<bool>("enable-sunrise")){

		auto bg = this->getChildByID("background");
		bg->setVisible(false);

		auto sprite_7 = this->getChildByID("fade-left");
		sprite_7->setVisible(false);

		auto sprite_8 = this->getChildByID("fade-right");
		sprite_8->setVisible(false);

		auto sprite_9 = this->getChildByID("fade-bottom");
		sprite_9->setVisible(false);
		
        auto layergrad = this->getChildByID("top-glow");
		layergrad->setVisible(false);

	    float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
        CCSprite* sunrise = CCSprite::create("sunrise.png"_spr);
        
        sunrise->setZOrder(-3);
        sunrise->setAnchorPoint({0, 0});
        sunrise->setScale(1.6 * relativescale);
        sunrise->setPosition({0, 0});
		sunrise->setID("sunrise"_spr);
        this->addChild(sunrise);

		}
		
	}
	else if ((hr > startsunsethr || (hr == startsunsethr && min >= startsunsetmin)) && (hr < endsunsethr || (hr == endsunsethr && min < endsunsetmin))){

		if (Mod::get()->getSettingValue<bool>("enable-sunset")){

		auto bg = this->getChildByID("background");
		bg->setVisible(false);

		auto sprite_7 = this->getChildByID("fade-left");
		sprite_7->setVisible(false);

		auto sprite_8 = this->getChildByID("fade-right");
		sprite_8->setVisible(false);

		auto sprite_9 = this->getChildByID("fade-bottom");
		sprite_9->setVisible(false);
		
        auto layergrad = this->getChildByID("top-glow");
		layergrad->setVisible(false);

	    float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
        CCSprite* sunset = CCSprite::create("sunset.png"_spr);
        
        sunset->setZOrder(-3);
        sunset->setAnchorPoint({0, 0});
        sunset->setScale(1.6 * relativescale);
        sunset->setPosition({0, 0});
		sunset->setID("sunset"_spr);
        this->addChild(sunset);

		}
		
	}
	else if ((hr > startnighthr || (hr == startnighthr && min >= startnightmin)) && (hr < endnighthr || (hr == endnighthr && min < endnightmin))){

		if (Mod::get()->getSettingValue<bool>("enable-night")){

		auto bg = this->getChildByID("background");
		bg->setVisible(false);

		auto sprite = this->getChildByID("light-1");
		sprite->setVisible(false);
		
		auto sprite_2 = this->getChildByID("light-2");
		sprite_2->setVisible(false);
		
        auto sprite_3 = this->getChildByID("light-3");
		sprite_3->setVisible(false);
	
        auto sprite_4 = this->getChildByID("light-4");
		sprite_4->setVisible(false);
		
        auto sprite_5 = this->getChildByID("light-5");
		sprite_5->setVisible(false);
	
        auto sprite_6 = this->getChildByID("light-6");
		sprite_6->setVisible(false);

		auto sprite_7 = this->getChildByID("fade-left");
		sprite_7->setVisible(false);

		auto sprite_8 = this->getChildByID("fade-right");
		sprite_8->setVisible(false);

		auto sprite_9 = this->getChildByID("fade-bottom");
		sprite_9->setVisible(false);
		
        auto layergrad = this->getChildByID("top-glow");
		layergrad->setVisible(false);
		
        auto particle = this->getChildByID("sparkle");
		particle->setVisible(false);
		
		if (Mod::get()->getSettingValue<bool>("enable-dark-overlay-night")){

		float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
        CCSprite* darkoverlay = CCSprite::create("night_overlay.png"_spr);
        
        darkoverlay->setZOrder(106);
        darkoverlay->setAnchorPoint({0, 0});
        darkoverlay->setScale(1.6 * relativescale);
        darkoverlay->setPosition({0, 0});
		darkoverlay->setID("darkoverlay"_spr);
        this->addChild(darkoverlay);

		}

		float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
        CCSprite* stars = CCSprite::create("night_stars.png"_spr);
        
        stars->setZOrder(-3);
        stars->setAnchorPoint({0, 0});
        stars->setScale(1.6 * relativescale);
        stars->setPosition({0, 0});
		stars->setID("stars"_spr);
        this->addChild(stars);

		}
		
	}
	else if ((hr > startdarkhr || (hr == startdarkhr && min >= startdarkmin)) && (hr < endhrbugfix || (hr == endhrbugfix && min < endminbugfix))){

		if (Mod::get()->getSettingValue<bool>("enable-dark")){

		auto bg = this->getChildByID("background");
		bg->setVisible(false);
		
        auto sprite = this->getChildByID("light-1");
		sprite->setVisible(false);
		
		auto sprite_2 = this->getChildByID("light-2");
		sprite_2->setVisible(false);
		
        auto sprite_3 = this->getChildByID("light-3");
		sprite_3->setVisible(false);
	
        auto sprite_4 = this->getChildByID("light-4");
		sprite_4->setVisible(false);
		
        auto sprite_5 = this->getChildByID("light-5");
		sprite_5->setVisible(false);
	
        auto sprite_6 = this->getChildByID("light-6");
		sprite_6->setVisible(false);

		auto sprite_7 = this->getChildByID("fade-left");
		sprite_7->setVisible(false);

		auto sprite_8 = this->getChildByID("fade-right");
		sprite_8->setVisible(false);

		auto sprite_9 = this->getChildByID("fade-bottom");
		sprite_9->setVisible(false);
		
        auto layergrad = this->getChildByID("top-glow");
		layergrad->setVisible(false);
		
        auto particle = this->getChildByID("sparkle");
		particle->setVisible(false);
		
		if (Mod::get()->getSettingValue<bool>("enable-dark-overlay-dark")){

		float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
        CCSprite* darkoverlay = CCSprite::create("night_overlay.png"_spr);
        
        darkoverlay->setZOrder(106);
        darkoverlay->setAnchorPoint({0, 0});
        darkoverlay->setScale(1.6 * relativescale);
        darkoverlay->setPosition({0, 0});
		darkoverlay->setID("darkoverlay"_spr);
        this->addChild(darkoverlay);

		}

		float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
        CCSprite* stars = CCSprite::create("stars.png"_spr);
        
        stars->setZOrder(-3);
        stars->setAnchorPoint({0, 0});
        stars->setScale(1.6 * relativescale);
        stars->setPosition({0, 0});
		stars->setID("stars"_spr);
        this->addChild(stars);

		}
	}
	else if ((hr > starthrbugfix || (hr == starthrbugfix && min >= startminbugfix)) && (hr < enddarkhr || (hr == enddarkhr && min < enddarkmin))){
		
		if (Mod::get()->getSettingValue<bool>("enable-dark")){

		auto bg = this->getChildByID("background");
		bg->setVisible(false);
		
        auto sprite = this->getChildByID("light-1");
		sprite->setVisible(false);
		
		auto sprite_2 = this->getChildByID("light-2");
		sprite_2->setVisible(false);
		
        auto sprite_3 = this->getChildByID("light-3");
		sprite_3->setVisible(false);
	
        auto sprite_4 = this->getChildByID("light-4");
		sprite_4->setVisible(false);
		
        auto sprite_5 = this->getChildByID("light-5");
		sprite_5->setVisible(false);
	
        auto sprite_6 = this->getChildByID("light-6");
		sprite_6->setVisible(false);

		auto sprite_7 = this->getChildByID("fade-left");
		sprite_7->setVisible(false);

		auto sprite_8 = this->getChildByID("fade-right");
		sprite_8->setVisible(false);

		auto sprite_9 = this->getChildByID("fade-bottom");
		sprite_9->setVisible(false);
		
        auto layergrad = this->getChildByID("top-glow");
		layergrad->setVisible(false);
		
        auto particle = this->getChildByID("sparkle");
		particle->setVisible(false);
		

		if (Mod::get()->getSettingValue<bool>("enable-dark-overlay-dark")){

		float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
        CCSprite* darkoverlay = CCSprite::create("night_overlay.png"_spr);
        
        darkoverlay->setZOrder(106);
        darkoverlay->setAnchorPoint({0, 0});
        darkoverlay->setScale(1.6 * relativescale);
        darkoverlay->setPosition({0, 0});
		darkoverlay->setID("darkoverlay"_spr);
        this->addChild(darkoverlay);

		}

		float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
        CCSprite* stars = CCSprite::create("stars.png"_spr);
        
        stars->setZOrder(-3);
        stars->setAnchorPoint({0, 0});
        stars->setScale(1.6 * relativescale);
        stars->setPosition({0, 0});
		stars->setID("stars"_spr);
        this->addChild(stars);

		}

	}
		return true;
	}
};