/*! Represents Heap binary tree
* \file Heap.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 26/09/20
*/

#ifndef HEAP_HPP
#define HEAP_HPP

#include "../PriorQueue.hpp"
#include "NodeHeap.hpp"

#include <vector>

template<typename T>
class Heap : public PriorQueue<T>
{
	/*! Array of elements.*/
	std::vector<NodeHeap<T>> elements;

public:
	Heap();
	void makeHeap(int index);


	int parent(int i) { return (i - 1) / 2; }

	// to get index of left child of node at index i 
	int left(int i) { return (2 * i + 1); }

	// to get index of right child of node at index i 
	int right(int i) { return (2 * i + 2); }

	// to extract the root which is the minimum element 
	T extractMin();

	// Decreases key value of key at index i to new_val 
	void decreaseKey(int i, T new_val);

	// Returns the minimum key (key at root) from min heap 
	int getMin() { return elements[0].priority; }

	// Deletes a key stored at index i 
	void deleteKey(int i);

	// Inserts a new key 'k' 
	void insertKey(T value, int priority);


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

#endif // !HEAP_HPP


template<typename T>
inline Heap<T>::Heap()
{
}

template<typename T>
inline void Heap<T>::makeHeap(int index)
{
	int l = left(index);
	int r = right(index);
	int smallest = index;

	if (l < elements.size() && 
		elements[l].priority < elements[index].priority)
		smallest = l;

	if (r < elements.size() &&
		elements[r].priority < elements[smallest].priority)
		smallest = r;

	if (smallest != index)
	{
		std::swap(elements[index], elements[smallest]); 
		makeHeap(smallest);
	}
}

template<typename T>
inline T Heap<T>::extractMin()
{
	if (elements.size() <= 0)
	{
		return T();
	}
	else
	if (elements.size() == 1)
	{
		NodeHeap<T> node = elements.back();
		elements.pop_back();
		return node.value;
	}
	else
	{
		// Store the minimum value, and remove it from heap 
		T value = elements[0].value;
		elements[0] = elements[elements.size() - 1];
		elements.erase(elements.end() - 1, elements.end());
		makeHeap(0);
		return value;
	}
}

template<typename T>
inline void Heap<T>::decreaseKey(int index, T new_val)
{
	elements[index] = new_val;
	while (
		index != 0 && 
		elements[parent(index)] > elements[index])
	{
		std::swap(elements[index], elements[parent(index)]);
		index = parent(index);
	}
}

template<typename T>
inline void Heap<T>::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
}

template<typename T>
inline void Heap<T>::insertKey(T value, int priority)
{
	// First insert the new key at the end 
	elements.push_back(NodeHeap<T>(value, priority));

	// Fix the heap property if it is violated
	int index = elements.size() - 1;
	while (
		index != 0 &&
		elements[parent(index)].priority > elements[index].priority)
	{
		std::swap(elements[index], elements[parent(index)]);
		index = parent(index);
	}
}

/*PUBLIC*/

template<typename T>
inline void Heap<T>::push(T value, unsigned int priority)
{
	insertKey(value, priority);
}

template<typename T>
inline T Heap<T>::pop()
{
	return extractMin();
}

template<typename T>
inline T Heap<T>::predict()
{
	return getMin();
}

template<typename T>
inline std::string Heap<T>::print()
{
	return std::string();
}
