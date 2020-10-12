/*! Search pattern class
* \file SearchPattern.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 28/09/20
*/

#ifndef SEARCH_PATTERN_HPP
#define SEARCH_PATTERN_HPP

#include "FileInfo.hpp"

/*! Search pattern list*/
struct SearchPattern
{
	/*! Search pattern set. Data that contain fields is different search pattern.*/
	FileInfo searchInfo;

	/*! Defines if search by name is enabled. FileInfo::name is used as parameter.*/
	bool toSearchByName;

	/*! Defines if search by date is enabled. FileInfo::dateTimeCreation is used as parameter.*/
	bool toSearchByDate;

	/*! Defines if search by size is enabled. FileInfo::length is used as parameter.*/
	bool toSearchBySize;

	/*! Defines if search by type is enabled. FileInfo::fileType is used as parameter.*/
	bool toSearchByType;

	/*! Creates empty pattern*/
	SearchPattern() :
		searchInfo(FileInfo()),
		toSearchByName(false), 
		toSearchByDate(false),
		toSearchBySize(false),
		toSearchByType(false){};
};

#endif // !SEARCH_PATTERN_HPP
