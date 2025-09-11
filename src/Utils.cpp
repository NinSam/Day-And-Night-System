#include "Utils.hpp"

using namespace geode::prelude;

int DayAndNightSystem::events;

bool DayAndNightSystem::init(){

	if (!CCNode::init())
	return false;

	auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    auto localtime = fmt::localtime(time);
    const int hr = static_cast<int>(localtime.tm_hour);
	const int min = static_cast<int>(localtime.tm_min);
	
	const int endhrbugfix = 24;
	const int endtimebugfix = 0;

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

	auto opacitysmallstarsnight = Mod::get()->getSettingValue<int64_t>("opacity-small-stars-night");
	auto opacitybigstarsnight = Mod::get()->getSettingValue<int64_t>("opacity-big-stars-night");
	auto opacitysmallstarsdark = Mod::get()->getSettingValue<int64_t>("opacity-small-stars-dark");
	auto opacitybigstarsdark = Mod::get()->getSettingValue<int64_t>("opacity-big-stars-dark");

	CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
	
	if ((hr > startsunrisehr || (hr == startsunrisehr && min >= startsunrisemin)) && (hr < endsunrisehr || (hr == endsunrisehr && min < endsunrisemin))){

		if (Mod::get()->getSettingValue<bool>("enable-sunrise")){
	    
        	auto sunrise = CCScale9Sprite::create("sunrise.png"_spr);
       	 	sunrise->setAnchorPoint({0, 0});
			sunrise->setContentWidth(850);
			sunrise->setScaleY(1.6f);
        	sunrise->setPosition({0, 0});
			sunrise->setID("sunrise"_spr);
        	this->addChild(sunrise);
			events = 1;

		}
		else{
		    events = 0;
		}

	}
	else if ((hr > startsunsethr || (hr == startsunsethr && min >= startsunsetmin)) && (hr < endsunsethr || (hr == endsunsethr && min < endsunsetmin))){

		if (Mod::get()->getSettingValue<bool>("enable-sunset")){

        	auto sunset = CCScale9Sprite::create("sunset.png"_spr);
        	sunset->setAnchorPoint({0, 0});
       	 	sunset->setContentWidth(850);
			sunset->setScaleY(1.6f);
        	sunset->setPosition({0, 0});
			sunset->setID("sunset"_spr);
        	this->addChild(sunset);
			events = 2;

		}
		else{
		    events = 0;
		}
		
	}
	else if ((hr > startnighthr || (hr == startnighthr && min >= startnightmin)) && (hr < endnighthr || (hr == endnighthr && min < endnightmin))){

		if (Mod::get()->getSettingValue<bool>("enable-night")){

			auto nightblue = CCLayerGradient::create(ccc4(0, 0, 85, 255),ccc4(0, 0, 0, 255));
			nightblue->setID("nightblue"_spr);
			this->addChild(nightblue);

			auto smallstars = CCSprite::create("small_stars.png"_spr);
        	smallstars->setAnchorPoint({0, 0});
       	 	smallstars->setScale(0.8f);
       	 	smallstars->setPosition({0, 0});
			smallstars->setOpacity(opacitysmallstarsnight);
			smallstars->setID("smallstars"_spr);
        	this->addChild(smallstars);

			auto bigstars = CCSprite::create("big_stars.png"_spr);
        	bigstars->setAnchorPoint({0, 0});
        	bigstars->setScale(0.8f);
       	 	bigstars->setPosition({0, 0});
			bigstars->setOpacity(opacitybigstarsnight);
			bigstars->setID("bigstars"_spr);
        	this->addChild(bigstars);
			events = 3;

		}
		else{
		    events = 0;
		}
		
	}
	else if ((hr > startdarkhr || (hr == startdarkhr && min >= startdarkmin)) && (hr < endhrbugfix || (hr == endhrbugfix && min < endtimebugfix))){

		if (Mod::get()->getSettingValue<bool>("enable-dark")){

			auto night = CCLayerColor::create(ccc4(0,0,0,255), screenSize.width, screenSize.height);
		    night->setID("night"_spr);
		    this->addChild(night);

        	auto smallstars = CCSprite::create("small_stars.png"_spr);
        	smallstars->setAnchorPoint({0, 0});
        	smallstars->setScale(0.8f);
        	smallstars->setPosition({0, 0});
			smallstars->setOpacity(opacitysmallstarsdark);
			smallstars->setID("smallstars"_spr);
       		this->addChild(smallstars);

			auto bigstars = CCSprite::create("big_stars.png"_spr);
        	bigstars->setAnchorPoint({0, 0});
        	bigstars->setScale(0.8f);
        	bigstars->setPosition({0, 0});
			bigstars->setOpacity(opacitybigstarsdark);
			bigstars->setID("bigstars"_spr);
        	this->addChild(bigstars);
			events = 4;

		}
		else{
		    events = 0;
		}
		
	}
	else if ((hr > endtimebugfix || (hr == endtimebugfix && min >= endtimebugfix)) && (hr < enddarkhr || (hr == enddarkhr && min < enddarkmin))){

		if (Mod::get()->getSettingValue<bool>("enable-dark")){

			auto night = CCLayerColor::create(ccc4(0,0,0,255), screenSize.width, screenSize.height);
		    night->setID("night"_spr);
		    this->addChild(night);

        	auto smallstars = CCSprite::create("small_stars.png"_spr);
       		smallstars->setAnchorPoint({0, 0});
        	smallstars->setScale(0.8f);
        	smallstars->setPosition({0, 0});
			smallstars->setOpacity(opacitysmallstarsdark);
			smallstars->setID("smallstars"_spr);
        	this->addChild(smallstars);

			auto bigstars = CCSprite::create("big_stars.png"_spr);
        	bigstars->setAnchorPoint({0, 0});
        	bigstars->setScale(0.8f);
        	bigstars->setPosition({0, 0});
			bigstars->setOpacity(opacitybigstarsdark);
			bigstars->setID("bigstars"_spr);
        	this->addChild(bigstars);
			events = 4;

		}
		else{
		    events = 0;
		}

	}
	else{
		events = 0;
	}
	return true;
}

