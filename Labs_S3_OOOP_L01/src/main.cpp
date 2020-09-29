/*! Main project file.
* \file main.cpp
* \author Maksym Rasakhatskyi
* \version 1.0 24/09/20
*/

#include "PriorQueue/PriorQueue.hpp"
#include "PriorQueue/List/LinkedList.hpp"
#include "PriorQueue/Tree/TreeAVL.hpp"
#include "PriorQueue/Heap/Heap.hpp"

#include "FileSystem/FileSystem.hpp"

#include <iostream>

//! main function
/*!
* Starts a program
*/
int main()
{

	FileSystem fileSystem("D:\\Doxygen_res_01");
	std::cout << fileSystem.print() << std::endl;

	auto res = fileSystem.searchByName(fileSystem.root, "node");
	for (auto& i : res)
		std::cout << i->getFullPath() << std::endl;

	/*fileSystem.createFile("user\\games\\factorio.exe", 0, 0, FileType::file);
	fileSystem.createFile("user\\facts\\docs.doc", 0, 0, FileType::file);
	fileSystem.createFile("user\\music\\Era Falsity.mp3", 0, 0, FileType::file);

	

	std::cout << std::endl;

	res = fileSystem.searchByName(fileSystem.root, "o");
	for (auto& i : res)
		std::cout << i->getFullPath() << std::endl;*/

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