/*! AVL Tree class.
* \file TreeAVL.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 15/09/20
*/

#ifndef TREE_AVL_HPP
#define TREE_AVL_HPP

#include "NodeTreeAVL.hpp"
#include "../PriorQueue.hpp"

#include <algorithm>
#include <string>

template <typename T>
class TreeAVL : public PriorQueue<T>
{
private:
	//! Root of the tree, first element in queue
	NodeTreeAVL<T>* root;

	/*! Right rotates subtree rooted with given node.
	* \param[in] node Subtree root.
	* \returns New root of rotated subtree.
	*/
	NodeTreeAVL<T>* rotateRight(NodeTreeAVL<T>* node);

	/*! Left rotates subtree rooted with given node.
	* \param[in] node Subtree root.
	* \returns New root of rotated subtree.
	*/
	NodeTreeAVL<T>* rotateLeft(NodeTreeAVL<T>* node);

	/*! Recursive function to insert a value in the subtree rooted with node.
	* \param[in] target Where to insert.
	* \param[in] value Item that contains tree.
	* \param[in] priority Priority of item on tree.
	* \returns New root of the subtree.
	*/
	NodeTreeAVL<T>* insertNode(NodeTreeAVL<T>* target, T value, int priority);

	/*! Recursive function to delete a node with given data from subtree
	* \param[in] target Where to delete.
	* \param[in] value Item that contains tree.
	* \param[in] priority Priority of item on tree.
	* \returns New root of the subtree.
	*/
	NodeTreeAVL<T>* deleteNode(NodeTreeAVL<T>* target, T value, int priority);

	/*! Searches branch for mininmum priority value. 
	* \param[in] node Node to start search.
	* \returns Node with minimum priority value in that tree.
	*/
	NodeTreeAVL<T>* findLeftMost(NodeTreeAVL<T>* node);

	/*! Recursive converts tree to text from given node.
	* \param[in] prefix Offset for the level.
	* \param[in] node Start of the tree.
	* \param[in] isLeft Makes prefix vertical or horizontal.
	* \returns Subtree in the string form.
	*/
	std::string printNode(const std::string& prefix, const NodeTreeAVL<T>* node, bool isLeft);
public:
	/*! Creates empty tree with NULL root. */
	TreeAVL();

	/*! Prints whole tree to string.
	* \returns Whole tree in the string form.
	*/
	std::string print() override;

	/*! Pushes value with priority to AVL Tree.
	* \param[in] value Value to insert.
	* \param[in] priority Priority in queue.
	*/
	void push(T value, unsigned int priority) override;

	/*! Pops element from queue.
	* Gets element from queue tree with most priority.
	* Removes it from queue.
	*/
	T pop() override;

	/*! Gets element from queue.
	* Gets element from queue tree with most priority.
	* Doesn't touch elements.
	*/
	T predict() override;

	/*! Gets node height.
	* \param node[int] Node with height.
	* \returns 0 if node is NULL or it's height.
	*/
	int getNodeHeight(NodeTreeAVL<T>* node);

	/*! Get the balance factor of this ancestor node.
	* \param node[int] Node with balance.
	* \returns Balance factor of this ancestor node.
	*/
	int getNodeBalance(NodeTreeAVL<T>* node);
};

template<typename T>
inline NodeTreeAVL<T>* TreeAVL<T>::rotateRight(NodeTreeAVL<T>* node)
{
	auto newNode = node->left;

	//swap
	auto buffer = newNode->right;
	newNode->right = node;
	node->left = buffer;

	//recalculate heights  
	node->height =
		std::max(
			getNodeHeight(node->left),
			getNodeHeight(node->right))
		+ 1;

	newNode->height =
		std::max(
			getNodeHeight(newNode->left),
			getNodeHeight(newNode->right))
		+ 1;

	//new root  
	return newNode;
}

template<typename T>
inline NodeTreeAVL<T>* TreeAVL<T>::rotateLeft(NodeTreeAVL<T>* node)
{
	NodeTreeAVL<T>* newNode = node->right;

	//swap
	auto buffer = newNode->left;
	newNode->left = node;
	node->right = buffer;

	// recalculate heights  
	node->height =
		std::max(
			getNodeHeight(node->left),
			getNodeHeight(node->right))
		+ 1;

	newNode->height = 
		std::max(
			getNodeHeight(newNode->left),
			getNodeHeight(newNode->right)) 
		+ 1;

	// Return new root  
	return newNode;
}

