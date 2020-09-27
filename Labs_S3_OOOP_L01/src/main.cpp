/*! Main project file.
* \file main.cpp
* \author Maksym Rasakhatskyi
* \version 1.0 24/09/20
*/

#include "PriorQueue/PriorQueue.hpp"
#include "PriorQueue/List/LinkedList.hpp"
#include "PriorQueue/Tree/TreeAVL.hpp"
#include "PriorQueue/Heap/Heap.hpp"

#include <iostream>

//! main function
/*!
* Starts a program
*/
int main()
{
	PriorQueue<int>* queue = new Heap<int>();
	queue->push(5, 5);
	std::cout << queue->print();

	queue->push(3, 3);
	std::cout << queue->print();

	queue->push(4, 4);
	std::cout << queue->print();

	queue->push(6, 6);
	std::cout << queue->print();

	queue->push(3, 3);
	std::cout << queue->print();

	queue->push(7, 7);
	std::cout << queue->print();

	queue->push(2, 2);
	std::cout << queue->print();

	queue->push(3, 3);
	std::cout << queue->print();

	queue->push(8, 8);
	std::cout << queue->print();
	
	for (int i = 0; i < 9; ++i)
	{
		std::cout << queue->pop() << std::endl;
	}
}