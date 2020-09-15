#pragma once
#include <vector>

template <typename T>
class TreeNode
{
public:
	std::vector<TreeNode*> nodes;
	T value;
	int priority;

	TreeNode(T value, int priority);

	void push(T item, unsigned int priority);
};

template<typename T>
inline TreeNode<T>::TreeNode(T value, int priority)
{
	this->value = value;
	this->priority = priority;
}

template<typename T>
inline void TreeNode<T>::push(T item, unsigned int priority)
{

}
