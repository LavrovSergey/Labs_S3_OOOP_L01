/*! File system class 
* \file FileSystem.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 28/09/20
*/

#ifndef FILE_SYSTEM_HPP
#define FILE_SYSTEM_HPP

#include <vector>
#include <string>

#include "FileInfo.hpp"
#include "../Helper/Helper.hpp"

class FileSystem
{
	/*! File system root*/
	FileInfo* root;

public:

	/*! Constructor 
	* Sets basic paramters - directory, name=root, etc
	*/
	FileSystem();

	/*! Searches for pattern in file names
	* \param[in] searchFrom Root of search.
	* \param[in] pattern String search pattern ("*.psd", "PHOTO_????.jpg", "kursach.docx", etc).
	* \returns List of found files.
	*/
	std::vector<FileInfo*> searchByName(FileInfo* searchFrom, std::string pattern);

	FileInfo* createFile(std::string path, DateTime dateTimeCreation, uint64_t length, FileType fileType);
};

#endif // !FILE_SYSTEM_HPP