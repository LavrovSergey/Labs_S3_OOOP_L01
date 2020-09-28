/*! File info class
* \file FileInfo.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 28/09/20
*/


#ifndef FILE_INFO_HPP
#define FILE_INFO_HPP

#include <vector>
#include <string>

#include "FileType.hpp"

/*! File info class
* Information about file system objects - files and directories (name, size, creation time, modification time, file type). 
* Calculates the full path to the file / directory. 
* Searches for files according to the specified criteria in the subdirectory tree.
*/
class FileInfo
{
	/*! Short file name + extension. To full path.*/
	std::string name;

	/*! List of children files / directories.*/
	std::vector<FileInfo> children;

	/*! Date and time of file creation.*/
	//TODO dateTimeCreation

	/*! Date and time of file modification.*/
	//TODO dateTimeModification

	/*! File size in bytes.*/
	uint64_t length;

	/*! File type: file, dir, etc...*/
	FileType fileType;
};

#endif // !FILE_INFO_HPP