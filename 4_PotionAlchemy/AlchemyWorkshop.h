#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "PotionRecipe.h"
#include "StockManager.h"

// AlchemyWorkshop Ŭ����: ������ ����� ����
class AlchemyWorkshop
{
private:
    std::vector<PotionRecipe> recipes;

public:
    StockManager stockmanager; //����4_���� ��� ������ �߰�

    // addRecipe �޼���: ��� ���(vector)�� �Ű������� �޵��� ����
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    // ��� ������ ��� �޼���
    void displayAllRecipes() const;

    //����4_�ʼ�: ������ ���ϰ� �ϱ� ���ؼ� ���� ���� �����ǿ� ��� �Լ��� ����
    void displayRecipe(const PotionRecipe& recipe) const;   //displayAllRecipes ���� �ڵ带 ���ͼ� ���� ���� ������ ��� �ڵ带 ���� - displayAllRecipe���� �ش� �Լ��� ������.

    //����4_�ʼ�: searchRecipeByName(name: stromg): PotionRecipe�� ����
    PotionRecipe* searchRecipeByName(const std::string& name);

    //����4_�ʼ�: searchRecipeByIngredient(name: stromg): vector<PotionRecipe>�� ����
    std::vector<PotionRecipe> searchRecipeByIngredient(std::string ingredient);
};