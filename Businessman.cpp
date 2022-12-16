#include "Businessman.h"

/*__________���������� ������ � ����__________*/
std::ofstream& operator<<(std::ofstream& out, const Businessman& T)
{
	static_cast<ofstream&>(out) << dynamic_cast<const Human&>(T) << setw(7) << T._number_of_license
		<< setw(13) << T._address.street << setw(4) << T._address.number
		<< setw(10) << T._number_of_pasport;
	for (int i = 0; i < size_4; ++i)
	{
		if (i)
			for (int g = 0; g < 66; ++g)
				out << ' ';

		static_cast<ofstream&>(out) << setfill(' ') << left << setw(6) << T._dues[i].sum;
		static_cast<ofstream&>(out) << T._dues[i].date;
		static_cast<ofstream&>(out) << setfill(' ') << right << setw(13) << T._data[i].country;
		static_cast<ofstream&>(out) << T._data[i].date << setw(13) << T._addresses[i].street
			<< setw(4) << T._addresses[i].number << endl;
	}
	return out;
}

/*__________���������� ������ �� �����__________*/
std::ifstream& operator>>(std::ifstream& is, Businessman& T)
{
	static_cast<ifstream&>(is) >> dynamic_cast<Human&>(T) >> T._number_of_license
		>> T._address.street >> T._address.number >> T._number_of_pasport;
	for (int i = 0; i < size_4; ++i)
	{
		static_cast<ifstream&>(is) >> T._dues[i].sum;
		static_cast<ifstream&>(is) >> T._dues[i].date;
		static_cast<ifstream&>(is) >> T._data[i].country;
		static_cast<ifstream&>(is) >> T._data[i].date;
		static_cast<ifstream&>(is) >> T._addresses[i].street >> T._addresses[i].number;
	}
	return is;
}

/*__________���������� ������ � ��������� �����__________*/
std::fstream& operator<<(std::fstream& out, Businessman& T)
{
	static_cast<fstream&>(out) << dynamic_cast<Entrepreneur&>(T);
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._number_of_pasport), size_9);
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._data), sizeof(Data_border) * size_4);
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._addresses), sizeof(Address) * size_4);
	return out;
}

/*__________���������� ������ �� ��������� �����__________*/
std::fstream& operator>>(std::fstream& is, Businessman& T)
{
	static_cast<fstream&>(is) >> dynamic_cast<Entrepreneur&>(T);
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._number_of_pasport), size_9);
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._data), sizeof(Data_border) * size_4);
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._addresses), sizeof(Address) * size_4);
	return is;
}

/*__________���������� ������__________*/
std::ostream& operator<<(std::ostream& out, const Businessman& T)
{
	for (int i = 0; i < 140; ++i)
		cout << "-";
	cout << endl;
	out << dynamic_cast<const Human&>(T);
	out.setf(ios::right);
	out << setfill(' ') << setw(6) << T._number_of_license << ' ';
	out << setfill(' ') << "|" << setw(13) << T._address.street << setw(4) << T._address.number << ' ';
	out << setfill(' ') << "|" << setw(9) << T._number_of_pasport << ' ';
	out.unsetf(ios::right);
	for (int i = 0; i < size_4; ++i)
	{
		out.setf(ios::right);
		if (i)
			for (int j = 0; j < 75; j++)
			{
				if (!j)out << "|";
				else if (j == 14)out << "|";
				else if (j == 28)out << "|";
				else if (j == 37)out << "|";
				else if (j == 45)out << "|";
				else if (j == 64)out << "|";
				else out << " ";
			}

		out << setfill(' ') << "|" << setw(13) << T._addresses[i].street << setw(4) << T._addresses[i].number
			<< " " << "|" << setfill('0') << T._dues[i].date
			<< " " << setfill(' ') << setw(6) << T._dues[i].sum << " ";
		out.unsetf(ios::right);
		out.setf(ios::left);
		out << setfill(' ') << "|" << setw(15) << T._data[i].country;
		out.unsetf(ios::left);
		out.setf(ios::right);
		out << setfill('0') << T._data[i].date << "|" << endl;
		out.unsetf(ios::right);
	}
	for (int i = 0; i < 140; ++i)
		cout << "-";
	cout << endl;
	return out;
}

/*__________���������� ����� __________*/
std::istream& operator>>(std::istream& is, Businessman& T)
{
	is >> dynamic_cast<Entrepreneur&>(T);
	cout << "������� ����� ��������" << endl;
	input_pasport(is, T.get_number_of_pasport());

	return is;
}

