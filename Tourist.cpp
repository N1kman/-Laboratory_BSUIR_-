#include "Tourist.h"

/*__________���������� ������ � ����__________*/
std::ofstream& operator<<(std::ofstream& out, const Tourist& T)
{
	static_cast<ofstream&>(out) << dynamic_cast<const Human&>(T) << setw(10) << T._number_of_pasport;
	for (int i = 0; i < size_4; ++i)
	{
		if (i)
			for (int g = 0; g < 42; ++g)
				out << ' ';

		static_cast<ofstream&>(out) << setfill(' ') << left << setw(13) << T._data[i].country;
		static_cast<ofstream&>(out) << T._data[i].date << endl;
	}
	return out;
}

/*__________���������� ������ �� �����__________*/
std::ifstream& operator>>(std::ifstream& is, Tourist& T)
{
	static_cast<ifstream&>(is) >> dynamic_cast<Human&>(T) >> T._number_of_pasport;
	for (int i = 0; i < size_4; ++i)
	{
		static_cast<ifstream&>(is) >> T._data[i].country;
		static_cast<ifstream&>(is) >> T._data[i].date;
	}
	return is;
}

/*__________���������� ������ � ��������� �����__________*/
std::fstream& operator<<(std::fstream& out, Tourist& T)
{
	static_cast<fstream&>(out) << dynamic_cast<Human&>(T);
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._number_of_pasport), size_9);
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._data), sizeof(Data_border) * size_4);
	return out;
}

/*__________���������� ������ �� ��������� �����__________*/
std::fstream& operator>>(std::fstream& is, Tourist& T)
{
	static_cast<fstream&>(is) >> dynamic_cast<Human&>(T);
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._number_of_pasport), size_9);
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._data), sizeof(Data_border) * size_4);
	return is;
}

/*__________���������� ������__________*/
std::ostream& operator<<(std::ostream& out, const Tourist& T)
{
	for (int i = 0; i < 75; ++i)
		out << "-";
	out << endl;
	out << dynamic_cast<const Human&>(T) << setfill(' ') << setw(9) << T._number_of_pasport << ' ' << "|";
	for (int i = 0; i < size_4; ++i)
	{
		out.setf(ios::left);
		if (i)
			for (int j = 0; j < 49; j++)
			{
				if (!j)out << "|";
				else if (j == 14)out << "|";
				else if (j == 28)out << "|";
				else if (j == 37)out << "|";
				else if (j == 48)out << "|";
				else out << " ";
			}
		
		out << setfill(' ') << setw(15) << T._data[i].country;
		out.unsetf(ios::left);
		out.setf(ios::right);
		out << setfill('0') << T._data[i].date << "|" << endl;
		out.unsetf(ios::right);
	}
	for (int i = 0; i < 75; ++i)
		out << "-";
	out << endl;
	return out;
}

/*__________���������� ����� __________*/
std::istream& operator>>(std::istream& is, Tourist& T)
{
	is >> dynamic_cast<Human&>(T);
	cout << "������� ����� ��������" << endl;
	input_pasport(is, T.get_number_of_pasport());

	return is;
}

/*__________���������� ��������� ������������__________*/
Tourist Tourist::operator=(const Tourist& T)
{
	if (this != &T)
	{
		strcpy_s(_name, T._name);
		strcpy_s(_second_name, T._second_name);
		_year = T._year;
		strcpy_s(_number_of_pasport, T._number_of_pasport);
		for (int i = 0; i < size_4; ++i)
			this->_data[i] = T._data[i];
	}
	return *this;
}

/*__________���������� ���������� � ����������� �������__________*/
void Tourist::add_data_border(Data_border data)
{
	for (int i = size_4 - 1; i > 0; --i)
		_data[i] = _data[i - 1];
	_data[0] = data;
}

/*__________��������� ������ ��������__________*/
void Tourist::set_number_of_pasport(const char* number_of_pasport)
{
	strcpy_s(_number_of_pasport, number_of_pasport);
}

/*__________��������� ������ ��������__________*/
char* Tourist::get_number_of_pasport()
{
	return &(_number_of_pasport[0]);
}

/*__________��������� ���������� � ����������� �������__________*/
void Tourist::set_data_border(int pos, Data_border data)
{
	try
	{
		if (pos < 0 or pos >= size_4)throw Container_error(5, "����� �� �������", "���� ������� ������� �� ��������� �������");
		this->_data[pos] = data;
	}
	catch (Container_error obj)
	{
		obj.show_e();
		exit(1);
	}
}

/*__________��������� ���������� � ����������� �������__________*/
Data_border& Tourist::get_data_border(int pos)
{
	try
	{
		if (pos < 0 or pos >= size_4)throw Container_error(5, "����� �� �������", "���� ������� ������� �� ��������� �������(���������� ������ �� 0 �������)");
		return _data[pos];
	}
	catch (Container_error obj)
	{
		obj.show_e();
		exit(1);
	}
}

/*__________������� ��� ������__________*/
void Tourist::table() const
{
	for (int i = 0; i < 75; ++i)
		cout << "-";
	cout << endl;
	Human::table();
	cout << "� ����.   |������ � �������. �������|" << endl;
	for (int i = 0; i < 75; ++i)
		cout << "-";
	cout << endl;
}

/*__________���������� ��������� ���������__________*/
bool Tourist::operator==(const Tourist& T)
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
	
	return true;
}

/*__________������� ����__________*/
Queue<Tourist> menu_correct(Queue<Tourist> mas, int size)
{
	for (;;)
	{
		int number;                          //��� ����� ������ ��������
		Address adres;                       //��� ����� �������
		Dues info_dues;                      //��� ����� ������ � �������
		Data_border info_border;             //��� ����� ������ � ����������� �������

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
				cout << "_______#####________CORRECT_TOURIST________#####_______" << endl;
				setColor(5);
				cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
				cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
				setColor(11);
				cout << ">> 1 - �������� ���.                                   " << endl;
				cout << ">> 2 - �������� �������.                               " << endl;
				cout << ">> 3 - �������� ��� ��������.                          " << endl;
				cout << ">> 4 - �������� ����� ��������.                        " << endl;
				cout << ">> 5 - �������� ����������� �������.                   " << endl;
				setColor(4);
				cout << ">> 0 - �����.                                          " << endl;
				setColor(7);
				choice = input_int(cin, 0, 5);
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

					default:
						throw Container_error(8, "������ ������ ����", "��������� ����� 0-5");
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
Tourist Tourist::menu_for_poisk()
{
	Tourist mas;
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
		cout << "_______#####_________SEARCH_TOURIST________#####_______" << endl;
		setColor(5);
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		setColor(11);
		cout << ">> 1 - ������ ���.                                     " << endl;
		cout << ">> 2 - ������ �������.                                 "  << endl;
		cout << ">> 3 - ������ ��� ��������.                            " << endl;
		cout << ">> 4 - ������ ����� ��������.                          " << endl;
		cout << ">> 5 - ������ ������.                                  " << endl;
		cout << ">> 6 - ������ ���� ����������� �������.                " << endl;
		setColor(2);
		cout << ">> 0 - ������ �����.                                   " << endl;
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
				cout << "������� ������(�� ���������� �����):" << endl;
				input_eng(cin, mas.get_data_border(0).country);
				setColor(2);
				cout << "������ ����������� �����������!" << endl;
				setColor(7);
				break;

			case 6:
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
Tourist Tourist::copy_place(int place)
{
	Tourist obj;
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