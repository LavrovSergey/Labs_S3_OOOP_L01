/*! File system class 
* \file FileSystem.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 28/09/20
*/

#ifndef FILE_SYSTEM_HPP
#define FILE_SYSTEM_HPP

#include <vector>
#include <string>
#include <sstream>
#include <filesystem>
#include <algorithm>

#include "FileInfo.hpp"
#include "../Helper/Helper.hpp"

namespace fs = std::filesystem;

class FileSystem
{

	/*! Prints*/
	std::string printNode(const std::string& prefix, const FileInfo* node, bool isLast);
public:
	/*! File system root*/
	FileInfo* root;

	/*! Constructor 
	* Sets basic paramters - directory, name=root, etc
	*/
	FileSystem();

	/*! Constructor
	* Imports All subdirectories and files from this pc file system
	* \param realPath Full path of the existing directory.
	*/
	FileSystem(std::string realPath);

	/*! Searches for pattern in file names
	* \param[in] searchFrom Root of search.
	* \param[in] pattern String search pattern (".psd", "PHOTO_", "kursach.docx", etc).
	* \returns List of found files.
	*/
	std::vector<FileInfo*> searchByName(FileInfo* searchFrom, std::string pattern);

	/*! Creates file at given path.
	* If there is no such path, it will be created.
	* \param[in] path Full path of the created file.
	* \param[in] dateTimeCreation Date and time of file creation.
	* \param[in] length File length.
	* \param[in] fileType Type of file.
	* \returns FileInfo of new file.
	*/
	FileInfo* createFile(std::string path, DateTime dateTimeCreation, uint64_t length, FileType fileType, std::string symlinkTarget = "");

	/*! Converts file system to string tree.
	* \returns Tree in string format.
	*/
	std::string print();
};

#endif // !FILE_SYSTEM_HPP