#include <iostream>
#include <vector>
#include <string>
#include "StockManager.h"
#include "Potion.h"

//과제4_도전: 포션의 재고 관리자 클래스
void StockManager::addPotion(std::string name)    //포션을 재고 리스트에 추가
{
    if (potionAlreadyExist(name) == nullptr)
    {
        potions.push_back(Potion(name));
    }
}

Potion* StockManager::potionAlreadyExist(const std::string& name) //해당 이름을 가진 포션이 이미 존재하는지 확인
{
    for (int i = 0; i < potions.size(); i++)
    {
        if (potions[i].potionName == name)
        {
            return &potions[i];
        }
    }
    return nullptr;
}

void StockManager::addPotionSupplyByName(std::string name)    //포션 재고 추가
{
    Potion* potion = potionAlreadyExist(name);

    if (potion != nullptr)
    {
        if (potion->potionAmount < 3)
        {
            std::cout << "debug: potion->pointAmount = " << potion->potionAmount << std::endl;
            potion->potionAmount++;
            std::cout << "debug: potion->pointAmount = " << potion->potionAmount << std::endl;
            std::cout << potion->potionName << "의 재고가 1 증가했습니다.\n";

        }
        else
        {
            std::cout << potion->potionName << "의 재고가 이미 3 입니다!.\n";
        }
    }
    if (potion == nullptr)
    {
        std::cout << "없는 포션 이름입니다.\n";
    }
}

void StockManager::givePotion(int index)   //displayAllPotions()로 1. HP물약 2. MP물약 3. ... 이런식으로 출력한 후, 숫자 입력값을 사용해 특정 index의 포션에 접근.
{
    Potion* potion = &potions[index - 1];
    if (potion->potionAmount > 0)
    {
        std::cout << "debug: potion->pointAmount = " << potion->potionAmount << std::endl;
        potion->potionAmount -= 1;
        std::cout << "debug: potion->pointAmount = " << potion->potionAmount << std::endl;
        std::cout << potion->potionName << " 1개를 지급/소진했습니다.\n";
        if (potion->potionAmount == 0)
        {
            std::cout << "재고가 소진되었습니다." << std::endl;
        }
    }
    else
    {
        std::cout << "이미 다 소진된 포션입니다." << std::endl;
    }
}

void StockManager::displayAllPotions()    //모든 만들어졌던 포션들의 재고 출력
{
    std::cout << "현재 보유한 모든 물약: \n";
    for (int i = 0; i < potions.size(); i++)
    {
        std::cout << i + 1 << ". ";
        displayPotion(potions[i]);
    }
}

void StockManager::displayPotion(const Potion& potion)   //단일 포션의 재고 출력
{
    std::cout << " > " << potion.potionName << ": " << potion.potionAmount << "개" << std::endl;
}