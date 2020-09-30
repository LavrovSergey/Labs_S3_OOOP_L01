/*! Represents Node of the AVL tree
* \file NodeTreeAVL.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 15/09/20
*/

#ifndef NODE_TREE_AVL_HPP
#define NODE_TREE_AVL_HPP

#include "../NodePriority.hpp"

template <typename T>
class NodeTreeAVL : public NodePriority<T>
{
public:
	/*! Left child.*/
	NodeTreeAVL<T>* left;

	/*! Right child.*/
	NodeTreeAVL<T>* right;

	/*! Height of the current node*/
	unsigned int height;

	/*! Constructor
	* \param[in] value Value for queue.
	* \param[in] priority Priority for value.
	* Assigns children as 0,
	* Assigns height as 1
	*/
	NodeTreeAVL(T value, int priority);
};

template<typename T>
inline NodeTreeAVL<T>::NodeTreeAVL(T value, int priority) : NodePriority<T>(value, priority)
{
	this->left = nullptr;
	this->right = nullptr;
	this->height = 1;
}

#endif // !NODE_TREE_AVL_HPP
