#ifndef OPERATION_H
#define OPERATION_H

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\employee.hpp"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\customer.hpp"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\room.hpp"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\floor.hpp"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\security.hpp"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 3 - Hotel Management\Header\bill.hpp"

void employeeLogIn(std::list <Employee> &Employee_Database);
void addEmployee(std::list <Employee> &Employee_Database, Security Admin_Account_Original);
void employeePrintInfo(Employee employee);
void employeeUpdateInfo(Employee *employee);

void adminLogIn(std::list <Employee> &Employee_Database, Security &Admin_Account_Original);
void printListEmployee(std::list <Employee> &Employee_Database, Security Admin_Account_Original);
void employeeChangePosition(std::list <Employee> &Employee_Database);
void employeeUpdateShift(Employee *employee, Security Admin_Account_Original);
void printShift(WorkSchedule schedule);
void printWorkSchedule(const std::list <WorkSchedule> Schedule_Database);

void employeeAddShift(Employee *employee);
int deleteShift(const std::list <WorkSchedule> Schedule_Database);

void addCustomer(std::list <Customer> &Customer_Database);
void updateInfoCustomer(std::list <Customer> &Customer_Database);
void deleteCustomer(std::list <Customer> &Customer_Database);
void printListCustomer(const std::list <Customer> Customer_Database);
void checkPhoneToPrintBookingHistory(const std::list <Customer> Customer_Database);
void printCustomerBookingHistory(const std::list <BookingHistory> bookingHistoryData, const std::string nameCustomer);
void printCustomerCheckInOrOut(Customer customer);

void printListRoomStatus(std::vector <Floor> &Hotel_Floor);
void deleteFloor(std::vector <Floor> &Hotel_Floor);
void deleteRoom(std::vector <Floor> &Hotel_Floor);

void bookingRoom(std::list <Customer> &Customer_Database, std::vector <Floor> &Hotel_Floor);
void printRoomStatus(Floor floor);

void roomCheckIn(std::vector <Floor> &Hotel_Floor, std::list <Customer> &Customer_Database );
void roomCheckOut(std::vector <Floor> &Hotel_Floor, std::list <Customer> &Customer_Database);
void roomSetFree(std::vector <Floor> &Hotel_Floor);


void prepaid(std::list <Bill> &Revenue_Database);
void printBill(Bill bill);
void postpaid(std::list <Customer> &Customer_Database, std::list <Bill> &Revenue_Database);


#endif