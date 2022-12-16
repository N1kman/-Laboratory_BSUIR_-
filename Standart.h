#pragma once

#include <iostream>
#include <fstream>
#include <windows.h>
#include <iso646.h>
#include <iomanip>
#include <set>
#include <iterator>
#include <algorithm>

#define _length_80 81 
#define _length_12 13
#define size_9 10
#define size_4 4
#define num 3 

#define file1 "file1.txt"
#define file2 "file2.bin"
#define file11 "file11.txt"
#define file22 "file22.bin"
#define file111 "file111.txt"
#define file222 "file222.bin"

using namespace std;

/*__________структура даты__________*/
struct Date
{
	int day = 0;      //день
	int month = 0;    //мес€ц
	int year = 0;     //год

	bool operator==(const Date& T)
	{
		if (T.day != day)return false;
		if (T.month != month)return false;
		if (T.month != month)return false;
		return true;
	}

	//перегрузка вывода
	friend std::ostream& operator<<(std::ostream& out, const Date& T)
	{
		out << setfill('0')
			<< setw(2) << T.day << "."
			<< setw(2) << T.month << "."
			<< setw(4) << T.year;
		return out;
	}

	//перегрузка вывода файл
	friend std::ofstream& operator<<(std::ofstream& out, const Date& T)
	{
		out << right << setw(3) << T.day
			<< setw(3) << T.month
			<< setw(6) << T.year;
		return out;
	}

	/*__________перегрузка ввода__________*/
	friend std::istream& operator>>(std::istream& in, Date& T);

	/*__________перегрузка чтени€ из файла__________*/
	friend std::ifstream& operator>>(std::ifstream& in, Date& T);

};

/*__________структура данных о пересечении границы__________*/
struct Data_border
{
	Date date;                              //дата
	char country[_length_12] = "-";         //страна
};

/*__________структура адреса__________*/
struct Address
{
	char street[_length_12] = "-";    //улица
	int number = 0;                   //номер дома
};

/*__________структура информации о налогах__________*/
struct Dues
{
	Date date;                //дата
	int sum = 0;              //сумма
};

/*__________функци€ окончани€ программы__________*/
void end_program();

/*__________ввод русской строки__________*/
char* input_rus(istream& in, char*);

/*__________ввод английской строки__________*/
char* input_eng(istream& in, char*);

/*__________ввод целого числа__________*/
int input_int(istream& in, int _a, int _b);

/*__________ввод паспорта__________*/
char* input_pasport(istream& in, char*);

/*__________метод задани€ цвета тексту__________*/
void setColor(int color);

