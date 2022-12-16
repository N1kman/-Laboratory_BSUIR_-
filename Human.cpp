#include "Human.h"

/*__________перегрузка оператора больше__________*/
bool Human::operator>(const Human& T)
{
	if (T._second_name[0] != '-')
		if (strcmp(_second_name, T._second_name) < 0)
			return false;
	
	if (T._name[0] != '-')
		if (strcmp(_name, T._name) < 0)
			return false;

	if (T._year)
		if (T._year < _year)
			return false;

	return true;
}

/*__________перегрузка оператора меньше__________*/
bool Human::operator<(const Human& T)
{
	if (T._second_name[0] != '-')
		if (strcmp(T._second_name, _second_name) < 0)
			return false;

	if (T._name[0] != '-')
		if (strcmp(T._name, _name) < 0)
			return false;

	if (T._year)
		if (T._year > _year)
			return false;

	return true;
}

/*__________перегрузка вывода в бинарного файла__________*/
std::fstream& operator<<(std::fstream& out, Human& T)
{
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._name), _length_12);
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._second_name), _length_12);
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._year), sizeof(int));
	return out;
}

/*__________перегрузка чтения из бинарного файла__________*/
std::fstream& operator>>(std::fstream& is, Human& T)
{
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._name), _length_12);
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._second_name), _length_12);
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._year), sizeof(int));
	return is;
}

/*__________перегрузка вывода в файл__________*/
std::ofstream& operator<<(std::ofstream& out, const Human& T)
{
	out << setfill(' ') << left << setw(13) << T._name << setw(13) << T._second_name;
	out << setw(6) << T._year;

	return out;
}

/*__________перегрузка чтения из файла__________*/
std::ifstream& operator>>(std::ifstream& is, Human& T)
{
	is >> T._name >> T._second_name
		>> T._year;

	return is;
}

/*__________перегрузка вывода__________*/
std::ostream& operator<<(std::ostream& out, const Human& T) 
{
	out.setf(ios::left);
	out << "|" << setfill(' ') << setw(13)
		<< T._name << "|" << setw(13) << T._second_name;
	out.unsetf(ios::left);
	out << "|" << setfill(' ') << setw(7) << T._year << " " << "|";
	
	return out;
}

/*__________перегрузка ввода__________*/
std::istream& operator>>(std::istream& is, Human& T)
{
	cout << "Введите имя(на английском):" << endl;
	input_eng(is, T._name);
	cout << "Введите фамилия(на английском):" << endl;
	input_eng(is, T._second_name);
	cout << "Введите год рождения:" << endl;
	rewind(stdin);
	T._year = input_int(is, 1900, 2022);

	return is;
}

/*__________деструктор__________*/
Human::~Human() {}

/*__________установка года__________*/
void Human::set_year(int year)
{
	this->_year = year;
}

/*__________установка имени__________*/
void Human::set_name(const char* name)
{
	strcpy_s(this->_name, name);
}

/*__________установка фамилии__________*/
void Human::set_second_name(const char* second_name)
{
	strcpy_s(this->_second_name, second_name);
}

/*__________получение года__________*/
int& Human::get_year()
{
	return _year;
}

/*__________получение имени__________*/
char* Human::get_name() 
{
	return &(_name[0]);
}

/*__________получение фамилии__________*/
char* Human::get_second_name() 
{
	return &(_second_name[0]);
}

/*__________таблица для вывода__________*/
void Human::table() const
{
	cout << "|Имя          |Фамилия      |Год рож.|";
}

/*__________меню сортировки__________*/
int Human::menu_sort()
{
	setColor(11);
	cout << "--------------------------------" << endl;
	cout << "|>> 1 - сортировка по фамилии. |" << endl;
	cout << "|>> 2 - сортировка по имени.   |" << endl;
	cout << "|>> 3 - сортировка по возрасту.|" << endl;
	cout << "--------------------------------" << endl;
	setColor(7);
	return input_int(cin, 1, 3);
}

/*__________перегрузка оператора меньше__________*/
bool operator<(const Human& T1, const Human& T2)
{	
	if (strcmp(T1._name, T2._name) < 0)
		return true;

	if (strcmp(T1._name, T2._name) > 0)
		return false;
	else
	{
		if (strcmp(T1._second_name, T2._second_name) >= 0)
			return false;
		else 
			return true;
	}

}