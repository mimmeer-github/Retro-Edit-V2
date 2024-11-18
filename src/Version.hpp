#pragma once

#include <Geode/Geode.hpp>

namespace VersionUtils
{
    std::string getVersionSimulating();

    cocos2d::CCArray* getObjectsForVersion(std::string version, int rows, int columns, EditorUI* ui);
};