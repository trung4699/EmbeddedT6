#ifndef OPERATION_H
#define OPERATION_H

/*
* File: operation.hpp
* Author: Phan Hoang Trung
* Date: 07/08/2023
* Description: This is a file include function declaration of operation with dish and order
*/

#include "C:\Users\Trine\Desktop\EmbeddedInterview\C++\Assignment 2 - Restaurant Management\Header\order.hpp"


void printMenu(std::list <Dish> &menu);
void addNewDish(std::list <Dish> &menu);
void updateInfoDish(std::list <Dish> &menu);
void deleteDish(std::list <Dish> &menu);

Order orderDish(std::list <Dish> &menu);
void printOrder(std::list <Order> &menu);
void changeDish(std::list <Order> &menu);


#endif