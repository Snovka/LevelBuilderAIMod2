#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "LevelBuilderUI.hpp"

using namespace geode::prelude;

class $modify(MyMenu, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto btn = CCMenuItemLabel::create(
            CCLabelBMFont::create("AI Builder", "bigFont.fnt"),
            this,
            menu_selector(MyMenu::onOpenUI)
        );

        auto menu = this->getChildByID("main-menu");
        if (menu) {
            menu->addChild(btn);
            btn->setPosition({100, 100});
        }

        return true;
    }

    void onOpenUI(CCObject*) {
        auto scene = CCDirector::sharedDirector()->getRunningScene();
        auto ui = LevelBuilderUI::create();
        scene->addChild(ui, 1000); // поверх всього
    }
};
