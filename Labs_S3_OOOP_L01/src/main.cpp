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
	PriorQueue<int> queue = TreeAVL<int>();
}