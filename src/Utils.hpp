#pragma once

using namespace geode::prelude;

class DayAndNightSystem: public CCNode{
protected:

bool init();

public:
   static DayAndNightSystem* create();
   static int events;
};

class DayAndNightSystemOverlay: public CCNode{
protected:

bool init();

public:
   static DayAndNightSystemOverlay* create();
};