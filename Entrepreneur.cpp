#include "Entrepreneur.h"

/*__________���������� ������ � ����__________*/
std::ofstream& operator<<(std::ofstream& out, const Entrepreneur& T)
{
	static_cast<ofstream&>(out) << dynamic_cast<const Human&>(T) << setw(7) << T._number_of_license
		<< setw(13) << T._address.street << setw(4) << T._address.number;
	for (int i = 0; i < size_4; ++i)
	{
		if (i)
			for (int g = 0; g < 56; ++g)
				out << ' ';

		static_cast<ofstream&>(out) << setfill(' ') << left << setw(6) << T._dues[i].sum;
		static_cast<ofstream&>(out) << T._dues[i].date << endl;
	}
	return out;
}

/*__________���������� ������ �� �����__________*/
std::ifstream& operator>>(std::ifstream& is, Entrepreneur& T)
{
	static_cast<ifstream&>(is) >> dynamic_cast<Human&>(T) >> T._number_of_license
		>> T._address.street >> T._address.number;
	for (int i = 0; i < size_4; ++i)
	{
		static_cast<ifstream&>(is) >> T._dues[i].sum;
		static_cast<ifstream&>(is) >> T._dues[i].date;
	}
	return is;
}

/*__________���������� ������ � ��������� �����__________*/
std::fstream& operator<<(std::fstream& out, Entrepreneur& T)
{
	static_cast<fstream&>(out) << dynamic_cast<Human&>(T);
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._number_of_license), sizeof(int));
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._address), sizeof(Address));
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._dues), sizeof(Dues) * size_4);
	return out;
}

/*__________���������� ������ �� ��������� �����__________*/
std::fstream& operator>>(std::fstream& is, Entrepreneur& T)
{
	static_cast<fstream&>(is) >> dynamic_cast<Human&>(T);
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._number_of_license), sizeof(int));
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._address), sizeof(Address));
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._dues), sizeof(Dues) * size_4);
	return is;
}

/*__________���������� ������__________*/
std::ostream& operator<<(std::ostream& out, const Entrepreneur& T)
{
	for (int i = 0; i < 83; ++i)
		out << "-";
	out << endl;

	out << dynamic_cast<const Human&>(T) << setfill(' ') << setw(7) << T._number_of_license << ' ';
	out.setf(ios::left);
	out << setfill(' ') << "|" << setw(13) << T._address.street << setw(3) << T._address.number << " " << "|";
	out.unsetf(ios::left);
	out.setf(ios::right);
	for (int i = 0; i < size_4; ++i)
	{
		if (i)
			for (int j = 0; j < 65; j++)
			{
				if (!j)out << "|";
				else if (j == 14)out << "|";
				else if (j == 28)out << "|";
				else if (j == 37)out << "|";
				else if (j == 46)out << "|";
				else if (j == 64)out << "|";
				else out << " ";
			
			}
		out << setfill('0') << T._dues[i].date
			<< " " << setfill(' ') << setw(6) << T._dues[i].sum << "|" << endl;
	}

	for (int i = 0; i < 83; ++i)
		out << "-";
	out << endl;
	
	out.unsetf(ios::right);
	return out;
}

/*__________���������� �����__________*/
std::istream& operator>>(std::istream& is, Entrepreneur& T)
{
	is >> dynamic_cast<Human&>(T);
	cout << "������� ����� ��������:" << endl;
	T._number_of_license = input_int(is, 1, 999999);
	cout << "������� ����� ������ �����������(�� ���������� �����):" << endl;
	input_eng(is, T._address.street);
	cout << "������� ����� ���� ������ �����������:" << endl;
	T._address.number = input_int(is, 1, 999);

	return is;
}

