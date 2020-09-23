#pragma once

template <typename T>
class NodeTreeAVL
{
public:
	NodeTreeAVL<T>* left;
	NodeTreeAVL<T>* right;
	T value;
	unsigned int priority;
	unsigned int height;

	NodeTreeAVL(T value, int priority);

	void push(T item, unsigned int priority);

public:
	T getValue();
	unsigned int getPriority();
	unsigned int getHeight();

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
inline void NodeTreeAVL<T>::push(T item, unsigned int priority)
{

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

template<typename T>
inline unsigned int NodeTreeAVL<T>::getHeight()
{
	return height;
}
