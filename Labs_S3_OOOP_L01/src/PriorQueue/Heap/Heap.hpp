/*! Represents Heap binary tree
* \file Heap.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 26/09/20
*/

#ifndef HEAP_HPP
#define HEAP_HPP

#include "../PriorQueue.hpp"
#include "NodeHeap.hpp"


template<typename T>
class Heap : public PriorQueue<T>
{
	/*! Root of the heap */
	NodeHeap<T>* root;


	/*! Recursive function to insert a value in the subtree rooted with node.
	* \param[in] target Where to insert.
	* \param[in] value Item that contains tree.
	* \param[in] priority Priority of item on tree.
	* \returns New root of the subtree.
	*/
	NodeHeap<T>* insertNode(NodeHeap<T>* target, T value, int priority);

	/*! Recursive converts tree to text from given node.
	* \param[in] prefix Offset for the level.
	* \param[in] node Start of the tree.
	* \param[in] isLeft Makes prefix vertical or horizontal.
	* \returns Subtree in the string form.
	*/
	std::string printNode(const std::string& prefix, const NodeHeap<T>* node, bool isLeft);
public:
	/*! Constructor
	* Assigns root null
	*/
	Heap();

	/*! Pushes value with priority to heap.
	* \param[in] value Value to insert.
	* \param[in] priority Priority in queue.
	*/
	void push(T value, unsigned int priority) override;

	/*! Pops element from heap.
	* Gets element from queue with most priority.
	* Removes it from queue.
	*/
	T pop() override;

	/*! Gets element from queue.
	* Gets element from queue with most priority.
	* Doesn't touch elements.
	*/
	T predict() override;

	/*! Prints whole heap to string.
	* \returns Whole heap in the string form.
	*/
	std::string print() override;
};


template<typename T>
inline NodeHeap<T>* Heap<T>::insertNode(NodeHeap<T>* target, T value, int priority)
{
	if (!target)
	{
		target = new NodeHeap<T>(value, priority);
		return target;
	}

	if (priority >= target->priority)
	{
		//no children
		if (!target->left &&
			!target->right)
		{
			target->left = new NodeHeap<T>(value, priority);
		}

		//only left children exists
		else 
		if (target->left &&
			!target->right)
		{
			if (priority >= target->left->priority)
				return insertNode(target->left, value, priority);
			else 
				target->right = new NodeHeap<T>(value, priority);
		}

		//only right children exists
		else 
		if (!target->left &&
			target->right)
		{
			if (priority >= target->right->priority)
				return insertNode(target->right, value, priority);
			else
				target->left = new NodeHeap<T>(value, priority);
		}

		//both exist
		else
		{
			// if both children have more priority
			if (priority >= target->left->priority &&
				priority >= target->right->priority)
			{
				//add value to highest priority
				if (target->left->priority <= target->right->priority)
					return insertNode(target->left, value, priority);
				else
					return insertNode(target->right, value, priority);
			}

			//add value to highest priority
			else
			{
				if (priority < target->left->priority &&
					priority >= target->right->priority)
					return insertNode(target->right, value, priority);
				else
					return insertNode(target->left, value, priority);
			}
		}
	}
	else
	{
		T t_value = target->value;
		int t_prioruty = target->priority;
		target->value = value;
		target->priority = priority;
		return insertNode(target, t_value, t_prioruty);
	}
	return target;
}

template<typename T>
inline std::string Heap<T>::printNode(const std::string& prefix, const NodeHeap<T>* node, bool isLeft)
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
		result += printNode(prefix + (isLeft ? "|   " : "    "), node->left, true);
		result += printNode(prefix + (isLeft ? "|   " : "    "), node->right, false);
	}
	return result;
}

template<typename T>
inline Heap<T>::Heap()
{
	root = nullptr;
}

template<typename T>
inline void Heap<T>::push(T value, unsigned int priority)
{
	root = insertNode(root, value, priority);
}

template<typename T>
inline T Heap<T>::pop()
{
	return T();
}

template<typename T>
inline T Heap<T>::predict()
{
	return T();
}

template<typename T>
inline std::string Heap<T>::print()
{
	return printNode("", root, false);
}

#endif // !HEAP_HPP