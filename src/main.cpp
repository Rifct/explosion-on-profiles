#include <Geode/Geode.hpp>
#include <Geode/binding/ProfilePage.hpp>
#include <Geode/modify/ProfilePage.hpp>

using namespace geode::prelude;

class $modify(MyProfilePage, ProfilePage) { 
    void loadPageFromUserInfo(GJUserScore* p0) {
        ProfilePage::loadPageFromUserInfo(p0);

        int explosionNum = p0->m_playerExplosion;
        std::string explosionStr = fmt::format("explosionIcon_{:02d}_001.png", explosionNum);
        
        auto explosionSpr = CCSprite::createWithSpriteFrameName(explosionStr.c_str());
        
        auto menu = this->getChildByIDRecursive("player-menu");
        menu->addChild(explosionSpr);
        menu->updateLayout();

        auto sprite1 = this->getChildByIDRecursive("player-icon");
        auto sprite2 = this->getChildByIDRecursive("player-ship");
        auto sprite3 = this->getChildByIDRecursive("player-ball");
        auto sprite4 = this->getChildByIDRecursive("player-ufo");
        auto sprite5 = this->getChildByIDRecursive("player-wave");
        auto sprite6 = this->getChildByIDRecursive("player-robot");
        auto sprite7 = this->getChildByIDRecursive("player-spider");
        auto sprite8 = this->getChildByIDRecursive("player-swing");

        sprite1->setScale(0.93f);
        sprite2->setScale(0.93f);
        sprite3->setScale(0.93f);
        sprite4->setScale(0.93f);
        sprite5->setScale(0.93f);
        sprite6->setScale(0.93f);
        sprite7->setScale(0.93f);
        sprite8->setScale(0.93f);
        explosionSpr->setScale(0.93f);
        explosionSpr->setPositionX(324.602);
        
        menu->setScale(0.975f);
        menu->setPositionX(282);

        geode::log::debug("explosion number: {}", p0->m_playerExplosion);
    }
};