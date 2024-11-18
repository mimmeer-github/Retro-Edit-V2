#include "Version.hpp"
#include <Geode/modify/GameObject.hpp>

using namespace geode::prelude;

std::string VersionUtils::getVersionSimulating()
{
    return Mod::get()->getSettingValue<std::string>("version");
}

bool isGameobjectCreateWithKeyFix = false;

// What the fucking fuck is this assing ass
class $modify (GameObject)
{
    static GameObject* createWithKey(int key)
    {
        auto pRet = GameObject::createWithKey(key);

        if (!pRet && isGameobjectCreateWithKeyFix)
        {
            if (key == 104)
            {
                pRet = GameObject::createWithKey(1);

                if (CCSprite* newSpr = CCSprite::create("alphalaneous.old_color_triggers/edit_eTintLBtn_001.png"))
                {
                    pRet->m_hasSpecialChild = true;
                    pRet->setTexture(newSpr->getTexture());
                    pRet->setTextureRect(newSpr->getTextureRect());
                }
            }
        }

        return pRet;
    }
};

#define EDITOR_BUTTON(__objid__) \
if (__objid__ == -1) \
    btn = as<CCMenuItemSpriteExtra*>(CCNode::create()); \
else \
{ \
    btn = ui->getCreateBtn(__objid__, 4); \
    btn->setTarget(ui, menu_selector(EditorUI::onCreateButton)); \
    spr = CCSprite::create(); \
    if (btn->getNormalImage()->getChildByType<GameObject>(0)) \
        spr->setColor(btn->getNormalImage()->getChildByType<GameObject>(0)->getColor()); \
    spr->setID("colour"_spr); \
    spr->setVisible(false); \
    btn->addChild(spr); \
} \
btn->setTag(__objid__); \
array->addObject(btn);

#define REPEATED_EDITOR_BUTTON(__objid__, __count__) \
for (int i = 0; i < __count__; i++) \
{ \
    EDITOR_BUTTON(__objid__); \
}

#define REPEATED_INCREASED_EDITOR_BUTTON(__objid__, __count__) \
start = __objid__; \
for (int i = 0; i < __count__; i++) \
{ \
    EDITOR_BUTTON(start + i); \
}

// There is a better way to do this, Too bad!

