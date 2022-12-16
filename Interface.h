#pragma once
#include "Businessman.h"
#include "Text_file.cpp"
#include "Binary_file.cpp"

/*__________����� ���������__________*/
template <class T>
class Interface
{
private:

	T nothing{};

public:

	/*__________�����������__________*/
	Interface() {}

	/*__________����������__________*/
	~Interface() {}

	/*__________���� ������ ������� ��� ������__________*/
	void menu_choice();	          

	/*__________�������������� ����__________*/
	Queue<T> menu_func(Queue<T>, const char*, const char*);

	/*__________���� ������ ������� ��� ������__________*/
	void menu_choice_set();

	/*__________�������������� ����__________*/
	set<T> menu_func(set<T> obj);

	/*__________���� �� ������ ����������__________*/
	void menu();
};

