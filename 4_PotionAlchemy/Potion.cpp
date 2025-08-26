#include <iostream>
#include <vector>
#include <string>
#include "Potion.h"

//과제4_도전: 표션 클래스 생성
Potion::Potion(const std::string& name, int amount)
    :potionName(name), potionAmount(amount)
    {
    }