template<typename T>
inline NodeTreeAVL<T>* TreeAVL<T>::deleteNode(NodeTreeAVL<T>* target, T value, int priority)
{
	if (!target)
		return target;

	if (priority < target->priority)
	{
		target->left = deleteNode(target->left, value, priority);
	}
	else if (priority > target->priority)
	{
		target->right = deleteNode(target->right, value, priority);
	}
	else
	{
		if (!target->left ||
			!target->right)
		{
			auto temp = target->left ?
				target->left :
				target->right;

			// No child case  
			if (!temp)
			{
				temp = target;
				target = NULL;
			}
			else
			{
				*target = *temp;
			}
			free(temp);
		}
		else
		{
			NodeTreeAVL<T>* temp = findLeftMost(target->right);

			target->priority = temp->priority;
			target->value = temp->value;

			target->right = deleteNode(
				target->right,
				temp->value,
				temp->priority);
		}
	}

	// If the tree had only one node 
	if (!target)
		return target;

	// upd height
	target->height = std::max(
		getNodeHeight(target->left),
		getNodeHeight(target->right))
		+ 1;

	int balance = getNodeBalance(target);

	// Left Left Case  
	if (balance > 1 &&
		getNodeBalance(target->left) >= 0)
		return rotateRight(target);

	// Left Right Case  
	if (balance > 1 &&
		getNodeBalance(target->left) < 0)
	{
		target->left = rotateLeft(target->left);
		return rotateRight(target);
	}

	// Right Right Case  
	if (balance < -1 &&
		getNodeBalance(target->right) <= 0)
		return rotateLeft(target);

	// Right Left Case  
	if (balance < -1 &&
		getNodeBalance(target->right) > 0)
	{
		target->right = rotateRight(target->right);
		return rotateLeft(target);
	}

	return target;
}

template<typename T>
inline NodeTreeAVL<T>* TreeAVL<T>::findLeftMost(NodeTreeAVL<T>* node)
{
	NodeTreeAVL<T>* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}

template<typename T>
inline std::string TreeAVL<T>::printNode(const std::string& prefix, const NodeTreeAVL<T>* node, bool isLeft)
{
	std::string result;
	if (node)
	{
		result = prefix;

		const unsigned char opened = 195;
		const unsigned char closed = 192;
		const unsigned char line = 196;

		//give direction
		result += (isLeft ? opened : closed);
		result += line;
		result += line;

		//add node value
		result += "[p: " + std::to_string(node->priority) + "  v: " + std::to_string(node->value) + "]\n";

		//enter the next tree level - left and right branch
		result += printNode(prefix + (isLeft ? "│   " : "    "), node->left, true);
		result += printNode(prefix + (isLeft ? "│   " : "    "), node->right, false);
	}
	return result;
}

template<typename T>
inline TreeAVL<T>::TreeAVL()
{
	root = nullptr;
}

template<typename T>
inline std::string TreeAVL<T>::print()
{
	return printNode("", root, false);
}

template<typename T>
inline void TreeAVL<T>::push(T value, unsigned int priority)
{
	if (!root)
		root = new NodeTreeAVL<T>(value, priority);
	else
		root = insertNode(root, value, priority);
}

template<typename T>
inline NodeTreeAVL<T>* TreeAVL<T>::insertNode(NodeTreeAVL<T>* target, T value, int priority)
{
	if (!target)
		return(new NodeTreeAVL<T>(value, priority));

	if (priority < target->priority)
		target->left = insertNode(target->left, value, priority);
	else
		target->right = insertNode(target->right, value, priority);


	// Update height of this ancestor node
	target->height = std::max(
		getNodeHeight(target->left),
		getNodeHeight(target->right));

	// Get the balance factor of this ancestor node to check whether this node became unbalanced
	int balance = getNodeBalance(target);

	// Left Left Case  
	if (balance > 1 &&
		priority < target->left->priority)
		return rotateRight(target);

	// Right Right Case  
	if (balance < -1 &&
		priority > target->right->priority)
		return rotateLeft(target);

	// Left Right Case  
	if (balance > 1 &&
		priority > target->left->priority)
	{
		target->left = rotateLeft(target->left);
		return rotateRight(target);
	}

	// Right Left Case  
	if (balance < -1 &&
		priority < target->right->priority)
	{
		target->right = rotateLeft(target->right);
		return rotateRight(target);
	}

	return target;
}

template<typename T>
inline T TreeAVL<T>::pop()
{
	if (!root) return NULL;
	auto value = root->value;
	root = deleteNode(root, root->value, root->priority);
	return value;
}

template<typename T>
inline T TreeAVL<T>::predict()
{
	if (!root) return NULL;
	else return root->value;
}

template<typename T>
inline int TreeAVL<T>::getNodeHeight(NodeTreeAVL<T>* node)
{
	if (!node) return 0;
	else return node->height;
}

template<typename T>
inline int TreeAVL<T>::getNodeBalance(NodeTreeAVL<T>* node)
{
	if (!node) return 0;
	else return getNodeHeight(node->left) - getNodeHeight(node->right);
}


#endif // !TREE_AVL_HPP
