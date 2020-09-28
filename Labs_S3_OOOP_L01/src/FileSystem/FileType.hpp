/*! File type enumeration
* \file FileType.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 28/09/20
*/

#ifndef FILE_TYPE_HPP
#define FILE_TYPE_HPP

/*! File type enum */
enum FileType
{
	/*! Regular file.*/
	file,

	/*! Directory.*/
	directory,

	/*! Symbolic link.*/
	link,

	/*! FIFO special.*/
	fifo,

	/*! Block special.*/
	block,

	/*! Character special.*/
	character,

	/*! Socket.*/
	soket
};

#endif // !FILE_TYPE_HPP
