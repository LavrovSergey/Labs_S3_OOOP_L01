/*! Hhelper class
* \file Helper.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 28/09/20
*/

#ifndef HELPER_HPP
#define HELPER_HPP

#include <string>
#include <vector>


/*! Class with handy functions*/
class Helper
{
public:

	/*! Splits string on substrings by delimiter.
	* \param[in] input Source string.
	* \param[in] delimiter Delimiter.
	* \returns Vector of substrings.
	*/
	static std::vector <std::string> splitString(std::string input, std::string delimiter);
};


#endif // !HELPER_HPP