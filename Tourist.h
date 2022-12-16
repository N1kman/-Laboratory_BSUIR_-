#pragma once
#include "standart.h"
#include "Human.h"

/*__________класс туриста__________*/
class Tourist :virtual public Human
{
protected:

	char _number_of_pasport[size_9];  //номер паспорта
	Data_border _data[size_4];        //данные пересечения границы

public:

	/*__________конструктор с/без параметрами__________*/
	Tourist(const char* name = "-", const char* second_name = "-", int year = 0,
		const char* number_of_pasport = "-", Data_border data[size_4] = {}) :
		Human(name, second_name, year)
	{
		strcpy_s(_number_of_pasport, number_of_pasport);
		if (data)
			for (int i = 0; i < size_4; ++i)
				this->_data[i] = data[i];
	}

	/*__________конструктор копирования__________*/
	Tourist(const Tourist& T) :Human(dynamic_cast<const Human&>(T))
	{
		strcpy_s(_number_of_pasport, T._number_of_pasport);
		for (int i = 0; i < size_4; ++i)
			this->_data[i] = T._data[i];
	}

	/*__________деструктор__________*/
	virtual ~Tourist() {}

	/*__________перегрузка оператора присваивания__________*/
	Tourist operator=(const Tourist& T);

	/*__________получение номера паспорта__________*/
	char* get_number_of_pasport();

	/*__________получение информации о пересечении границы__________*/
	Data_border& get_data_border(int pos);

	/*__________установка номера паспорта__________*/
	void set_number_of_pasport(const char* number_of_pasport);

	/*__________установка информации о пересечении границы__________*/
	void set_data_border(int pos, Data_border data);

	/*__________добавление информации о пересечении границы__________*/
	void add_data_border(Data_border data);

	/*__________перегрузка ввода __________*/
	friend std::istream& operator>>(std::istream& is, Tourist& T);
	
	/*__________перегрузка вывода__________*/
	friend std::ostream& operator<<(std::ostream& out, const Tourist& T);

	/*__________перегрузка вывода в файл__________*/
	friend std::ofstream& operator<<(std::ofstream& out, const Tourist& T);

	/*__________перегрузка чтения из файла__________*/
	friend std::ifstream& operator>>(std::ifstream& is, Tourist& T);

	/*__________перегрузка вывода в бинарного файла__________*/
	friend std::fstream& operator<<(std::fstream& out, Tourist& T);

	/*__________перегрузка чтения из бинарного файла__________*/
	friend std::fstream& operator>>(std::fstream& is, Tourist& T);

	/*__________таблица для вывода__________*/
	virtual void table() const;

	/*__________перегрузка оператора сравнения__________*/
	bool operator==(const Tourist& T);

	/*__________функция меню для поиска__________*/
	Tourist menu_for_poisk();

	/*__________копирование одного поля__________*/
	Tourist copy_place(int place);
};

/*__________функция меню__________*/
Queue<Tourist> menu_correct(Queue<Tourist> mas, int size);
