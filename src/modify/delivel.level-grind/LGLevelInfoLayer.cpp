#include <Geode/Geode.hpp>
#include <alphalaneous.alphas_geode_utils/include/ObjectModify.hpp>
#include <cue/RepeatingBackground.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $nodeModify(MyLGLevelInfoLayer, LGLevelInfoLayer){

    void modify(){

        if (DayAndNightSystem::events > 0.99f){

            if (auto rBG = getChildByType<cue::RepeatingBackground>(0)){
                rBG->setVisible(false);
            }
            else if (auto bg = this->getChildByID("bg")){
			    bg->setVisible(false);
		    }

        }

    }

};