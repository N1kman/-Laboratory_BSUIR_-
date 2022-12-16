#pragma once
#include "Queue.h"

/*__________функция добaвления элемента очереди(в хвост)__________*/
template <typename T>
void Queue<T>::push_back(T information)
{
	part_queue<T>* buff = new part_queue<T>; //выделение памяти
	buff->_information = information;
	_size++;

	if (!_head or !_tail)
	{
		_head = _tail = buff;
		buff->_last = nullptr;           //зануления указателя на предыдущий элемент
		buff->_next = nullptr;           //зануления указателя на следующий элемент
	}
	else
	{
		buff->_next = nullptr;            //зануления указателя на следующий элемент
		buff->_last = _tail;              //указание на предыдущий элемент
		_tail->_next = buff;              //указание на следующий
		_tail = buff;                     //новый хвост
	}
	
}

/*__________функция добaвления элемента очереди(в голову)__________*/
template <typename T>
void Queue<T>::push_front(T information)
{
	part_queue<T>* buff = new part_queue<T>; //выделение памяти
	buff->_information = information;
	_size++;

	if (!_head or !_tail)
	{
		_head = _tail = buff;
		buff->_last = nullptr;           //зануления указателя на предыдущий элемент
		buff->_next = nullptr;           //зануления указателя на следующий элемент
	}
	else
	{
		buff->_next = _head;              //указываем на следующий
		buff->_last = nullptr;            //зануления указателя на предыдущий элемент
		_head->_last = buff;              //указание на следующий
		_head = buff;                     //новый хвост
	}

}

/*__________функция удаления с хвоста__________*/
template <typename T>
void Queue<T>::pop_back()
{
	try
	{
		if (!_head or !_tail)
		{
			throw Container_error(6, "Очередь пуста", 
				"Возможно выхотели выполнить другое действие");
		}
		else
		{
			_size--;
			if (_tail->_last == nullptr)
			{
				delete _tail;               //очистка
				_tail = _head = nullptr;    //зануление
			}
			else
			{
				part_queue<T>* buff = _tail;
				_tail = _tail->_last;       //новый хвост
				_tail->_next = nullptr;     //зануление
				delete buff;                //очистка
			}
		}
	}
	catch (Container_error obj)
	{
		obj.show_e();
	}
}

/*__________функция удаления с хвоста c возвратом__________*/
template <typename T>
T Queue<T>::pop_back_ret()
{
	T ret;
	try
	{
		if (!_head or !_tail)
		{
			throw Container_error(6, "Очередь пуста", "Возможно выхотели выполнить другое действие");
		}
		else
		{
			_size--;
			if (_tail->_last == nullptr)
			{
				ret = _tail->_information;
				delete _tail;               //очистка
				_tail = _head = nullptr;    //зануление
			}
			else
			{
				part_queue<T>* buff = _tail;
				_tail = _tail->_last;       //новый хвост
				_tail->_next = nullptr;     //зануление
				ret = buff->_information;
				delete buff;                //очистка
			}
		}
	}
	catch (Container_error obj)
	{
		obj.show_e();
	}

	return ret;
}

/*__________функция удаления с головы__________*/
template <typename T>
void Queue<T>::pop_front()
{
	try
	{
		if (!_head or !_tail)
		{
			throw Container_error(6, "Очередь пуста", "Возможно выхотели выполнить другое действие");
		}
		else
		{
			_size--;
			if (_tail->_last == nullptr)
			{
				delete _tail;               //очистка
				_tail = _head = nullptr;    //зануление
			}
			else
			{
				part_queue<T>* buff = _head;
				_head = _head->_next;       //новая голова
				_head->_last = nullptr;     //зануление
				delete buff;                //очистка
			}
		}
	}
	catch (Container_error obj)
	{
		obj.show_e();
	}
}

/*__________полная очистка очереди__________*/
template <typename T>
void Queue<T>::clear()
{
	while (_head or _tail)this->pop_back();
}

/*__________вывод__________*/
template <typename T>
void Queue<T>::show(size_t choice)
{
	try
	{
		if (!_head or !_tail)
		{
			throw Container_error(6, "Очередь пуста", "Возможно выхотели выполнить другое действие");
		}
		else
		{
			part_queue<T>* point;
			if (!choice)point = _head;                        //продвижение от головы
			else point = _tail;                               //продвижение от хвоста
			do
			{
				cout << point->_information;
				if (!choice)point = point->_next;              //продвижение от головы
				else point = point->_last;                     //продвижение от хвоста
			} while (point);
		}
	}
	catch (Container_error obj)
	{
		obj.show_e();
	}
}

/*__________получение количества элементов в очереди__________*/
template <typename T>
int Queue<T>::size()
{
	return _size;
}


/*__________получение пустого экземпляра обьекта в очереди__________*/
template <typename T>
T Queue<T>::get_example_zero()
{
	T obj{};
	return obj;
}

/*__________перегрузка оператора []__________*/
template <typename T>
T& Queue<T>::operator[](size_t pos)
{
	try
	{
		if (pos >= _size or pos < 0)
			throw Container_error(7, "Выход за границы контейнера", 
				"Возможно вы хотели выбрать другую позицию(возвращен пустой объект)");
		part_queue<T>* point = _head;
		while (pos and point->_next)
		{
			point = point->_next;
			pos--;
		}
		return point->_information;
	}
	catch (Container_error obj)
	{
		obj.show_e();
		T* ret = new T;
		return *ret;
	}
}

/*__________перегрузка оператора присваивания__________*/
template <typename T>
Queue<T> Queue<T>::operator=(const Queue<T>& buff)
{
	if (this != &buff)
	{
		this->clear();
		part_queue<T>* point = buff._head;
		for (size_t i = 0; i < buff._size; ++i, point = point->_next)
			this->push_back(point->_information);
	}
	return *this;
}

