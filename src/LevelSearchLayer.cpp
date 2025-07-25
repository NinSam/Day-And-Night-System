#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

class $modify(LevelSearchLayer) {

	bool init(int p0) {
		if (!LevelSearchLayer::init(p0))
			return false;

	auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    auto localtime = fmt::localtime(time);
    int hr = static_cast<int>(localtime.tm_hour);
	int min = static_cast<int>(localtime.tm_min);

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
	

	auto screenSize = CCDirector::sharedDirector()->getWinSize();
	float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;

	auto DayAndNightSystem = DayAndNightSystem::create();
	DayAndNightSystem->setID("Events"_spr);
	this->addChild(DayAndNightSystem,-3);

	auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
	DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
	this->addChild(DayAndNightSystemOverlay,106);



    if ((hr > startsunrisehr || (hr == startsunrisehr && min >= startsunrisemin)) && (hr < endsunrisehr || (hr == endsunrisehr && min < endsunrisemin))){

		if (Mod::get()->getSettingValue<bool>("enable-sunrise")){

		if (auto bg = this->getChildByID("background")){

			bg->setVisible(false);
		}
		if (auto bg_1 = this->getChildByID("level-search-bg")){

			bg_1->setVisible(false);
		}
		if (auto bg_2 = this->getChildByID("difficulty-filters-bg")){

			bg_2->setVisible(false);
		}
		if (auto bg_3 = this->getChildByID("length-filters-bg")){

			bg_3->setVisible(false);
		}
		if (CCScale9Sprite* sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bar-bg"))){

		sprite->setColor(ccc3(0, 0, 0));
		sprite->setOpacity(80);

		}
		if (CCScale9Sprite* sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("quick-search-bg"))){

		sprite_1->setColor(ccc3(0, 0, 0));
		sprite_1->setOpacity(80);

		}

        CCSprite* cc9fix = CCSprite::create("CCScale9Sprite_fix.png"_spr); // trying not to use happy textures
        
        cc9fix->setScale(1.185f * relativescale);
		cc9fix->setOpacity(90);
        cc9fix->setPosition(screenSize / 2 + CCPoint {0,2});
		cc9fix->setID("cc9fix"_spr);
        this->addChild(cc9fix,-2);

		}
		
	}
	else if ((hr > startsunsethr || (hr == startsunsethr && min >= startsunsetmin)) && (hr < endsunsethr || (hr == endsunsethr && min < endsunsetmin))){

		if (Mod::get()->getSettingValue<bool>("enable-sunset")){

		if (auto bg = this->getChildByID("background")){

			bg->setVisible(false);
		}
		if (auto bg_1 = this->getChildByID("level-search-bg")){

			bg_1->setVisible(false);
		}
		if (auto bg_2 = this->getChildByID("difficulty-filters-bg")){

			bg_2->setVisible(false);
		}
		if (auto bg_3 = this->getChildByID("length-filters-bg")){

			bg_3->setVisible(false);
		}
		if (CCScale9Sprite* sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bar-bg"))){

		sprite->setColor(ccc3(0, 0, 0));
		sprite->setOpacity(80);

		}
		if (CCScale9Sprite* sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("quick-search-bg"))){

		sprite_1->setColor(ccc3(0, 0, 0));
		sprite_1->setOpacity(80);

		}

        CCSprite* cc9fix = CCSprite::create("CCScale9Sprite_fix.png"_spr); // trying not to use happy textures
    
        cc9fix->setScale(1.185f * relativescale);
		cc9fix->setOpacity(90);
        cc9fix->setPosition(screenSize / 2 + CCPoint {0,2});
		cc9fix->setID("cc9fix"_spr);
        this->addChild(cc9fix,-2);

		}
		
	}
	else if ((hr > startnighthr || (hr == startnighthr && min >= startnightmin)) && (hr < endnighthr || (hr == endnighthr && min < endnightmin))){

		if (Mod::get()->getSettingValue<bool>("enable-night")){

		if (auto bg = this->getChildByID("background")){

			bg->setVisible(false);
		}
		if (CCScale9Sprite* sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bg"))){

			sprite->setColor(ccc3(0, 30, 125));
		}
		if (CCScale9Sprite* sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("quick-search-bg"))){

			sprite_1->setColor(ccc3(0, 30, 125));
		}
		if (CCScale9Sprite* sprite_2 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("difficulty-filters-bg"))){
			
			sprite_2->setColor(ccc3(0, 30, 125));
		}
		if (CCScale9Sprite* sprite_3 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("length-filters-bg"))){

			sprite_3->setColor(ccc3(0, 30, 125));
		}
		if (CCScale9Sprite* sprite_4 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bar-bg"))){

			sprite_4->setColor(ccc3(0, 0, 75));
		}

		}
	}
	else if ((hr > startdarkhr || (hr == startdarkhr && min >= startdarkmin)) && (hr < endhrbugfix || (hr == endhrbugfix && min < endtimebugfix))){

		if (Mod::get()->getSettingValue<bool>("enable-dark")){

		if (auto bg = this->getChildByID("background")){

			bg->setVisible(false);
		}
		if (CCScale9Sprite* sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bg"))){

			sprite->setColor(ccc3(0, 0, 50));
		}
		if (CCScale9Sprite* sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("quick-search-bg"))){

			sprite_1->setColor(ccc3(0, 0, 50));
		}
		if (CCScale9Sprite* sprite_2 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("difficulty-filters-bg"))){

			sprite_2->setColor(ccc3(0, 0, 50));
		}
		if (CCScale9Sprite* sprite_3 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("length-filters-bg"))){

			sprite_3->setColor(ccc3(0, 0, 50));
		}
		if (CCScale9Sprite* sprite_4 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bar-bg"))){

			sprite_4->setColor(ccc3(0, 0, 0));
		}

		}
	}
	else if ((hr > endtimebugfix || (hr == endtimebugfix && min >= endtimebugfix)) && (hr < enddarkhr || (hr == enddarkhr && min < enddarkmin))){

		if (Mod::get()->getSettingValue<bool>("enable-dark")){

		if (auto bg = this->getChildByID("background")){

			bg->setVisible(false);
		}
		if (CCScale9Sprite* sprite = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bg"))){

			sprite->setColor(ccc3(0, 0, 50));
		}
		if (CCScale9Sprite* sprite_1 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("quick-search-bg"))){

			sprite_1->setColor(ccc3(0, 0, 50));
		}
		if (CCScale9Sprite* sprite_2 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("difficulty-filters-bg"))){

			sprite_2->setColor(ccc3(0, 0, 50));
		}
		if (CCScale9Sprite* sprite_3 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("length-filters-bg"))){

			sprite_3->setColor(ccc3(0, 0, 50));
		}
		if (CCScale9Sprite* sprite_4 = typeinfo_cast<CCScale9Sprite*>(this->getChildByID("level-search-bar-bg"))){

			sprite_4->setColor(ccc3(0, 0, 0));
		}

		}

	}
		return true;
	}
};