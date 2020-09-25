/*! Main project file.
* \file main.cpp
* \author Maksym Rasakhatskyi
* \version 1.0 24/09/20
*/

#include "PriorQueue/PriorQueue.hpp"
#include "PriorQueue/Tree/TreeAVL.hpp"

#include <iostream>

//! main function
/*!
* Starts a program
*/
int main()
{
	PriorQueue<int>* queue = new TreeAVL<int>();
	queue->push(1, 1);
	queue->push(2, 2);
	queue->push(4, 4);
	queue->push(3, 3);
	queue->push(7, 7);
	queue->push(5, 5);
	std::cout << queue->print();
}