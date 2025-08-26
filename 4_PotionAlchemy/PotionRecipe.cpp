#include <iostream>
#include <vector>
#include <string>
#include "PotionRecipe.h"

// 생성자: 재료 목록을 받아 초기화하도록 수정
PotionRecipe::PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients)
    : potionName(name), ingredients(ingredients)
{
}