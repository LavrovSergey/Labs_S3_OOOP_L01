/*! File with interaction functions for main menu.
* \file Interaction.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 30/09/20
*/


#ifndef INTERACTION_HPP
#define INTERACTION_HPP

#include <iostream>
// _getch
#include <conio.h>

#include "PriorQueue/Heap/Heap.hpp"
#include "PriorQueue/List/LinkedList.hpp"
#include "PriorQueue/Tree/TreeAVL.hpp"
#include "FileSystem/FileSystem.hpp"

class Interactor
{
public:
	inline static PriorQueue<int>* priorQueueI;
	inline static PriorQueue<FileSystem>* priorQueueF;
	inline static FileSystem* fileSystem;

	static void function_createList_int();
	static void function_createHeap_int();
	static void function_createTree_int();

	static void function_createList_file();
	static void function_createHeap_file();
	static void function_createTree_file();

	static void function_push_int();
	static void function_pop_int();
	static void function_predict_int();
	static void function_print_int();

	static void function_push_file();
	static void function_pop_file();
	static void function_predict_file();
	static void function_print_file();

	static void function_filesystem_create();
	static void function_filesystem_createReal();
	static void function_filesystem_addFile();
	static void function_filesystem_search();
	static void function_filesystem_print();

	static void wait();
};


#endif // !INTERACTION_HPP

