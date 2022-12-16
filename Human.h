#pragma once
#include "Input_error.h"
#include "File_error.h"
#include "Container_error.h"
#include "Standart.h"
#include "Algos.cpp"

/*__________класс человека__________*/
class Human
{
protected:

	char _name[_length_12];         //имя
	char _second_name[_length_12];  //фамилия
	int _year;                      //год рождения

public:

	/*__________конструктор с/без параметрами__________*/
	Human(const char* name = "-", const char* second_name = "-", int year = 0) :_year(year)
	{
		strcpy_s(_name, name);
		strcpy_s(_second_name, second_name);
	}

	/*__________конструктор копирования__________*/
	Human(const Human& T)
	{
		strcpy_s(_name, T._name);
		strcpy_s(_second_name, T._second_name);
		_year = T._year;
	}

	/*__________перегрузка оператора больше__________*/
	bool operator>(const Human& T);

	/*__________перегрузка оператора меньше__________*/
	bool operator<(const Human& T);

	/*__________деструктор__________*/
	virtual ~Human() = 0;

	/*__________установка имени__________*/
	void set_name(const char* name = "");

	/*__________установка фамилии__________*/
	void set_second_name(const char* second_name = "");

	/*__________установка года__________*/
	void set_year(int year = 0);

	/*__________получение года__________*/
	int& get_year();

	/*__________получение имени__________*/
	char* get_name();

	/*__________получение фамилии__________*/
	char* get_second_name();

	/*__________перегрузка вывода__________*/
	friend std::ostream& operator<<(std::ostream& out, const Human& T);

	/*__________перегрузка ввода__________*/
	friend std::istream& operator>>(std::istream& is, Human& T);

	/*__________перегрузка вывода в файл__________*/
	friend std::ofstream& operator<<(std::ofstream& out, const Human& T);

	/*__________перегрузка чтения из файла__________*/
	friend std::ifstream& operator>>(std::ifstream& is, Human& T);

	/*__________перегрузка вывода в бинарного файла__________*/
	friend std::fstream& operator<<(std::fstream& out, Human& T);

	/*__________перегрузка чтения из бинарного файла__________*/
	friend std::fstream& operator>>(std::fstream& is, Human& T);

	/*__________таблица для вывода__________*/
	virtual void table() const;

	/*__________меню сортировки__________*/
	virtual int menu_sort();

	/*__________перегрузка оператора меньше__________*/
	friend bool operator<(const Human& T1, const Human& T2);

};

