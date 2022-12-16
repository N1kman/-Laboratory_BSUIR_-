#pragma once
#include "Queue.cpp"

template <class T>
class Algos
{
public:

	/*__________метод поиска__________*/
	typename Queue<T>::Iter poisk(typename Queue<T>::Iter, typename Queue<T>::Iter, T);

	/*__________метод сортировки__________*/
	void sort(typename Queue<T>::Iter begin, typename Queue<T>::Iter end, bool (*func)(T& ob1, T& ob2), int);

	/*__________метод поиска минимального элемента__________*/
	typename Queue<T>::Iter FindMin(typename Queue<T>::Iter begin, typename Queue<T>::Iter end, bool (*func)(T& ob1, T& ob2), int);

	/*__________метод перестановки__________*/
	void swap(typename Queue<T>::Iter iter1, typename Queue<T>::Iter iter2);
};

