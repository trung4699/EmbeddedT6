#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\operation.hpp"

void employeeLogIn( std::list <Employee> &Employee_Database)
{   
    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
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
                std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                std::cout << "Wrong password " << '\n';
            }
        }
    }
    if (checkEmployeeAccount)
    {
        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
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
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
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
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            std::cout << "Enter your new name: " << '\n';
            std::string newName;
            std::cin >> newName;
            (*employee).setName(newName);
        }

        else if (checkEmployeeUpdateSelection == 2)
        {
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            std::cout << "Enter your new phone: " << '\n';
            std::string newPhone;
            std::cin >> newPhone;
            (*employee).setPhone(newPhone);
        }

        else if (checkEmployeeUpdateSelection == 3)
        {
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            std::cout << "Enter your new password: " << '\n';
            std::string newPassword;
            std::cin >> newPassword;
            (*employee).changePassword(newPassword);
        }

        else if (checkEmployeeUpdateSelection == 4)
        {
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            std::cout << "Name    " << "\t|\t" << "Phone   " << "\t|\t" << "Position" << '\n';
            employeePrintInfo(*employee);
        }

        else if (checkEmployeeUpdateSelection == 5)
        {
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            printWorkSchedule(((*employee).getWorkSchedule()));
        }
        
        
        else if (checkEmployeeUpdateSelection == 0)
        {
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            checkContinue = false;
            (*employee).checkLogOut();
        }

    } while (checkContinue);
}


void printListEmployee(std::list <Employee> &Employee_Database, Security Admin_Account_Original)
{
    std::list <Employee> ::iterator it;

    it = Employee_Database.begin();

    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
    if (Admin_Account_Original.getAuthenticate())
    {
        std::cout << "Name    " << "\t|\t" << "Phone   " << "\t|\t" << "Position" << '\n';

        for (it = Employee_Database.begin(); it != Employee_Database.end(); ++it)
        {
            employeePrintInfo((*it));
        }
    }
    
}


void addEmployee(std::list <Employee> &Employee_Database, Security Admin_Account_Original)
{
    if (Admin_Account_Original.getAuthenticate())
    {
        std::string nameEmployee, phoneEmployee;
        JobPosition positionEmployee;
        User_Account accountEmployee;
        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
        std::cout << "Enter employee name: " << '\n';
        std::cin >> nameEmployee;

        std::cout << "Enter employee phone: " << '\n';
        std::cin >> phoneEmployee;

        int positionSelection;
        do
        {
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            std::cout << "Enter employee position: " << '\n'
                      << "1. Hotel Manager " << '\n'
                      << "2. Room Attendant " << '\n'
                      << "3. Hotel Receiptionist " << '\n'
                      << "4. Hotel Housekeeper " << '\n'
                      << "5. Maintainace Technician " << '\n';

            std::cin >> positionSelection;
        } while (positionSelection != 1 && positionSelection != 2 && positionSelection != 3 && positionSelection != 4 && positionSelection != 5);
        
        if (positionSelection == 1)
        {
            positionEmployee = Hotel_Manager;
        }
        else if (positionSelection == 2)
        {
            positionEmployee = Room_Attendant;
        }
        else if (positionSelection == 3)
        {
            positionEmployee = Hotel_Receptionist;
        }
        else if (positionSelection == 4)
        {
            positionEmployee = Hotel_HouseKeeper;
        }
        else if (positionSelection == 5)
        {
            positionEmployee = Maintainance_Technician;
        }

        
        bool checkUsername = false;
        do
        {
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            std::cout << "Enter employee account username: " << '\n';
            std::cin >> accountEmployee.userName;
            std::list <Employee> ::iterator it;
            for (it = Employee_Database.begin(); it != Employee_Database.end() ; ++it)
            {
                if ((*it).getUsernameAccount() == accountEmployee.userName)
                {
                    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                    std::cout << "This username already exist " << '\n';
                    checkUsername = true;
                }
            }
            
        } while (checkUsername);
        

        std::string checkPassword;
        do
        {
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            std::cout << "Enter employee account password: " << '\n';
            std::cin >> accountEmployee.password;
            std::cout << "Enter password again: " << '\n';
            std::cin >> checkPassword;

        } while (accountEmployee.password != checkPassword);
        
        Employee newEmployee(nameEmployee, phoneEmployee, positionEmployee, accountEmployee);
        Employee_Database.push_back(newEmployee);
        
    }
    
}

