#include <iostream>
#include <vector>
#include <string>
#include "AlchemyWorkshop.h"

// AlchemyWorkshop 클래스: 레시피 목록을 관리
StockManager stockmanager; //과제4_도전 재고 관리자 추가

// addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
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
        std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;

        //과제4_도전: 레시피 추가할 때 재고 3개 추가.
        stockmanager.addPotion(name);
    }
    else
    {
        std::cout << "이미 존재하는 레시피입니다.\n";
    }
}

// 모든 레시피 출력 메서드
void AlchemyWorkshop::displayAllRecipes() const
{
    if (recipes.empty())
    {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }

    std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl;
    for (size_t i = 0; i < recipes.size(); ++i)
    {
        displayRecipe(recipes[i]);  //단일 레시피 출력 함수를 만들어서 대체함

        /*
        std::cout << "- 물약 이름: " << recipes[i].potionName << std::endl;
        std::cout << "  > 필요 재료: ";

        // 재료 목록을 순회하며 출력
        for (size_t j = 0; j < recipes[i].ingredients.size(); ++j)
        {
            std::cout << recipes[i].ingredients[j];
            // 마지막 재료가 아니면 쉼표로 구분
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

//과제4_필수: 과제를 편하게 하기 위해서 따로 단일 레시피용 출력 함수를 만듦
void AlchemyWorkshop::displayRecipe(const PotionRecipe& recipe) const   //displayAllRecipes 에서 코드를 따와서 따로 단일 레시피 출력 코드를 만듦 - displayAllRecipe에서 해당 함수를 적용함.
{
    std::cout << "- 물약 이름: " << recipe.potionName << std::endl;
    std::cout << "  > 필요 재료: ";

    // 재료 목록을 순회하며 출력
    for (size_t j = 0; j < recipe.ingredients.size(); ++j)
    {
        std::cout << recipe.ingredients[j];
        // 마지막 재료가 아니면 쉼표로 구분
        if (j < recipe.ingredients.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

//과제4_필수: searchRecipeByName(name: stromg): PotionRecipe로 리턴
PotionRecipe* AlchemyWorkshop::searchRecipeByName(const std::string& name)
{
    if (recipes.empty())
    {
        std::cout << "현재 등록된 레시피가 업습니다. \n";
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
    std::cout << "해당 이름의 레시피를 찾을 수 없습니다." << std::endl;
    std::cout << "---------------------------\n";
    return nullptr;
}

//과제4_필수: searchRecipeByIngredient(name: stromg): vector<PotionRecipe>로 리턴
std::vector<PotionRecipe> AlchemyWorkshop::searchRecipeByIngredient(std::string ingredient)
{
    std::vector<PotionRecipe> foundRecipes;

    if (recipes.empty())
    {
        std::cout << "현재 등록된 레시피가 업습니다. \n";
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
        std::cout << "해당 재료의 레시피를 찾을 수 없습니다." << std::endl;
        std::cout << "---------------------------\n";
        return foundRecipes;
    }
    else
    {
        return foundRecipes;
    }
}