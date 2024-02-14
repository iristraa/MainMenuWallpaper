#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto mainMenu = this->getChildByID("main-menu-bg");
        mainMenu->setVisible(false);

        auto wallpaperSprite = CCSprite::create("wallpaper.png"_spr);

        auto winSize = CCDirector::sharedDirector()->getWinSize();
        auto wallpaperSize = wallpaperSprite->getContentSize();

        switch (Mod::get()->getSettingValue<int64_t>("wallpaper-fit-type")) 
        {
        case 1:
            // fill
            wallpaperSprite->setPosition({ winSize.width / 2, winSize.height / 2 }); 
            wallpaperSprite->setScaleX(std::max(winSize.height / wallpaperSize.height, winSize.width / wallpaperSize.width));
            wallpaperSprite->setScaleY(std::max(winSize.height / wallpaperSize.height, winSize.width / wallpaperSize.width));
            wallpaperSprite->setZOrder(-5); 
            this->addChild(wallpaperSprite); 
            break;

        case 2:
            // fit
            wallpaperSprite->setPosition({ winSize.width / 2, winSize.height / 2 });
            wallpaperSprite->setScaleX(std::min(winSize.height / wallpaperSize.height, winSize.width / wallpaperSize.width));
            wallpaperSprite->setScaleY(std::min(winSize.height / wallpaperSize.height, winSize.width / wallpaperSize.width));
            wallpaperSprite->setZOrder(-5); 
            this->addChild(wallpaperSprite); 
            break;

        case 3:
            // stretch
            wallpaperSprite->setAnchorPoint({ 0, 0 });
            wallpaperSprite->setPosition({ 0, 0 });
            wallpaperSprite->setScaleX(winSize.width / wallpaperSize.width); 
            wallpaperSprite->setScaleY(winSize.height / wallpaperSize.height);
            wallpaperSprite->setZOrder(-5);
            this->addChild(wallpaperSprite);
            break;

        case 4:
            // center
            wallpaperSprite->setPosition({ winSize.width / 2, winSize.height / 2 });
            wallpaperSprite->setZOrder(-5);
            this->addChild(wallpaperSprite);
            break;
        }

        return true;
    }
};
