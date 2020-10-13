#include "Interaction.hpp"


FileType Interactor::enterFileType()
{
	char answer;
	std::cout << "Enter type file \n(Regular [f]ile, [D]irectory, Symbolic [l]ink, FIF[O] special, [B]lock special, [C]haracter special, [S]ocket:" << std::endl;
	std::cin >> answer;
	switch (answer)
	{
		case 'f':
		case 'F':
			return FileType::file;
			break;

		case 'd':
		case 'D':
			return FileType::directory;
			break;

		case 'l':
		case 'L':
			return FileType::link;
			break;

		case 'o':
		case 'O':
			return FileType::fifo;
			break;

		case 'b':
		case 'B':
			return FileType::block;
			break;

		case 'c':
		case 'C':
			return FileType::character;
			break;

		case 's':
		case 'S':
			return FileType::soket;
			break;

		default:
			return FileType::file;
			break;
	}
}

std::string Interactor::readLine()
{
	std::string line;
	while (line.size() == 0)
		std::getline(std::cin, line);
	return line;
}

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
	if (!fileSystem)
	{
		std::cout << "Not created" << std::endl;
		return;
	}

	std::cout << "\nEnter path" << std::endl;
	std::string path = readLine();

	std::cout << "\nEnter file size" << std::endl;
	uint64_t size; 
	std::cin >> size;

	std::cout << "\nEnter date of creation (yyyy-MM-dd HH-mm-ss) :" << std::endl;
	DateTime time(readLine());

	std::cout << "\n";

	FileType type = enterFileType();

	fileSystem->createFile(path, time, size, type);

	std::cout << "\nAdded." << std::endl;
	wait();
}

void Interactor::function_filesystem_search()
{
	if (!fileSystem)
	{
		std::cout << "Not created" << std::endl;
		return;
	}

	SearchPattern pattern;
	char answer;


	std::cout << "Search by name? (y/n)" << std::endl;
	std::cin >> answer; 
	if (answer == 'Y' || answer == 'y')
	{
		pattern.toSearchByName = true;
		std::cout << "Enter name :" << std::endl;
		pattern.searchInfo.name = readLine();
	}

	std::cout << "Search by date? (y/n)" << std::endl;
	std::cin >> answer;
	if (answer == 'Y' || answer == 'y')
	{
		pattern.toSearchByDate = true;
		std::cout << "Enter date (yyyy-MM-dd HH-mm-ss) :" << std::endl;
		pattern.searchInfo.dateTimeCreation = DateTime(readLine());
	}

	std::cout << "Search by size? (y/n)" << std::endl;
	std::cin >> answer;
	if (answer == 'Y' || answer == 'y')
	{
		pattern.toSearchBySize = true;
		std::cout << "Enter size in bytes :" << std::endl;
		uint64_t length;
		std::cin >> length;
		pattern.searchInfo.length = length;
	}

	std::cout << "Search by type? (y/n)" << std::endl;
	std::cin >> answer;
	if (answer == 'Y' || answer == 'y')
	{
		pattern.toSearchByType = true;
		pattern.searchInfo.fileType = enterFileType();
	}

	std::cout << "Search by ALL parameters or Any parameter (A/O):" << std::endl;
	std::cin >> answer;

	auto result =
		answer == 'A' || answer == 'a' ?
		fileSystem->search(pattern, true) :
		fileSystem->search(pattern, false);

	if (result.size() == 0)
		std::cout << "No files found." << std::endl;
	else
		for (auto& i : result)
			std::cout << i->getFullPath() << std::endl;

	wait();
}

void Interactor::function_filesystem_print()
{
	if (!fileSystem)
	{
		std::cout << "Not created" << std::endl;
		return;
	}

	std::cout << fileSystem->print();
	wait();
}

void Interactor::wait()
{
	std::cout << "Press any key..." << std::endl;
	_getch();
}