/*__________���������� ��������� ������������__________*/
Businessman Businessman::operator=(const Businessman& T)
{
	if (this != &T)
	{
		*(dynamic_cast<Tourist*>(this)) = dynamic_cast<const Tourist&>(T);
		*(dynamic_cast<Entrepreneur*>(this)) = dynamic_cast<const Entrepreneur&>(T);
		for (int i = 0; i < size_4; ++i)
			this->_addresses[i] = T._addresses[i];
	}
	return *this;
}

/*__________��������� ���������� � ������ ������� �������__________*/
void Businessman::set_addreses(int pos, Address data)
{
	try
	{
		if (pos < 0 or pos >= size_4)throw Container_error(5, "����� �� �������", "���� ������� ������� �� ��������� �������");
		this->_addresses[pos] = data;
	}
	catch (Container_error obj)
	{
		obj.show_e();
		exit(1);
	}
}

/*__________��������� ���������� � ������ ������� ������_________*/
Address& Businessman::get_address(int pos)
{
	try
	{
		if (pos < 0 or pos >= size_4)throw Container_error(5, "����� �� �������", "���� ������� ������� �� ��������� �������(���������� ������ �� 0 �������)");
		return _addresses[pos];
	}
	catch (Container_error obj)
	{
		obj.show_e();
		exit(1);
	}
}

/*__________���������� ���������� � ������� �������__________*/
void Businessman::add_data_addreses(Address adres)
{
	for (int i = size_4 - 1; i > 0; --i)
		_addresses[i] = _addresses[i - 1];
	_addresses[0] = adres;
}

/*__________������� ��� ������__________*/
void Businessman::table() const
{
	for (int i = 0; i < 140; ++i)
		cout << "-";
	cout << endl;
	cout << "|���          |�������      |��� ���.|� ���. |����� ����������� |� ����.   |������ �������    |������ � �������  |������ � �������. �������|" << endl;
	for (int i = 0; i < 140; ++i)
		cout << "-";
	cout << endl;
}

/*__________���������� ��������� ���������__________*/
bool Businessman::operator==(const Businessman& T)
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

	if (T._number_of_pasport[0] != '-')
	{
		if (_number_of_pasport != T._number_of_pasport)return false;
	}

	if (T._data[0].country[0] != '-' and (T._data[0].date.day or T._data[0].date.month or T._data[0].date.year))
	{
		for (int i = 0; i < size_4; i++)
		{
			if (!strcmp(_data[0].country, T._data[i].country) and _data[0].date == T._data[i].date)flag = 0;
			if (!flag)break;
		}
		if (flag)return false;
		else flag = 1;
	}
	else {
		if (T._data[0].country[0] != '-')
		{
			for (int i = 0; i < size_4; i++)
			{
				flag = strcmp(_data[0].country, T._data[i].country);
				if (!flag)break;
			}
			if (flag)return false;
			else flag = 1;
		}

		if (T._data[0].date.day or T._data[0].date.month or T._data[0].date.year)
		{
			for (int i = 0; i < size_4; i++)
			{
				if (_data[0].date == T._data[i].date)flag = 0;
				if (!flag)break;
			}
			if (flag)return false;
			else flag = 1;
		}
	}

	if (T._addresses[0].number or T._addresses[0].street[0] != '-')
	{
		for (int i = 0; i < size_4; i++)
		{
			if (!strcmp(_addresses[0].street, T._addresses[i].street) and _addresses[0].number == T._addresses[0].number)flag = 0;
			if (!flag)break;
		}
		if (flag)return false;
		else flag = 1;
	}

	return true;
}

