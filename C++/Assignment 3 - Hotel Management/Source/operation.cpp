#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\operation.hpp"

void employeeLogIn( std::list <Employee> &Employee_Database)
{   
    std::list <Employee> ::iterator it;
    std::string username, password;
    User_Account account;
    bool checkEmployeeAccount = true;

    std::cout << "Enter your username: " << '\n';
    std::cin >> username;

    std::cout << "Enter your password: " << '\n';
    std::cin >> password;

    account.userName = username;
    account.password = password;

    for (it = Employee_Database.begin(); it != Employee_Database.end(); ++it)
    {
        if ((*it).checkLogInUsername(account))
        {
            checkEmployeeAccount = false;
            if ((*it).checkLogInPassword(account))
            {
                (*it).checkLogIn(account);
                employeeUpdateInfo(&(*it));
            }
            else
            {
                std::cout << "Wrong password " << '\n';
            }
        }
    }
    if (checkEmployeeAccount)
    {
        std::cout << "Username unfound " << '\n';
    }
    
}


void employeeUpdateInfo(Employee *employee)
{
    bool checkContinue = true;
    do
    {
        int checkEmployeeUpdateSelection;
        do
        {
            std::cout << "Please select option by enter number: " << '\n'
                      << "1. Update name " << '\n'
                      << "2. Update phone " << '\n'
                      << "3. Update password " << '\n'
                      << "4. Print info " << '\n'
                      << "5. Print work schedule " << '\n'
                      << "0. Log out " << '\n';
            std::cin >> checkEmployeeUpdateSelection;
        } while (checkEmployeeUpdateSelection != 1 && checkEmployeeUpdateSelection != 2 && checkEmployeeUpdateSelection != 3 && checkEmployeeUpdateSelection != 4 && checkEmployeeUpdateSelection != 5 && checkEmployeeUpdateSelection != 0);
    
        if (checkEmployeeUpdateSelection == 1)
        {
            std::cout << "Enter your new name: " << '\n';
            std::string newName;
            std::cin >> newName;
            (*employee).setName(newName);
        }

        else if (checkEmployeeUpdateSelection == 2)
        {
            std::cout << "Enter your new phone: " << '\n';
            std::string newPhone;
            std::cin >> newPhone;
            (*employee).setPhone(newPhone);
        }

        else if (checkEmployeeUpdateSelection == 3)
        {
            std::cout << "Enter your new password: " << '\n';
            std::string newPassword;
            std::cin >> newPassword;
            (*employee).changePassword(newPassword);
        }

        else if (checkEmployeeUpdateSelection == 4)
        {
            std::cout << "Name    " << "\t|\t" << "Phone   " << "\t|\t" << "Position" << '\n';
            (*employee).printInfo();
        }

        else if (checkEmployeeUpdateSelection == 5)
        {
            (*employee).printWorkSchedule();
        }
        
        
        else if (checkEmployeeUpdateSelection == 0)
        {
            checkContinue = false;
            (*employee).checkLogOut();
        }

    } while (checkContinue);
}


void printListEmployee(std::list <Employee> &Employee_Database)
{
    std::list <Employee> ::iterator it;

    it = Employee_Database.begin();
    
    if ((*it).checkAdminLogIn())
    {
        std::cout << "Name    " << "\t|\t" << "Phone   " << "\t|\t" << "Position" << '\n';

        for (it = Employee_Database.begin(); it != Employee_Database.end(); ++it)
        {
            (*it).printInfo();
        }
        (*it).checkLogOut();
    }
    
}


void employeeChangePosition(Employee *employee)
{
    if ((*employee).checkAdminLogIn())
    {
        int newPositionSelection;
        do
        {
            std::cout << "Enter new position: " << '\n'
                      << "1. Hotel Manager " << '\n'
                      << "2. Room Attendant " << '\n'
                      << "3. Hotel Receiptionist " << '\n'
                      << "4. Hotel Housekeeper " << '\n'
                      << "5. Maintainace Technician " << '\n';

            std::cin >> newPositionSelection;
        } while (newPositionSelection != 1 && newPositionSelection != 2 && newPositionSelection != 3 && newPositionSelection != 4 && newPositionSelection != 5);
        
        if (newPositionSelection == 1)
        {
            (*employee).setPosition(Hotel_Manager);
        }
        else if (newPositionSelection == 2)
        {
            (*employee).setPosition(Room_Attendant);
        }
        else if (newPositionSelection == 3)
        {
            (*employee).setPosition(Hotel_Receptionist);
        }
        else if (newPositionSelection == 4)
        {
            (*employee).setPosition(Hotel_HouseKeeper);
        }
        else if (newPositionSelection == 5)
        {
            (*employee).setPosition(Maintainance_Technician);
        }
        (*employee).checkLogOut();
    }
}


