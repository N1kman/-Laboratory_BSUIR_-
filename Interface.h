#pragma once
#include "Businessman.h"
#include "Text_file.cpp"
#include "Binary_file.cpp"

/*__________класс интерфейс__________*/
template <class T>
class Interface
{
private:

	T nothing{};

public:

	/*__________конструктор__________*/
	Interface() {}

	/*__________деструктор__________*/
	~Interface() {}

	/*__________меню выбора объекта для работы__________*/
	void menu_choice();	          

	/*__________функциональное меню__________*/
	Queue<T> menu_func(Queue<T>, const char*, const char*);

	/*__________меню выбора объекта для работы__________*/
	void menu_choice_set();

	/*__________функциональное меню__________*/
	set<T> menu_func(set<T> obj);

	/*__________меню по выбору контейнера__________*/
	void menu();
};

