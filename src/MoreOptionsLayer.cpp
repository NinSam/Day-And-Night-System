#include <Geode/Geode.hpp>
#include <ctime>
#include <Geode/modify/MoreOptionsLayer.hpp>

using namespace geode::prelude;

class $modify(MoreOptionsLayer) {

	bool init() {
		if (!MoreOptionsLayer::init())
			return false;

	time_t now = time(0);
    tm* localTime = localtime(&now);

    const int hr = localTime->tm_hour;
    const int min = localTime->tm_min;

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
	
	if ((hr > startHr_night || (hr == startHr_night && min >= startMin_night)) && (hr < endHr_night || (hr == endHr_night && min < endMin_night)))
	{
		if (Mod::get()->getSettingValue<bool>("enable-night")){
		
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

		}
		
	}
	else if ((hr > startHr_fullnight || (hr == startHr_fullnight && min >= startMin_fullnight)) && (hr < endHr_fullnight || (hr == endHr_fullnight && min < endMin_fullnight)))
	{
		if (Mod::get()->getSettingValue<bool>("enable-dark")){
		
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

		}
	}
	else if ((hr > startHr_fullnightfix || (hr == startHr_fullnightfix && min >= startMin_fullnightfix)) && (hr < endHr_fullnightfix || (hr == endHr_fullnightfix && min < endMin_fullnightfix)))
	{

		if (Mod::get()->getSettingValue<bool>("enable-dark")){
		
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

		}
		
	}
		return true;
	}
};