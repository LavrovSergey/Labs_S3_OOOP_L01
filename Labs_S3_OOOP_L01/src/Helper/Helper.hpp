/*! Hhelper class
* \file Helper.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 28/09/20
*/

#ifndef HELPER_HPP
#define HELPER_HPP

#include <string>
#include <vector>
#include <utility>
#include <sys/stat.h>
#include <string>
#include <fstream>

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

	/*! Checks file for existance.
	* \param[in] name File path.
	* \returns True if file exists, False if not.
	*/
	static bool isFileExists(const std::string& name);
};

/*! Argument Dependent Lookup (ADL) lookup namespace for std::to_string.*/
namespace notstd 
{

	/*! ADL helper namespace created for overloading standard std::to_string function.*/
	namespace adl_helper 
	{
		using std::to_string;

		/*! Function that returns standard to_string() function if posibble, else my self-defined to_string() function from my class.
		* \param[in] t My class object.
		* \returns Result of my class to_string function.
		*/
		template<class T>
		std::string as_string(T&& t) 
		{
			return to_string(std::forward<T>(t));
		}
	}

	/*! Calls adl_helper::as_string
	* \param[in] t My class object.
	* \returns Result of my class to_string function.
	*/
	template<class T>
	std::string to_string(T&& t) 
	{
		return adl_helper::as_string(std::forward<T>(t));
	}
}

#endif // !HELPER_HPP