bool DayAndNightSystemOverlay::init(){

	if (!CCNode::init())
	return false;

	auto opacitydarkoverlaynight = Mod::get()->getSettingValue<int64_t>("opacity-dark-overlay-night");
	auto opacitydarkoverlaydark = Mod::get()->getSettingValue<int64_t>("opacity-dark-overlay-dark");

	CCSize screenSize = CCDirector::sharedDirector()->getWinSize();

	if (DayAndNightSystem::events == 1){

	}
	else if (DayAndNightSystem::events == 2){

	}
	else if (DayAndNightSystem::events == 3){

		if (Mod::get()->getSettingValue<bool>("enable-night")){

			auto darkoverlay = CCLayerColor::create(ccc4(0,0,0,opacitydarkoverlaynight), screenSize.width, screenSize.height);
			darkoverlay->setID("darkoverlay"_spr);
			this->addChild(darkoverlay);

		}
		
	}
	else if (DayAndNightSystem::events == 4){

		if (Mod::get()->getSettingValue<bool>("enable-dark")){
			
		    auto darkoverlay = CCLayerColor::create(ccc4(0,0,0,opacitydarkoverlaydark), screenSize.width, screenSize.height);
			darkoverlay->setID("darkoverlay"_spr);
			this->addChild(darkoverlay);
		
		}
		
	}
	return true;
}

DayAndNightSystem* DayAndNightSystem::create(){
	auto ret = new DayAndNightSystem;
	if (ret->init()){
		
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

DayAndNightSystemOverlay* DayAndNightSystemOverlay::create(){
	auto ret = new DayAndNightSystemOverlay;
	if (ret->init()){
		
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}