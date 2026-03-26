# Changelog

## v1.3.0

- Ported to GD 2.2081 & Geode v5.4.1
- Added 11 Modded Layers
- Added LevelPage in LevelSelectLayer
- Added a white outline around the progress bars in LevelInfoLayer & LevelPage in the night & dark event
- Tweaked CCScale9Sprites/NineSlice colors in the night event
- GJListLayer's bg is set to a solid black color in the night & dark event in some Modded Layers
- Renamed some Mod Settings
- Fixed a crash in EditLevelLayer if the level is uploaded in the sunrise & sunset event
- Fixed a bug in LevelListLayer where the title-background wouldn't show if the list is uploaded in the sunrise & sunset event
- Fixed Dark Overlay layering above BetterInfo's ProfileSearchOptions Popup
- Fixed unnecessary backgrounds not disabling in the sunrise event
- Reworked code

## v1.2.3

- Fixed crash when entering an online list during the sunrise & sunset event

## v1.2.2

- Fixed title-background in LevelListLayer not appearing/changing colors when one of the events have started
- Fixed CCScale9Sprite positioning on different resolutions in EditLevelLayer during the sunrise & sunset event

## v1.2.1

- Optimization: Disabled unnecessary backgrounds when one of the events have started
- CCScale9Sprites in EditLevelLayer, LevelSearchLayer, & RandomLayer are a bit more visible in the dark event
- Replaced some sprites with CCLayerColor & CCLayerGradient
- Added GYSettingSelectLayer
- Reworked some code

## v1.2.0

- Added Modded Layers
- Added Dependency: Alpha's Geode Utils (for modded layers)
- Added GauntletLayer & GauntletSelectLayer
- Sprites now have low, medium, and high graphics
- Changed default settings for customize time
- Removed Dark Overlay to popups
- Internal changes for getting current time

## v1.1.9

- Added iOS Jitless support

## v1.1.8

- Added iOS support

## v1.1.7

- Added LoadingLayer

## v1.1.6

- Improved the colors on the sunset sprite ([#7](https://github.com/NinSam/Day-And-Night-System/issues/7))
- Dark Overlay max opacity is now 225 instead of 255
- Dark Overlay has been removed from SetFolderPopup and SetTextPopup
- Changed mod logo

## v1.1.5

- Fixed Start Dark Hr being on Start Sunset Hr for EditLevelLayer, LevelSearchLayer, and LevelAreaLayer

## v1.1.4

- Improved the quality of the star sprites
- Fixed Start Dark Hr being on Start Sunset Hr

## v1.1.3

- You can now set the opacity for the stars
- Dark Overlay has been removed from SetIDPopup

## v1.1.2

- Fixed a small gradient cutoff on the sunrise sprite
- You can now set the opacity for the Dark Overlay
- Added Dark Overlay to ShareCommentLayer

## v1.1.1

- Fixed Dark Overlay appearing in the sunset event
- Changed descriptions from customize time settings
- Added Dark Overlay to 7 more popups/layers

## v1.1.0

- Added customization when an event starts and ends

## v1.0.2

- Added Dark Overlay to LikeItemLayer and RateStarsLayer
- Fixed crash when adding levels to lists ([#1](https://github.com/NinSam/Day-And-Night-System/issues/1))

## v1.0.1

- Fixed Dark Overlay visual bug
- Reworked code

## v1.0.0

- Initial Release