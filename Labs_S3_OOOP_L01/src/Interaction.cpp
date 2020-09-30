#include "Interaction.hpp"

bool isInt = true;
PriorQueue<int>* priorQueueI;
PriorQueue<FileSystem>* priorQueueF;
FileSystem* fileSystem;

void function_createList_int()
{
	if (priorQueueI)
	{
		delete priorQueueI;
		std::cout << "Old queue deleted" << std::endl;
	}
	priorQueueI = new LinkedList<int>();
	std::cout << "List created" << std::endl;
	wait();
}

void function_createHeap_int()
{
	if (priorQueueI)
	{
		delete priorQueueI;
		std::cout << "Old queue deleted" << std::endl;
	}
	priorQueueI = new Heap<int>();
	std::cout << "Heap created" << std::endl;
	wait();
}

void function_createTree_int()
{
	if (priorQueueI)
	{
		delete priorQueueI;
		std::cout << "Old queue deleted" << std::endl;
	}
	priorQueueI = new TreeAVL<int>();
	std::cout << "Tree created" << std::endl;
	wait();
}

void function_createList_file()
{
}

void function_createHeap_file()
{
}

void function_createTree_file()
{
}

void function_push()
{
}

void function_pop()
{
}

void function_predict()
{
}

void function_print()
{
}


void wait()
{
	std::cout << "Press any key..." << std::endl;
}
