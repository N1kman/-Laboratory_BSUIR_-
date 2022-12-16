#include "Tourist.h"

/*__________перегрузка вывода в файл__________*/
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

/*__________перегрузка чтения из файла__________*/
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

/*__________перегрузка вывода в бинарного файла__________*/
std::fstream& operator<<(std::fstream& out, Tourist& T)
{
	static_cast<fstream&>(out) << dynamic_cast<Human&>(T);
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._number_of_pasport), size_9);
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._data), sizeof(Data_border) * size_4);
	return out;
}

/*__________перегрузка чтения из бинарного файла__________*/
std::fstream& operator>>(std::fstream& is, Tourist& T)
{
	static_cast<fstream&>(is) >> dynamic_cast<Human&>(T);
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._number_of_pasport), size_9);
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._data), sizeof(Data_border) * size_4);
	return is;
}

/*__________перегрузка вывода__________*/
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

/*__________перегрузка ввода __________*/
std::istream& operator>>(std::istream& is, Tourist& T)
{
	is >> dynamic_cast<Human&>(T);
	cout << "Введите номер паспорта" << endl;
	input_pasport(is, T.get_number_of_pasport());

	return is;
}

/*__________перегрузка оператора присваивания__________*/
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

/*__________добавление информации о пересечении границы__________*/
void Tourist::add_data_border(Data_border data)
{
	for (int i = size_4 - 1; i > 0; --i)
		_data[i] = _data[i - 1];
	_data[0] = data;
}

/*__________установка номера паспорта__________*/
void Tourist::set_number_of_pasport(const char* number_of_pasport)
{
	strcpy_s(_number_of_pasport, number_of_pasport);
}

/*__________получение номера паспорта__________*/
char* Tourist::get_number_of_pasport()
{
	return &(_number_of_pasport[0]);
}

/*__________установка информации о пересечении границы__________*/
void Tourist::set_data_border(int pos, Data_border data)
{
	try
	{
		if (pos < 0 or pos >= size_4)throw Container_error(5, "Выход за пределы", "Была выбрана позиция за пределами массива");
		this->_data[pos] = data;
	}
	catch (Container_error obj)
	{
		obj.show_e();
		exit(1);
	}
}

/*__________получение информации о пересечении границы__________*/
Data_border& Tourist::get_data_border(int pos)
{
	try
	{
		if (pos < 0 or pos >= size_4)throw Container_error(5, "Выход за пределы", "Была выбрана позиция за пределами массива(возвращена ссылка на 0 позицию)");
		return _data[pos];
	}
	catch (Container_error obj)
	{
		obj.show_e();
		exit(1);
	}
}

/*__________таблица для вывода__________*/
void Tourist::table() const
{
	for (int i = 0; i < 75; ++i)
		cout << "-";
	cout << endl;
	Human::table();
	cout << "№ пасп.   |Данные о пересеч. границы|" << endl;
	for (int i = 0; i < 75; ++i)
		cout << "-";
	cout << endl;
}

/*__________перегрузка оператора сравнения__________*/
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

