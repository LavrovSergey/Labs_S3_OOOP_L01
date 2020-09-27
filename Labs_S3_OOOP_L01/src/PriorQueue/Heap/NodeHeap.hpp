/*! Represents Node of the heap
* \file NodeHeap.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 09/27/20
*/

#ifndef NODE_HEAP_HPP
#define NODE_HEAP_HPP

template<typename T>
class NodeHeap
{
public:
	/*! Left child*/
	NodeHeap<T>* left;

	/*! Right child*/
	NodeHeap<T>* right;

	/*! Value*/
	T value;

	/*! Priority of value*/
	int priority;

	/*! Constructor
	* Assigns nullptr to children.
	* \param[in] value Node value.
	* \param[in] priority Priority of value.
	*/
	NodeHeap(T value, int priority);
};


template<typename T>
inline NodeHeap<T>::NodeHeap(T value, int priority)
{
	this->left = nullptr;
	this->right = nullptr;
	this->value = value;
	this->priority = priority;
}

#endif // !NODE_HEAP_HPP