/*__________���������� ��������� ������������__________*/
Entrepreneur Entrepreneur::operator=(const Entrepreneur& T)
{
	if (this != &T)
	{
		strcpy_s(_name, T._name);
		strcpy_s(_second_name, T._second_name);
		_year = T._year;
		_number_of_license = T._number_of_license;
		_address = T._address;
		for (int i = 0; i < size_4; ++i)
			this->_dues[i] = T._dues[i];
	}
	return *this;
}

/*__________��������� ������ ��������__________*/
void Entrepreneur::set_number_of_license(int number_of_license)
{
	this->_number_of_license = number_of_license;
}

/*__________��������� ������ ��������__________*/
int& Entrepreneur::get_number_of_license()
{
	return _number_of_license;
}

/*__________��������� ���������� � �������__________*/
void Entrepreneur::set_data_dues(int pos, Dues data)
{
	try
	{
		if (pos < 0 or pos >= size_4)throw Container_error(5, "����� �� �������", "���� ������� ������� �� ��������� �������");
		this->_dues[pos] = data;
	}
	catch (Container_error obj)
	{
		obj.show_e();
		exit(1);
	}
}

/*__________��������� ���������� � �������__________*/
Dues& Entrepreneur::get_data_dues(int pos)
{
	try
	{
		if (pos < 0 or pos >= size_4)throw Container_error(5, "����� �� �������", "���� ������� ������� �� ��������� �������(���������� ���������� ������ 0 �������)");
		return _dues[pos];
	}
	catch (Container_error obj)
	{
		obj.show_e();
		exit(1);
	}
	
}

/*__________��������� ������__________*/
void Entrepreneur::set_address(Address address)
{
	this->_address = address;
}

/*__________��������� ������__________*/
Address& Entrepreneur::get_address()
{
	return _address;
}

/*__________���������� ���������� � �������__________*/
void Entrepreneur::add_data_dues(Dues dues)
{
	for (int i = size_4 - 1; i > 0; --i)
		_dues[i] = _dues[i - 1];
	_dues[0] = dues;
}

/*__________������� ��� ������__________*/
void Entrepreneur::table() const
{
	for (int i = 0; i < 83; ++i)
		cout << "-";
	cout << endl;
	Human::table();
	cout << "� ���.  |����� �����������|������ � ������� |" << endl;
	for (int i = 0; i < 83; ++i)
		cout << "-";
	cout << endl;
}

/*__________���������� ��������� ���������__________*/
bool Entrepreneur::operator==(const Entrepreneur& T)
{
	int flag = 1;

	if (T._name[0] != '-')
	{
		if (strcmp(_name, T._name))return false;
	}

	if (T._second_name[0] != '-')
	{
		if (strcmp(_second_name, T._second_name))return false;
	}

	if (T._year)
	{
		if (_year != T._year)return false;
	}

	if (T._number_of_license)
	{
		if (_number_of_license != T._number_of_license)return false;
	}

	if (T._address.number or T._address.street[0] != '-')
	{
		if (_address.number != T._address.number and !strcmp(T._address.street, _address.street))return false;
	}

	if (T._dues[0].sum and (T._dues[0].date.day or T._dues[0].date.month or T._dues[0].date.year))
	{
		for (int i = 0; i < size_4; i++)
		{
			if (_dues[0].sum == T._dues[i].sum and _dues[0].date == T._dues[i].date)flag = 0;
			if (!flag)break;
		}
		if (flag)return false;
		else flag = 1;
	}
	else {
		if (T._dues[0].sum)
		{
			for (int i = 0; i < size_4; i++)
			{
				if (_dues[0].sum == T._dues[i].sum)flag = 0;
				if (!flag)break;
			}
			if (flag)return false;
			else flag = 1;
		}

		if (T._dues[0].date.day or T._dues[0].date.month or T._dues[0].date.year)
		{
			for (int i = 0; i < size_4; i++)
			{
				if (_dues[0].date == T._dues[i].date)flag = 0;
				if (!flag)break;
			}
			if (flag)return false;
			else flag = 1;
		}
	}
	
	return true;
}

