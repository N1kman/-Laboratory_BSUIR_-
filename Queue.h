#pragma once
#include "Input_error.h"
#include "File_error.h"
#include "Container_error.h"
#include "Standart.h"

/*__________структура для класса очереди__________*/
template <typename T>
struct part_queue
{
	T _information{};                   //информация
	part_queue<T>* _last = nullptr;        //указатель на предыдущий элемент
	part_queue<T>* _next = nullptr;        //указaтель на следующий элемент
};

/*__________класс двунаправленной очереди__________*/
template <typename T>
class Queue
{
private:
	
	size_t _size = 0;                    //количество элементов в очереди
	part_queue<T>* _head = nullptr;         //указатель на голову
	part_queue<T>* _tail = nullptr;         //указaтель на хвост

public:

	/*__________класс итератора__________*/
	class Iter
	{

	private:

		part_queue<T>* _current;
		part_queue<T>* _head;

	public:

		/*__________конструктор с параметром__________*/
		Iter(part_queue<T>* current) :_current(current)
		{
			if (current)
				while (current->_last)current = current->_last;
			_head = current;
		}

		/*__________деструктор__________*/
		~Iter() {}

		/*__________постинкремент__________*/
		Iter operator++(int);

		/*__________инкремент__________*/
		Iter operator++();

		/*__________постдекремент__________*/
		Iter operator--(int);

		/*__________декремент__________*/
		Iter operator--();

		/*__________разыменовывание__________*/
		T& operator*();

		/*__________оператор не равно__________*/
		bool operator!=(const Iter& it);

		/*__________оператор не равно__________*/
		bool operator==(const Iter& it);

		/*__________оператор сложения__________*/
		Iter operator+(int col);

		/*__________оператор вычитания__________*/
		Iter operator-(int col);

		/*__________оператор сложения__________*/
		void operator+=(int col);

		/*__________оператор вычитания__________*/
		void operator-=(int col);

		/*__________оператор вычитания итераторов__________*/
		int operator-(Iter& it);

	};

	Iter begin()
	{
		return _head;
	}

	Iter end()
	{
		return _tail->_next;
	}

	/*__________конструктор с параметром__________*/
	Queue<T>(T info) :_size(1)
	{
		part_queue<T>* buff = new part_queue; //выделение памяти
		buff->_information = info;
		_head = _tail = buff;
		buff->_last = nullptr;                   //зануления указателя на предыдущий элемент
		buff->_next = nullptr;                   //зануления указателя на следующий элемент
	}

	/*__________конструктор по умолчанию__________*/
	Queue<T>() : _head(nullptr), _tail(nullptr), _size(0) {}

	/*__________деструктор__________*/
	~Queue<T>()
	{
		this->clear();
	}

	/*__________конструктор копирования__________*/
	Queue<T>(const Queue<T>& buff)
	{
		part_queue<T>* point = buff._head;
		for (size_t i = 0; i < buff._size; ++i, point = point->_next)
			this->push_back(point->_information);
	}

	/*__________перегрузка оператора присваивания__________*/
	Queue<T> operator=(const Queue<T>&);

	/*__________перегрузка оператора []__________*/
	T& operator[](size_t pos);          

	/*__________функция добaвления элемента очереди(в голову)__________*/
	void push_front(T information);	    

	/*__________функция добaвления элемента очереди(в хвост)__________*/
	void push_back(T information);      

	/*__________функция удаления с головы__________*/
	void pop_front();               	

	/*__________функция удаления с хвоста__________*/
	void pop_back();                    

	/*__________функция удаления с хвоста c возвратом__________*/
	T pop_back_ret();	                

	/*__________функция добaвления элемента по индексу__________*/
	void push_any(T, size_t);           

	/*__________функция удаления элемента по индексу__________*/
	void pop_any(size_t);               

	/*__________полная очистка очереди__________*/
	void clear();	                    

	/*__________получение количества элементов в очереди__________*/
	int size();	                        

	/*__________проверка пуста ли очередь__________*/
	bool empty();	                    

	/*__________получение пустого экземпляра обьекта в очереди__________*/
	T get_example_zero();               

	/*__________вывод__________*/
	void show(size_t choice);                     

};

