#include "Utils.hpp"
#include <ctime>

using namespace geode::prelude;

bool DayAndNightSystem::init(){

	if (!CCNode::init())

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

	auto startdarkhr = Mod::get()->getSettingValue<int64_t>("start-dark-hr"); // there's no way I set it to sunset this whole time bruh...
	auto startdarkmin = Mod::get()->getSettingValue<int64_t>("start-dark-min");
	auto enddarkhr = Mod::get()->getSettingValue<int64_t>("end-dark-hr");
	auto enddarkmin = Mod::get()->getSettingValue<int64_t>("end-dark-min");

	auto opacitysmallstarsnight = Mod::get()->getSettingValue<int64_t>("opacity-small-stars-night");
	auto opacitybigstarsnight = Mod::get()->getSettingValue<int64_t>("opacity-big-stars-night");
	auto opacitysmallstarsdark = Mod::get()->getSettingValue<int64_t>("opacity-small-stars-dark");
	auto opacitybigstarsdark = Mod::get()->getSettingValue<int64_t>("opacity-big-stars-dark");

	float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4; // used this line of code from the Minecraftify mod to make the sprites scale to the screen size. Ty alphalaneous for saving me from even more hours of pain trying to fix this

	if ((hr > startsunrisehr || (hr == startsunrisehr && min >= startsunrisemin)) && (hr < endsunrisehr || (hr == endsunrisehr && min < endsunrisemin))){

		if (Mod::get()->getSettingValue<bool>("enable-sunrise")){
	    
        CCScale9Sprite* sunrise = CCScale9Sprite::create("sunrise.png"_spr);
        
        sunrise->setAnchorPoint({0, 0});
		sunrise->setContentWidth(850);
		sunrise->setScaleY(1.6f * relativescale);
        sunrise->setPosition({0, 0});
		sunrise->setID("sunrise"_spr);
        this->addChild(sunrise);

		}

	}
	else if ((hr > startsunsethr || (hr == startsunsethr && min >= startsunsetmin)) && (hr < endsunsethr || (hr == endsunsethr && min < endsunsetmin))){

		if (Mod::get()->getSettingValue<bool>("enable-sunset")){

        CCScale9Sprite* sunset = CCScale9Sprite::create("sunset.png"_spr);
        
        sunset->setAnchorPoint({0, 0});
        sunset->setContentWidth(850);
		sunset->setScaleY(1.6f * relativescale);
        sunset->setPosition({0, 0});
		sunset->setID("sunset"_spr);
        this->addChild(sunset);

		}
		
	}
	else if ((hr > startnighthr || (hr == startnighthr && min >= startnightmin)) && (hr < endnighthr || (hr == endnighthr && min < endnightmin))){

		if (Mod::get()->getSettingValue<bool>("enable-night")){

		CCScale9Sprite* nightblue = CCScale9Sprite::create("night_blue.png"_spr);
        
        nightblue->setAnchorPoint({0, 0});
        nightblue->setContentWidth(850);
		nightblue->setScaleY(1.6f * relativescale);
        nightblue->setPosition({0, 0});
		nightblue->setID("nightblue"_spr);
        this->addChild(nightblue,-3);

		CCSprite* smallstars = CCSprite::create("small_stars.png"_spr);
        
        smallstars->setAnchorPoint({0, 0});
        smallstars->setScale(0.8f * relativescale);
        smallstars->setPosition({0, 0});
		smallstars->setOpacity(opacitysmallstarsnight);
		smallstars->setID("smallstars"_spr);
        this->addChild(smallstars,-2);

		CCSprite* bigstars = CCSprite::create("big_stars.png"_spr);
        
        bigstars->setAnchorPoint({0, 0});
        bigstars->setScale(0.8f * relativescale);
        bigstars->setPosition({0, 0});
		bigstars->setOpacity(opacitybigstarsnight);
		bigstars->setID("bigstars"_spr);
        this->addChild(bigstars,-2);

		}
		
	}
	else if ((hr > startdarkhr || (hr == startdarkhr && min >= startdarkmin)) && (hr < endhrbugfix || (hr == endhrbugfix && min < endminbugfix))){

		if (Mod::get()->getSettingValue<bool>("enable-dark")){

		CCSprite* night = CCSprite::create("night.png"_spr);
        
        night->setAnchorPoint({0, 0});
        night->setScale(1.6f * relativescale);
        night->setPosition({0, 0});
		night->setID("night"_spr);
        this->addChild(night,-3);

        CCSprite* smallstars = CCSprite::create("small_stars.png"_spr);
        
        smallstars->setAnchorPoint({0, 0});
        smallstars->setScale(0.8f * relativescale);
        smallstars->setPosition({0, 0});
		smallstars->setOpacity(opacitysmallstarsdark);
		smallstars->setID("smallstars"_spr);
        this->addChild(smallstars,-2);

		CCSprite* bigstars = CCSprite::create("big_stars.png"_spr);
        
        bigstars->setAnchorPoint({0, 0});
        bigstars->setScale(0.8f * relativescale);
        bigstars->setPosition({0, 0});
		bigstars->setOpacity(opacitybigstarsdark);
		bigstars->setID("bigstars"_spr);
        this->addChild(bigstars,-2);

		}
	}
	else if ((hr > starthrbugfix || (hr == starthrbugfix && min >= startminbugfix)) && (hr < enddarkhr || (hr == enddarkhr && min < enddarkmin))){

		if (Mod::get()->getSettingValue<bool>("enable-dark")){

        CCSprite* night = CCSprite::create("night.png"_spr);
        
        night->setAnchorPoint({0, 0});
        night->setScale(1.6f * relativescale);
        night->setPosition({0, 0});
		night->setID("night"_spr);
        this->addChild(night);

        CCSprite* smallstars = CCSprite::create("small_stars.png"_spr);
        
        smallstars->setAnchorPoint({0, 0});
        smallstars->setScale(0.8f * relativescale);
        smallstars->setPosition({0, 0});
		smallstars->setOpacity(opacitysmallstarsdark);
		smallstars->setID("smallstars"_spr);
        this->addChild(smallstars);

		CCSprite* bigstars = CCSprite::create("big_stars.png"_spr);
        
        bigstars->setAnchorPoint({0, 0});
        bigstars->setScale(0.8f * relativescale);
        bigstars->setPosition({0, 0});
		bigstars->setOpacity(opacitybigstarsdark);
		bigstars->setID("bigstars"_spr);
        this->addChild(bigstars);

		}
	}
	return true;
}