/*__________������� ���� ��� ��������������__________*/
Queue<Entrepreneur> menu_correct(Queue<Entrepreneur> mas, int size)
{
	for (;;)
	{
		int number;                          //��� ����� ������ ��������
		Address adres;                       //��� ����� �������
		Dues info_dues;                      //��� ����� ������ � �������

		system("CLS");
		setColor(2);
		cout << ">> ������� ����� ������� ��� ���������:" << endl;
		setColor(4);
		cout << ">> 0 - �����.                          " << endl;
		setColor(7);

		number = input_int(cin, 0, size);
		if (number)
		{
			number--;                         //�������������� ������� 

			int choice = 1;
			for (; choice;)
			{
				setColor(5);
				cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
				cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
				setColor(2);
				cout << "_______#####______CORRECT_ENTREPRENEUR______#####______" << endl;
				setColor(5);
				cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
				cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
				setColor(11);
				cout << ">> 1 - �������� ���." << endl;
				cout << ">> 2 - �������� �������." << endl;
				cout << ">> 3 - �������� ��� ��������." << endl;
				cout << ">> 4 - �������� ����� ��������." << endl;
				cout << ">> 5 - �������� ����� �����������." << endl;
				cout << ">> 6 - �������� ������ ������." << endl;
				setColor(4);
				cout << ">> 0 - �����.                                          " << endl;
				setColor(7);
				choice = input_int(cin, 0, 6);
				try
				{
					switch (choice)
					{
					case 0:
						system("cls");
						break;

					case 1:
						system("cls");
						cout << "������� ���(�� ���������� �����):" << endl;
						input_eng(cin, mas[number].get_name());
						setColor(2);
						cout << "��� ��������!" << endl;
						setColor(7);
						break;

					case 2:
						system("cls");
						cout << "������� �������(�� ���������� �����):" << endl;
						input_eng(cin, mas[number].get_second_name());
						setColor(2);
						cout << "������� ��������!" << endl;
						setColor(7);
						break;

					case 3:
						system("cls");
						cout << "������� ��� ��������:" << endl;
						mas[number].set_year(input_int(cin, 1900, 2022));
						setColor(2);
						cout << "��� �������� �������!" << endl;
						setColor(7);
						break;

					case 4:
						system("cls");
						cout << "������� ����� ��������:" << endl;
						mas[number].set_number_of_license(input_int(cin, 1, 999999));
						setColor(2);
						cout << "����� �������� �������!" << endl;
						setColor(7);
						break;

					case 5:
						system("cls");
						cout << "������� ����� �����������(�� ���������� �����):" << endl;
						input_eng(cin, adres.street);
						cout << "������� ��� �����������:" << endl;
						adres.number = input_int(cin, 1, 999);
						mas[number].set_address(adres);
						setColor(2);
						cout << "������� ����� �����������!" << endl;
						setColor(7);
						break;

					case 6:
						system("cls");
						cout << "������� �����:" << endl;
						info_dues.sum = input_int(cin, 1, 999999);
						cout << "������� ����:" << endl;
						info_dues.date.day = input_int(cin, 1, 31);
						cout << "������� �����:" << endl;
						info_dues.date.month = input_int(cin, 1, 12);
						cout << "������� ���:" << endl;
						info_dues.date.year = input_int(cin, 1900, 2022);
						mas[number].add_data_dues(info_dues);
						setColor(2);
						cout << "��������� ���������� � �������!" << endl;
						setColor(7);
						break;

					default:
						throw Container_error(8, "������ ������ ����", "��������� ����� 0-6");
						break;
					}
				}
				catch (Container_error obj)
				{
					obj.show_e();
				}
			}
		}
		else
		{
			system("cls");
			return mas;
		}
	}
}

