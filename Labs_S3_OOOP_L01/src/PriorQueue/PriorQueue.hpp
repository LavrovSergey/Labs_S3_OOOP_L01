/*! Queue with priority base class.
* \file PriorQueue.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 25/09/20
*/

#ifndef PRIOR_QUEUE_HPP
#define PRIOR_QUEUE_HPP

#include <string>

template <typename T>
class PriorQueue
{
public:
	/*! Constructor.*/
	virtual PriorQueue();

	/*! Destructor.*/
	virtual ~PriorQueue();

	/*! Pushes item with priority to queue and puts it on right position.
	* \param item Value to store.
	* \param priority Priority of item.
	*/
	virtual void push(T item, unsigned int priority);

	/*! Gets element from queue with highest priority, removes it from queue and shifts queue.
	* \returns Value that stored.
	*/
	virtual T pop();

	/*! Gets element from queue with highest priority, DOESN'T remove it from queue.
	* \returns Value that stored.
	*/
	virtual T predict();

	/*! Prints queue to string in format that matches type of container (list, tree, etc).
	* \returns Queued structure in the string form.
	*/
	virtual std::string print();
};

template<typename T>
inline PriorQueue<T>::PriorQueue()
{
}

template<typename T>
inline PriorQueue<T>::~PriorQueue()
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

template<typename T>
inline std::string PriorQueue<T>::print()
{
	return std::string();
}


#endif // !PRIOR_QUEUE_HPP


