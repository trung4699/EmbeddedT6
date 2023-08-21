/*
* File: main.cpp
* Author: Phan Hoang Trung
* Date: 12/08/2023
* Description: This is a main file for restaurant management
* 
*/

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\customer.hpp"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\employee.hpp"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\operation.hpp"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\room.hpp"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\floor.hpp"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\security.hpp"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\bill.hpp"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\feedback.hpp"


void customerManagement(std::list <Customer> &Customer_Database, Security &Admin_Account_Original)
{
    bool checkContinue = true;
    do
    {
        int checkCustomerSelection;
        do
        {
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            std::cout << "Please select option by enter number: " << '\n'
                      << "1. Add customer " << '\n'
                      << "2. Update information " << '\n'
                      << "3. Delete customer " << '\n'
                      << "4. List " << '\n' 
                      << "5. Booking history " << '\n'
                      << "0. Back " << '\n';
            std::cin >> checkCustomerSelection;
        } while (checkCustomerSelection != 1 && checkCustomerSelection != 2 && checkCustomerSelection != 3 && checkCustomerSelection != 4 && checkCustomerSelection != 5 && checkCustomerSelection != 0);
    
        if (checkCustomerSelection == 1)
        {
            addCustomer(Customer_Database);
        }

        else if (checkCustomerSelection == 2)
        {
            updateInfoCustomer(Customer_Database);
        }
        
        else if (checkCustomerSelection == 3)
        {
            deleteCustomer(Customer_Database);
        }

        else if (checkCustomerSelection == 4)
        {
            printListCustomer(Customer_Database);
        }

        else if (checkCustomerSelection == 5)
        {
            
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            User_Account checkAdminAccount;
            std::cout << "Enter admin username: " << '\n';
            std::cin >> checkAdminAccount.userName;
            std::cout << "Enter admin password: " << '\n';
            std::cin >> checkAdminAccount.password;

            Admin_Account_Original.checkAdminLogIn(checkAdminAccount);

            if (Admin_Account_Original.getAuthenticate())
            {
                checkPhoneToPrintBookingHistory(Customer_Database);
                Admin_Account_Original.adminLogOut();
            }
            else    
            {
                std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                std::cout << "Wrong username or password " << '\n';
            }
        }


        else if (checkCustomerSelection == 0)
        {
            checkContinue = false;
        }

    } while (checkContinue);
}


void floorManagement(std::vector <Floor> &Hotel_Floor, Security &Admin_Account_Original)
{
    bool checkContinue = true;
    do
    {
        int checkFloorSelection;
        do
        {
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            std::cout << "Please select option by enter number: " << '\n'
                      << "1. Set number of floor to serve " << '\n'
                      << "2. Set number of room to serve in one floor " << '\n'
                      << "3. Delete floor " << '\n'
                      << "4. Print room status " << '\n' 
                      << "0. Back " << '\n';
            std::cin >> checkFloorSelection;
        } while (checkFloorSelection != 1 && checkFloorSelection != 2 && checkFloorSelection != 3 && checkFloorSelection != 4  && checkFloorSelection != 0);
    
        if (checkFloorSelection == 1)
        {
            User_Account checkAdminAccount;
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            std::cout << "Enter admin username: " << '\n';
            std::cin >> checkAdminAccount.userName;
            std::cout << "Enter admin password: " << '\n';
            std::cin >> checkAdminAccount.password;

            Admin_Account_Original.checkAdminLogIn(checkAdminAccount);

            if (Admin_Account_Original.getAuthenticate())
            {
                int numberFloor;
                std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                std::cout << "Enter number of floor to serve: " << '\n';
                std::cin >> numberFloor;
                Hotel_Floor.resize(numberFloor);
                Admin_Account_Original.adminLogOut();
            }
            else    
            {
                std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                std::cout << "Wrong username or password " << '\n';
            }
        }

        else if (checkFloorSelection == 2)
        {
            User_Account checkAdminAccount;
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            std::cout << "Enter admin username: " << '\n';
            std::cin >> checkAdminAccount.userName;
            std::cout << "Enter admin password: " << '\n';
            std::cin >> checkAdminAccount.password;

            Admin_Account_Original.checkAdminLogIn(checkAdminAccount);

            if (Admin_Account_Original.getAuthenticate())
            {
                int floorNumber, roomNumber;
                std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                do
                {
                    std::cout << "Select floor to set up room to serve: " << '\n';
                    std::cin >> floorNumber;
                } while (floorNumber > (int) Hotel_Floor.size());

                do
                {
                    std::cout << "Enter number of room serve in this floor: " << '\n';
                    std::cin >> roomNumber;
                } while (roomNumber < 1);
            
                Hotel_Floor.at(floorNumber-1).setRoom(roomNumber);
                Admin_Account_Original.adminLogOut();
            }
            else    
            {
                std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                std::cout << "Wrong username or password " << '\n';
            }
        }

        else if (checkFloorSelection == 3)
        {
        
            User_Account checkAdminAccount;
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            std::cout << "Enter admin username: " << '\n';
            std::cin >> checkAdminAccount.userName;
            std::cout << "Enter admin password: " << '\n';
            std::cin >> checkAdminAccount.password;

            Admin_Account_Original.checkAdminLogIn(checkAdminAccount);

            if (Admin_Account_Original.getAuthenticate())
            {
                deleteFloor(Hotel_Floor);
                Admin_Account_Original.adminLogOut();
            }
            else    
            {
                std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                std::cout << "Wrong username or password " << '\n';
            }
        }
        
        else if (checkFloorSelection == 4)
        {
            printListRoomStatus(Hotel_Floor);
        }

        else if (checkFloorSelection == 0)
        {
            checkContinue = false;
        }

    } while (checkContinue);
}