bool DayAndNightSystemOverlay::init(){

	if (!CCNode::init())

	return false;

	time_t now = time(0);
    tm* localTime = localtime(&now);

    const int hr = localTime->tm_hour;
    const int min = localTime->tm_min;
	
	const int endhrdarkbugfix = 24;
	const int endmindarkbugfix = 0;

	const int starthrdarkbugfix = 0;
	const int startmindarkbugfix = 0;

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

	auto opacitydarkoverlaynight = Mod::get()->getSettingValue<int64_t>("opacity-dark-overlay-night");
	auto opacitydarkoverlaydark = Mod::get()->getSettingValue<int64_t>("opacity-dark-overlay-dark");

	float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
	

	if ((hr > startsunrisehr || (hr == startsunrisehr && min >= startsunrisemin)) && (hr < endsunrisehr || (hr == endsunrisehr && min < endsunrisemin))){

	}
	else if ((hr > startsunsethr || (hr == startsunsethr && min >= startsunsetmin)) && (hr < endsunsethr || (hr == endsunsethr && min < endsunsetmin))){

	}
	else if ((hr > startnighthr || (hr == startnighthr && min >= startnightmin)) && (hr < endnighthr || (hr == endnighthr && min < endnightmin))){

		if (Mod::get()->getSettingValue<bool>("enable-night")){

        CCSprite* darkoverlay = CCSprite::create("night.png"_spr);
        
        darkoverlay->setAnchorPoint({0, 0});
        darkoverlay->setScale(1.6f * relativescale);
        darkoverlay->setPosition({0, 0});
		darkoverlay->setOpacity(opacitydarkoverlaynight);
		darkoverlay->setID("darkoverlay"_spr);
        this->addChild(darkoverlay);

		}
		
	}
	else if ((hr > startdarkhr || (hr == startdarkhr && min >= startdarkmin)) && (hr < endhrdarkbugfix || (hr == endhrdarkbugfix && min < endmindarkbugfix))){

		if (Mod::get()->getSettingValue<bool>("enable-dark")){
			
        CCSprite* darkoverlay = CCSprite::create("night.png"_spr);
        
        darkoverlay->setAnchorPoint({0, 0});
        darkoverlay->setScale(1.6f * relativescale);
		darkoverlay->setOpacity(opacitydarkoverlaydark);
        darkoverlay->setPosition({0, 0});
		darkoverlay->setID("darkoverlay"_spr);
        this->addChild(darkoverlay);
		
		}
	}
	else if ((hr > starthrdarkbugfix || (hr == starthrdarkbugfix && min >= startmindarkbugfix)) && (hr < enddarkhr || (hr == enddarkhr && min < enddarkmin))){
		
		if (Mod::get()->getSettingValue<bool>("enable-dark")){

        CCSprite* darkoverlay = CCSprite::create("night.png"_spr);
        
        darkoverlay->setAnchorPoint({0, 0});
        darkoverlay->setScale(1.6f * relativescale);
        darkoverlay->setPosition({0, 0});
		darkoverlay->setOpacity(opacitydarkoverlaydark);
		darkoverlay->setID("darkoverlay"_spr);
        this->addChild(darkoverlay);

		}

	}

	return true;
}

    DayAndNightSystem* DayAndNightSystem::create(){
	auto ret = new DayAndNightSystem;
	if (ret && ret->init()){
		
		ret->autorelease();
		return ret;
	}
	delete ret;
	return nullptr;
	}

    DayAndNightSystemOverlay* DayAndNightSystemOverlay::create(){
	auto ret = new DayAndNightSystemOverlay;
	if (ret && ret->init()){
		
		ret->autorelease();
		return ret;
	}
	delete ret;
	return nullptr;
	}