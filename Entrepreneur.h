#pragma once
#include "standart.h"
#include "Human.h"

/*__________класс препринимателя__________*/
class Entrepreneur : virtual public Human
{
protected:

	int _number_of_license; //номер лицензии
	Address _address;       //адрес регистрации
	Dues _dues[size_4];     //данные о налогах

public:

	/*__________конструктор с/без параметрами__________*/
	Entrepreneur(const char* name = "", const char* second_name = "", int year = 0,
		int number_of_license = 0, Address* address = 0, Dues dues[size_4] = 0) :
		Human(name, second_name, year), _number_of_license(number_of_license)
	{
		
		if (address)_address = *address;
		if (dues)
			for (int i = 0; i < size_4; ++i)
				this->_dues[i] = dues[i];
	}

	/*__________конструктор копирования__________*/
	Entrepreneur(const Entrepreneur& T) : Human(dynamic_cast<const Human&>(T)),
		_number_of_license(T._number_of_license)
		, _address(T._address)
	{
		for (int i = 0; i < size_4; ++i)
			this->_dues[i] = T._dues[i];
	}

	/*__________деструктор__________*/
	virtual ~Entrepreneur() {}

	/*__________перегрузка оператора присваивания__________*/
	Entrepreneur operator=(const Entrepreneur& T);

	/*__________установка номера паспорта__________*/
	void set_number_of_license(int number_of_license);

	/*__________установка информации о налогах__________*/
	void set_data_dues(int pos, Dues data);

	/*__________установка адреса__________*/
	void set_address(Address address);

	/*__________получение номера паспорта__________*/
	int& get_number_of_license();

	/*__________получение информации о налогах__________*/
	Dues& get_data_dues(int pos);

	/*__________получение адреса__________*/
	Address& get_address();

	/*__________добавление информации о налогах__________*/
	void add_data_dues(Dues data);
	
	/*__________перегрузка вывода__________*/
	friend std::ostream& operator<<(std::ostream& out, const Entrepreneur& T);
    
	/*__________перегрузка ввода__________*/
	friend std::istream& operator>>(std::istream& is, Entrepreneur& T);

	/*__________перегрузка вывода в файл__________*/
	friend std::ofstream& operator<<(std::ofstream& out, const Entrepreneur& T);

	/*__________перегрузка чтения из файла__________*/
	friend std::ifstream& operator>>(std::ifstream& is, Entrepreneur& T);

	/*__________перегрузка вывода в бинарного файла__________*/
	friend std::fstream& operator<<(std::fstream& out, Entrepreneur& T);

	/*__________перегрузка чтения из бинарного файла__________*/
	friend std::fstream& operator>>(std::fstream& is, Entrepreneur& T);

	/*__________таблица для вывода__________*/
	virtual void table() const;

	/*__________перегрузка оператора сравнения__________*/
	bool operator==(const Entrepreneur& T);

	/*__________функция меню для поиска__________*/
	Entrepreneur menu_for_poisk();

	/*__________копирование одного поля__________*/
	Entrepreneur copy_place(int place);
};

/*__________функция меню для редактирования__________*/
Queue<Entrepreneur> menu_correct(Queue<Entrepreneur> mas, int size);