void roomBooking( std::vector <Floor> &Hotel_Floor, std::list <Customer> &Customer_Database)
{
    bool checkContinue = true;
    do
    {
        int checkBookRoomSelection;
        do
        {
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            std::cout << "Please select option by enter number: " << '\n'
                      << "1. You are new customer " << '\n'
                      << "2. You already booking once  " << '\n'
                      << "0. Back " << '\n';
            std::cin >> checkBookRoomSelection;
        } while (checkBookRoomSelection != 1 && checkBookRoomSelection != 2  && checkBookRoomSelection != 0);
    
        if (checkBookRoomSelection == 1)
        {
            addCustomer(Customer_Database);  
            bookingRoom(Customer_Database, Hotel_Floor);
        }

        else if (checkBookRoomSelection == 2)
        { 
            bookingRoom(Customer_Database, Hotel_Floor);
        }

        else if (checkBookRoomSelection == 0)
        {
            checkContinue = false;
        }

    } while (checkContinue);    
}


void employeeManagement(std::list <Employee> &Employee_Database, Security &Admin_Account_Original, std::list <Bill> &Revenue_Database,std::vector <Floor> &Hotel_Floor, std::list <FeedbackAndRating> Feedback_Database)
{
    bool checkContinue = true;
    do
    {
        int checkEmployeeSelection;
        do
        {
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            std::cout << "Please select option by enter number: " << '\n'
                      << "1. Employee log in " << '\n'
                      << "2. Admin log in " << '\n'
                      << "0. Back " << '\n';
            std::cin >> checkEmployeeSelection;
        } while (checkEmployeeSelection != 1 && checkEmployeeSelection != 2  && checkEmployeeSelection != 0);
    
        if (checkEmployeeSelection == 1)
        {
            employeeLogIn(Employee_Database);
        }

        else if (checkEmployeeSelection == 2)
        {
            adminLogIn(Employee_Database,Admin_Account_Original,Revenue_Database,Hotel_Floor, Feedback_Database);
        }
        

        else if (checkEmployeeSelection == 0)
        {
            checkContinue = false;
        }

    } while (checkContinue);
}

