//! main project file
/*!
* \file main.cpp
* \author Maksym Rasakhatskyi
* \version 1.0 24/09/20
*/


#include <iostream>

#include "PriorQueue/PriorQueue.hpp"
#include "PriorQueue/Tree/TreeAVL.hpp"

//! main function
/*!
* Starts a program
*/
int main()
{
	PriorQueue<int> queue = TreeAVL<int>();
}