#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Potion.h"

//과제4_도전: 포션의 재고 관리자 클래스 생성
class StockManager
{
private:
    std::vector<Potion> potions;    //포션 클래스 객체들의 리스트

public:
    int getPotionsListSize() { return potions.size(); }    //포션 리스트의 크기

    std::vector<Potion> getPotionsList() { return potions; }

    Potion* potionAlreadyExist(const std::string& name);  //해당 이름을 가진 포션이 이미 존재하는지 확인

    void addPotion(std::string name);    //포션을 재고 리스트에 추가

    void addPotionSupplyByName(std::string name);    //포션 재고 추가

    void givePotion(int index);   //displayAllPotions()로 1. HP물약 2. MP물약 3. ... 이런식으로 출력한 후, 숫자 입력값을 사용해 특정 index의 포션에 접근.

    void displayAllPotions();    //모든 만들어졌던 포션들의 재고 출력

    void displayPotion(const Potion& potion);   //단일 포션의 재고 출력
};
