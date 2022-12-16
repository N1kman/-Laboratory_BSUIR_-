#pragma once
#include "standart.h"
#include "Tourist.h"
#include "Entrepreneur.h"

/*__________класс бизнессмена__________*/
class Businessman :public Tourist, public Entrepreneur
{
protected:

	Address _addresses[size_4];       //адреса покупки товаров

public:

	/*__________конструктор с/без параметрами__________*/
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

	/*__________конструктор копирования__________*/
	Businessman(const Businessman& T) :Human(dynamic_cast<const Human&>(T)),
		Tourist(dynamic_cast<const Tourist&>(T)),
		Entrepreneur(dynamic_cast<const Entrepreneur&>(T))
	{
		for (int i = 0; i < size_4; ++i)
			this->_addresses[i] = T._addresses[i];
	}

	/*__________деструктор__________*/
	virtual ~Businessman() {}

	/*__________перегрузка оператора присваивания__________*/
	Businessman operator=(const Businessman& T);

	/*__________установка информации о адресе покупки товаров__________*/
	void set_addreses(int pos, Address data);

	/*__________получение информации о адресе покупки товаро_________*/
	Address& get_address(int pos);

	/*__________добавление информации о адресах закупок__________*/
	void add_data_addreses(Address dues);

	/*__________перегрузка вывода__________*/
	friend std::ostream& operator<<(std::ostream& out, const Businessman& T);

	/*__________перегрузка ввода __________*/
	friend std::istream& operator>>(std::istream& is, Businessman& T);

	/*__________перегрузка вывода в файл__________*/
	friend std::ofstream& operator<<(std::ofstream& out, const Businessman& T);

	/*__________перегрузка чтения из файла__________*/
	friend std::ifstream& operator>>(std::ifstream& is, Businessman& T);

	/*__________перегрузка вывода в бинарного файла__________*/
	friend std::fstream& operator<<(std::fstream& out, Businessman& T);

	/*__________перегрузка чтения из бинарного файла__________*/
	friend std::fstream& operator>>(std::fstream& is, Businessman& T);

	/*__________таблица для вывода__________*/
	virtual void table() const;

	/*__________перегрузка оператора сравнения__________*/
	bool operator==(const Businessman& T);

	/*__________функция меню для поиска__________*/
	Businessman menu_for_poisk();

	/*__________копирование одного поля__________*/
	Businessman copy_place(int place);
};

/*__________функция меню__________*/
Queue<Businessman> menu_correct(Queue<Businessman> mas, int size);
