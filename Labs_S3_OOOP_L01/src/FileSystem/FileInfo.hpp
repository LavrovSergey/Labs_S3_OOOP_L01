/*! File info class (file node)
* \file FileInfo.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 28/09/20
*/


#ifndef FILE_INFO_HPP
#define FILE_INFO_HPP

#include <vector>
#include <string>

#include "FileType.hpp"
#include "../../../Easy_CPP_DateTime/EasyDateTime.hpp"

/*! File info class
* Information about file system objects - files and directories (name, size, creation time, modification time, file type). 
* Calculates the full path to the file / directory. 
* Searches for files according to the specified criteria in the subdirectory tree.
*/
class FileInfo
{
private:
	/*! Parent directory. Nullptr if root.*/
	FileInfo* parent;


public:

	/*! Short file name + extension. To full path.*/
	std::string name;

	/*! List of children files / directories.*/
	std::vector<FileInfo*> children;

	/*! Date and time of file creation.*/
	DateTime dateTimeCreation;

	/*! Date and time of file modification.*/
	DateTime dateTimeModification;

	/*! File size in bytes.*/
	uint64_t length;

	/*! File type: file, dir, etc...*/
	FileType fileType;


	/*! Constructor
	* Creates ne file info.
	* Assigns parent to nullptr
	* Assigns date of modification date of creation
	*/
	FileInfo(std::string name, DateTime dateTimeCreation, uint64_t length, FileType fileType);

	/*! Recursive reads full path of file from root.
	* \returns Full path in string format.
	*/
	std::string getFullPath();

	/*! Creates file in current dir if it is dir.
	* \param file New file to add.
	* \exception std::invalid_argument Thrown if file type is not directory
	*/
	void createFile(FileInfo* file);
};

#endif // !FILE_INFO_HPP