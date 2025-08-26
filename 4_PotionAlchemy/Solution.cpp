#include <iostream>
#include <vector>
#include <string>
#include "AlchemyWorkshop.h"

//숫자 입력 말고, 이름 같은 문자 입력을 받는 코드를 그냥 함수로 만들어버림.
std::string getInputName()
{
    std::string input;
    while (true)
    {
        //std::cin >> [variable]은 마지막 엔터 입력 값이 버퍼에 남아버려서, 그 후에 getline을 사용하면 남아있는 엔터값을 바로 이어 받아 스킵이 된다. 버퍼에 남은 개행문자 제거가 필요.
        std::cin.ignore();
        std::getline(std::cin, input);
        break;
    }
    return input;
}

int main()
{
    AlchemyWorkshop myWorkshop;

    while (true)
    {
        std::cout << std::endl;
        std::cout << "⚗️ 연금술 공방 관리 시스템" << std::endl;
        std::cout << "1. 레시피 추가" << std::endl;
        std::cout << "2. 모든 레시피 출력" << std::endl;
        std::cout << "3. 이름으로 레시피 찾기" << std::endl;
        std::cout << "4. 재료로 레시피 찾기" << std::endl;
        std::cout << "5. 모든 포션 재고 출력" << std::endl;
        std::cout << "6. 포션 지급/재고 감소" << std::endl;
        std::cout << "7. 이름으로 포션 재고 추가" << std::endl;
        std::cout << "8. 종료" << std::endl;
        std::cout << "선택: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cout << "잘못된 입력입니다. 숫자를 입력해주세요." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1)
        {
            std::string name;
            std::cout << "물약 이름: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);

            // 여러 재료를 입력받기 위한 로직
            std::vector<std::string> ingredients_input;
            std::string ingredient;
            std::cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << std::endl;

            while (true)
            {
                std::cout << "재료 입력: ";
                std::getline(std::cin, ingredient);

                // 사용자가 '끝'을 입력하면 재료 입력 종료
                if (ingredient == "끝")
                {
                    break;
                }
                ingredients_input.push_back(ingredient);
            }

            // 입력받은 재료가 하나 이상 있을 때만 레시피 추가
            if (!ingredients_input.empty())
            {
                myWorkshop.addRecipe(name, ingredients_input);
            }
            else
            {
                std::cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << std::endl;
            }

        }
        else if (choice == 2)
        {
            myWorkshop.displayAllRecipes();

        }
        //과제4_필수: search Recipe By Name()
        else if (choice == 3)
        {
            std::cout << "찾으실 레시피 이름을 적어주세요." << std::endl;
            myWorkshop.searchRecipeByName(getInputName());
        }
        //과제4_필수: search Recipe By Ingredient()
        else if (choice == 4)
        {
            std::cout << "재료의 이름을 적어주세요." << std::endl;
            myWorkshop.searchRecipeByIngredient(getInputName());
        }
        //과제4_도전: 포션 재고 출력
        else if (choice == 5)
        {
            if (myWorkshop.stockmanager.getPotionsListSize() > 0)
            {
                myWorkshop.stockmanager.displayAllPotions();
            }
            else
            {
                std::cout << "보유한 / 등록된 포션 재고가 없습니다.\n";
            }
        }
        //과제4_도전: 플레이어가 고른 포션 지급 (포션 재고 감소만)
        else if (choice == 6)
        {
            if (myWorkshop.stockmanager.getPotionsListSize() != 0)
            {
                int index;
                while (true)
                {
                    myWorkshop.stockmanager.displayAllPotions();
                    std::cin >> index;

                    if (std::cin.fail())
                    {
                        std::cout << "잘못된 입력입니다. 숫자를 입력해주세요." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        continue;
                    }
                    else if (index > 0 && index < myWorkshop.stockmanager.getPotionsListSize() + 1)
                    {
                        myWorkshop.stockmanager.givePotion(index); //index 값은 1부터 받아서 index 0번에 접근하려면 -1을 해줘야 하지만, 이건 함수내에서 해주고 있다.
                        break;
                    }
                    else
                    {
                        std::cout << "잘못된 입력입니다. 올바른 범위 내의 숫자를 입력해주세요." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        continue;
                    }
                }
            }
            else
            {
                std::cout << "추가된 포션이 아예 없음.\n";
            }
        }
        //과제5_도전: 포션 재고 추가
        else if (choice == 7)
        {
            if (myWorkshop.stockmanager.getPotionsListSize() > 0)
            {
                myWorkshop.stockmanager.addPotionSupplyByName(getInputName());
            }
            else
            {
                std::cout << "현재 추가할/등록된 포션이 아예 없음.\n";
            }
        }
        else if (choice == 8)
        {
            std::cout << "공방 문을 닫습니다..." << std::endl;
            break;
        }
        else
        {
            std::cout << "잘못된 선택입니다. 다시 시도하세요." << std::endl;
        }
    }

    return 0;
}