#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/NodeModding.h>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyRandomLayer, RandomLayer) {

    void modify(){

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
	

		auto screenSize = CCDirector::sharedDirector()->getWinSize();
		float relativescale = CCDirector::sharedDirector()->getContentScaleFactor()/4;

		auto DayAndNightSystem = DayAndNightSystem::create();
		DayAndNightSystem->setID("Events"_spr);
		this->addChild(DayAndNightSystem,-2);

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay,106);


    	if ((hr > startsunrisehr || (hr == startsunrisehr && min >= startsunrisemin)) && (hr < endsunrisehr || (hr == endsunrisehr && min < endsunrisemin))){
			
			if (Mod::get()->getSettingValue<bool>("enable-sunrise")){

                for (int i = 0; i < 4; ++i){
                    if (auto sprite = getChildByType<CCScale9Sprite>(i)){

                        sprite->setColor(ccc3(0, 0, 0));
                        sprite->setOpacity(80);
						
						auto cc9fix = CCSprite::create("CCScale9Sprite_fix_2.png"_spr); // trying not to use happy textures
						cc9fix->setScale(1.185f * relativescale);
						cc9fix->setOpacity(90);
						cc9fix->setPosition(screenSize / 2 + CCPoint {0,2});
						cc9fix->setID("cc9fix"_spr);
						this->addChild(cc9fix,-2);
                    }
                    else{
                        // no sprite found
                    }

                }

			}
		
		}
		else if ((hr > startsunsethr || (hr == startsunsethr && min >= startsunsetmin)) && (hr < endsunsethr || (hr == endsunsethr && min < endsunsetmin))){

			if (Mod::get()->getSettingValue<bool>("enable-sunset")){

                for (int i = 0; i < 4; ++i){
                    if (auto sprite = getChildByType<CCScale9Sprite>(i)){

                        sprite->setColor(ccc3(0, 0, 0));
                        sprite->setOpacity(80);
						
						auto cc9fix = CCSprite::create("CCScale9Sprite_fix_2.png"_spr); // trying not to use happy textures
						cc9fix->setScale(1.185f * relativescale);
						cc9fix->setOpacity(90);
						cc9fix->setPosition(screenSize / 2 + CCPoint {0,2});
						cc9fix->setID("cc9fix"_spr);
						this->addChild(cc9fix,-2);
                    }
                    else{
                        // no sprite found
                    }

                }

			}
		
		}
		else if ((hr > startnighthr || (hr == startnighthr && min >= startnightmin)) && (hr < endnighthr || (hr == endnighthr && min < endnightmin))){

			if (Mod::get()->getSettingValue<bool>("enable-night")){

                for (int i = 0; i < 4; ++i){
                    if (auto sprite = getChildByType<CCScale9Sprite>(i)){

                        sprite->setColor(ccc3(0, 30, 125));
                    }
                    else{
                        // no sprite found
                    }

                }

			}
		}
		else if ((hr > startdarkhr || (hr == startdarkhr && min >= startdarkmin)) && (hr < endhrbugfix || (hr == endhrbugfix && min < endtimebugfix))){

			if (Mod::get()->getSettingValue<bool>("enable-dark")){

                for (int i = 0; i < 4; ++i){
                    if (auto sprite = getChildByType<CCScale9Sprite>(i)){
                            
                        sprite->setColor(ccc3(0, 0, 50));
                    }
                    else{
                        // no sprite found
                    }

                }

			}
		}
		else if ((hr > endtimebugfix || (hr == endtimebugfix && min >= endtimebugfix)) && (hr < enddarkhr || (hr == enddarkhr && min < enddarkmin))){

			if (Mod::get()->getSettingValue<bool>("enable-dark")){

                for (int i = 0; i < 4; ++i){
                    if (auto sprite = getChildByType<CCScale9Sprite>(i)){
                            
                        sprite->setColor(ccc3(0, 0, 50));
                    }
                    else{
                        // no sprite found
                    }

                }

			}

		}

    }
};