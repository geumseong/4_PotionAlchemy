#pragma once
#include <iostream>
#include <vector>
#include <string>

//����4_����: ǥ�� Ŭ���� ����
class Potion
{
public:
    std::string potionName;
    int potionAmount;

    //������
    Potion(const std::string& name, int amount = 3);
};