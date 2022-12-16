#pragma once
#include "Input_error.h"
#include "File_error.h"
#include "Container_error.h"
#include "Standart.h"
#include "Algos.cpp"

/*__________����� ��������__________*/
class Human
{
protected:

	char _name[_length_12];         //���
	char _second_name[_length_12];  //�������
	int _year;                      //��� ��������

public:

	/*__________����������� �/��� �����������__________*/
	Human(const char* name = "-", const char* second_name = "-", int year = 0) :_year(year)
	{
		strcpy_s(_name, name);
		strcpy_s(_second_name, second_name);
	}

	/*__________����������� �����������__________*/
	Human(const Human& T)
	{
		strcpy_s(_name, T._name);
		strcpy_s(_second_name, T._second_name);
		_year = T._year;
	}

	/*__________���������� ��������� ������__________*/
	bool operator>(const Human& T);

	/*__________���������� ��������� ������__________*/
	bool operator<(const Human& T);

	/*__________����������__________*/
	virtual ~Human() = 0;

	/*__________��������� �����__________*/
	void set_name(const char* name = "");

	/*__________��������� �������__________*/
	void set_second_name(const char* second_name = "");

	/*__________��������� ����__________*/
	void set_year(int year = 0);

	/*__________��������� ����__________*/
	int& get_year();

	/*__________��������� �����__________*/
	char* get_name();

	/*__________��������� �������__________*/
	char* get_second_name();

	/*__________���������� ������__________*/
	friend std::ostream& operator<<(std::ostream& out, const Human& T);

	/*__________���������� �����__________*/
	friend std::istream& operator>>(std::istream& is, Human& T);

	/*__________���������� ������ � ����__________*/
	friend std::ofstream& operator<<(std::ofstream& out, const Human& T);

	/*__________���������� ������ �� �����__________*/
	friend std::ifstream& operator>>(std::ifstream& is, Human& T);

	/*__________���������� ������ � ��������� �����__________*/
	friend std::fstream& operator<<(std::fstream& out, Human& T);

	/*__________���������� ������ �� ��������� �����__________*/
	friend std::fstream& operator>>(std::fstream& is, Human& T);

	/*__________������� ��� ������__________*/
	virtual void table() const;

	/*__________���� ����������__________*/
	virtual int menu_sort();

	/*__________���������� ��������� ������__________*/
	friend bool operator<(const Human& T1, const Human& T2);

};

