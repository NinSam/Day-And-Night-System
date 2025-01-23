#include <Geode/Geode.hpp>
#include <ctime>
#include <Geode/modify/EditLevelLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(EditLevelLayer) {

	bool init(GJGameLevel *p0) {
		if (!EditLevelLayer::init(p0))
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

	auto startdarkhr = Mod::get()->getSettingValue<int64_t>("start-sunset-hr");
	auto startdarkmin = Mod::get()->getSettingValue<int64_t>("start-dark-min");
	auto enddarkhr = Mod::get()->getSettingValue<int64_t>("end-dark-hr");
	auto enddarkmin = Mod::get()->getSettingValue<int64_t>("end-dark-min");


	CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
	float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;

	auto DayAndNightSystem = DayAndNightSystem::create();
	DayAndNightSystem->setZOrder(-3);
	DayAndNightSystem->setID("Events"_spr);
	this->addChild(DayAndNightSystem);

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setZOrder(106);
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay);


	if ((hr > startsunrisehr || (hr == startsunrisehr && min >= startsunrisemin)) && (hr < endsunrisehr || (hr == endsunrisehr && min < endsunrisemin))){

		if (Mod::get()->getSettingValue<bool>("enable-sunrise")){

		if (auto bg = this->getChildByID("background")){

			bg->setVisible(false);
		}
		if (auto bg_1 = this->getChildByID("level-name-background")){

			bg_1->setVisible(false);
		}
		if (auto bg_2 = this->getChildByID("description-background")){

			bg_2->setVisible(false);
		}

        CCSprite* cc9fix = CCSprite::create("CCScale9Sprite_fix_1.png"_spr); // trying not to use happy textures
        
        cc9fix->setZOrder(-2);
        cc9fix->setAnchorPoint({0.5f, 0.5f});
        cc9fix->setScale(1.185f * relativescale);
        cc9fix->setPosition(screenSize / 2);
		cc9fix->setID("cc9fix"_spr);
        this->addChild(cc9fix);

		}
		
	}
	else if ((hr > startsunsethr || (hr == startsunsethr && min >= startsunsetmin)) && (hr < endsunsethr || (hr == endsunsethr && min < endsunsetmin))){

		if (Mod::get()->getSettingValue<bool>("enable-sunset")){

		if (auto bg = this->getChildByID("background")){

			bg->setVisible(false);
		}
		if (auto bg_1 = this->getChildByID("level-name-background")){

			bg_1->setVisible(false);
		}
		if (auto bg_2 = this->getChildByID("description-background")){

			bg_2->setVisible(false);
		}

        CCSprite* cc9fix = CCSprite::create("CCScale9Sprite_fix_1.png"_spr); // trying not to use happy textures
        
        cc9fix->setZOrder(-2);
        cc9fix->setAnchorPoint({0.5f, 0.5f});
        cc9fix->setScale(1.185f * relativescale);
        cc9fix->setPosition(screenSize / 2);
		cc9fix->setID("cc9fix"_spr);
        this->addChild(cc9fix);

		}
		
	}
	else if ((hr > startnighthr || (hr == startnighthr && min >= startnightmin)) && (hr < endnighthr || (hr == endnighthr && min < endnightmin))){

		if (Mod::get()->getSettingValue<bool>("enable-night")){

		if (auto bg = this->getChildByID("background")){

			bg->setVisible(false);
		}
		if (CCScale9Sprite* sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-name-background"))){

			sprite->setColor(ccc3(0, 30, 125));
		}
		if (CCScale9Sprite* sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("description-background"))){

			sprite_1->setColor(ccc3(0, 30, 125));
		}

		}
	}
	else if ((hr > startdarkhr || (hr == startdarkhr && min >= startdarkmin)) && (hr < endhrbugfix || (hr == endhrbugfix && min < endminbugfix))){
		
		if (Mod::get()->getSettingValue<bool>("enable-dark")){

		if (auto bg = this->getChildByID("background")){

			bg->setVisible(false);
		}
		if (CCScale9Sprite* sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-name-background"))){

			sprite->setColor(ccc3(0, 0, 50));
		}
		if (CCScale9Sprite* sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("description-background"))){

			sprite_1->setColor(ccc3(0, 0, 50));
		}

		}
	}
	else if ((hr > starthrbugfix || (hr == starthrbugfix && min >= startminbugfix)) && (hr < enddarkhr || (hr == enddarkhr && min < enddarkmin))){

		if (Mod::get()->getSettingValue<bool>("enable-dark")){

		if (auto bg = this->getChildByID("background")){

			bg->setVisible(false);
		}
		if (CCScale9Sprite* sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-name-background"))){

			sprite->setColor(ccc3(0, 0, 50));
		}
		if (CCScale9Sprite* sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("description-background"))){

			sprite_1->setColor(ccc3(0, 0, 50));
		}

		}

	}
		return true;
	}
};