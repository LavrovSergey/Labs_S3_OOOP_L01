/*! Main project file.
* \file main.cpp
* \author Maksym Rasakhatskyi
* \version 1.0 24/09/20
*/
#include <iostream>

// _getch
#include <conio.h>

#include "PriorQueue/PriorQueue.hpp"
#include "PriorQueue/List/LinkedList.hpp"
#include "PriorQueue/Tree/TreeAVL.hpp"
#include "PriorQueue/Heap/Heap.hpp"

#include "FileSystem/FileSystem.hpp"

#include "../../FlawlessMenu/FlawlessMenu/lib/FlawlessMenu.hpp"

#include "Interaction.hpp"

using namespace FlawlessMenu;

//! main function
/*!
* Starts a program
*/
int main()
{
	
	//Setup static variables first
	Menu::Selector = ">";
	Menu::Filler = "==========";
	Menu::GetKeyFunc = _getch;

	auto root = new Menu("Main menu");


	auto menuQueue = new Menu("Work with queue");

	auto menuQueueInt = new Menu("Integer queue");
	menuQueueInt->Add("Create list", function_createList_int);
	menuQueueInt->Add("Create heap", function_createHeap_int);
	menuQueueInt->Add("Create tree", function_createTree_int);
	menuQueueInt->Add("Add element", function_push);
	menuQueueInt->Add("Get element", function_pop);
	menuQueueInt->Add("Predict element", function_predict);
	menuQueueInt->Add("Print queue", function_print);
	menuQueue->Add("Integer queue", menuQueueInt);


	auto menuQueueFile = new Menu("File system queue");
	menuQueueFile->Add("Create list", function_createList_file);
	menuQueueFile->Add("Create heap", function_createHeap_file);
	menuQueueFile->Add("Create tree", function_createTree_file);
	menuQueueFile->Add("Add element", function_push);
	menuQueueFile->Add("Get element", function_pop);
	menuQueueFile->Add("Predict element", function_predict);
	menuQueueFile->Add("Print queue", function_print);
	menuQueue->Add("File system queue", menuQueueFile);


	root->Add("Work with queue", menuQueue);



	auto menuFileSystem = new Menu("Work with file system");
	

	root->Add("Work with file system", menuFileSystem);

	root->Start();

	//FileSystem fileSystem("D:\\Doxygen_res_01");
	//fileSystem.createFile("D:\\Doxygen_res_01\\_symlink\\wow\\new\\file.exe", 0, 0, FileType::file);

	//std::cout << fileSystem.print() << std::endl;
}