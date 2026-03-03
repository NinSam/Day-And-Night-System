#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/ObjectModify.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyGlobalListLayer, GlobalListLayer){

    void modify(){

        auto DayAndNightSystem = DayAndNightSystem::create();
        DayAndNightSystem->setID("Events"_spr);
        this->addChild(DayAndNightSystem, -2);
        
        auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
        DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
        this->addChild(DayAndNightSystemOverlay, 106);

        if (auto bg = this->getChildByID("gdl-backgrownd")){
            if (DayAndNightSystem::events > 0.99f){
				bg->setVisible(false);
			}
		}
        if (auto listLayer = typeinfo_cast<GJListLayer*>(this->getChildByID("GJListLayer"))){
            if (DayAndNightSystem::events > 2.99f){
				listLayer->setOpacity(255);
                listLayer->setColor(ccc3(0, 0, 0));
			}
		}

    }

};