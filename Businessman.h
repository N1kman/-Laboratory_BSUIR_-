#pragma once
#include "standart.h"
#include "Tourist.h"
#include "Entrepreneur.h"

/*__________����� �����������__________*/
class Businessman :public Tourist, public Entrepreneur
{
protected:

	Address _addresses[size_4];       //������ ������� �������

public:

	/*__________����������� �/��� �����������__________*/
	Businessman(const char* name = "-", const char* second_name = "-", int year = 0,
		const char* number_of_pasport = "-", Data_border data[size_4] = 0,
		int number_of_license = 0, Address* address = 0, Dues dues[size_4] = 0,
		Address addresses[size_4] = 0) :
		Human(name, second_name, year),
		Tourist(name, second_name, year, number_of_pasport, data),
		Entrepreneur(name, second_name, year, number_of_license, address, dues)
	{
		if (addresses)
			for (int i = 0; i < size_4; ++i)
				this->_addresses[i] = addresses[i];
	}

	/*__________����������� �����������__________*/
	Businessman(const Businessman& T) :Human(dynamic_cast<const Human&>(T)),
		Tourist(dynamic_cast<const Tourist&>(T)),
		Entrepreneur(dynamic_cast<const Entrepreneur&>(T))
	{
		for (int i = 0; i < size_4; ++i)
			this->_addresses[i] = T._addresses[i];
	}

	/*__________����������__________*/
	virtual ~Businessman() {}

	/*__________���������� ��������� ������������__________*/
	Businessman operator=(const Businessman& T);

	/*__________��������� ���������� � ������ ������� �������__________*/
	void set_addreses(int pos, Address data);

	/*__________��������� ���������� � ������ ������� ������_________*/
	Address& get_address(int pos);

	/*__________���������� ���������� � ������� �������__________*/
	void add_data_addreses(Address dues);

	/*__________���������� ������__________*/
	friend std::ostream& operator<<(std::ostream& out, const Businessman& T);

	/*__________���������� ����� __________*/
	friend std::istream& operator>>(std::istream& is, Businessman& T);

	/*__________���������� ������ � ����__________*/
	friend std::ofstream& operator<<(std::ofstream& out, const Businessman& T);

	/*__________���������� ������ �� �����__________*/
	friend std::ifstream& operator>>(std::ifstream& is, Businessman& T);

	/*__________���������� ������ � ��������� �����__________*/
	friend std::fstream& operator<<(std::fstream& out, Businessman& T);

	/*__________���������� ������ �� ��������� �����__________*/
	friend std::fstream& operator>>(std::fstream& is, Businessman& T);

	/*__________������� ��� ������__________*/
	virtual void table() const;

	/*__________���������� ��������� ���������__________*/
	bool operator==(const Businessman& T);

	/*__________������� ���� ��� ������__________*/
	Businessman menu_for_poisk();

	/*__________����������� ������ ����__________*/
	Businessman copy_place(int place);
};

/*__________������� ����__________*/
Queue<Businessman> menu_correct(Queue<Businessman> mas, int size);
