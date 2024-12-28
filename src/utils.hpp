// ty alphalaneous. EditLevelLayer, LevelAreaLayer, and LevelSearchLayer are not changed due to some problems.

using namespace geode::prelude;

class DayAndNightSystem: public CCNode{
protected:

bool init();

public:

   static DayAndNightSystem* create();

};

class DayAndNightSystemOverlay: public CCNode{
protected:

bool init();

public:

   static DayAndNightSystemOverlay* create();

};