#include "Entrepreneur.h"

/*__________перегрузка вывода в файл__________*/
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

/*__________перегрузка чтения из файла__________*/
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

/*__________перегрузка вывода в бинарного файла__________*/
std::fstream& operator<<(std::fstream& out, Entrepreneur& T)
{
	static_cast<fstream&>(out) << dynamic_cast<Human&>(T);
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._number_of_license), sizeof(int));
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._address), sizeof(Address));
	static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T._dues), sizeof(Dues) * size_4);
	return out;
}

/*__________перегрузка чтения из бинарного файла__________*/
std::fstream& operator>>(std::fstream& is, Entrepreneur& T)
{
	static_cast<fstream&>(is) >> dynamic_cast<Human&>(T);
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._number_of_license), sizeof(int));
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._address), sizeof(Address));
	static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T._dues), sizeof(Dues) * size_4);
	return is;
}

/*__________перегрузка вывода__________*/
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

/*__________перегрузка ввода__________*/
std::istream& operator>>(std::istream& is, Entrepreneur& T)
{
	is >> dynamic_cast<Human&>(T);
	cout << "Введите номер лицензии:" << endl;
	T._number_of_license = input_int(is, 1, 999999);
	cout << "Введите улицу адреса регистрации(на английском языке):" << endl;
	input_eng(is, T._address.street);
	cout << "Введите номер дома адреса регистрации:" << endl;
	T._address.number = input_int(is, 1, 999);

	return is;
}

/*__________перегрузка оператора присваивания__________*/
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

/*__________установка номера паспорта__________*/
void Entrepreneur::set_number_of_license(int number_of_license)
{
	this->_number_of_license = number_of_license;
}

/*__________получение номера паспорта__________*/
int& Entrepreneur::get_number_of_license()
{
	return _number_of_license;
}

/*__________установка информации о налогах__________*/
void Entrepreneur::set_data_dues(int pos, Dues data)
{
	try
	{
		if (pos < 0 or pos >= size_4)throw Container_error(5, "Выход за пределы", "Была выбрана позиция за пределами массива");
		this->_dues[pos] = data;
	}
	catch (Container_error obj)
	{
		obj.show_e();
		exit(1);
	}
}

/*__________получение информации о налогах__________*/
Dues& Entrepreneur::get_data_dues(int pos)
{
	try
	{
		if (pos < 0 or pos >= size_4)throw Container_error(5, "Выход за пределы", "Была выбрана позиция за пределами массива(возвращена возвращена ссылка 0 позицию)");
		return _dues[pos];
	}
	catch (Container_error obj)
	{
		obj.show_e();
		exit(1);
	}
	
}

/*__________установка адреса__________*/
void Entrepreneur::set_address(Address address)
{
	this->_address = address;
}

/*__________получение адреса__________*/
Address& Entrepreneur::get_address()
{
	return _address;
}

/*__________добавление информации о налогах__________*/
void Entrepreneur::add_data_dues(Dues dues)
{
	for (int i = size_4 - 1; i > 0; --i)
		_dues[i] = _dues[i - 1];
	_dues[0] = dues;
}

/*__________таблица для вывода__________*/
void Entrepreneur::table() const
{
	for (int i = 0; i < 83; ++i)
		cout << "-";
	cout << endl;
	Human::table();
	cout << "№ лиц.  |Адрес регистрации|Данные о налогах |" << endl;
	for (int i = 0; i < 83; ++i)
		cout << "-";
	cout << endl;
}

/*__________перегрузка оператора сравнения__________*/
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

