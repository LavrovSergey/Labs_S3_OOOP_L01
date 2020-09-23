/**
	AVL Tree class
	@file TreeAVL.hpp
	@author Maksym Rasakhatskyi
	@version 1.0 15/09/20
*/

#pragma once
#include "NodeTreeAVL.hpp"
#include "../PriorQueue.hpp"

#include <algorithm>

template <typename T>
class TreeAVL : public PriorQueue<T>
{
private:
	NodeTreeAVL<T>* root;

	/**
	Right rotates subtree rooted with given node.
	@param node subtree root.
	@returns new root of rotated subtree.
	*/
	NodeTreeAVL<T>* rotateRight(NodeTreeAVL<T>* node);

	/**
	Left rotates subtree rooted with given node.
	@param node subtree root.
	@returns new root of rotated subtree.
	*/
	NodeTreeAVL<T>* rotateLeft(NodeTreeAVL<T>* node);

public:
	TreeAVL();
	void push(T item, unsigned int priority) override;
	T pop() override;
	T predict() override;
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
			node->left->getHeight(),
			node->right->getHeight()) 
		+ 1;

	newNode->height = 
		std::max(
			newNode->left->getHeight(),
			newNode->right->getHeight()) 
		+ 1;

	//new root  
	return newNode;
}

template<typename T>
inline NodeTreeAVL<T>* TreeAVL<T>::rotateLeft(NodeTreeAVL<T>* node)
{
	auto newNode = node->right;

	//swap
	auto buffer = newNode->left;
	newNode->left = node;
	node->right = buffer;

	// recalculate heights  
	node->height = 
		std::max(
			node->left->getHeight(),
			node->right->getHeight()) 
		+ 1;
	newNode->height = std::max(height(newNode->left),
		height(newNode->right)) + 1;

	// Return new root  
	return newNode;
}

template<typename T>
inline TreeAVL<T>::TreeAVL()
{
	root = nullptr;
}

template<typename T>
inline void TreeAVL<T>::push(T item, unsigned int priority)
{
	if (!root)
		root = new NodeTreeAVL<T>(item, priority);
}

template<typename T>
inline T TreeAVL<T>::pop()
{
	return T();
}

template<typename T>
inline T TreeAVL<T>::predict()
{
	return T();
}
