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

/*__________��������� ����__________*/
struct Date
{
	int day = 0;      //����
	int month = 0;    //�����
	int year = 0;     //���

	bool operator==(const Date& T)
	{
		if (T.day != day)return false;
		if (T.month != month)return false;
		if (T.month != month)return false;
		return true;
	}

	//���������� ������
	friend std::ostream& operator<<(std::ostream& out, const Date& T)
	{
		out << setfill('0')
			<< setw(2) << T.day << "."
			<< setw(2) << T.month << "."
			<< setw(4) << T.year;
		return out;
	}

	//���������� ������ ����
	friend std::ofstream& operator<<(std::ofstream& out, const Date& T)
	{
		out << right << setw(3) << T.day
			<< setw(3) << T.month
			<< setw(6) << T.year;
		return out;
	}

	/*__________���������� �����__________*/
	friend std::istream& operator>>(std::istream& in, Date& T);

	/*__________���������� ������ �� �����__________*/
	friend std::ifstream& operator>>(std::ifstream& in, Date& T);

};

/*__________��������� ������ � ����������� �������__________*/
struct Data_border
{
	Date date;                              //����
	char country[_length_12] = "-";         //������
};

/*__________��������� ������__________*/
struct Address
{
	char street[_length_12] = "-";    //�����
	int number = 0;                   //����� ����
};

/*__________��������� ���������� � �������__________*/
struct Dues
{
	Date date;                //����
	int sum = 0;              //�����
};

/*__________������� ��������� ���������__________*/
void end_program();

/*__________���� ������� ������__________*/
char* input_rus(istream& in, char*);

/*__________���� ���������� ������__________*/
char* input_eng(istream& in, char*);

/*__________���� ������ �����__________*/
int input_int(istream& in, int _a, int _b);

/*__________���� ��������__________*/
char* input_pasport(istream& in, char*);

/*__________����� ������� ����� ������__________*/
void setColor(int color);

