#pragma once // ty alphalaneous

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