/*__________������� ����__________*/
Queue<Businessman> menu_correct(Queue<Businessman> mas, int size)
{
	for (;;)
	{
		int number;                          //��� ����� ������ ��������
		Address adres;                       //��� ����� �������
		Dues info_dues;                      //��� ����� ������ � �������
		Data_border info_border;             //��� ����� ������ � ����������� �������

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
				cout << "_______#####______CORRECT_BUSINESSMAN______#####_______" << endl;
				setColor(5);
				cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
				cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
				setColor(11);
				cout << ">> 1 - �������� ���." << endl;
				cout << ">> 2 - �������� �������." << endl;
				cout << ">> 3 - �������� ��� ��������." << endl;
				cout << ">> 4 - �������� ����� ��������." << endl;
				cout << ">> 5 - �������� ����� ��������." << endl;
				cout << ">> 6 - �������� ����� �����������." << endl;
				cout << ">> 7 - �������� ����������� �������." << endl;
				cout << ">> 8 - �������� ������ ������." << endl;
				cout << ">> 9 - �������� ����� �������." << endl;
				setColor(4);
				cout << ">> 0 - �����.                                          " << endl;
				setColor(7);
				choice = input_int(cin, 0, 9);
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
						input_pasport(cin, mas[number].get_number_of_pasport());
						setColor(2);
						cout << "����� �������� �������!" << endl;
						setColor(7);
						break;

					case 5:
						system("cls");
						cout << "������� ����� ��������:" << endl;
						mas[number].set_number_of_license(input_int(cin, 1, 999999));
						setColor(2);
						cout << "����� �������� �������!" << endl;
						setColor(7);
						break;

					case 6:
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

					case 7:
						system("cls");
						cout << "������� ������(�� ���������� �����):" << endl;
						input_eng(cin, info_border.country);
						cout << "������� ����:" << endl;
						info_border.date.day = input_int(cin, 1, 31);
						cout << "������� �����:" << endl;
						info_border.date.month = input_int(cin, 1, 12);
						cout << "������� ���:" << endl;
						info_border.date.year = input_int(cin, 1900, 2022);
						mas[number].add_data_border(info_border);
						setColor(2);
						cout << "��������� ����������� �������!" << endl;
						setColor(7);
						break;

					case 8:
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

					case 9:
						system("cls");
						cout << "������� ����� �������(�� ���������� �����):" << endl;
						input_eng(cin, adres.street);
						cout << "������� ��� �������:" << endl;
						adres.number = input_int(cin, 1, 999);
						mas[number].add_data_addreses(adres);
						setColor(2);
						cout << "��������� ���������� �� ������� �������!" << endl;
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
Businessman Businessman::menu_for_poisk()
{
	Businessman mas;
	Address adres;                       //��� ����� �������
	Dues info_dues;                      //��� ����� ������ � �������
	Data_border info_border;             //��� ����� ������ � ����������� �������

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
		cout << ">> 5 - ������ ����� ��������." << endl;
		cout << ">> 6 - ������ ����� �����������." << endl;
		cout << ">> 7 - ������ ������." << endl;
		cout << ">> 8 - ������ ���� ����������� �������." << endl;
		cout << ">> 9 - ������ ����� ������." << endl;
		cout << ">> 10 - ������ ���� ������� ������." << endl;
		cout << ">> 11 - ������ ����� �������." << endl;
		setColor(2);
		cout << ">> 0 - ������ �����.                                   " << endl;
		setColor(7);
		choice = input_int(cin, 0, 11);
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
				rewind(stdin);
				input_pasport(cin, mas.get_number_of_pasport());
				setColor(2);
				cout << "����� �������� ����������!" << endl;
				setColor(7);
				break;

			case 5:
				system("cls");
				cout << "������� ����� ��������:" << endl;
				mas.set_number_of_license(input_int(cin, 1, 999999));
				setColor(2);
				cout << "����� �������� ����������!" << endl;
				setColor(7);
				break;

			case 6:
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

			case 7:
				system("cls");
				cout << "������� ������(�� ���������� �����):" << endl;
				input_eng(cin, mas.get_data_border(0).country);
				setColor(2);
				cout << "������ ����������� �����������!" << endl;
				setColor(7);
				break;

			case 8:
				system("cls");
				cout << "������� ����:" << endl;
				info_border.date.day = input_int(cin, 1, 31);
				cout << "������� �����:" << endl;
				info_border.date.month = input_int(cin, 1, 12);
				cout << "������� ���:" << endl;
				info_border.date.year = input_int(cin, 1900, 2022);
				mas.get_data_border(0).date = info_border.date;
				setColor(2);
				cout << "���� ����������� ������� �����������!" << endl;
				setColor(7);
				break;

			case 9:
				system("cls");
				cout << "������� �����:" << endl;
				info_dues.sum = input_int(cin, 1, 999999);
				mas.get_data_dues(0).sum = info_dues.sum;
				setColor(2);
				cout << "����� ������ �����������!" << endl;
				setColor(7);
				break;

			case 10:
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

			case 11:
				system("cls");
				cout << "������� ����� �������(�� ���������� �����):" << endl;
				input_eng(cin, adres.street);
				cout << "������� ��� �������:" << endl;
				adres.number = input_int(cin, 1, 999);
				mas.set_addreses(0, adres);
				setColor(2);
				cout << "����� ������� ����������!" << endl;
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
Businessman Businessman::copy_place(int place)
{
	Businessman obj;
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