CCArray* VersionUtils::getObjectsForVersion(std::string version, int rows, int columns, EditorUI* ui)
{
    auto array = CCArray::create();

    isGameobjectCreateWithKeyFix = true;

    CCMenuItemSpriteExtra* btn;
    CCSprite* spr;
    int start = 0;

    if (version == "1.0" || version == "1.1" || version == "1.2")
    {
        REPEATED_INCREASED_EDITOR_BUTTON(1, 8);
        EDITOR_BUTTON(39);
        EDITOR_BUTTON(9);
        EDITOR_BUTTON(40);
        REPEATED_INCREASED_EDITOR_BUTTON(35, 2);
        REPEATED_INCREASED_EDITOR_BUTTON(10, 4);

        int _11offset = 1;

        if (version == "1.1" || version == "1.2")
        {
            _11offset += (version == "1.2" ? 3 : 2);

            REPEATED_INCREASED_EDITOR_BUTTON(45, (version == "1.2" ? 3 : 2));
        }

        REPEATED_INCREASED_EDITOR_BUTTON(15, 7);
        EDITOR_BUTTON(41);

        REPEATED_EDITOR_BUTTON(-1, rows * columns - _11offset);

        EDITOR_BUTTON(22);
        EDITOR_BUTTON(24);
        EDITOR_BUTTON(23);
        REPEATED_INCREASED_EDITOR_BUTTON(25, 3);
        REPEATED_INCREASED_EDITOR_BUTTON(29, 3);
        EDITOR_BUTTON(33);
        EDITOR_BUTTON(32);
    }
    else if (version == "1.3" || version == "1.4" || version == "1.5" || version == "1.6")
    {
        EDITOR_BUTTON(1);
        EDITOR_BUTTON(83);
        REPEATED_INCREASED_EDITOR_BUTTON(2, 7);
        EDITOR_BUTTON(39);

        if (version == "1.4" || version == "1.5" || version == "1.6")
        {
            EDITOR_BUTTON(103);
        }

        EDITOR_BUTTON(9);
        EDITOR_BUTTON(61);
        EDITOR_BUTTON(40);
        EDITOR_BUTTON(62);
        EDITOR_BUTTON(66);
        EDITOR_BUTTON(65);
        EDITOR_BUTTON(68);
        EDITOR_BUTTON(35);

        if (version == "1.5" || version == "1.6")
        {
            EDITOR_BUTTON(140);
        }

        EDITOR_BUTTON(67);
        EDITOR_BUTTON(36);

        if (version == "1.5" || version == "1.6")
        {
            EDITOR_BUTTON(141);
        }

        EDITOR_BUTTON(84);
        REPEATED_INCREASED_EDITOR_BUTTON(10, 4);
        REPEATED_INCREASED_EDITOR_BUTTON(45, 3);

        if (version == "1.4" || version == "1.5" || version == "1.6")
        {
            EDITOR_BUTTON(99);
            EDITOR_BUTTON(101);

            if (version == "1.5" || version == "1.6")
            {
                EDITOR_BUTTON(111);
            }
        }

        REPEATED_INCREASED_EDITOR_BUTTON(15, 7);
        EDITOR_BUTTON(41);

        if (version == "1.5" || version == "1.6")
        {
            EDITOR_BUTTON(110);
            REPEATED_INCREASED_EDITOR_BUTTON(106, 2);
        }

        if (version == "1.5" || version == "1.6")
        {
            REPEATED_INCREASED_EDITOR_BUTTON(48, 2);
            REPEATED_INCREASED_EDITOR_BUTTON(129, 2);

            if (version == "1.6")
            {
                EDITOR_BUTTON(131);
            }

            REPEATED_INCREASED_EDITOR_BUTTON(113, 3);

            REPEATED_INCREASED_EDITOR_BUTTON(50, 5);
        }
        else
        {
            REPEATED_INCREASED_EDITOR_BUTTON(48, 7);
        }

        EDITOR_BUTTON(60);

        if (version == "1.6")
        {
            REPEATED_INCREASED_EDITOR_BUTTON(148, 2);
        }

        if (version == "1.4" || version == "1.5" || version == "1.6")
        {
            REPEATED_INCREASED_EDITOR_BUTTON(85, 3);
            EDITOR_BUTTON(97);

            if (version == "1.5" || version == "1.6")
            {
                REPEATED_INCREASED_EDITOR_BUTTON(137, 3);
            }

            REPEATED_INCREASED_EDITOR_BUTTON(88, 2);
            EDITOR_BUTTON(98);
        }

        REPEATED_INCREASED_EDITOR_BUTTON(69, 7);

        if (version == "1.4" || version == "1.5" || version == "1.6")
        {
            REPEATED_INCREASED_EDITOR_BUTTON(76, 3);
            REPEATED_INCREASED_EDITOR_BUTTON(80, 3);
            REPEATED_INCREASED_EDITOR_BUTTON(90, 7);

            if (version == "1.5" || version == "1.6")
            {
                REPEATED_INCREASED_EDITOR_BUTTON(116, 7);

                if (version == "1.6")
                {
                    REPEATED_INCREASED_EDITOR_BUTTON(160, 10);
                    EDITOR_BUTTON(193);

                    REPEATED_INCREASED_EDITOR_BUTTON(170, 3);
                    EDITOR_BUTTON(192);

                    EDITOR_BUTTON(173);
                    EDITOR_BUTTON(194);
                    REPEATED_INCREASED_EDITOR_BUTTON(174, 3);
                    EDITOR_BUTTON(197);
                }

                EDITOR_BUTTON(135);

                EDITOR_BUTTON(128);

                REPEATED_INCREASED_EDITOR_BUTTON(123, 5);

                REPEATED_INCREASED_EDITOR_BUTTON(132, 2);
                EDITOR_BUTTON(136);

                if (version == "1.6")
                {
                    EDITOR_BUTTON(150);
                    EDITOR_BUTTON(143);
                    EDITOR_BUTTON(146);
                    EDITOR_BUTTON(147);
                    EDITOR_BUTTON(144);
                    EDITOR_BUTTON(145);

                    EDITOR_BUTTON(134);
                    EDITOR_BUTTON(190);
                    EDITOR_BUTTON(151);
                    EDITOR_BUTTON(152);
                    EDITOR_BUTTON(153);
                    EDITOR_BUTTON(154);
                    EDITOR_BUTTON(155);
                    EDITOR_BUTTON(156);
                    EDITOR_BUTTON(157);
                    EDITOR_BUTTON(158);
                    EDITOR_BUTTON(159);

                    EDITOR_BUTTON(177);
                    EDITOR_BUTTON(178);
                    EDITOR_BUTTON(179);

                    EDITOR_BUTTON(180);
                    EDITOR_BUTTON(181);
                    EDITOR_BUTTON(182);
                    EDITOR_BUTTON(182);
                    EDITOR_BUTTON(184);
                    EDITOR_BUTTON(185);
                    EDITOR_BUTTON(186);
                    EDITOR_BUTTON(187);
                    EDITOR_BUTTON(188);

                    EDITOR_BUTTON(191);
                    EDITOR_BUTTON(198);
                    EDITOR_BUTTON(199);

                    EDITOR_BUTTON(195);
                    EDITOR_BUTTON(196);

                    REPEATED_EDITOR_BUTTON(-1, 2);
                }
            }
        }

        if (version == "1.5" || version == "1.6")
        {
            REPEATED_EDITOR_BUTTON(-1, rows * columns - 10);
        }
        else
        {
            REPEATED_EDITOR_BUTTON(-1, rows * columns - 3);
        }

        if (version == "1.4" || version == "1.5" || version == "1.6")
        {
            EDITOR_BUTTON(-1);
        }

        EDITOR_BUTTON(22);
        EDITOR_BUTTON(24);
        EDITOR_BUTTON(23);
        REPEATED_INCREASED_EDITOR_BUTTON(25, 4);
        REPEATED_INCREASED_EDITOR_BUTTON(56, 4);
        
        EDITOR_BUTTON(-1);

        if (version == "1.4" || version == "1.5" || version == "1.6")
        {
            REPEATED_INCREASED_EDITOR_BUTTON(29, 2);

            EDITOR_BUTTON(104);

            if (version == "1.5" || version == "1.6")
            {
                EDITOR_BUTTON(105);
            }

            EDITOR_BUTTON(31);
        }
        else
        {
            REPEATED_INCREASED_EDITOR_BUTTON(29, 3);
        }

        EDITOR_BUTTON(33);
        EDITOR_BUTTON(32);
    }

    isGameobjectCreateWithKeyFix = false;

    return array;
}