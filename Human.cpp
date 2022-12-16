#include "Human.h"

/*__________���������� ��������� ������__________*/
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

/*__________���������� ��������� ������__________*/
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

/*__________���������� ������ � ��������� �����__________*/
std::fstream& operator<<(std::fstream& out, Human& T)
{
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._name), _length_12);
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._second_name), _length_12);
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._year), sizeof(int));
	return out;
}

/*__________���������� ������ �� ��������� �����__________*/
std::fstream& operator>>(std::fstream& is, Human& T)
{
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._name), _length_12);
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._second_name), _length_12);
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._year), sizeof(int));
	return is;
}

/*__________���������� ������ � ����__________*/
std::ofstream& operator<<(std::ofstream& out, const Human& T)
{
	out << setfill(' ') << left << setw(13) << T._name << setw(13) << T._second_name;
	out << setw(6) << T._year;

	return out;
}

/*__________���������� ������ �� �����__________*/
std::ifstream& operator>>(std::ifstream& is, Human& T)
{
	is >> T._name >> T._second_name
		>> T._year;

	return is;
}

/*__________���������� ������__________*/
std::ostream& operator<<(std::ostream& out, const Human& T) 
{
	out.setf(ios::left);
	out << "|" << setfill(' ') << setw(13)
		<< T._name << "|" << setw(13) << T._second_name;
	out.unsetf(ios::left);
	out << "|" << setfill(' ') << setw(7) << T._year << " " << "|";
	
	return out;
}

/*__________���������� �����__________*/
std::istream& operator>>(std::istream& is, Human& T)
{
	cout << "������� ���(�� ����������):" << endl;
	input_eng(is, T._name);
	cout << "������� �������(�� ����������):" << endl;
	input_eng(is, T._second_name);
	cout << "������� ��� ��������:" << endl;
	rewind(stdin);
	T._year = input_int(is, 1900, 2022);

	return is;
}

/*__________����������__________*/
Human::~Human() {}

/*__________��������� ����__________*/
void Human::set_year(int year)
{
	this->_year = year;
}

/*__________��������� �����__________*/
void Human::set_name(const char* name)
{
	strcpy_s(this->_name, name);
}

/*__________��������� �������__________*/
void Human::set_second_name(const char* second_name)
{
	strcpy_s(this->_second_name, second_name);
}

/*__________��������� ����__________*/
int& Human::get_year()
{
	return _year;
}

/*__________��������� �����__________*/
char* Human::get_name() 
{
	return &(_name[0]);
}

/*__________��������� �������__________*/
char* Human::get_second_name() 
{
	return &(_second_name[0]);
}

/*__________������� ��� ������__________*/
void Human::table() const
{
	cout << "|���          |�������      |��� ���.|";
}

/*__________���� ����������__________*/
int Human::menu_sort()
{
	setColor(11);
	cout << "--------------------------------" << endl;
	cout << "|>> 1 - ���������� �� �������. |" << endl;
	cout << "|>> 2 - ���������� �� �����.   |" << endl;
	cout << "|>> 3 - ���������� �� ��������.|" << endl;
	cout << "--------------------------------" << endl;
	setColor(7);
	return input_int(cin, 1, 3);
}

/*__________���������� ��������� ������__________*/
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