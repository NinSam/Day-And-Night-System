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

	const int startHr_morning = 7; // start 7am
	const int startMin_morning = 0;
	const int endHr_morning = 8; // end 8am
	const int endMin_morning = 0;

	const int startHr_sunset = 18; // start 6pm
	const int startMin_sunset = 0;
	const int endHr_sunset = 19; // end 7pm
	const int endMin_sunset = 0;

	const int startHr_night = 19; // start 7pm
	const int startMin_night = 0;
	const int endHr_night = 21; // end 9pm
	const int endMin_night = 0;

	const int startHr_fullnight = 21; // start 9pm
	const int startMin_fullnight = 0;
	const int endHr_fullnight = 24;
	const int endMin_fullnight = 0;

	// bugfix (idk why it breaks past midnight)
	
	const int startHr_fullnightfix = 0; 
	const int startMin_fullnightfix = 0;
	const int endHr_fullnightfix = 7;  // end 7am
	const int endMin_fullnightfix = 0;

	if ((hr > startHr_morning || (hr == startHr_morning && min >= startMin_morning)) && (hr < endHr_morning || (hr == endHr_morning && min < endMin_morning)))
	{
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
	else if ((hr > startHr_sunset || (hr == startHr_sunset && min >= startMin_sunset)) && (hr < endHr_sunset || (hr == endHr_sunset && min < endMin_sunset)))
	{
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
	else if ((hr > startHr_night || (hr == startHr_night && min >= startMin_night)) && (hr < endHr_night || (hr == endHr_night && min < endMin_night)))
	{
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
	else if ((hr > startHr_fullnight || (hr == startHr_fullnight && min >= startMin_fullnight)) && (hr < endHr_fullnight || (hr == endHr_fullnight && min < endMin_fullnight)))
	{
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
	else if ((hr > startHr_fullnightfix || (hr == startHr_fullnightfix && min >= startMin_fullnightfix)) && (hr < endHr_fullnightfix || (hr == endHr_fullnightfix && min < endMin_fullnightfix)))
	{
		
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