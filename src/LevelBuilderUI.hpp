#pragma once
#include <Geode/Geode.hpp>
#include <Geode/ui/FLAlertLayer.hpp>
#include <thread>
#include <chrono>

using namespace geode::prelude;

class LevelBuilderUI : public CCLayer {
public:
    static LevelBuilderUI* create() {
        auto ret = new LevelBuilderUI();
        if (ret && ret->init()) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }

    bool init() override {
        if (!CCLayer::init()) return false;

        auto winSize = CCDirector::sharedDirector()->getWinSize();
        auto bg = CCLayerColor::create(ccc4(139, 69, 19, 220), 500, 300); // коричневий
        bg->setPosition({winSize.width/2 - 250, winSize.height/2 - 150});
        this->addChild(bg);

        startProcess();

        return true;
    }

private:
    void startProcess() {
        std::thread([this]() {
            showMessage("Checking if possible...");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            
            bool possible = checkLevel();
            if (!possible) {
                showMessage("Level impossible, regenerating...");
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }

            showMessage("Decorating...");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            decorateLevel();

            showMessage("Level generated!");
        }).detach();
    }

    void showMessage(const std::string& msg) {
        CCDirector::sharedDirector()->getScheduler()->performFunctionInCocosThread([msg]() {
            FLAlertLayer::create("LevelBuilderAI", msg.c_str(), "OK")->show();
        });
    }

    bool checkLevel() {
        // Алгоритм перевірки прохідності
        return true; // тимчасово
    }

    void decorateLevel() {
        // Автоматичне розміщення блоків та декорацій
    }
};
