#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "PotionRecipe.h"
#include "StockManager.h"

// AlchemyWorkshop 클래스: 레시피 목록을 관리
class AlchemyWorkshop
{
private:
    std::vector<PotionRecipe> recipes;

public:
    StockManager stockmanager; //과제4_도전 재고 관리자 추가

    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    // 모든 레시피 출력 메서드
    void displayAllRecipes() const;

    //과제4_필수: 과제를 편하게 하기 위해서 따로 단일 레시피용 출력 함수를 만듦
    void displayRecipe(const PotionRecipe& recipe) const;   //displayAllRecipes 에서 코드를 따와서 따로 단일 레시피 출력 코드를 만듦 - displayAllRecipe에서 해당 함수를 적용함.

    //과제4_필수: searchRecipeByName(name: stromg): PotionRecipe로 리턴
    PotionRecipe* searchRecipeByName(const std::string& name);

    //과제4_필수: searchRecipeByIngredient(name: stromg): vector<PotionRecipe>로 리턴
    std::vector<PotionRecipe> searchRecipeByIngredient(std::string ingredient);
};