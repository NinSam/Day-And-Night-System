cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(DayAndNightSystem VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED
    src/LevelInfoLayer.cpp
    src/MenuLayer.cpp
    src/CreatorLayer.cpp
    src/LevelSearchLayer.cpp
    src/LevelBrowserLayer.cpp
    src/EditLevelLayer.cpp
    src/LoadingLayer.cpp
    src/LeaderboardsLayer.cpp
    src/LevelSelectLayer.cpp
    src/LevelAreaLayer.cpp
    src/DailyLevelPage.cpp
    src/ProfilePage.cpp
    src/RewardsPage.cpp
    src/ChallengesPage.cpp
    src/MoreSearchLayer.cpp
    src/InfoLayer.cpp
    src/LevelLeaderboard.cpp
    src/MessagesProfilePage.cpp
    src/FriendsProfilePage.cpp
    src/FRequestProfilePage.cpp
    src/GJAccountSettingsLayer.cpp
    src/RateDemonLayer.cpp
    src/DemonInfoPopup.cpp
    src/StarInfoPopup.cpp
    src/MoreOptionsLayer.cpp
    src/VideoOptionsLayer.cpp
    src/TutorialLayer.cpp
    src/LevelListLayer.cpp
    src/LevelListLayer.cpp
    src/GJPathsLayer.cpp
    src/MoreVideoOptionsLayer.cpp
    src/Utils/utils.hpp
    src/Utils/utils.cpp
    # Add any extra C++ source files here
)

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

setup_geode_mod(${PROJECT_NAME})