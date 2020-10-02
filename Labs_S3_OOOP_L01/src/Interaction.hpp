/*! File with interaction functions for main menu.
* \file Interaction.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 30/09/20
*/


#ifndef INTERACTION_HPP
#define INTERACTION_HPP

#include <iostream>
#include <conio.h> // _getch

#include "PriorQueue/Heap/Heap.hpp"
#include "PriorQueue/List/LinkedList.hpp"
#include "PriorQueue/Tree/TreeAVL.hpp"
#include "FileSystem/FileSystem.hpp"


/*! Ñlass for the menu to interact with my classes.*/
class Interactor
{
public:
	/* Object of PriorQueue with value of type int.*/
	inline static PriorQueue<int>* priorQueueI;

	/* Object of PriorQueue with value of type file system.*/
	inline static PriorQueue<FileSystem>* priorQueueF;

	/* Object fylesystem.*/
	inline static FileSystem* fileSystem;



	/*! Creates Priority queue <int> of type List, deletes previous queue.*/
	static void function_createList_int();

	/*! Creates Priority queue <int> of type Heap, deletes previous queue.*/
	static void function_createHeap_int();

	/*! Creates Priority queue <int> of type AVL tree, deletes previous queue.*/
	static void function_createTree_int();



	/*! Creates Priority queue <Filesystem> of type List, deletes previous queue.*/
	static void function_createList_file();

	/*! Creates Priority queue <Filesystem> of type Heap, deletes previous queue.*/
	static void function_createHeap_file();

	/*! Creates Priority queue <Filesystem> of type AVL tree, deletes previous queue.*/
	static void function_createTree_file();



	/*! Pushes to queue int value entered from console.*/
	static void function_push_int();

	/*! Gets element from int queue with most priority and deletes it from queue.*/
	static void function_pop_int();

	/*! Gets element from int queue with most priority without deleting it from queue.*/
	static void function_predict_int();

	/*! Prints queue on screen*/
	static void function_print_int();



	/*! Pushes to queue filesystem value entered from console.*/
	static void function_push_file();

	/*! Gets element from filesystem queue with most priority and deletes it from queue.*/
	static void function_pop_file();

	/*! Gets element from filesystem queue with most priority without deleting it from queue.*/
	static void function_predict_file();

	/*! Prints queue on screen*/
	static void function_print_file();



	/*! Creates empty filesystem, deletes previous filesystem.*/
	static void function_filesystem_create();

	/*! Creates filesystem from path of the real file on PC.*/
	static void function_filesystem_createReal();

	/*! Reads path of new file from console and adds it to filesystem.*/
	static void function_filesystem_addFile();

	/*! Searches for file in filesystem.*/
	static void function_filesystem_search();

	/*! Prints filesystem.*/
	static void function_filesystem_print();



	/*! Freezes the console.*/
	static void wait();
};


#endif // !INTERACTION_HPP