/*__________проверка пуста ли очередь__________*/
template <typename T>
bool Queue<T>::empty()
{
	if (_size)
		return false;
	else return true;
}

/*__________метод добaвления элемента по индексу__________*/
template <typename T>
void Queue<T>::push_any(T information, size_t index)
{
	try
	{
		if (index > _size or index < 0)
			throw Container_error(7, "Выход за границы контейнера", 
				"Возможно вы хотели выбрать другую позицию");
		else
		{
			if (!_size or _size == index)
			{
				this->push_back(information);
			}
			else
				if (index == 0)
				{
					this->push_front(information);
				}
				else
				{
					part_queue<T>* buff = new part_queue<T>; //выделение памяти
					buff->_information = information;
					_size++;
					part_queue<T>* point = _head;
					while (index--)point = point->_next;
					point->_last->_next = buff;
					buff->_last = point->_last;
					buff->_next = point;
					point->_last = buff;
				}
		}
	}
	catch (Container_error obj)
	{
		obj.show_e();
	}
}

/*__________метод удаления элемента по индексу__________*/
template <typename T>
void Queue<T>::pop_any(size_t index)
{
	try
	{
		if (index >= _size or index < 0)
			throw Container_error(7, "Выход за границы контейнера",
				"Возможно вы хотели выбрать другую позицию");
		else
		{
			if (!_size)
			{
				throw Container_error(6, "Очередь пуста", 
					"Возможно выхотели выполнить другое действие");
			}
			else
				if (_size == index)
				{
					this->pop_back();
				}
				else
					if (index == 0)
					{
						this->pop_front();
					}
					else
					{
						_size--;
						part_queue<T>* point = _head;
						while (index--)point = point->_next;
						point->_last->_next = point->_next;
						point->_next->_last = point->_last;
						delete point;
					}
		}
	}
	catch (Container_error obj)
	{
		obj.show_e();
	}
}

/*__________постинкремент __________*/
template <typename T>
typename Queue<T>::Iter Queue<T>::Iter::operator++(int)
{
	part_queue<T>* buff = _current;
	if (!_current)
	{
		_current = _head;
		return nullptr;
	}
	else
	{
		_current = _current->_next;
		return buff;
	}
}

/*__________инкремент __________*/
template <typename T>
typename Queue<T>::Iter Queue<T>::Iter::operator++()
{
	if (!_current)
	{
		_current = _head;
		return _current;
	}
	else
	{
		_current = _current->_next;
		return _current;
	}
}

/*__________постдекремент __________*/
template <typename T>
typename Queue<T>::Iter Queue<T>::Iter::operator--(int)
{
	part_queue<T>* buff = _current;
	if (!(_current->_last))
	{
		while (_current->_next)_current = _current->_next;
		return _head;
	}
	else
	{
		_current = _current->_last;
		return buff;
	}
}

/*__________декремент __________*/
template <typename T>
typename Queue<T>::Iter Queue<T>::Iter::operator--()
{
	if (!(_current->_last))
	{
		while (_current->_next)_current = _current->_next;
		return _current;
	}
	else
	{
		_current = _current->_last;
		return _current;
	}
}

/*__________разыменовывание__________*/
template <typename T>
T& Queue<T>::Iter::operator*()
{
	if (!_current)
		return _head->_information;
	else
		return _current->_information;
}

/*__________оператор не равно__________*/
template <typename T>
bool Queue<T>::Iter::operator!=(const typename Queue<T>::Iter& it)
{
	if (this->_current != it._current)
		return true;
	else
		return false;
}

/*__________оператор не равно__________*/
template <typename T>
bool Queue<T>::Iter::operator==(const typename Queue<T>::Iter& it)
{
	if (this->_current != it._current)
		return false;
	else
		return true;
}

/*__________оператор сложения__________*/
template <typename T>
typename Queue<T>::Iter Queue<T>::Iter::operator+(int col)
{
	for (int i = 0; i < col; ++i)
	{
		if (!_current)
			_current = _head;
		else
			_current = _current->_next;
	}
	return _current;
}

/*__________оператор вычитания__________*/
template <typename T>
typename Queue<T>::Iter Queue<T>::Iter::operator-(int col)
{
	for (int i = 0; i < col; ++i)
	{
		if (!(_current->_last))
			while (_current->_next)_current = _current->_next;
		else
			_current = _current->_last;
	}
	return _current;
}

/*__________оператор сложения__________*/
template <typename T>
void Queue<T>::Iter::operator+=(int col)
{
	for (int i = 0; i < col; ++i)
	{
		if (!_current)
			_current = _head;
		else
			_current = _current->_next;
	}
}

/*__________оператор вычитания__________*/
template <typename T>
void Queue<T>::Iter::operator-=(int col)
{
	for (int i = 0; i < col; ++i)
	{
		if (!(_current->_last))
			while (_current->_next)_current = _current->_next;
		else
			_current = _current->_last;
	}
}

/*__________оператор вычитания итераторов__________*/
template <typename T>
int Queue<T>::Iter::operator-(typename Queue<T>::Iter& it)
{
	//количество позиций между итераторами
	int pos = 0;  
	part_queue<T>* buff = _current;
	if (_current == it._current)
		return pos;
	else
	{
		//проход от позиции первого до второго
		while (buff)
		{
			if (buff == it._current)
				return pos;
			buff = buff->_next;
			pos++;
		};
		pos = 0;
		buff = it._current;
		//проход от позиции второго до первого
		while (buff)
		{
			if (buff == _current)
				return pos;
			buff = buff->_next;
			pos++;
		};
		return -1;
	}
}