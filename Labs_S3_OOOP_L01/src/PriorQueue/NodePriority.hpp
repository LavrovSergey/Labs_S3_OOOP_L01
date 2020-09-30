/*! Base node class.
* \file TreeAVL.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 15/09/20
*/

#ifndef NODE_PRIORITY_HPP
#define NODE_PRIORITY_HPP


#include <algorithm>
#include <string>

/*! Base node class. Has value and priority.*/
template <typename T>
class NodePriority
{
public:
	/*! Value that our queue contains.*/
	T value;

	/*! Priority of this value.*/
	int priority;

	/*! Constructor
	* \param[in] value Value for queue.
	* \param[in] priority Priority for value.
	* Assigns next as null
	*/
	NodePriority(T value, int priority);
};

template<typename T>
inline NodePriority<T>::NodePriority(T value, int priority)
{
	this->value = value;
	this->priority = priority;
}

#endif //NODE_PRIORITY_HPP
