/*! Represents Heap binary tree
* \file Heap.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 26/09/20
*/

#ifndef HEAP_HPP
#define HEAP_HPP

#include "../PriorQueue.hpp"
#include "../NodePriority.hpp"

#include <vector>

template<typename T>
class Heap : public PriorQueue<T>
{
	/*! Array of elements.*/
	std::vector<NodePriority<T>> elements;

	/*! Makes a subheap with given root and given index.
	* \param[in] index Index of the needed root.
	*/
	void makeHeap(int index);

	/*! Calculates index of the parent node.
	* \param[in] index Index of the current node.
	* \returns Index of the parent node.
	*/
	int getParentIndex(int index);

	/*! Calculates index of left child node.
	* \param[in] index Index of the current node.
	* \returns Index of the child node.
	*/
	int getLeftChildIndex(int index);

	/*! Calculates index of right child node.
	* \param[in] index Index of the current node.
	* \returns Index of the child node.
	*/
	int getRightChildIndex(int index);

	/*! Extracts root.
	* Extracts maximum priority value from queue.
	* \returns Value with maximum priority.
	*/
	T extractRoot();

	/*! Sets priority of element at index.
	* Decreases value of priority at index to new priority.  
	* It is assumed that new priority is smaller than old one.
	* \param[in] index Index for decreasing.
	* \param[in] newPriority New priority of the element.
	*/
	void decreaseKey(int index, int newPriority);

	/*! Returns highest priority.
	* \returns the highest priority value (just priority, not value).
	*/
	int getFirst();

	/*! Deletes element on index
	* \param index Index to delete.
	*/
	void deleteElement(int index);

	/*! Add new value
	* \param value Value to insert.
	* \param priority Priority of value.
	*/
	void insertNode(T value, int priority);

public:

	/*! Constructor*/
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


/*PRIVATE*/

template<typename T>
inline Heap<T>::Heap()
{
}

template<typename T>
inline void Heap<T>::makeHeap(int index)
{
	int l = getLeftChildIndex(index);
	int r = getRightChildIndex(index);
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
inline int Heap<T>::getParentIndex(int index)
{
	return (index - 1) / 2;
}

template<typename T>
inline int Heap<T>::getLeftChildIndex(int index)
{
	return (2 * index + 1);
}

template<typename T>
inline int Heap<T>::getRightChildIndex(int index)
{
	return (2 * index + 2);
}

template<typename T>
inline T Heap<T>::extractRoot()
{
	if (elements.size() <= 0)
	{
		return T();
	}
	else
	if (elements.size() == 1)
	{
		NodePriority<T> node = elements.back();
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
inline void Heap<T>::decreaseKey(int index, int new_priority)
{
	elements[index].priority = new_priority;
	while (
		index != 0 && 
		elements[getParentIndex(index)].priority > elements[index].priority)
	{
		std::swap(elements[index], elements[getParentIndex(index)]);
		index = getParentIndex(index);
	}
}

template<typename T>
inline int Heap<T>::getFirst()
{
	return elements[0].priority;
}

template<typename T>
inline void Heap<T>::deleteElement(int i)
{
	decreaseKey(i, INT_MIN);
	extractRoot();
}

template<typename T>
inline void Heap<T>::insertNode(T value, int priority)
{
	// First insert the new key at the end 
	elements.push_back(NodePriority<T>(value, priority));

	// Fix the heap property if it is violated
	int index = elements.size() - 1;
	while (
		index != 0 &&
		elements[getParentIndex(index)].priority > elements[index].priority)
	{
		std::swap(elements[index], elements[getParentIndex(index)]);
		index = getParentIndex(index);
	}
}

/*PUBLIC*/

template<typename T>
inline void Heap<T>::push(T value, unsigned int priority)
{
	insertNode(value, priority);
}

template<typename T>
inline T Heap<T>::pop()
{
	return extractRoot();
}

template<typename T>
inline T Heap<T>::predict()
{
	return getFirst();
}

template<typename T>
inline std::string Heap<T>::print()
{
	std::string result;
	for (int i = 0; i < elements.size(); ++i)
		result += std::to_string(elements[i].value) + " ";
	return result;
}

#endif // !HEAP_HPP
