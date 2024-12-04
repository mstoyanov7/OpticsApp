#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <sstream>

enum MENU_TYPE
{   
    INVALID,
    SHOPPING_MENU,
    MANAGER_MENU,
    EXIT
};

enum MANAGER_MENU_OPTIONS
{
    INVALID_OPTION,
    ADD_SUPPLIER,
    REMOVE_SUPPLIER,
    MODIFY_SUPPLIER,
    EXIT_MANAGER_MENU
};

static const char MAIN_MENU[] = "#--------------------#\n"
                                "| --- Main Menu ---  |\n"
                                "|1. Go shopping      |\n"
                                "|2. Manage suppliers |\n"
                                "|3. Exit             |\n"
                                "#--------------------#\n";

static const char SUPPLIER_MENU[] = "#-----------------------------#\n"
                                    "|--- Manage Suppliers Menu ---|\n"
                                    "|1. Add new supplier          |\n"
                                    "|2. Remove supplier           |\n"
                                    "|3. Modify supplier           |\n"
                                    "|4. Go back                   |\n"
                                    "#-----------------------------#\n"
                                    "Enter your choice: ";

static const char PRODUCT_CHOICE[] = "\nDo you want to add products for this supplier?\n"
                                    "1. Yes\n"
                                    "2. No\n"
                                    "Enter your choice: ";

static const char DATABASE[] = "../data/data.txt";

class Utility
{
    public:
        static int MainMenuGetChoice()
        {   
            int menuSelection;

            std::cout << MAIN_MENU;
            std::cout << "Enter your choice: ";
            std::cin >> menuSelection;
            std::cin.ignore();
            system("cls");

            return menuSelection;
        }
        static int ShoppingMenuGetChoice()
        {
            int choice;
            std::cout << "\nSelect a supplier by number: ";
            std::cin >> choice;
            std::cin.ignore();

            return choice - 1;
        }
        static int ManagerMenuGetChoice(int& choice)
        {
            std::cout << SUPPLIER_MENU;
            std::cin >> choice;
            std::cin.ignore();
            system("cls");
            
            return choice;
        }
        static bool AddProducts()
        {   
            int addProductChoice;
            std::cout << PRODUCT_CHOICE;
            std::cin >> addProductChoice;
            std::cin.ignore();

            return addProductChoice == 1;
        }

        static void trimWhitespaces(std::string& s)
        {
            while (!s.empty() && std::isspace(s.back())) s.pop_back();
            while (!s.empty() && std::isspace(s.front())) s.erase(0, 1);
        };

    private:
        Utility() = default;
        Utility(const Utility&) = delete;
        Utility& operator=(const Utility&) = delete;
};

#endif // UTILITY_HPP