/*__________функция меню__________*/
Queue<Tourist> menu_correct(Queue<Tourist> mas, int size)
{
	for (;;)
	{
		int number;                          //для ввода номера элемента
		Address adres;                       //для ввода адресов
		Dues info_dues;                      //для ввода данных о налогах
		Data_border info_border;             //для ввода данных о пересечении границы

		system("CLS");
		setColor(2);
		cout << ">> Введите номер объекта для изменения:" << endl;
		setColor(4);
		cout << ">> 0 - назад.                          " << endl;
		setColor(7);

		number = input_int(cin, 0, size);
		if (number)
		{
			number--;                         //действительная позиция 

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
				cout << ">> 1 - изменить имя.                                   " << endl;
				cout << ">> 2 - изменить фамилию.                               " << endl;
				cout << ">> 3 - изменить год рождения.                          " << endl;
				cout << ">> 4 - изменить номер паспорта.                        " << endl;
				cout << ">> 5 - добавить пересечение границы.                   " << endl;
				setColor(4);
				cout << ">> 0 - назад.                                          " << endl;
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
						cout << "Введите имя(на английском языке):" << endl;
						input_eng(cin, mas[number].get_name());
						setColor(2);
						cout << "Имя изменено!" << endl;
						setColor(7);
						break;

					case 2:
						system("cls");
						cout << "Введите фамилию(на английском языке):" << endl;
						input_eng(cin, mas[number].get_second_name());
						setColor(2);
						cout << "Фамилия изменена!" << endl;
						setColor(7);
						break;

					case 3:
						system("cls");
						cout << "Введите год рождения:" << endl;
						mas[number].set_year(input_int(cin, 1900, 2022));
						setColor(2);
						cout << "Год рождения изменен!" << endl;
						setColor(7);
						break;

					case 4:
						system("cls");
						cout << "Введите номер паспорта:" << endl;
						input_pasport(cin, mas[number].get_number_of_pasport());
						setColor(2);
						cout << "Номер паспорта изменен!" << endl;
						setColor(7);
						break;

					case 5:
						system("cls");
						cout << "Введите страну(на английском языке):" << endl;
						input_eng(cin, info_border.country);
						cout << "Введите день:" << endl;
						info_border.date.day = input_int(cin, 1, 31);
						cout << "Введите месяц:" << endl;
						info_border.date.month = input_int(cin, 1, 12);
						cout << "Введите год:" << endl;
						info_border.date.year = input_int(cin, 1900, 2022);
						mas[number].add_data_border(info_border);
						setColor(2);
						cout << "Добавлено пересечение границы!" << endl;
						setColor(7);
						break;

					default:
						throw Container_error(8, "Ошибка выбора меню", "Доступные опции 0-5");
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

/*__________функция меню для поиска__________*/
Tourist Tourist::menu_for_poisk()
{
	Tourist mas;
	Address adres;                       //для ввода адресов
	Dues info_dues;                      //для ввода данных о налогах
	Data_border info_border;             //для ввода данных о пересечении границы

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
		cout << ">> 1 - ввести имя.                                     " << endl;
		cout << ">> 2 - ввести фамилию.                                 "  << endl;
		cout << ">> 3 - ввести год рождения.                            " << endl;
		cout << ">> 4 - ввести номер паспорта.                          " << endl;
		cout << ">> 5 - ввести страну.                                  " << endl;
		cout << ">> 6 - ввести дату пересечения границы.                " << endl;
		setColor(2);
		cout << ">> 0 - начать поиск.                                   " << endl;
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
				cout << "Введите имя(на английском языке):" << endl;
				input_eng(cin, mas.get_name());
				setColor(2);
				cout << "Имя установлено!" << endl;
				setColor(7);
				break;

			case 2:
				system("cls");
				cout << "Введите фамилию(на английском языке):" << endl;
				input_eng(cin, mas.get_second_name());
				setColor(2);
				cout << "Фамилия установлена!" << endl;
				setColor(7);
				break;

			case 3:
				system("cls");
				cout << "Введите год рождения:" << endl;
				mas.set_year(input_int(cin, 1900, 2022));
				setColor(2);
				cout << "Год рождения установлен!" << endl;
				setColor(7);
				break;

			case 4:
				system("cls");
				cout << "Введите номер паспорта:" << endl;
				rewind(stdin);
				input_pasport(cin, mas.get_number_of_pasport());
				setColor(2);
				cout << "Номер паспорта установлен!" << endl;
				setColor(7);
				break;

			case 5:
				system("cls");
				cout << "Введите страну(на английском языке):" << endl;
				input_eng(cin, mas.get_data_border(0).country);
				setColor(2);
				cout << "Страна пересечения установлена!" << endl;
				setColor(7);
				break;

			case 6:
				system("cls");
				cout << "Введите день:" << endl;
				info_border.date.day = input_int(cin, 1, 31);
				cout << "Введите месяц:" << endl;
				info_border.date.month = input_int(cin, 1, 12);
				cout << "Введите год:" << endl;
				info_border.date.year = input_int(cin, 1900, 2022);
				mas.get_data_border(0).date = info_border.date;
				setColor(2);
				cout << "Дата пересечения границы установлена!" << endl;
				setColor(7);
				break;

			default:
				throw Container_error(8, "Ошибка выбора меню", "Доступные опции 0-6");
				break;
			}
		}
		catch (Container_error obj)
		{
			obj.show_e();
		}
	}
	cout << "Параметры по которым ищете:" << endl;
	mas.table();
	cout << mas;
	return mas;
}

/*__________копирование одного поля__________*/
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
		throw Container_error(1, "Выход за диапозон 1 - 3",
			"Возможно вы хотели выполнить другое действие");

	}
	return obj;
}