void employeeChangePosition(Employee *employee, Security Admin_Account_Original)
{
    
    if (Admin_Account_Original.getAuthenticate())
    {
        int newPositionSelection;
        do
        {
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
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


void employeeUpdateShift(Employee *employee, Security Admin_Account_Original)
{
    bool checkContinue = true;


    if (Admin_Account_Original.getAuthenticate())
    {
        do
        {
            int checkEmployeeUpdateSelection;
            do
            {
                std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                std::cout << "Please select option by enter number: " << '\n'
                          << "1. Add shift " << '\n'
                          << "2. Delete shift " << '\n'
                          << "3. Print shift " << '\n'
                          << "0. Log out " << '\n';
                std::cin >> checkEmployeeUpdateSelection;
            } while (checkEmployeeUpdateSelection != 1 && checkEmployeeUpdateSelection != 2 && checkEmployeeUpdateSelection != 3  && checkEmployeeUpdateSelection != 0);
    
            if (checkEmployeeUpdateSelection == 1)
            {
                employeeAddShift(employee);
            }

            else if (checkEmployeeUpdateSelection == 2)
            {
                int deleteID = deleteShift((*employee).getWorkSchedule());
                if (deleteID != 0)
                {
                    (*employee).deleteShift(deleteID);
                }
                
            }

            else if (checkEmployeeUpdateSelection == 3)
            {
                printWorkSchedule((*employee).getWorkSchedule());
            }
        
            else if (checkEmployeeUpdateSelection == 0)
            {
                checkContinue = false;
                (*employee).checkLogOut();
            }

        } while (checkContinue);
    }
    
    
}

void adminLogIn(std::list <Employee> &Employee_Database, Security &Admin_Account_Original)
{
    User_Account checkAdminAccount;
    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
    std::cout << "Enter admin username: " << '\n';
    std::cin >> checkAdminAccount.userName;
    std::cout << "Enter admin password " << '\n';
    std::cin >> checkAdminAccount.password;
    Admin_Account_Original.checkAdminLogIn(checkAdminAccount);

    if (Admin_Account_Original.getAuthenticate())
    {
        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
        std::cout << "Login success " << '\n';
        bool checkContinue = true;
        do
        {
            int checkEmployeeUpdateSelection;
            do
            {
                std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                std::cout << "Please select option by enter number: " << '\n'
                        << "1. Print list employee " << '\n'
                        << "2. Add employee " << '\n'
                        << "3. Change position for employee " << '\n'
                        << "4. Update work schedule for employee " << '\n'
                        << "5. Update info for employee " << '\n'
                        << "6. Change password " << '\n'
                        << "0. Log out " << '\n';
                std::cin >> checkEmployeeUpdateSelection;
            } while (checkEmployeeUpdateSelection != 1 && checkEmployeeUpdateSelection != 2 && checkEmployeeUpdateSelection != 3 && checkEmployeeUpdateSelection != 4 && checkEmployeeUpdateSelection != 5 && checkEmployeeUpdateSelection != 6 && checkEmployeeUpdateSelection != 0);
        
            if (checkEmployeeUpdateSelection == 1)
            {
                printListEmployee(Employee_Database,Admin_Account_Original);
            }

            if (checkEmployeeUpdateSelection == 2)
            {
                addEmployee(Employee_Database, Admin_Account_Original);
            }

            else if (checkEmployeeUpdateSelection == 3)
            {
                bool checkChangePosition = false;
                do
                {
                    bool checkPhone = true;

                    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                    std::cout << "Enter employee phone to select " << '\n';
                    std::string phoneChangePosition;
                    std::cin >> phoneChangePosition;

                    std::list <Employee> ::iterator it;
                    for (it = Employee_Database.begin(); it != Employee_Database.end(); ++it)
                    {
                        if ((*it).getPhone() == phoneChangePosition)
                        {
                            checkPhone = false;
                            employeeChangePosition(&(*it), Admin_Account_Original);
                        }
                    }

                    if (checkPhone)
                    {
                        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                        std::cout << "Phone doesn't exist " << '\n';
                    }

                    int checkChangeOtherEmployee;

                    do
                    {
                        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
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

            else if (checkEmployeeUpdateSelection == 4)
            {
                bool checkUpdateShift = false;
                do
                {
                    bool checkPhone = true;

                    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                    std::cout << "Enter employee phone to select " << '\n';
                    std::string phoneUpdateShift;
                    std::cin >> phoneUpdateShift;

                    std::list <Employee> ::iterator it;
                    for (it = Employee_Database.begin(); it != Employee_Database.end(); ++it)
                    {
                        if ((*it).getPhone() == phoneUpdateShift)
                        {
                            checkPhone = false;
                            employeeUpdateShift(&(*it), Admin_Account_Original);
                        }
                    }

                    if (checkPhone)
                    {
                        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                        std::cout << "Phone doesn't exist " << '\n';
                    }

                    int checkUpdateShiftOtherEmployee;

                    do
                    {
                        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
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
            
            else if (checkEmployeeUpdateSelection == 5)
            {
                bool checkUpdateInfo = false;
                do
                {
                    bool checkPhone = true;

                    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
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
                        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                        std::cout << "Phone doesn't exist " << '\n';
                    }

                    int checkUpdateInfoOtherEmployee;

                    do
                    {
                        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
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

            else if (checkEmployeeUpdateSelection == 6)
            {
                std::string newPassword, checkPassword;

                do
                {
                    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                    std::cout << "Enter new password: " << '\n';
                    std::cin >> newPassword;
                    std::cout << "Enter password again: " << '\n';
                    std::cin >> checkPassword;
                } while (newPassword != checkPassword);

                std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                Admin_Account_Original.setPassword(newPassword);
                std::cout << "Change password success " << '\n';
                
            }

            else if (checkEmployeeUpdateSelection == 0)
            {
                Admin_Account_Original.adminLogOut();
                checkContinue = false;
            }

        } while (checkContinue);
    }
    else
    {
        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
        std::cout << "Wrong username or password " << '\n';
    }
    

}



void printShift(WorkSchedule schedule)
{
    if (schedule.getShiftWork() == Morning_Shift)
    {
        std::cout << schedule.getID() << "\t|\t" << "Morning  " << "\t|\t" << schedule.getDateWork().day << "/" << schedule.getDateWork().month << "/" << schedule.getDateWork().year << '\n';
    }
    else if (schedule.getShiftWork() == Afternoon_Shift)
    {
        std::cout << schedule.getID() << "\t|\t" << "Afternoon" << "\t|\t" << schedule.getDateWork().day << "/" << schedule.getDateWork().month << "/" << schedule.getDateWork().year << '\n';
    }
    else if (schedule.getShiftWork() == Night_Shift)
    {
        std::cout << schedule.getID() << "\t|\t" << "Night    " << "\t|\t" << schedule.getDateWork().day << "/" << schedule.getDateWork().month << "/" << schedule.getDateWork().year << '\n';
    }
}



void printWorkSchedule(const std::list <WorkSchedule> Schedule_Database)
{
    std::list <WorkSchedule> ::iterator it;
    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
    std::cout << "ID" << "\t|\t" << "Shift   " << "\t|\t" << "Date" << '\n';

    for (auto it : Schedule_Database)
    {
        printShift(it);
    }
}



int deleteShift(const std::list <WorkSchedule> Schedule_Database)
{
    std::list <WorkSchedule> ::iterator it, ptr;
    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
    std::cout << "Enter ID of shift you want to delete: " << '\n';
    int deleteID;
    std::cin >> deleteID;
    bool checkID = true;

    for (auto it : Schedule_Database)
    {
        if (it.getID()== deleteID)
        {
            checkID = false;
        }
    }

    if (checkID)
    {
        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
        std::cout << "ID unfound " << '\n';
        deleteID = 0;
    }
    else
    {
        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
        std::cout << "Delete success " << '\n';
    }

    return deleteID;
}



void employeeAddShift(Employee *employee)
{
    Date newDateWork;
    ShiftWork newShiftWork;
    int numWorkShift;

    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
    std::cout << "Enter work day: " << '\n';
    std::cin >> newDateWork.day;

    std::cout << "Enter work month: " << '\n';
    std::cin >> newDateWork.month;

    std::cout << "Enter work year: " << '\n';
    std::cin >> newDateWork.year;

    do
    {
        std::cout << "Enter work shift: " << '\n'
                  << "1. Morning shift " << '\n'
                  << "2. Afternoon shift " << '\n'
                  << "3. Night shift " << '\n';
        std::cin >> numWorkShift;
    } while (numWorkShift != 1 && numWorkShift != 2 && numWorkShift != 3);

    if (numWorkShift == 1)
    {
        newShiftWork = Morning_Shift;
    }
    else if (numWorkShift == 2)
    {
        newShiftWork = Afternoon_Shift;
    }
    else if (numWorkShift == 3)
    {
        newShiftWork = Night_Shift;
    }
    
    WorkSchedule newWorkSchedule(newDateWork,newShiftWork);
    (*employee).addShift(newWorkSchedule);
    
    
}


void employeePrintInfo( Employee employee)
{
    std::cout << employee.getName() << "\t|\t" << employee.getPhone() << "\t|\t";

    if (employee.getPosition() == Hotel_Manager)
    {
        std::cout << "Hotel Manager " << '\n';
    }
    else if (employee.getPosition() == Hotel_HouseKeeper)
    {
        std::cout << "Housekeeper " << '\n';
    }
    else if (employee.getPosition() == Hotel_Receptionist)
    {
        std::cout << "Receptionist " << '\n';
    }
    else if (employee.getPosition() == Maintainance_Technician)
    {
        std::cout << "Maintaninace Technician " << '\n';
    }
    else if (employee.getPosition() == Room_Attendant)
    {
        std::cout << "Room Attendant " << '\n';
    }
    
}


/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/

void addCustomer(std::list <Customer> &Customer_Database)
{
    std::string newName, newPhone, newAddress;

    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
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
    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
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
                    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                    std::cout << "Please select option by enter number to update your info: " << '\n'
                              << "1. Name " << '\n'
                              << "2. Phone" << '\n'
                              << "3. Address " << '\n';
                    std::cin >> checkSelectionUpdateInfo;
                } while (checkSelectionUpdateInfo != 1 && checkSelectionUpdateInfo != 2 && checkSelectionUpdateInfo != 3);

                if (checkSelectionUpdateInfo == 1)
                {
                    std::string updateName;
                    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                    std::cout << "Enter your new name: " << '\n';
                    std::cin >> updateName;
                    (*it).setName(updateName);
                }
                
                else if (checkSelectionUpdateInfo == 2)
                {
                    std::string updatePhone;
                    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                    std::cout << "Enter your new phone: " << '\n';
                    std::cin >> updatePhone;
                    (*it).setPhone(updatePhone);
                }
                
                else if (checkSelectionUpdateInfo == 3)
                {
                    std::string updateAddress;
                    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                    std::cout << "Enter your new address: " << '\n';
                    std::cin >> updateAddress;
                    (*it).setPhone(updateAddress);
                }

                int checkSelectUpdateOther;

                do
                {
                    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
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
    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
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
        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
        std::cout << "Delete success " << '\n';
    }
    else
    {
        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
        std::cout << "Phone unfound " << '\n';
    }
    
}

void printCustomerInfo(Customer customer)
{
    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
    std::cout << "Name" << "\t|\t" << "Phone" << "\t|\t" << "Address" << '\n';
    std::cout << customer.getName() << "\t|\t" << customer.getPhone() << "\t|\t" << customer.getAddress() << '\n';
    
}

void printListCustomer(const std::list <Customer> Customer_Database)
{
    
    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
    std::cout << "Name" << "\t|\t" << "Phone     " << "\t\t|\t" << "Address" << '\n';
    for (auto it : Customer_Database)
    {
        std::cout << it.getName() << "\t|\t" <<it.getPhone() << "\t\t|\t" << it.getAddress() << '\n';
    }
    
}



/*
* Function: printCustomerBookingHistory
* Description: This function will print customer booking history
* Input:
* Output:
*/
void printCustomerBookingHistory(const std::list <BookingHistory> bookingHistoryData, const std::string nameCustomer)
{
    
    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
    std::cout << "Customer " << nameCustomer << " booking history: " << '\n';
    std::cout << "Time" << "\t\t|\t" <<  "Date" <<  "\t\t|\t" << "Check"  << '\n';
    for (auto it : bookingHistoryData)
    {
        if (it.check == IN)
        {
            if (it.time.hours < 10 || it.time.minutes < 10 || it.time.seconds < 10)
            {
                std::cout << it.time.hours << ":" << it.time.minutes << ":" << it.time.seconds << "\t\t|\t"
                          << it.date.day << "/" << it.date.month << "/" << it.date.year << "\t|\t"
                          << "IN"  <<'\n';
            }
            else
            {
                std::cout << it.time.hours << ":" << it.time.minutes << ":" << it.time.seconds << "\t|\t"
                          << it.date.day << "/" << it.date.month << "/" << it.date.year << "\t|\t"
                          << "IN"  <<'\n';
            }
        }

        else
        {
            if (it.time.hours < 10 || it.time.minutes < 10 || it.time.seconds < 10)
            {
                std::cout << it.time.hours << ":" << it.time.minutes << ":" << it.time.seconds << "\t\t|\t"
                          << it.date.day << "/" << it.date.month << "/" << it.date.year << "\t|\t"
                          << "OUT"  <<'\n';
            }
            else
            {
                std::cout << it.time.hours << ":" << it.time.minutes << ":" << it.time.seconds << "\t|\t"
                          << it.date.day << "/" << it.date.month << "/" << it.date.year << "\t|\t"
                          << "OUT"  <<'\n';
            }
        }
    }
}

void checkPhoneToPrintBookingHistory(const std::list <Customer> Customer_Database)
{

    std::string phone;
    bool checkPhone = true;
    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
    std::cout << "Enter your phone to print booking history: " << '\n';
    std::cin >> phone;
    for (auto it : Customer_Database)
    {
        if (it.getPhone() == phone)
        {
            checkPhone = false;
            printCustomerBookingHistory(it.getBookingHistory(), it.getName());
        }
    }
    if (checkPhone)
    {
        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
        std::cout << "Phone unfound " << '\n';
    }
}



void printCustomerCheckInOrOut(Customer customer)
{
    if (customer.getCheckInOut() == IN)
    {
        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
        std::cout << "Check in success " << '\n';
    }
    else if (customer.getCheckInOut() == OUT)
    {
        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
        std::cout << "Check out success " << '\n';
    }
    
    
}





/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/




void printListRoomStatus(std::vector <Floor> &Hotel_Floor)
{
    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
    for (int i = 0; i < (int)Hotel_Floor.size(); ++i)
    {
        std::cout << "Floor " << i + 1 << " :" << '\n';
        printRoomStatus(Hotel_Floor.at(i));
    }
    std::cout << "A: Available " << '\n'
              << "U: Unavailable " << '\n'
              << "C: Cleaning " << '\n';
}

void deleteFloor(std::vector <Floor> &Hotel_Floor)
{
    int floorDelete;
    do
    {
        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
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
    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
    std::cout << "Enter your phone to book a room: " << '\n';
    std::cin >> phoneBookingRoom;

    for ( it_customer = Customer_Database.begin(); it_customer != Customer_Database.end(); ++it_customer)
    {
        if ((*it_customer).getPhone() == phoneBookingRoom)
        {
            checkPhoneBooking = false;
            printListRoomStatus(Hotel_Floor);
            int floorBook, roomBook;
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            do
            {
                std::cout << "Enter floor have room you want to book: " << '\n';
                std::cin >> floorBook;
            } while (floorBook > (int)Hotel_Floor.size() || floorBook < 1);

            do
            {
                std::cout << "Enter room you want to book: " << '\n';
                std::cin >> roomBook;
            } while (roomBook > Hotel_Floor.at(floorBook - 1).getNumberOfRoom() || roomBook < 1);


            if (Hotel_Floor.at(floorBook - 1).getRoomData().at(roomBook - 1).getStatus() == Available)
            {
                Hotel_Floor.at(floorBook - 1).selectRoom(*(&(*it_customer)),roomBook - 1);
                std::cout << "Booking success " << '\n';
            }
            else if (Hotel_Floor.at(floorBook - 1).getRoomData().at(roomBook - 1).getStatus() == Cleaning)
            {
                std::cout << "This room is cleaning, please wait" << '\n';
            }
            else if (Hotel_Floor.at(floorBook - 1).getRoomData().at(roomBook - 1).getStatus() == Unavailable)
            {
                std::cout << "Cannot book this room " << '\n';
            }
        }
        
    }

    if (checkPhoneBooking)
    {
        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
        std::cout << "Wrong phone, please check again." << '\n'
                  << "If you are new, please register. " << '\n';
    }
    
    
}


void printRoomStatus(Floor floor)
{
    int countRoom = 1;
    
    std::cout << "Room: " << "\t\t";
    for (int i = 0; i < floor.getNumberOfRoom(); ++i)
    {
        std::cout << countRoom << '\t';
        ++countRoom;
    }
    
    std::cout << '\n';

    std::cout << "Status: " << '\t';
    for (int i = 0; i < floor.getNumberOfRoom(); ++i)
    {
        if (floor.getRoomData().at(i).getStatus() == Available)
        {
            std::cout << "A" << '\t';
        }
        else if (floor.getRoomData().at(i).getStatus() == Unavailable)
        {
            std::cout << "U" << '\t';
        }
        else if (floor.getRoomData().at(i).getStatus() == Cleaning)
        {
            std::cout << "C" << '\t';
        }
    }

    std::cout << '\n';
}



/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/




void roomCheckIn(std::vector <Floor> &Hotel_Floor, std::list <Customer> &Customer_Database)
{
    bool checkPhone = true;
    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
    std::cout << "Please enter your phone: " << '\n';
    std::string phoneRoomCheckIn;
    std::cin >> phoneRoomCheckIn;

    for (int i = 0; i < (int)Hotel_Floor.size(); ++i)
    {
        for (int j = 0; j < Hotel_Floor.at(i).getNumberOfRoom(); ++j)
        {
            if (Hotel_Floor.at(i).getRoomData().at(j).getCustomerRoom().getPhone() == phoneRoomCheckIn)
            {
                std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                std::cout << "Welcome " << Hotel_Floor.at(i).getRoomData().at(j).getCustomerRoom().getName() << '\n'   
                          << "Check in success " << '\n';
                checkPhone = false;
            }
        }
    }
    
    if (checkPhone)
    {
        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
        std::cout << "Wrong phone " << '\n';
    }
    else
    {
        std::list <Customer> ::iterator ptr;
        for (ptr = Customer_Database.begin(); ptr != Customer_Database.end(); ++ptr)
        {
            if ((*ptr).getPhone() == phoneRoomCheckIn)
            {
                (*ptr).addCheckInAndOutHistory();
            }
            
        }
    }
}


void roomCheckOut(std::vector <Floor> &Hotel_Floor, std::list <Customer> &Customer_Database)
{
    bool checkPhone = true;
    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
    std::cout << "Please enter your phone: " << '\n';
    std::string phoneRoomCheckOut;
    std::cin >> phoneRoomCheckOut;

    for (int i = 0; i < (int)Hotel_Floor.size(); ++i)
    {
        for (int j = 0; j < Hotel_Floor.at(i).getNumberOfRoom(); ++j)
        {
            if (Hotel_Floor.at(i).getRoomData().at(j).getCustomerRoom().getPhone() == phoneRoomCheckOut)
            {
                std::cout << "------------------------------------------------------------------------------------------ " << '\n';
                std::cout << "Hi " << Hotel_Floor.at(i).getRoomData().at(j).getCustomerRoom().getName() << '\n'   
                          << "Check out success " << '\n';
                Hotel_Floor.at(i).checkOutRoom(j);

                std::list <Customer> ::iterator ptr;
                for (ptr = Customer_Database.begin(); ptr != Customer_Database.end(); ++ptr)
                {
                    if ((*ptr).getPhone() == phoneRoomCheckOut)
                    {
                        (*ptr).addCheckInAndOutHistory();
                    }
                }
                checkPhone = false;
            }
        }
    }
    
    if (checkPhone)
    {
        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
        std::cout << "Wrong phone " << '\n';
    }
    
}


void roomSetFree(std::vector <Floor> &Hotel_Floor)
{
    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
    int floorNumber, roomNumber;
    do
    {
        std::cout << "Select floor to set free room: " << '\n';
                std::cin >> floorNumber;
    } while (floorNumber > (int) Hotel_Floor.size());

    do
    {
        std::cout << "Enter room number to set free: " << '\n';
        std::cin >> roomNumber;
    } while (roomNumber < 1 || roomNumber > Hotel_Floor.at(floorNumber - 1).getNumberOfRoom());

    
    if (Hotel_Floor.at(floorNumber-1).getRoomData().at(roomNumber - 1).getStatus() == Cleaning)
    {
        Hotel_Floor.at(floorNumber-1).setFreeRoom(roomNumber - 1);
        std::cout << "Set free room success " << '\n' ;
    }
    else if (Hotel_Floor.at(floorNumber-1).getRoomData().at(roomNumber - 1).getStatus() == Available)
    {
        std::cout << "This room is Available " << '\n';
    }
    else if (Hotel_Floor.at(floorNumber-1).getRoomData().at(roomNumber -1 ).getStatus() == Unavailable)
    {
        std::cout << "This room is not check out yet " << '\n'; 
    }
    
    
}



/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------*/





void prepaid(std::list <Bill> &Revenue_Database)
{
    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
    int dayCheckIn, dayCheckOut;
    std::cout << "Enter day check in: " << '\n';
    std::cin >> dayCheckIn;
    std::cout << "Enter day check out: " << '\n';
    std::cin >> dayCheckOut;

    Bill bill;
    bill.setDayCheckIn(dayCheckIn);
    bill.setDayCheckOut(dayCheckOut);

    printBill(bill);
    int checkPrepaidSelection;
    do
    {
        std::cout << "------------------------------------------------------------------------------------------ " << '\n';
        std::cout << "Please select option by enter number: " << '\n'
                  << "1. Make payment " << '\n'
                  << "0. Back " << '\n';
        std::cin >> checkPrepaidSelection;
    } while (checkPrepaidSelection != 0 && checkPrepaidSelection != 1);

    if (checkPrepaidSelection == 1)
    {
        Revenue_Database.push_back(bill);
    }
    else if (checkPrepaidSelection == 0)
    {
        
    }
    
    
    
}

void printBill(Bill bill)
{
    std::cout << "------------------------------------------------------------------------------------------ " << '\n';
    std::cout << "Day check in: " << bill.getDayCheckIn() << '\n';
    std::cout << "Day check out: " << bill.getDayCheckOut() << '\n';
    std::cout << "Price per day: " << bill.getPrice() << '\n';
    std::cout << "Payment total: " << bill.getPayment() <<'\n';
}

void postpaid(std::list <Customer> &Customer_Database, std::list <Bill> &Revenue_Database)
{
    int dayCheckIn, dayCheckOut;
    std::string phonePostpaid;
    bool checkPhonePaid = true;

    std::cout << "Enter your phone to payment: " << '\n';
    std::cin >> phonePostpaid;

    std::list <Customer> ::iterator it, customer;
    std::list <BookingHistory> ::iterator ptr;

    for (it = Customer_Database.begin(); it != Customer_Database.end(); ++it)
    {
        if ((*it).getPhone() == phonePostpaid)
        {
            customer = it; 
            for (ptr = (*it).getBookingHistory().begin(); ptr != (*it).getBookingHistory().end(); ++ptr)
            {
                if ((*ptr).payment_status == No)
                {
                    if ((*ptr).check == IN)
                    {
                        dayCheckIn = (*ptr).date.day;
                    }
                    else if ((*ptr).check == OUT)
                    {
                        dayCheckOut = (*ptr).date.day;
                    }
                }
            }
        }
    }

    if (checkPhonePaid)
    {
        std::cout << "Wrong phone " << '\n';
    }
    else
    {
        Bill bill;
        bill.setDayCheckIn(dayCheckIn);
        bill.setDayCheckOut(dayCheckOut);
        
        printBill(bill);
        
        

        int checkPostpaidSelection;
        do
        {
            std::cout << "------------------------------------------------------------------------------------------ " << '\n';
            std::cout << "Please select option by enter number: " << '\n'
                    << "1. Make payment " << '\n'
                    << "0. Back " << '\n';
            std::cin >> checkPostpaidSelection;
        } while (checkPostpaidSelection != 0 && checkPostpaidSelection != 1);

        if (checkPostpaidSelection == 1)
        {
            Revenue_Database.push_back(bill);
            (*customer).setPaymentStatus(dayCheckIn);
            (*customer).setPaymentStatus(dayCheckOut);
            std::cout << "Payment success " << '\n';
        }
        else if (checkPostpaidSelection == 0)
        {
            return;
        }
    }
    

    
}