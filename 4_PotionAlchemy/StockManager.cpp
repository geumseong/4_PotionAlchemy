#include <iostream>
#include <vector>
#include <string>
#include "StockManager.h"
#include "Potion.h"

//����4_����: ������ ��� ������ Ŭ����
void StockManager::addPotion(std::string name)    //������ ��� ����Ʈ�� �߰�
{
    if (potionAlreadyExist(name) == nullptr)
    {
        potions.push_back(Potion(name));
    }
}

Potion* StockManager::potionAlreadyExist(const std::string& name) //�ش� �̸��� ���� ������ �̹� �����ϴ��� Ȯ��
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

void StockManager::addPotionSupplyByName(std::string name)    //���� ��� �߰�
{
    Potion* potion = potionAlreadyExist(name);

    if (potion != nullptr)
    {
        if (potion->potionAmount < 3)
        {
            std::cout << "debug: potion->pointAmount = " << potion->potionAmount << std::endl;
            potion->potionAmount++;
            std::cout << "debug: potion->pointAmount = " << potion->potionAmount << std::endl;
            std::cout << potion->potionName << "�� ��� 1 �����߽��ϴ�.\n";

        }
        else
        {
            std::cout << potion->potionName << "�� ��� �̹� 3 �Դϴ�!.\n";
        }
    }
    if (potion == nullptr)
    {
        std::cout << "���� ���� �̸��Դϴ�.\n";
    }
}

void StockManager::givePotion(int index)   //displayAllPotions()�� 1. HP���� 2. MP���� 3. ... �̷������� ����� ��, ���� �Է°��� ����� Ư�� index�� ���ǿ� ����.
{
    Potion* potion = &potions[index - 1];
    if (potion->potionAmount > 0)
    {
        std::cout << "debug: potion->pointAmount = " << potion->potionAmount << std::endl;
        potion->potionAmount -= 1;
        std::cout << "debug: potion->pointAmount = " << potion->potionAmount << std::endl;
        std::cout << potion->potionName << " 1���� ����/�����߽��ϴ�.\n";
        if (potion->potionAmount == 0)
        {
            std::cout << "��� �����Ǿ����ϴ�." << std::endl;
        }
    }
    else
    {
        std::cout << "�̹� �� ������ �����Դϴ�." << std::endl;
    }
}

void StockManager::displayAllPotions()    //��� ��������� ���ǵ��� ��� ���
{
    std::cout << "���� ������ ��� ����: \n";
    for (int i = 0; i < potions.size(); i++)
    {
        std::cout << i + 1 << ". ";
        displayPotion(potions[i]);
    }
}

void StockManager::displayPotion(const Potion& potion)   //���� ������ ��� ���
{
    std::cout << " > " << potion.potionName << ": " << potion.potionAmount << "��" << std::endl;
}