void employeeUpdateShift(Employee *employee)
{
    bool checkContinue = true;
    if ((*employee).checkAdminLogIn())
    {
        do
        {
            int checkEmployeeUpdateSelection;
            do
            {
                std::cout << "Please select option by enter number: " << '\n'
                          << "1. Add shift " << '\n'
                          << "2. Delete shift " << '\n'
                          << "3. Print shift " << '\n'
                          << "0. Log out " << '\n';
                std::cin >> checkEmployeeUpdateSelection;
            } while (checkEmployeeUpdateSelection != 1 && checkEmployeeUpdateSelection != 2 && checkEmployeeUpdateSelection != 3  && checkEmployeeUpdateSelection != 0);
    
            if (checkEmployeeUpdateSelection == 1)
            {
                (*employee).addShift();
            }

            else if (checkEmployeeUpdateSelection == 2)
            {
                (*employee).deleteShift();
            }

            else if (checkEmployeeUpdateSelection == 3)
            {
                (*employee).printWorkSchedule();
            }
        
            else if (checkEmployeeUpdateSelection == 0)
            {
                checkContinue = false;
                (*employee).checkLogOut();
            }

        } while (checkContinue);
    }
    
    
}

void adminLogIn(std::list <Employee> &Employee_Database)
{
    bool checkContinue = true;
    do
    {
        int checkEmployeeUpdateSelection;
        do
        {
            std::cout << "Please select option by enter number: " << '\n'
                      << "1. Print list employee " << '\n'
                      << "2. Change position for employee " << '\n'
                      << "3. Update work schedule for employee " << '\n'
                      << "4. Update info for employee " << '\n'
                      << "0. Log out " << '\n';
            std::cin >> checkEmployeeUpdateSelection;
        } while (checkEmployeeUpdateSelection != 1 && checkEmployeeUpdateSelection != 2 && checkEmployeeUpdateSelection != 3 && checkEmployeeUpdateSelection != 4 && checkEmployeeUpdateSelection != 0);
    
        if (checkEmployeeUpdateSelection == 1)
        {
            printListEmployee(Employee_Database);
        }

        else if (checkEmployeeUpdateSelection == 2)
        {
            bool checkChangePosition = false;
            do
            {
                bool checkPhone = true;

                std::cout << "Enter employee phone to select " << '\n';
                std::string phoneChangePosition;
                std::cin >> phoneChangePosition;

                std::list <Employee> ::iterator it;
                for (it = Employee_Database.begin(); it != Employee_Database.end(); ++it)
                {
                    if ((*it).getPhone() == phoneChangePosition)
                    {
                        checkPhone = false;
                        employeeChangePosition(&(*it));
                    }
                }

                if (checkPhone)
                {
                    std::cout << "Phone doesn't exist " << '\n';
                }

                int checkChangeOtherEmployee;

                do
                {
                    std::cout << "Do you want to change for other employee ? " << '\n'
                              << "1. Yes " << '\n'
                              << "0. 0 " << '\n';
                    std::cin >> checkChangeOtherEmployee;        
                } while (checkChangeOtherEmployee != 0 && checkChangeOtherEmployee != 1);
                
                if (checkChangeOtherEmployee == 1)
                {
                    checkChangePosition = true;
                }
                else if (checkChangeOtherEmployee == 0)
                {
                    checkChangePosition = false;
                }
                
            } while (checkChangePosition);
            
        }

        else if (checkEmployeeUpdateSelection == 3)
        {
            bool checkUpdateShift = false;
            do
            {
                bool checkPhone = true;

                std::cout << "Enter employee phone to select " << '\n';
                std::string phoneUpdateShift;
                std::cin >> phoneUpdateShift;

                std::list <Employee> ::iterator it;
                for (it = Employee_Database.begin(); it != Employee_Database.end(); ++it)
                {
                    if ((*it).getPhone() == phoneUpdateShift)
                    {
                        checkPhone = false;
                        employeeUpdateShift(&(*it));
                    }
                }

                if (checkPhone)
                {
                    std::cout << "Phone doesn't exist " << '\n';
                }

                int checkUpdateShiftOtherEmployee;

                do
                {
                    std::cout << "Do you want to update for other employee ? " << '\n'
                              << "1. Yes " << '\n'
                              << "0. 0 " << '\n';
                    std::cin >> checkUpdateShiftOtherEmployee;        
                } while (checkUpdateShiftOtherEmployee != 0 && checkUpdateShiftOtherEmployee != 1);
                
                if (checkUpdateShiftOtherEmployee == 1)
                {
                    checkUpdateShift = true;
                }
                else if (checkUpdateShiftOtherEmployee == 0)
                {
                    checkUpdateShift = false;
                }
                
            } while (checkUpdateShift);
        }
        
        else if (checkEmployeeUpdateSelection == 4)
        {
            bool checkUpdateInfo = false;
            do
            {
                bool checkPhone = true;

                std::cout << "Enter employee phone to select " << '\n';
                std::string phoneUpdateShift;
                std::cin >> phoneUpdateShift;

                std::list <Employee> ::iterator it;
                for (it = Employee_Database.begin(); it != Employee_Database.end(); ++it)
                {
                    if ((*it).getPhone() == phoneUpdateShift)
                    {
                        checkPhone = false;
                        employeeUpdateInfo(&(*it));
                    }
                }

                if (checkPhone)
                {
                    std::cout << "Phone doesn't exist " << '\n';
                }

                int checkUpdateInfoOtherEmployee;

                do
                {
                    std::cout << "Do you want to update for other employee ? " << '\n'
                              << "1. Yes " << '\n'
                              << "0. 0 " << '\n';
                    std::cin >> checkUpdateInfoOtherEmployee;        
                } while (checkUpdateInfoOtherEmployee != 0 && checkUpdateInfoOtherEmployee != 1);
                
                if (checkUpdateInfoOtherEmployee == 1)
                {
                    checkUpdateInfo = true;
                }
                else if (checkUpdateInfoOtherEmployee == 0)
                {
                    checkUpdateInfo = false;
                }
                
            } while (checkUpdateInfo);
        }

        else if (checkEmployeeUpdateSelection == 0)
        {
            checkContinue = false;
        }

    } while (checkContinue);
}

