/*! Represents Node of the AVL tree
* \file NodeTreeAVL.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 15/09/20
*/

#ifndef NODE_TREE_AVL_HPP
#define NODE_TREE_AVL_HPP

template <typename T>
class NodeTreeAVL
{

public:
	//! Left child.
	NodeTreeAVL<T>* left;

	//! Right child.
	NodeTreeAVL<T>* right;

	//! Value that our queue contains.
	T value;

	//! Priority of this value.
	int priority;

	//! Height of the current node
	unsigned int height;

	/*! Constructor
	* \param[in] value Value for queue.
	* \param[in] priority Priority for value.
	* Assigns children as 0,
	* Assigns height as 1
	*/
	NodeTreeAVL(T value, int priority);

	/*! Gets node value.
	* \returns Node value.
	*/
	T getValue();

	/*! Gets priority for value in current node.
	* \returns Priority for value in current node.
	*/
	unsigned int getPriority();

};

template<typename T>
inline NodeTreeAVL<T>::NodeTreeAVL(T value, int priority)
{
	this->value = value;
	this->priority = priority;
	this->left = nullptr;
	this->right = nullptr;
	this->height = 1;
}

template<typename T>
inline T NodeTreeAVL<T>::getValue()
{
	return value;
}

template<typename T>
inline unsigned int NodeTreeAVL<T>::getPriority()
{
	return priority;
}

#endif // !NODE_TREE_AVL_HPP
