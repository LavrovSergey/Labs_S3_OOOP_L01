/*! Represents Node of the linked list
* \file NodeLinkedList.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 26/09/20
*/

#ifndef NODE_LINKED_LIST_HPP
#define NODE_LINKED_LIST_HPP

template <typename T>
class NodeLinkedList
{
public:
	//! Value that our queue contains.
	T value;

	//! Priority of this value.
	int priority;

	//! Next element in list
	NodeLinkedList<T>* next;

	/*! Constructor
	* \param[in] value Value for queue.
	* \param[in] priority Priority for value.
	* Assigns next as null
	*/
	NodeLinkedList(T value, int priority);
};

template<typename T>
NodeLinkedList<T>::NodeLinkedList(T value, int priority)
{
	this->value = value;
	this->priority = priority;
	this->next = nullptr;
}

#endif // !NODE_LINKED_LIST_HPP