void roomManagement(std::vector <Floor> &Hotel_Floor, std::list <Customer> &Customer_Database)
{
    bool checkContinue = true;
    do
    {
        int checkRoomManagementSelection;
        do
        {
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            std::cout << "Please select option by enter number: " << '\n'
                      << "1. Check in " << '\n'
                      << "2. Check out " << '\n'
                      << "3. Set room free " << '\n'
                      << "0. Back " << '\n';
            std::cin >> checkRoomManagementSelection;
        } while (checkRoomManagementSelection != 1 && checkRoomManagementSelection != 2  && checkRoomManagementSelection != 3  && checkRoomManagementSelection != 0);
    
        if (checkRoomManagementSelection == 1)
        {
            roomCheckIn(Hotel_Floor, Customer_Database);
        }

        else if (checkRoomManagementSelection == 2)
        {
            roomCheckOut(Hotel_Floor, Customer_Database);
        }

        else if (checkRoomManagementSelection == 3)
        {
            roomSetFree(Hotel_Floor);
        }
        

        else if (checkRoomManagementSelection == 0)
        {
            checkContinue = false;
        }

    } while (checkContinue);
}



void paymentManagement(std::list <Customer> &Customer_Database, std::list <Bill> &Revenue_Database, std::vector <Floor> &Hotel_Floor)
{
    bool checkContinue = true;
    do
    {
        int checkPaymentSelection;
        do
        {
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            std::cout << "Please select option by enter number: " << '\n'
                      << "1. Prepaid " << '\n'
                      << "2. Postpaid " << '\n'
                      << "0. Back " << '\n';
            std::cin >> checkPaymentSelection;
        } while (checkPaymentSelection != 1 && checkPaymentSelection != 2 &&  checkPaymentSelection != 0);
    
        if (checkPaymentSelection == 1)
        {
            prepaid(Revenue_Database, Hotel_Floor);
        }

        else if (checkPaymentSelection == 2)
        {
           postpaid(Customer_Database,Revenue_Database);
        }

        else if (checkPaymentSelection == 0)
        {
            checkContinue = false;
        }

    } while (checkContinue);
}



int main()
{
    std::list <Employee> Employee_Database;
    std::list <Customer> Customer_Database;
    std::list <Bill> Revenue_Database;
    std::list <FeedbackAndRating> Feedback_Database;

    Security admin;

    int numberOfFloor = 1;
    std::vector <Floor> Hotel_Floor;
    Hotel_Floor.resize(numberOfFloor);
    

    Customer customer1("Trung", "123456789", "Q11");
    Customer customer2("An", "987654321", "Q12");
    Customer customer3("Phong", "456798123", "Q10");


    Customer_Database.push_back(customer1);
    Customer_Database.push_back(customer2);
    Customer_Database.push_back(customer3);



    bool checkContinue = true;
    while (checkContinue)
    {
        int checkProgramSelection;
        do
        {
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            std::cout << "Please enter number to access program: " << '\n'
                      << "1. Room booking " << '\n'
                      << "2. Customer Management " << '\n'
                      << "3. Employee Management " << '\n'
                      << "4. Floor Management " << '\n'
                      << "5. Room Management " << '\n'
                      << "6. Payment " << '\n'
                      << "7. Write feedback " << '\n'
                      << "0. Stop " << '\n';
            std::cin >> checkProgramSelection;
        } while (checkProgramSelection != 1 && checkProgramSelection != 2 && checkProgramSelection != 3 && checkProgramSelection != 4 && checkProgramSelection != 5 && checkProgramSelection != 6 && checkProgramSelection != 7 && checkProgramSelection != 0);
        
        if (checkProgramSelection == 1)
        {
            roomBooking(Hotel_Floor,Customer_Database);
        }

        else if (checkProgramSelection == 2)
        {
            customerManagement(Customer_Database, admin);
        }

        else if (checkProgramSelection == 3)
        {
            employeeManagement(Employee_Database, admin, Revenue_Database, Hotel_Floor, Feedback_Database);
        }

        else if (checkProgramSelection == 4)
        {
            floorManagement(Hotel_Floor,admin);
        }

        
        else if (checkProgramSelection == 5)
        {
            roomManagement(Hotel_Floor, Customer_Database);
        }

        else if (checkProgramSelection == 6)
        {
            paymentManagement(Customer_Database,Revenue_Database, Hotel_Floor);
        }

        else if (checkProgramSelection == 7)
        {
            writeFeedback(Feedback_Database);
        }

        else if (checkProgramSelection == 0)
        {
            checkContinue = false;
        }
        
    
        
    }
    

    return 0;
}