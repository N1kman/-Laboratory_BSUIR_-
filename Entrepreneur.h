#pragma once
#include "standart.h"
#include "Human.h"

/*__________����� ��������������__________*/
class Entrepreneur : virtual public Human
{
protected:

	int _number_of_license; //����� ��������
	Address _address;       //����� �����������
	Dues _dues[size_4];     //������ � �������

public:

	/*__________����������� �/��� �����������__________*/
	Entrepreneur(const char* name = "", const char* second_name = "", int year = 0,
		int number_of_license = 0, Address* address = 0, Dues dues[size_4] = 0) :
		Human(name, second_name, year), _number_of_license(number_of_license)
	{
		
		if (address)_address = *address;
		if (dues)
			for (int i = 0; i < size_4; ++i)
				this->_dues[i] = dues[i];
	}

	/*__________����������� �����������__________*/
	Entrepreneur(const Entrepreneur& T) : Human(dynamic_cast<const Human&>(T)),
		_number_of_license(T._number_of_license)
		, _address(T._address)
	{
		for (int i = 0; i < size_4; ++i)
			this->_dues[i] = T._dues[i];
	}

	/*__________����������__________*/
	virtual ~Entrepreneur() {}

	/*__________���������� ��������� ������������__________*/
	Entrepreneur operator=(const Entrepreneur& T);

	/*__________��������� ������ ��������__________*/
	void set_number_of_license(int number_of_license);

	/*__________��������� ���������� � �������__________*/
	void set_data_dues(int pos, Dues data);

	/*__________��������� ������__________*/
	void set_address(Address address);

	/*__________��������� ������ ��������__________*/
	int& get_number_of_license();

	/*__________��������� ���������� � �������__________*/
	Dues& get_data_dues(int pos);

	/*__________��������� ������__________*/
	Address& get_address();

	/*__________���������� ���������� � �������__________*/
	void add_data_dues(Dues data);
	
	/*__________���������� ������__________*/
	friend std::ostream& operator<<(std::ostream& out, const Entrepreneur& T);
    
	/*__________���������� �����__________*/
	friend std::istream& operator>>(std::istream& is, Entrepreneur& T);

	/*__________���������� ������ � ����__________*/
	friend std::ofstream& operator<<(std::ofstream& out, const Entrepreneur& T);

	/*__________���������� ������ �� �����__________*/
	friend std::ifstream& operator>>(std::ifstream& is, Entrepreneur& T);

	/*__________���������� ������ � ��������� �����__________*/
	friend std::fstream& operator<<(std::fstream& out, Entrepreneur& T);

	/*__________���������� ������ �� ��������� �����__________*/
	friend std::fstream& operator>>(std::fstream& is, Entrepreneur& T);

	/*__________������� ��� ������__________*/
	virtual void table() const;

	/*__________���������� ��������� ���������__________*/
	bool operator==(const Entrepreneur& T);

	/*__________������� ���� ��� ������__________*/
	Entrepreneur menu_for_poisk();

	/*__________����������� ������ ����__________*/
	Entrepreneur copy_place(int place);
};

/*__________������� ���� ��� ��������������__________*/
Queue<Entrepreneur> menu_correct(Queue<Entrepreneur> mas, int size);