/*__________������� ���� ��� ������__________*/
Entrepreneur Entrepreneur::menu_for_poisk()
{
	Entrepreneur mas;
	Address adres;                       //��� ����� �������
	Dues info_dues;                      //��� ����� ������ � �������

	int choice = 1;
	for (; choice;)
	{
		setColor(5);
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		setColor(2);
		cout << "_______#####_______SEARCH_ENTREPRENEUR______#####______" << endl;
		setColor(5);
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		setColor(11);
		cout << ">> 1 - ������ ���." << endl;
		cout << ">> 2 - ������ �������." << endl;
		cout << ">> 3 - ������ ��� ��������." << endl;
		cout << ">> 4 - ������ ����� ��������." << endl;
		cout << ">> 5 - ������ ����� �����������." << endl;
		cout << ">> 6 - ������ ����� ������." << endl;
		cout << ">> 7 - ������ ���� ������� ������." << endl;
		setColor(2);
		cout << ">> 0 - ������ �����.                                   " << endl;
		setColor(7);
		choice = input_int(cin, 0, 7);
		try
		{
			switch (choice)
			{
			case 0:
				system("cls");
				break;

			case 1:
				system("cls");
				cout << "������� ���(�� ���������� �����):" << endl;
				input_eng(cin, mas.get_name());
				setColor(2);
				cout << "��� �����������!" << endl;
				setColor(7);
				break;

			case 2:
				system("cls");
				cout << "������� �������(�� ���������� �����):" << endl;
				input_eng(cin, mas.get_second_name());
				setColor(2);
				cout << "������� �����������!" << endl;
				setColor(7);
				break;

			case 3:
				system("cls");
				cout << "������� ��� ��������:" << endl;
				mas.set_year(input_int(cin, 1900, 2022));
				setColor(2);
				cout << "��� �������� ����������!" << endl;
				setColor(7);
				break;

			case 4:
				system("cls");
				cout << "������� ����� ��������:" << endl;
				mas.set_number_of_license(input_int(cin, 1, 999999));
				setColor(2);
				cout << "����� �������� ����������!" << endl;
				setColor(7);
				break;

			case 5:
				system("cls");
				cout << "������� ����� �����������(�� ���������� �����):" << endl;
				input_eng(cin, adres.street);
				cout << "������� ��� �����������:" << endl;
				adres.number = input_int(cin, 1, 999);
				mas.set_address(adres);
				setColor(2);
				cout << "����� ����������� ����������!" << endl;
				setColor(7);
				break;

			case 6:
				system("cls");
				cout << "������� �����:" << endl;
				mas.get_data_dues(0).sum = input_int(cin, 1, 999999);
				setColor(2);
				cout << "����� ������ �����������!" << endl;
				setColor(7);
				break;

			case 7:
				system("cls");
				cout << "������� ����:" << endl;
				info_dues.date.day = input_int(cin, 1, 31);
				cout << "������� �����:" << endl;
				info_dues.date.month = input_int(cin, 1, 12);
				cout << "������� ���:" << endl;
				info_dues.date.year = input_int(cin, 1900, 2022);
				mas.get_data_dues(0).date = info_dues.date;
				setColor(2);
				cout << "���� ������� ������ �����������!" << endl;
				setColor(7);
				break;

			default:
				throw Container_error(8, "������ ������ ����", "��������� ����� 0-6");
				break;
			}
		}
		catch (Container_error obj)
		{
			obj.show_e();
		}
	}
	cout << "��������� �� ������� �����:" << endl;
	mas.table();
	cout << mas;
	return mas;
}

/*__________����������� ������ ����__________*/
Entrepreneur Entrepreneur::copy_place(int place)
{
	Entrepreneur obj;
	switch (place)
	{
	case 1:
		obj.set_second_name(this->_second_name);
		break;

	case 2:
		obj.set_name(this->_name);
		break;

	case 3:
		obj.set_year(this->_year);
		break;

	default:
		throw Container_error(1, "����� �� �������� 1 - 3",
			"�������� �� ������ ��������� ������ ��������");

	}
	return obj;
}