void addCustomer(std::list <Customer> &Customer_Database)
{
    std::string newName, newPhone, newAddress;

    std::cout << "Enter your name: " << '\n';
    std::cin >> newName;

    std::cout << "Enter your phone: " << '\n';
    std::cin >> newPhone;

    std::cout << "Enter your address: " << '\n';
    std::cin >> newAddress;

    Customer newCustomer(newName,newPhone,newAddress);
    Customer_Database.push_back(newCustomer);
}



void updateInfoCustomer(std::list <Customer> &Customer_Database)
{
    std::list <Customer> ::iterator it;

    std::string phone;
    std::cout << "Enter your phone to update information " << '\n';
    std::cin >> phone;

    for ( it = Customer_Database.begin() ; it != Customer_Database.end() ; ++it)
    {
        if ((*it).getPhone() == phone)
        {
            bool checkContinue = true;
            do
            {
                int checkSelectionUpdateInfo;
                do
                {
                    std::cout << "Please select option by enter number to update your info: " << '\n'
                              << "1. Name " << '\n'
                              << "2. Phone" << '\n'
                              << "3. Address " << '\n';
                    std::cin >> checkSelectionUpdateInfo;
                } while (checkSelectionUpdateInfo != 1 && checkSelectionUpdateInfo != 2 && checkSelectionUpdateInfo != 3);

                if (checkSelectionUpdateInfo == 1)
                {
                    std::string updateName;
                    std::cout << "Enter your new name: " << '\n';
                    std::cin >> updateName;
                    (*it).setName(updateName);
                }
                
                else if (checkSelectionUpdateInfo == 2)
                {
                    std::string updatePhone;
                    std::cout << "Enter your new phone: " << '\n';
                    std::cin >> updatePhone;
                    (*it).setPhone(updatePhone);
                }
                
                else if (checkSelectionUpdateInfo == 3)
                {
                    std::string updateAddress;
                    std::cout << "Enter your new address: " << '\n';
                    std::cin >> updateAddress;
                    (*it).setPhone(updateAddress);
                }

                int checkSelectUpdateOther;

                do
                {
                    std::cout << "Do you want to update other information ? " << '\n'
                              << "1. Yes " << '\n'
                              << "0. No " << '\n';
                    
                    std::cin >> checkSelectUpdateOther;
                } while (checkSelectUpdateOther != 0 && checkSelectUpdateOther != 1);
                
                if (checkSelectUpdateOther == 1)
                {
                    checkContinue = true;
                }
                else if (checkSelectUpdateOther == 0)
                {
                    checkContinue = false;
                }
                

            } while (checkContinue);
        
        }
    }
    
}



