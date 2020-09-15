#pragma once

template <typename T>
class PriorQueue
{
public:
	//static PriorQueue fromTree();
	//static PriorQueue fromList();
	PriorQueue();
	virtual void push(T item, unsigned int priority);
	virtual T pop();
	virtual T predict();
};

template<typename T>
inline PriorQueue<T>::PriorQueue()
{
}

template<typename T>
inline void PriorQueue<T>::push(T item, unsigned int priority)
{
}

template<typename T>
inline T PriorQueue<T>::pop()
{
	return T();
}

template<typename T>
inline T PriorQueue<T>::predict()
{
	return T();
}