/*__________функция меню для редактирования__________*/
Queue<Entrepreneur> menu_correct(Queue<Entrepreneur> mas, int size)
{
	for (;;)
	{
		int number;                          //для ввода номера элемента
		Address adres;                       //для ввода адресов
		Dues info_dues;                      //для ввода данных о налогах

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
				cout << "_______#####______CORRECT_ENTREPRENEUR______#####______" << endl;
				setColor(5);
				cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
				cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
				setColor(11);
				cout << ">> 1 - изменить имя." << endl;
				cout << ">> 2 - изменить фамилию." << endl;
				cout << ">> 3 - изменить год рождения." << endl;
				cout << ">> 4 - изменить номер лицензии." << endl;
				cout << ">> 5 - изменить адрес регистрации." << endl;
				cout << ">> 6 - добавить уплату налога." << endl;
				setColor(4);
				cout << ">> 0 - назад.                                          " << endl;
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
						cout << "Введите номер лицензии:" << endl;
						mas[number].set_number_of_license(input_int(cin, 1, 999999));
						setColor(2);
						cout << "Номер лицензии изменен!" << endl;
						setColor(7);
						break;

					case 5:
						system("cls");
						cout << "Введите улицу регистрации(на английском языке):" << endl;
						input_eng(cin, adres.street);
						cout << "Введите дом регистрации:" << endl;
						adres.number = input_int(cin, 1, 999);
						mas[number].set_address(adres);
						setColor(2);
						cout << "Изменен адрес регистрации!" << endl;
						setColor(7);
						break;

					case 6:
						system("cls");
						cout << "Введите сумму:" << endl;
						info_dues.sum = input_int(cin, 1, 999999);
						cout << "Введите день:" << endl;
						info_dues.date.day = input_int(cin, 1, 31);
						cout << "Введите месяц:" << endl;
						info_dues.date.month = input_int(cin, 1, 12);
						cout << "Введите год:" << endl;
						info_dues.date.year = input_int(cin, 1900, 2022);
						mas[number].add_data_dues(info_dues);
						setColor(2);
						cout << "Добавлена информация о налогах!" << endl;
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
		}
		else
		{
			system("cls");
			return mas;
		}
	}
}

/*__________функция меню для поиска__________*/
Entrepreneur Entrepreneur::menu_for_poisk()
{
	Entrepreneur mas;
	Address adres;                       //для ввода адресов
	Dues info_dues;                      //для ввода данных о налогах

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
		cout << ">> 1 - ввести имя." << endl;
		cout << ">> 2 - ввести фамилию." << endl;
		cout << ">> 3 - ввести год рождения." << endl;
		cout << ">> 4 - ввести номер лицензии." << endl;
		cout << ">> 5 - ввести адрес регистрации." << endl;
		cout << ">> 6 - ввести сумму налога." << endl;
		cout << ">> 7 - ввести дату выплаты налога." << endl;
		setColor(2);
		cout << ">> 0 - начать поиск.                                   " << endl;
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
				cout << "Введите номер лицензии:" << endl;
				mas.set_number_of_license(input_int(cin, 1, 999999));
				setColor(2);
				cout << "Номер лицензии установлен!" << endl;
				setColor(7);
				break;

			case 5:
				system("cls");
				cout << "Введите улицу регистрации(на английском языке):" << endl;
				input_eng(cin, adres.street);
				cout << "Введите дом регистрации:" << endl;
				adres.number = input_int(cin, 1, 999);
				mas.set_address(adres);
				setColor(2);
				cout << "Адрес регистрации установлен!" << endl;
				setColor(7);
				break;

			case 6:
				system("cls");
				cout << "Введите сумму:" << endl;
				mas.get_data_dues(0).sum = input_int(cin, 1, 999999);
				setColor(2);
				cout << "Сумма налога установлена!" << endl;
				setColor(7);
				break;

			case 7:
				system("cls");
				cout << "Введите день:" << endl;
				info_dues.date.day = input_int(cin, 1, 31);
				cout << "Введите месяц:" << endl;
				info_dues.date.month = input_int(cin, 1, 12);
				cout << "Введите год:" << endl;
				info_dues.date.year = input_int(cin, 1900, 2022);
				mas.get_data_dues(0).date = info_dues.date;
				setColor(2);
				cout << "Дата выплаты налога установлена!" << endl;
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
		throw Container_error(1, "Выход за диапозон 1 - 3",
			"Возможно вы хотели выполнить другое действие");

	}
	return obj;
}