void deleteCustomer(std::list <Customer> &Customer_Database)
{
    std::list <Customer> ::iterator it, ptr;

    bool checkPhone = false;
    
    std::string phone;
    std::cout << "Please enter your phone to delete " << '\n';
    std::cin >> phone;

    for (it = Customer_Database.begin(); it != Customer_Database.end(); ++it)
    {
        if ((*it).getPhone() == phone)
        {
            checkPhone = true;
            ptr = it;
        }
    }

    if (checkPhone)
    {
        Customer_Database.erase(ptr);
        std::cout << "Delete success " << '\n';
    }
    else
    {
        std::cout << "Phone unfound " << '\n';
    }
    
}


void printListCustomer(std::list <Customer> &Customer_Database)
{
    std::list <Customer> ::iterator it;
    
    std::cout << "Name" << "\t|\t" << "Phone" << "\t\t|\t" << "Address" << '\n';
    for (it = Customer_Database.begin(); it != Customer_Database.end(); ++it)
    {
        (*it).printInfo();
    }
    
}


void printBookingHistory(std::list <Customer> &Customer_Database)
{
    std::list <Customer> ::iterator it;

    std::string phone;
    bool checkPhone = true;
    std::cout << "Enter your phone to print booking history: " << '\n';
    std::cin >> phone;
    for (it = Customer_Database.begin(); it != Customer_Database.end() ; ++it)
    {
        if ((*it).getPhone() == phone)
        {
            checkPhone = false;
            (*it).printBookingHistory();
        }
        
    }
    if (checkPhone)
    {
        std::cout << "Phone unfound " << '\n';
    }
    
}


void printListRoomStatus(std::vector <Floor> &Hotel_Floor)
{
    for (int i = 0; i < (int)Hotel_Floor.size(); ++i)
    {
        std::cout << "Floor " << i + 1 << " :" << '\n';
        Hotel_Floor.at(i).printRoomStatus();
    }
}

void deleteFloor(std::vector <Floor> &Hotel_Floor)
{
    int floorDelete;
    do
    {
        std::cout << "Enter floor you want to delete: " << '\n';
        std::cin >> floorDelete;
    } while (floorDelete > (int)Hotel_Floor.size() );

    Hotel_Floor.erase(Hotel_Floor.begin() + floorDelete - 1);
    std::cout << "Delete success " << '\n';
    
}




void bookingRoom(std::list <Customer> &Customer_Database, std::vector <Floor> &Hotel_Floor)
{
    std::list <Customer> ::iterator it_customer;

    bool checkPhoneBooking = true;
    std::string phoneBookingRoom;
    std::cout << "Enter your phone to book a room: " << '\n';
    std::cin >> phoneBookingRoom;

    for ( it_customer = Customer_Database.begin(); it_customer != Customer_Database.end(); ++it_customer)
    {
        if ((*it_customer).getPhone() == phoneBookingRoom)
        {
            checkPhoneBooking = false;
            printListRoomStatus(Hotel_Floor);
            int floorBook;
            do
            {
                std::cout << "Enter floor have room you want to book: " << '\n';
                std::cin >> floorBook;
            } while (floorBook > (int)Hotel_Floor.size() || floorBook < 1);

            Hotel_Floor.at(floorBook - 1).selectRoom(*(&(*it_customer)));
        }
    }

    if (checkPhoneBooking)
    {
        std::cout << "Wrong phone, please check again." << '\n'
                  << "If you are new, please register. " << '\n';
    }
    
    
    
}