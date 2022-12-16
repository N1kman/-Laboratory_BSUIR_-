#include "Standart.h"
#include "Businessman.h"

/*__________функция окончания программы__________*/
void end_program()
{
	system("cls");
	setColor(2);
	puts("Попробуете снова?(Y/N)");
	setColor(7);
	for (;;)
	{
		try
		{
			rewind(stdin);                                   //очистка буффера
			char choice;
			cin >> choice;                                   //ввод 
			if (!cin)
			{
				cin.clear();
				throw Input_error(4, "Ошибка ввода строки", "Введите 1 символ");
			}
			if (choice == 'N' or choice == 'n')
			{
				system("cls");
				setColor(11);
				cout << " ___________________________" << endl;
				cout << " |#### |                   |" << endl;
				cout << " |_____|    THANK YOU      |" << endl;
				cout << ">>   - |     GOODBYE       |" << endl;
				cout << " |_____|___________________|" << endl;
				cout << "    @@                 @@   " << endl;
				setColor(7);
				exit(0);         //выход из программы	
			}
			else if (choice == 'Y' or choice == 'y') return; //выход из функции
			else
			{
				throw Input_error(2, "Ошибка выбора", "Данной опции не добавлено,доступно: N(n)|Y(y)");
			}
		}
		catch (Input_error obj)
		{
			obj.show_e();
		}
	}
}

/*__________ввод русской строки__________*/
char* input_rus(istream& in, char* str)
{
	setColor(13);
	cout << "[12]" << endl;
	setColor(7);
	bool flag = false;
	do
	{
		flag = true;
		try
		{
			rewind(stdin);
			in.getline(str, _length_12);
			//проверка переполнения строки
			if (!cin)
			{
				cin.clear();
				throw Input_error(4, "Ошибка ввода строки", "Ограничение на 12 символов");
			}
			//проверка на ввод строки
			if (!strlen(str))
				throw Input_error(1, "Ошибка ввода строки", "Строка не введена");
			//проверка на русские символы
			for (size_t i = 0; i < strlen(str); ++i)
			{
				if ((str[i] < 'А' or str[i] >'я') and str[i] != '-')
					throw Input_error(1, "Ошибка ввода строки", "Введены нерусские буквы");
			}
		}
		catch (Input_error obj)
		{
			obj.show_e();
			flag = false;
		}
	} while (!flag);
	return str;
}

/*__________ввод английской строки__________*/
char* input_eng(istream& in, char* str)
{
	setColor(13);
	cout << "[12]" << endl;
	setColor(7);
	bool flag = false;
	do
	{
		flag = true;
		try
		{
			rewind(stdin);
			in.getline(str, _length_12);
			//проверка переполнения строки
			if (!cin)
			{
				cin.clear();
				throw Input_error(4, "Ошибка ввода строки", "Ограничение на 12 символов");
			}
			//проверка на ввод строки
			if (!strlen(str))
				throw Input_error(1, "Ошибка ввода строки", "Строка не введена");
			//проверка на английские символы
			for (size_t i = 0; i < strlen(str); ++i)
			{
				if ((str[i] < 'a' or str[i] >'z') and (str[i] < 'A' or str[i] >'Z')
					and str[i] != '-')throw Input_error(1, "Ошибка ввода строки", "Введены неанглийские буквы");
			}
		}
		catch (Input_error obj)
		{
			obj.show_e();
			flag = false;
		}
	} while (!flag);
	return str;
}

/*__________ввод целого числа__________*/
int input_int(istream& in, int _a, int _b)
{
	setColor(13);
	cout << "[" << _a << ";" << _b << "]" << endl;
	setColor(7);
	int _int;
	bool flag = false;
	do
	{
		flag = true;
		try
		{
			rewind(stdin);
			in >> _int;
			//проверка введено ли число
			if (cin.peek() != '\n')
			{
				throw Input_error(2, "Ошибка ввода", "Введено не число");
			}
			//проверка введено ли число
			if (!in)
			{
				throw Input_error(2, "Ошибка ввода", "Введено не число");
			}
			//проверка выхода за границу
			if (_int<_a or _int>_b)
			{
				throw Input_error(2, "Ошибка ввода", "Выход за границы");
			}
		}
		catch (Input_error obj)
		{
			obj.show_e();
			flag = false;
			in.clear();
		}
	} while (!flag);
	return _int;
}

/*__________ввод паспорта__________*/
char* input_pasport(istream& in, char* str)
{

	bool flag = false;
	do
	{
		flag = true;
		try
		{
			rewind(stdin);
			in.getline(str, size_9);
			//проверка переполнения строки
			if (!cin)
			{
				cin.clear();
				throw Input_error(4, "Ошибка ввода строки", "Номер паспорта состоит из 9 символов");
			}
			//проверка серии
			for (size_t i = 0; i < 2; ++i)
			{
				if (str[i] < 'A' or str[i] >'Z')throw Input_error(3, "Ошибка ввода паспорта", "Введите серию и номер паспорта");
			}
			//проверка номера
			for (size_t i = 2; i < size_9 - 1; ++i)
			{
				if (str[i] < '0' or str[i] >'9')throw Input_error(3, "Ошибка ввода паспорта", "Введите серию и номер паспорта");
			}
		}
		catch (Input_error obj)
		{
			obj.show_e();
			flag = false;
		}
	} while (!flag);
	return str;
}

/*__________метод задания цвета тексту__________*/
void setColor(int color) 
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color); //задание цвета текста
}

/*__________перегрузка ввода__________*/
std::istream& operator>>(std::istream& in, Date& T)
{
	cout << "Введите день:" << endl;
	T.day = input_int(in, 1, 31);
	cout << "Введите месяц:" << endl;
	T.month = input_int(in, 1, 12);
	cout << "Введите год:" << endl;
	T.year = input_int(in, 1900, 2022);
	return in;
}

/*__________перегрузка чтения из файла__________*/
std::ifstream& operator>>(std::ifstream& in, Date& T)
{
	in >> T.day
		>> T.month
		>> T.year;
	return in;
}