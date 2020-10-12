#include "Interaction.hpp"


void Interactor::function_createList_int()
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

void Interactor::function_createHeap_int()
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

void Interactor::function_createTree_int()
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



void Interactor::function_createList_file()
{
	if (priorQueueF)
	{
		delete priorQueueF;
		std::cout << "Old queue deleted" << std::endl;
	}
	priorQueueF = new LinkedList<FileSystem>();
	std::cout << "List created" << std::endl;
	wait();
}

void Interactor::function_createHeap_file()
{
	if (priorQueueF)
	{
		delete priorQueueF;
		std::cout << "Old queue deleted" << std::endl;
	}
	priorQueueF = new Heap<FileSystem>();
	std::cout << "Heap created" << std::endl;
	wait();
}

void Interactor::function_createTree_file()
{
	if (priorQueueF)
	{
		delete priorQueueF;
		std::cout << "Old queue deleted" << std::endl;
	}
	priorQueueF = new TreeAVL<FileSystem>();
	std::cout << "Tree created" << std::endl;
	wait();
}



void Interactor::function_push_int()
{
	std::cout << "Enter value ";
	int v; std::cin >> v;
	std::cout << "Enter priority ";
	int p; std::cin >> p;
	priorQueueI->push(v, p);
	std::cout << "Pushed." << std::endl;
	wait();
}

void Interactor::function_pop_int()
{
	std::cout << "Value : " << priorQueueI->pop() << std::endl;
	wait();
}

void Interactor::function_predict_int()
{
	std::cout << "Value : " << priorQueueI->predict() << std::endl;
	wait();
}

void Interactor::function_print_int()
{
	std::cout << priorQueueI->print() << std::endl;
	wait();
}



void Interactor::function_push_file()
{
	std::string path;

	while (!Helper::isFileExists(path))
	{
		std::cout << "Enter real file path: " << std::endl;
		std::getline(std::cin, path);
	}

	std::cout << "Enter priority: ";
	int p; std::cin >> p;
	priorQueueF->push(FileSystem(path), p);
	std::cout << "Pushed." << std::endl;
	wait();
}

void Interactor::function_pop_file()
{
	std::cout << "Value : " << priorQueueF->pop().print() << std::endl;
	wait();
}

void Interactor::function_predict_file()
{
	std::cout << "Value : " << priorQueueF->predict().print() << std::endl;
	wait();
}

void Interactor::function_print_file()
{
	std::cout << priorQueueF->print() << std::endl;
	wait();
}



void Interactor::function_filesystem_create()
{
	if (fileSystem) 
	{
		delete priorQueueF;
		std::cout << "Old filesystem deleted" << std::endl;
	}
	fileSystem = new FileSystem();
	std::cout << "Created" << std::endl;
	wait();
}

void Interactor::function_filesystem_createReal()
{
	if (fileSystem)
	{
		delete priorQueueF;
		std::cout << "Old filesystem deleted" << std::endl;
	}
	std::cout << "Enter path" << std::endl;
	std::string path;
	std::getline(std::cin, path);
	fileSystem = new FileSystem(path);
	std::cout << "Created" << std::endl;
	wait();
}

void Interactor::function_filesystem_addFile()
{
	if (fileSystem)
	{
		std::cout << "Enter path" << std::endl;
		std::string path;
		std::getline(std::cin, path);
		std::cout << "Enter file size" << std::endl;
		int size; std::cin >> size;
		fileSystem->createFile(path, 0, size, FileType::file);
		std::cout << "Added" << std::endl;
		wait();
	}
}

void Interactor::function_filesystem_search()
{
	std::cout << "Enter name" << std::endl;
	std::string path;
	std::getline(std::cin, path);
	/*auto result = fileSystem->searchByName(path);
	for (auto& i : result)
		std::cout << i << std::endl;*/
	wait();
}

void Interactor::function_filesystem_print()
{
	std::cout << fileSystem->print();
	wait();
}






void Interactor::wait()
{
	std::cout << "Press any key..." << std::endl;
	_getch();
}
