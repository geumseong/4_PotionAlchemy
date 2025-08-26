#include <iostream>
#include <vector>
#include <string>
#include "AlchemyWorkshop.h"

// AlchemyWorkshop Ŭ����: ������ ����� ����
StockManager stockmanager; //����4_���� ��� ������ �߰�

// addRecipe �޼���: ��� ���(vector)�� �Ű������� �޵��� ����
void AlchemyWorkshop::addRecipe(const std::string& name, const std::vector<std::string>& ingredients)
{
    bool alreadyExist = 0;
    for (int i = 0; i < recipes.size(); i++)
    {
        if (recipes[i].potionName == name)
        {
            alreadyExist = 1;
        }
    }
    if (!alreadyExist)
    {
        recipes.push_back(PotionRecipe(name, ingredients));
        std::cout << ">> ���ο� ������ '" << name << "'��(��) �߰��Ǿ����ϴ�." << std::endl;

        //����4_����: ������ �߰��� �� ��� 3�� �߰�.
        stockmanager.addPotion(name);
    }
    else
    {
        std::cout << "�̹� �����ϴ� �������Դϴ�.\n";
    }
}

// ��� ������ ��� �޼���
void AlchemyWorkshop::displayAllRecipes() const
{
    if (recipes.empty())
    {
        std::cout << "���� ��ϵ� �����ǰ� �����ϴ�." << std::endl;
        return;
    }

    std::cout << "\n--- [ ��ü ������ ��� ] ---" << std::endl;
    for (size_t i = 0; i < recipes.size(); ++i)
    {
        displayRecipe(recipes[i]);  //���� ������ ��� �Լ��� ���� ��ü��

        /*
        std::cout << "- ���� �̸�: " << recipes[i].potionName << std::endl;
        std::cout << "  > �ʿ� ���: ";

        // ��� ����� ��ȸ�ϸ� ���
        for (size_t j = 0; j < recipes[i].ingredients.size(); ++j)
        {
            std::cout << recipes[i].ingredients[j];
            // ������ ��ᰡ �ƴϸ� ��ǥ�� ����
            if (j < recipes[i].ingredients.size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
        */
    }
    std::cout << "---------------------------\n";
}

//����4_�ʼ�: ������ ���ϰ� �ϱ� ���ؼ� ���� ���� �����ǿ� ��� �Լ��� ����
void AlchemyWorkshop::displayRecipe(const PotionRecipe& recipe) const   //displayAllRecipes ���� �ڵ带 ���ͼ� ���� ���� ������ ��� �ڵ带 ���� - displayAllRecipe���� �ش� �Լ��� ������.
{
    std::cout << "- ���� �̸�: " << recipe.potionName << std::endl;
    std::cout << "  > �ʿ� ���: ";

    // ��� ����� ��ȸ�ϸ� ���
    for (size_t j = 0; j < recipe.ingredients.size(); ++j)
    {
        std::cout << recipe.ingredients[j];
        // ������ ��ᰡ �ƴϸ� ��ǥ�� ����
        if (j < recipe.ingredients.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

//����4_�ʼ�: searchRecipeByName(name: stromg): PotionRecipe�� ����
PotionRecipe* AlchemyWorkshop::searchRecipeByName(const std::string& name)
{
    if (recipes.empty())
    {
        std::cout << "���� ��ϵ� �����ǰ� �����ϴ�. \n";
    }
    for (int i = 0; i < recipes.size(); i++)
    {
        if (recipes[i].potionName == name)
        {
            displayRecipe(recipes[i]);
            std::cout << "---------------------------\n";
            return &recipes[i];
        }
    }
    std::cout << "�ش� �̸��� �����Ǹ� ã�� �� �����ϴ�." << std::endl;
    std::cout << "---------------------------\n";
    return nullptr;
}

//����4_�ʼ�: searchRecipeByIngredient(name: stromg): vector<PotionRecipe>�� ����
std::vector<PotionRecipe> AlchemyWorkshop::searchRecipeByIngredient(std::string ingredient)
{
    std::vector<PotionRecipe> foundRecipes;

    if (recipes.empty())
    {
        std::cout << "���� ��ϵ� �����ǰ� �����ϴ�. \n";
        std::cout << "---------------------------\n";
        //return foundRecipes;
    }

    for (int i = 0; i < recipes.size(); i++)
    {
        for (int j = 0; j < recipes[i].ingredients.size(); j++)
        {
            if (recipes[i].ingredients[j] == ingredient)
            {
                foundRecipes.push_back(recipes[i]);
                displayRecipe(recipes[i]);
                break;
            }
        }
    }

    if (foundRecipes.empty())
    {
        std::cout << "�ش� ����� �����Ǹ� ã�� �� �����ϴ�." << std::endl;
        std::cout << "---------------------------\n";
        return foundRecipes;
    }
    else
    {
        return foundRecipes;
    }
}