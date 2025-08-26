#pragma once
#include <iostream>
#include <vector>
#include <string>

//과제4_도전: 표션 클래스 생성
class Potion
{
public:
    std::string potionName;
    int potionAmount;

    //생성자
    Potion(const std::string& name, int amount = 3);
};