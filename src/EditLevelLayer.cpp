#include <Geode/Geode.hpp>
#include <ctime>
#include <Geode/modify/EditLevelLayer.hpp>

using namespace geode::prelude;

class $modify(EditLevelLayer) {

	bool init(GJGameLevel *p0) {
		if (!EditLevelLayer::init(p0))
			return false;

	time_t now = time(0);
    tm* localTime = localtime(&now);

	const int hr = localTime->tm_hour;
    const int min = localTime->tm_min;

	// bugfix (idk why it breaks past midnight)

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

	auto startdarkhr = Mod::get()->getSettingValue<int64_t>("start-sunset-hr");
	auto startdarkmin = Mod::get()->getSettingValue<int64_t>("start-dark-min");
	auto enddarkhr = Mod::get()->getSettingValue<int64_t>("end-dark-hr");
	auto enddarkmin = Mod::get()->getSettingValue<int64_t>("end-dark-min");

	if ((hr > startsunrisehr || (hr == startsunrisehr && min >= startsunrisemin)) && (hr < endsunrisehr || (hr == endsunrisehr && min < endsunrisemin))){

		if (Mod::get()->getSettingValue<bool>("enable-sunrise")){

		auto bg = this->getChildByID("background");
		bg->setVisible(false);

		auto bg_1 = this->getChildByID("level-name-background");
		bg_1->setVisible(false);

		auto bg_2 = this->getChildByID("description-background");
		bg_2->setVisible(false);
		
	    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();

	    float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
        CCSprite* sunrise = CCSprite::create("sunrise.png"_spr);
        
        sunrise->setZOrder(-3);
        sunrise->setAnchorPoint({0, 0});
        sunrise->setScale(1.6 * relativescale);
        sunrise->setPosition({0, 0});
		sunrise->setID("sunrise"_spr);
        this->addChild(sunrise);


        CCSprite* cc9fix = CCSprite::create("CCScale9Sprite_fix_1.png"_spr); // trying not to use happy textures
        
        cc9fix->setZOrder(-2);
        cc9fix->setAnchorPoint({0.5, 0.5});
        cc9fix->setScale(1.185 * relativescale);
        cc9fix->setPosition(screenSize / 2);
        this->addChild(cc9fix);

		}
		
	}
	else if ((hr > startsunsethr || (hr == startsunsethr && min >= startsunsetmin)) && (hr < endsunsethr || (hr == endsunsethr && min < endsunsetmin))){

		if (Mod::get()->getSettingValue<bool>("enable-sunset")){

		auto bg = this->getChildByID("background");
		bg->setVisible(false);

		auto bg_1 = this->getChildByID("level-name-background");
		bg_1->setVisible(false);

		auto bg_2 = this->getChildByID("description-background");
		bg_2->setVisible(false);

	    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();

	    float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
        CCSprite* sunset = CCSprite::create("sunset.png"_spr);
        
        sunset->setZOrder(-3);
        sunset->setAnchorPoint({0, 0});
        sunset->setScale(1.6 * relativescale);
        sunset->setPosition({0, 0});
		sunset->setID("sunset"_spr);
        this->addChild(sunset);

        CCSprite* cc9fix = CCSprite::create("CCScale9Sprite_fix_1.png"_spr); // trying not to use happy textures
        
        cc9fix->setZOrder(-2);
        cc9fix->setAnchorPoint({0.5, 0.5});
        cc9fix->setScale(1.185 * relativescale);
        cc9fix->setPosition(screenSize / 2);
        this->addChild(cc9fix);

		}
		
	}
	else if ((hr > startnighthr || (hr == startnighthr && min >= startnightmin)) && (hr < endnighthr || (hr == endnighthr && min < endnightmin))){

		if (Mod::get()->getSettingValue<bool>("enable-night")){

		auto bg = this->getChildByID("background");
		bg->setVisible(false);

		CCScale9Sprite* sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-name-background"));
		sprite->setColor(ccc3(0, 30, 125));
	

		CCScale9Sprite* sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("description-background"));
		sprite_1->setColor(ccc3(0, 30, 125));
		
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
	else if ((hr > startdarkhr || (hr == startdarkhr && min >= startdarkmin)) && (hr < endhrdarkbugfix || (hr == endhrdarkbugfix && min < endmindarkbugfix))){
		
		if (Mod::get()->getSettingValue<bool>("enable-dark")){

		auto bg = this->getChildByID("background");
		bg->setVisible(false);

		CCScale9Sprite* sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-name-background"));
		sprite->setColor(ccc3(0, 0, 50));
	

		CCScale9Sprite* sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("description-background"));
		sprite_1->setColor(ccc3(0, 0, 50));
		
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
	else if ((hr > starthrdarkbugfix || (hr == starthrdarkbugfix && min >= startmindarkbugfix)) && (hr < enddarkhr || (hr == enddarkhr && min < enddarkmin))){

		if (Mod::get()->getSettingValue<bool>("enable-dark")){

		auto bg = this->getChildByID("background");
		bg->setVisible(false);

		CCScale9Sprite* sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-name-background"));
		sprite->setColor(ccc3(0, 0, 50));
	

		CCScale9Sprite* sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("description-background"));
		sprite_1->setColor(ccc3(0, 0, 50));
		
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