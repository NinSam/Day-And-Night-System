#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/ObjectModify.hpp>
#include <cue/RepeatingBackground.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyLGLevelInfoLayer, LGLevelInfoLayer){

    void modify(){

        if (auto rBG = getChildByType<cue::RepeatingBackground>(0)){
            if (DayAndNightSystem::events > 0.99f){
                rBG->setVisible(false);
            }
        }
        if (auto bg = this->getChildByID("bg")){
            if (DayAndNightSystem::events > 0.99f){
				bg->setVisible(false);
			}
		}
    }

};