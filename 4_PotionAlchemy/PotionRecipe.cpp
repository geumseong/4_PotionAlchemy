#include <iostream>
#include <vector>
#include <string>
#include "PotionRecipe.h"

// ������: ��� ����� �޾� �ʱ�ȭ�ϵ��� ����
PotionRecipe::PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients)
    : potionName(name), ingredients(ingredients)
{
}