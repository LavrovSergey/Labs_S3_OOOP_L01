#pragma once
#include "TreeNode.hpp"
#include "../PriorQueue.hpp"

template <typename T>
class Tree : public PriorQueue<T>
{
private:
	TreeNode<T>* root;
public:
	Tree();
	void push(T item, unsigned int priority) override;
	T pop() override;
	T predict() override;
};

template<typename T>
inline Tree<T>::Tree()
{
	root = nullptr;
}

template<typename T>
inline void Tree<T>::push(T item, unsigned int priority)
{
	if (!root)
		root = new TreeNode<T>(item, priority);
}

template<typename T>
inline T Tree<T>::pop()
{
	return T();
}

template<typename T>
inline T Tree<T>::predict()
{
	return T();
}
