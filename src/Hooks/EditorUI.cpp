#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>
#include <Geode/modify/EditButtonBar.hpp>

#include "../Version.hpp"

using namespace geode::prelude;

class $modify (RetroEditorUI, EditorUI)
{
    struct Fields
    {
        EditButtonBar* bar;
        Ref<CCArray> objs;
    };

    bool init(LevelEditorLayer* editorLayer)
    {
        if (!EditorUI::init(editorLayer))
            return false;

        if (auto tabs = m_tabsMenu)
        {
            tabs->setScale(0);
        }

        for (auto tab : CCArrayExt<CCNode*>(m_createButtonBars))
        {
            tab->setScale(0);
        }

        int rows = 6;
        int columns = 2;

        auto objs = VersionUtils::getObjectsForVersion(VersionUtils::getVersionSimulating(), rows, columns, this);
        m_fields->objs = objs;

        auto editBar = EditButtonBar::create(objs, ccp(CCDirector::get()->getWinSize().width / 2 - 5, 86), 69, false, rows, columns);
        editBar->setZOrder(10);
        editBar->setID("edit-bar"_spr);
        m_fields->bar = editBar;
        
        this->addChild(editBar);
        return true;
    }

    void resetUI()
    {
        EditorUI::resetUI();

        if (m_fields->bar && m_tabsMenu)
            m_fields->bar->setVisible(m_tabsMenu->isVisible());
    }

    void updateCreateMenu(bool p0)
    {
        EditorUI::updateCreateMenu(p0);

        for (auto btn : CCArrayExt<CCNode*>(m_fields->objs))
        {
            if (auto tbtn = typeinfo_cast<CreateMenuItem*>(btn))
            {
                auto btnSpr = as<ButtonSprite*>(tbtn->getNormalImage());
                auto go = btnSpr->getChildByType<EffectGameObject>(0) || btnSpr->getChildByType<GameObject>(0);

                auto col3 = as<CCSprite*>(tbtn->getChildByID("colour"_spr))->getColor();
                auto col = btn->getTag() == m_selectedObjectIndex ? ccc3(127, 127, 127) : ccWHITE;
                auto col2 = col3 == ccBLACK ? col3 : (btn->getTag() == m_selectedObjectIndex ? ccc3(127, 127, 127) : col3);

                btnSpr->m_subBGSprite->setColor(col);
                // go->setColor(col2);
            }
        }
    }
};