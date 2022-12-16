#pragma once
#include "standart.h"
#include "Human.h"

/*__________����� �������__________*/
class Tourist :virtual public Human
{
protected:

	char _number_of_pasport[size_9];  //����� ��������
	Data_border _data[size_4];        //������ ����������� �������

public:

	/*__________����������� �/��� �����������__________*/
	Tourist(const char* name = "-", const char* second_name = "-", int year = 0,
		const char* number_of_pasport = "-", Data_border data[size_4] = {}) :
		Human(name, second_name, year)
	{
		strcpy_s(_number_of_pasport, number_of_pasport);
		if (data)
			for (int i = 0; i < size_4; ++i)
				this->_data[i] = data[i];
	}

	/*__________����������� �����������__________*/
	Tourist(const Tourist& T) :Human(dynamic_cast<const Human&>(T))
	{
		strcpy_s(_number_of_pasport, T._number_of_pasport);
		for (int i = 0; i < size_4; ++i)
			this->_data[i] = T._data[i];
	}

	/*__________����������__________*/
	virtual ~Tourist() {}

	/*__________���������� ��������� ������������__________*/
	Tourist operator=(const Tourist& T);

	/*__________��������� ������ ��������__________*/
	char* get_number_of_pasport();

	/*__________��������� ���������� � ����������� �������__________*/
	Data_border& get_data_border(int pos);

	/*__________��������� ������ ��������__________*/
	void set_number_of_pasport(const char* number_of_pasport);

	/*__________��������� ���������� � ����������� �������__________*/
	void set_data_border(int pos, Data_border data);

	/*__________���������� ���������� � ����������� �������__________*/
	void add_data_border(Data_border data);

	/*__________���������� ����� __________*/
	friend std::istream& operator>>(std::istream& is, Tourist& T);
	
	/*__________���������� ������__________*/
	friend std::ostream& operator<<(std::ostream& out, const Tourist& T);

	/*__________���������� ������ � ����__________*/
	friend std::ofstream& operator<<(std::ofstream& out, const Tourist& T);

	/*__________���������� ������ �� �����__________*/
	friend std::ifstream& operator>>(std::ifstream& is, Tourist& T);

	/*__________���������� ������ � ��������� �����__________*/
	friend std::fstream& operator<<(std::fstream& out, Tourist& T);

	/*__________���������� ������ �� ��������� �����__________*/
	friend std::fstream& operator>>(std::fstream& is, Tourist& T);

	/*__________������� ��� ������__________*/
	virtual void table() const;

	/*__________���������� ��������� ���������__________*/
	bool operator==(const Tourist& T);

	/*__________������� ���� ��� ������__________*/
	Tourist menu_for_poisk();

	/*__________����������� ������ ����__________*/
	Tourist copy_place(int place);
};

/*__________������� ����__________*/
Queue<Tourist> menu_correct(Queue<Tourist> mas, int size);
