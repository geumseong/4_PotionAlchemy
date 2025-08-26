#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Potion.h"

//����4_����: ������ ��� ������ Ŭ���� ����
class StockManager
{
private:
    std::vector<Potion> potions;    //���� Ŭ���� ��ü���� ����Ʈ

public:
    int getPotionsListSize() { return potions.size(); }    //���� ����Ʈ�� ũ��

    std::vector<Potion> getPotionsList() { return potions; }

    Potion* potionAlreadyExist(const std::string& name);  //�ش� �̸��� ���� ������ �̹� �����ϴ��� Ȯ��

    void addPotion(std::string name);    //������ ��� ����Ʈ�� �߰�

    void addPotionSupplyByName(std::string name);    //���� ��� �߰�

    void givePotion(int index);   //displayAllPotions()�� 1. HP���� 2. MP���� 3. ... �̷������� ����� ��, ���� �Է°��� ����� Ư�� index�� ���ǿ� ����.

    void displayAllPotions();    //��� ��������� ���ǵ��� ��� ���

    void displayPotion(const Potion& potion);   //���� ������ ��� ���
};
