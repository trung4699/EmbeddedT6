/*
* File: main.cpp
* Author: Phan Hoang Trung
* Date: 07/08/2023
* Description: This is a main file for restaurant management
* 
*/


#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 2 - Restaurant Management\Header\table.hpp"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 2 - Restaurant Management\Header\operation.hpp"
#include <vector>

int main()
{
    std::list <Dish> g_menu;
    Dish dish1 ("FriedChicken", 35.000);
    Dish dish2 ("Coca", 10.000);
    Dish dish3 ("Soup", 20.000);

    g_menu.push_back(dish1);
    g_menu.push_back(dish2);
    g_menu.push_back(dish3);

    unsigned int numberTable = 1;
    std::vector <Table> g_table(numberTable);
    
    bool checkStopProgram = true;
    while(checkStopProgram)
    {
        int program;
        do
        {
            std::cout << "Please enter number to access program:  " << '\n';
            std::cout << "1. Dishes management " << '\n';
            std::cout << "2. Staff " << '\n';
            std::cout << "3. Stop " << '\n';
            std::cout << "---------------------------------------------" << '\n';
            std::cin >> program;
        } while (program != 1 && program != 2 && program != 3);


        if (program == 1)
        {
            bool checkManage = true;
            do
            {
                int selectOption;
                
                do
                {
                    std::cout << "Please select option by enter number: " << '\n';
                    std::cout << "1. Enter number of table: " << '\n';
                    std::cout << "2. Add new dish: " << '\n';
                    std::cout << "3. Update info for a dish: " << '\n';
                    std::cout << "4. Delete dish: " << '\n';
                    std::cout << "5. Menu: " << '\n';
                    std::cout << "0. Back " << '\n';
                    std::cout << "---------------------------------------------" << '\n';
                    std::cin >> selectOption;
                } while (selectOption != 0 && selectOption != 1 && selectOption != 2 && selectOption != 3 && selectOption != 4 && selectOption != 5);
                

                if (selectOption == 1)
                {  
                    std::cout << "Enter number of table: " << '\n';
                    std::cin >> numberTable;
                    g_table.resize(numberTable);
                    
                    int numberSwitch;
                    do
                    {
                        std::cout << "Do you want to select other option ? " << '\n';
                        std::cout << "1. Yes " << '\n';
                        std::cout << "0. Back " << '\n';
                        std::cout << "---------------------------------------------" << '\n';
                        std::cin >> numberSwitch;
                    } while (numberSwitch != 0 && numberSwitch != 1);
                    
                    if (numberSwitch == 0)
                    {
                        checkManage = false;
                    }
                    else if (numberSwitch == 1)
                    {
                        checkManage = true;
                    }
                }


                else if (selectOption == 2)
                {
                    bool checkSelectNewDish = false;
                    do
                    {

                        int numberSwitch;
                        addNewDish(g_menu);

                        std::cout << "Please select option by enter number: " << '\n';
                        std::cout << "1. Add new dish " << '\n';
                        std::cout << "0. Back " << '\n';
                        std::cout << "---------------------------------------------" << '\n';
                        std::cin >> numberSwitch;

                        if (numberSwitch == 1)
                        {
                            checkSelectNewDish = true;
                        }
                        else if (numberSwitch == 0)
                        {
                            checkSelectNewDish = false;
                        }
                        
                    } while (checkSelectNewDish); 
                }

                else if (selectOption == 3)
                {
                    
                    bool checkSelectUpdate = false;
                    int numberSwitch;
                    do
                    {
                        updateInfoDish(g_menu);

                        std::cout << "Please select option by enter number: " << '\n';
                        std::cout << "1. Update info for other dish " << '\n';
                        std::cout << "0. Back " << '\n';
                        std::cout << "---------------------------------------------" << '\n';
                        std::cin >> numberSwitch;

                        if (numberSwitch == 1)
                        {
                            checkSelectUpdate = true;
                        }

                        else if (numberSwitch == 0)
                        {
                            checkSelectUpdate = false;
                        }    

                    } while (checkSelectUpdate);    
        
                }


                else if (selectOption == 4)
                {
                    
                    bool checkSelectDelete = false;
                    int numberSwitch;
                    do
                    {
                        deleteDish(g_menu);
                        
                        std::cout << "Please select option by enter number: " << '\n';
                        std::cout << "1. Delete other dish " << '\n';
                        std::cout << "0. Back " << '\n';
                        std::cout << "---------------------------------------------" << '\n';
                        do
                        {
                            std::cin >> numberSwitch;
                        } while (numberSwitch != 0 && numberSwitch != 1);

                        if (numberSwitch == 1)
                        {
                            checkSelectDelete = true;
                        }
                        else if (numberSwitch == 0)
                        {
                            checkSelectDelete = false;
                        }
                    
                    } while (checkSelectDelete);
                    
                }


                else if (selectOption == 5)
                {
                    printMenu(g_menu);
                    checkManage = true;
                }


                else if (selectOption == 0)
                {
                    checkManage = false;
                }

            } while (checkManage);
        }


        else if (program == 2)
        {
            bool checkStaff = true;
            
            std::cout << "Table number: " << '\t';
            
            for (unsigned int i = 0; i < numberTable; ++i)
            {
                std::cout << i + 1<< '\t';
            }

            std::cout << '\n';
            std::cout << "Status: " << '\t';
            
            for (unsigned int i = 0; i < numberTable; ++i)
            {
                if (g_table.at(i).getStatus())
                {
                    std::cout << "O" << '\t';
                }
                else
                {
                    std::cout << "X" << '\t';
                }
            }
            std::cout << '\n';
            std::cout << "X: Unavailable" << '\n';
            std::cout << "O: Available" << '\n';
            std::cout << "---------------------------------------------" << '\n';

            unsigned int chooseTable;
            do
            {
                std::cout << "Choose table: " << '\n';
                std::cout << "---------------------------------------------" << '\n';
                std::cin >> chooseTable;
            } while (chooseTable < 1 && chooseTable > numberTable);
            
            chooseTable -= 1;
            
            do
            {
                int selectOptionTable; 
                std::cout << "This is table " << chooseTable + 1 << '\n';
                do
                {
                    std::cout << "Please select option by enter number: " << '\n';
                    std::cout << "1. Order: " << '\n';
                    std::cout << "2. Change dish: " << '\n';
                    std::cout << "3. Cancel dish: " << '\n';
                    std::cout << "4. List of dish: " << '\n';
                    std::cout << "5. Payment: " << '\n';
                    std::cout << "0. Back " << '\n';
                    std::cout << "---------------------------------------------" << '\n';
                    std::cin >> selectOptionTable;
                } while (selectOptionTable != 0 && selectOptionTable != 1 && selectOptionTable != 2 && selectOptionTable != 3 && selectOptionTable != 4 && selectOptionTable != 5);
                
                
                if (selectOptionTable == 1)
                {
                    bool checkOrder = false;
                    int numberSwitch;
                    do
                    {
                        g_table.at(chooseTable).addOrder(orderDish(g_menu));
                        g_table.at(chooseTable).printOrder();
                        
                        do
                        {
                            std::cout << "Please select option by enter number: " << '\n';
                            std::cout << "1. Order new dish " << '\n';
                            std::cout << "0. Back " << '\n';
                            std::cout << "---------------------------------------------" << '\n';
                            std::cin >> numberSwitch;
                        } while (numberSwitch != 0 && numberSwitch != 1);

                        if (numberSwitch == 1)
                        {
                            checkOrder = true;
                        }

                        else if (numberSwitch == 0)
                        {
                            checkOrder = false;
                        }
    
                    } while (checkOrder);
                }

                else if (selectOptionTable == 2)
                {
                   int numberSwitch;
                   bool checkChangeOrder;
                   do
                   {
                        g_table.at(chooseTable).printOrder();
                        g_table.at(chooseTable).deleteOrder();
                        g_table.at(chooseTable).addOrder(orderDish(g_menu));
                        do
                        {
                            std::cout << "Please select option by enter number: " << '\n';
                            std::cout << "1. Change other dish " << '\n';
                            std::cout << "0. Back " << '\n';
                            std::cout << "---------------------------------------------" << '\n';
                            std::cin >> numberSwitch;
                        } while (numberSwitch != 0 && numberSwitch != 1);

                        if (numberSwitch == 1)
                        {
                            checkChangeOrder = true;
                        }

                        else if (numberSwitch == 0)
                        {
                            checkChangeOrder = false;
                        }
    
                    } while (checkChangeOrder);
            
                }

                else if (selectOptionTable == 3)
                {
                    
                    int numberSwitch;
                    bool checkCancelOrder;
                    do
                    {
                        g_table.at(chooseTable).printOrder();
                        g_table.at(chooseTable).deleteOrder();
                        do
                        {
                            std::cout << "Please select option by enter number: " << '\n';
                            std::cout << "1. Cancel other dish " << '\n';
                            std::cout << "0. Back " << '\n';
                            std::cout << "---------------------------------------------" << '\n';
                            std::cin >> numberSwitch;
                        } while (numberSwitch != 0 && numberSwitch != 1);

                        if (numberSwitch == 1)
                        {
                            checkCancelOrder = true;
                        }

                        else if (numberSwitch == 0)
                        {
                            checkCancelOrder = false;
                        }
    
                    } while (checkCancelOrder);
                }


                else if (selectOptionTable == 4)
                {
                    
                    int numberSwitch;
                    bool checkPrintOrder;
                    do
                    {
                        g_table.at(chooseTable).printOrder();
                        do
                        {
                            std::cout << "Please select option by enter number: " << '\n';
                            std::cout << "1. Print order again " << '\n';
                            std::cout << "0. Back " << '\n';
                            std::cout << "---------------------------------------------" << '\n';
                            std::cin >> numberSwitch;
                        } while (numberSwitch != 0 && numberSwitch != 1);

                        if (numberSwitch == 1)
                        {
                            checkPrintOrder = true;
                        }

                        else if (numberSwitch == 0)
                        {
                            checkPrintOrder = false;
                        }
    
                    } while (checkPrintOrder);
                }


                else if (selectOptionTable == 5)
                {
                    int numberSwitch;
                    bool checkPaymentOrder;
                    do
                    {
                        g_table.at(chooseTable).printPayment();
                        do
                        {
                            std::cout << "Please select option by enter number: " << '\n';
                            std::cout << "1. Make payment " << '\n';
                            std::cout << "0. Back " << '\n';
                            std::cout << "---------------------------------------------" << '\n';
                            std::cin >> numberSwitch;
                        } while (numberSwitch != 0 && numberSwitch != 1);

                        if (numberSwitch == 1)
                        {
                            checkPaymentOrder = false;
                            checkStaff = false;
                            g_table.at(chooseTable).makePayment();
                        }

                        else if (numberSwitch == 0)
                        {
                            checkPaymentOrder = false;
                        }
    
                    } while (checkPaymentOrder);
                    
                }


                else if (selectOptionTable == 0)
                {
                    checkStaff = false;
                }
                
            } while (checkStaff);
        }

        else if (program == 3)
        {
            checkStopProgram = false;
        }
        
    } 
    

    return 0;
}


