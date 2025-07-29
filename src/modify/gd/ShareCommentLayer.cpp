#include <Geode/Geode.hpp>
#include <Geode/modify/ShareCommentLayer.hpp>
#include "../../Utils.hpp"

using namespace geode::prelude;

class $modify(ShareCommentLayer) {

	bool init(gd::string title, int charLimit, CommentType type, int ID, gd::string desc) {
		if (!ShareCommentLayer::init(title, charLimit, type, ID, desc))
		return false;

		auto DayAndNightSystemOverlay = DayAndNightSystemOverlay::create();
		DayAndNightSystemOverlay->setID("ScreenOverlay"_spr);
		this->addChild(DayAndNightSystemOverlay,106);

		return true;
	}
};