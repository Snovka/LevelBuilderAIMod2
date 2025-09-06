#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

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
        FLAlertLayer::create("LevelBuilderAI", "UI ще в розробці!", "OK")->show();
    }
};
