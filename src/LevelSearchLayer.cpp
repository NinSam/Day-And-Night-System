#include <Geode/Geode.hpp>
#include <ctime>
#include <Geode/modify/LevelSearchLayer.hpp>

using namespace geode::prelude;

class $modify(LevelSearchLayer) {

	bool init(int p0) {
		if (!LevelSearchLayer::init(p0))
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

    if ((hr > startHr_morning || (hr == startHr_morning && min >= startMin_morning)) && (hr < endHr_morning || (hr == endHr_morning && min < endMin_morning))){

		if (Mod::get()->getSettingValue<bool>("enable-sunrise")){

		auto bg = this->getChildByID("background");
		bg->setVisible(false);

		auto bg_1 = this->getChildByID("level-search-bg");
		bg_1->setVisible(false);

		auto bg_2 = this->getChildByID("difficulty-filters-bg");
		bg_2->setVisible(false);

		auto bg_3 = this->getChildByID("length-filters-bg");
		bg_3->setVisible(false);

		CCScale9Sprite* sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bar-bg"));
		sprite->setColor(ccc3(0, 0, 0));
		sprite->setOpacity(80);

		CCScale9Sprite* sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("quick-search-bg"));
		sprite_1->setColor(ccc3(0, 0, 0));
		sprite_1->setOpacity(80);

	    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();

	    float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
        CCSprite* sunrise = CCSprite::create("sunrise.png"_spr);
        
        sunrise->setZOrder(-3);
        sunrise->setAnchorPoint({0, 0});
        sunrise->setScale(1.6 * relativescale);
        sunrise->setPosition({0, 0});
		sunrise->setID("sunrise"_spr);
        this->addChild(sunrise);

        CCSprite* cc9fix = CCSprite::create("CCScale9Sprite_fix.png"_spr); // trying not to use happy textures
        
        cc9fix->setZOrder(-2);
        cc9fix->setAnchorPoint({0.5, 0.5});
        cc9fix->setScale(1.185 * relativescale);
        cc9fix->setPosition(screenSize / 2);
        this->addChild(cc9fix);

		}
		
	}
	else if ((hr > startHr_sunset || (hr == startHr_sunset && min >= startMin_sunset)) && (hr < endHr_sunset || (hr == endHr_sunset && min < endMin_sunset))){

		if (Mod::get()->getSettingValue<bool>("enable-sunset")){

		auto bg = this->getChildByID("background");
		bg->setVisible(false);

		auto bg_1 = this->getChildByID("level-search-bg");
		bg_1->setVisible(false);

		auto bg_2 = this->getChildByID("difficulty-filters-bg");
		bg_2->setVisible(false);

		auto bg_3 = this->getChildByID("length-filters-bg");
		bg_3->setVisible(false);

		CCScale9Sprite* sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bar-bg"));
		sprite->setColor(ccc3(0, 0, 0));
		sprite->setOpacity(80);

		CCScale9Sprite* sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("quick-search-bg"));
		sprite_1->setColor(ccc3(0, 0, 0));
		sprite_1->setOpacity(80);

	    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();

	    float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;
        CCSprite* sunset = CCSprite::create("sunset.png"_spr);
        
        sunset->setZOrder(-3);
        sunset->setAnchorPoint({0, 0});
        sunset->setScale(1.6 * relativescale);
        sunset->setPosition({0, 0});
		sunset->setID("sunset"_spr);
        this->addChild(sunset);

        CCSprite* cc9fix = CCSprite::create("CCScale9Sprite_fix.png"_spr); // trying not to use happy textures
        
        cc9fix->setZOrder(-2);
        cc9fix->setAnchorPoint({0.5, 0.5});
        cc9fix->setScale(1.185 * relativescale);
        cc9fix->setPosition(screenSize / 2);
        this->addChild(cc9fix);

		}
		
	}
	else if ((hr > startHr_night || (hr == startHr_night && min >= startMin_night)) && (hr < endHr_night || (hr == endHr_night && min < endMin_night))){

		if (Mod::get()->getSettingValue<bool>("enable-night")){

		auto bg = this->getChildByID("background");
		bg->setVisible(false);

		CCScale9Sprite* sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bg"));
		sprite->setColor(ccc3(0, 30, 125));
	

		CCScale9Sprite* sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("quick-search-bg"));
		sprite_1->setColor(ccc3(0, 30, 125));
		

		CCScale9Sprite* sprite_2 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("difficulty-filters-bg"));
		sprite_2->setColor(ccc3(0, 30, 125));
		

		CCScale9Sprite* sprite_3 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("length-filters-bg"));
		sprite_3->setColor(ccc3(0, 30, 125));
		

		CCScale9Sprite* sprite_4 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bar-bg"));
		sprite_4->setColor(ccc3(0, 0, 75));
		
		
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
	else if ((hr > startHr_fullnight || (hr == startHr_fullnight && min >= startMin_fullnight)) && (hr < endHr_fullnight || (hr == endHr_fullnight && min < endMin_fullnight))){

		if (Mod::get()->getSettingValue<bool>("enable-dark")){

		auto bg = this->getChildByID("background");
		bg->setVisible(false);

		CCScale9Sprite* sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bg"));
		sprite->setColor(ccc3(0, 0, 50));

		CCScale9Sprite* sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("quick-search-bg"));
		sprite_1->setColor(ccc3(0, 0, 50));
		
		CCScale9Sprite* sprite_2 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("difficulty-filters-bg"));
		sprite_2->setColor(ccc3(0, 0, 50));

		CCScale9Sprite* sprite_3 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("length-filters-bg"));
		sprite_3->setColor(ccc3(0, 0, 50));

		CCScale9Sprite* sprite_4 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bar-bg"));
		sprite_4->setColor(ccc3(0, 0, 0));
		
		
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
	else if ((hr > startHr_fullnightfix || (hr == startHr_fullnightfix && min >= startMin_fullnightfix)) && (hr < endHr_fullnightfix || (hr == endHr_fullnightfix && min < endMin_fullnightfix))){

		if (Mod::get()->getSettingValue<bool>("enable-dark")){

		auto bg = this->getChildByID("background");
		bg->setVisible(false);

		CCScale9Sprite* sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bg"));
		sprite->setColor(ccc3(0, 0, 50));

		CCScale9Sprite* sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("quick-search-bg"));
		sprite_1->setColor(ccc3(0, 0, 50));
		
		CCScale9Sprite* sprite_2 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("difficulty-filters-bg"));
		sprite_2->setColor(ccc3(0, 0, 50));

		CCScale9Sprite* sprite_3 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("length-filters-bg"));
		sprite_3->setColor(ccc3(0, 0, 50));

		CCScale9Sprite* sprite_4 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bar-bg"));
		sprite_4->setColor(ccc3(0, 0, 0));

		
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