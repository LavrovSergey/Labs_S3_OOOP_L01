/*! Represents class of the linked list
* \file LinkedList.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 26/09/20
*/

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "../PriorQueue.hpp"
#include "NodeLinkedList.hpp"

template <typename T>
class LinkedList : public PriorQueue<T>
{
private:
	//! First element of queue
	NodeLinkedList<T>* head;

public:
	/*! Constructor
	* Assigns head null
	*/
	LinkedList();

	/*! Pushes value with priority to list.
	* \param[in] value Value to insert.
	* \param[in] priority Priority in queue.
	*/
	void push(T value, unsigned int priority) override;

	/*! Pops element from list.
	* Gets element from queue with most priority.
	* Removes it from queue.
	*/
	T pop() override;

	/*! Gets element from queue.
	* Gets element from queue with most priority.
	* Doesn't touch elements.
	*/
	T predict() override;

	/*! Prints whole list to string.
	* \returns Whole list in the string form.
	*/
	std::string print() override;
};

template<typename T>
inline LinkedList<T>::LinkedList()
{
	head = nullptr;
}

template<typename T>
inline void LinkedList<T>::push(T value, unsigned int priority)
{
	if (!head)
	{
		head = new NodeLinkedList<T>(value, priority);
		return;
	}
	NodeLinkedList<T>* current = head;
	while (current->next)
	{
		if (current->next->priority > priority)
		{
			NodeLinkedList<T>* newNode = new NodeLinkedList<T>(value, priority);
			newNode->next = current->next;
			current->next = newNode;
			return;
		}
		else
		{
			current = current->next;
		}
	}
	current->next = new NodeLinkedList<T>(value, priority);
	return;
}

template<typename T>
inline T LinkedList<T>::pop()
{
	if (!head)
		return T();
	T value = head->value;
	if (head->next)
		head = head->next;
	else
		head = nullptr;
	return value;
}

template<typename T>
inline T LinkedList<T>::predict()
{
	if (!head)
		return T();
	return head->value;
}

template<typename T>
inline std::string LinkedList<T>::print()
{
	if (!head)
		return "\n";
	std::string result;
	result += std::to_string(head->value);
	NodeLinkedList<T>* current = head;
	while (current->next)
	{
		current = current->next;
		result += "->";
		result += std::to_string(current->value);
	}
	result += "\n";
	return result;
}


#endif // !LINKED_LIST_HPP