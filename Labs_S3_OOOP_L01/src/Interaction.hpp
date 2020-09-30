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

extern bool isInt;
extern PriorQueue<int>* priorQueueI;
extern PriorQueue<FileSystem>* priorQueueF;
extern FileSystem* fileSystem;

void function_createList_int();
void function_createHeap_int();
void function_createTree_int();

void function_createList_file();
void function_createHeap_file();
void function_createTree_file();

void function_push_int();
void function_pop_int();
void function_predict_int();
void function_print_int();

void function_push_file();
void function_pop_file();
void function_predict_file();
void function_print_file();

void function_filesystem_create();
void function_filesystem_createReal();
void function_filesystem_addFile();
void function_filesystem_search();
void function_filesystem_print();

void wait();
#endif // !INTERACTION_HPP

