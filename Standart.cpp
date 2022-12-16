#include "Standart.h"
#include "Businessman.h"

/*__________������� ��������� ���������__________*/
void end_program()
{
	system("cls");
	setColor(2);
	puts("���������� �����?(Y/N)");
	setColor(7);
	for (;;)
	{
		try
		{
			rewind(stdin);                                   //������� �������
			char choice;
			cin >> choice;                                   //���� 
			if (!cin)
			{
				cin.clear();
				throw Input_error(4, "������ ����� ������", "������� 1 ������");
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
				exit(0);         //����� �� ���������	
			}
			else if (choice == 'Y' or choice == 'y') return; //����� �� �������
			else
			{
				throw Input_error(2, "������ ������", "������ ����� �� ���������,��������: N(n)|Y(y)");
			}
		}
		catch (Input_error obj)
		{
			obj.show_e();
		}
	}
}

/*__________���� ������� ������__________*/
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
			//�������� ������������ ������
			if (!cin)
			{
				cin.clear();
				throw Input_error(4, "������ ����� ������", "����������� �� 12 ��������");
			}
			//�������� �� ���� ������
			if (!strlen(str))
				throw Input_error(1, "������ ����� ������", "������ �� �������");
			//�������� �� ������� �������
			for (size_t i = 0; i < strlen(str); ++i)
			{
				if ((str[i] < '�' or str[i] >'�') and str[i] != '-')
					throw Input_error(1, "������ ����� ������", "������� ��������� �����");
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

/*__________���� ���������� ������__________*/
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
			//�������� ������������ ������
			if (!cin)
			{
				cin.clear();
				throw Input_error(4, "������ ����� ������", "����������� �� 12 ��������");
			}
			//�������� �� ���� ������
			if (!strlen(str))
				throw Input_error(1, "������ ����� ������", "������ �� �������");
			//�������� �� ���������� �������
			for (size_t i = 0; i < strlen(str); ++i)
			{
				if ((str[i] < 'a' or str[i] >'z') and (str[i] < 'A' or str[i] >'Z')
					and str[i] != '-')throw Input_error(1, "������ ����� ������", "������� ������������ �����");
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

/*__________���� ������ �����__________*/
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
			//�������� ������� �� �����
			if (cin.peek() != '\n')
			{
				throw Input_error(2, "������ �����", "������� �� �����");
			}
			//�������� ������� �� �����
			if (!in)
			{
				throw Input_error(2, "������ �����", "������� �� �����");
			}
			//�������� ������ �� �������
			if (_int<_a or _int>_b)
			{
				throw Input_error(2, "������ �����", "����� �� �������");
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

/*__________���� ��������__________*/
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
			//�������� ������������ ������
			if (!cin)
			{
				cin.clear();
				throw Input_error(4, "������ ����� ������", "����� �������� ������� �� 9 ��������");
			}
			//�������� �����
			for (size_t i = 0; i < 2; ++i)
			{
				if (str[i] < 'A' or str[i] >'Z')throw Input_error(3, "������ ����� ��������", "������� ����� � ����� ��������");
			}
			//�������� ������
			for (size_t i = 2; i < size_9 - 1; ++i)
			{
				if (str[i] < '0' or str[i] >'9')throw Input_error(3, "������ ����� ��������", "������� ����� � ����� ��������");
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

/*__________����� ������� ����� ������__________*/
void setColor(int color) 
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color); //������� ����� ������
}

/*__________���������� �����__________*/
std::istream& operator>>(std::istream& in, Date& T)
{
	cout << "������� ����:" << endl;
	T.day = input_int(in, 1, 31);
	cout << "������� �����:" << endl;
	T.month = input_int(in, 1, 12);
	cout << "������� ���:" << endl;
	T.year = input_int(in, 1900, 2022);
	return in;
}

/*__________���������� ������ �� �����__________*/
std::ifstream& operator>>(std::ifstream& in, Date& T)
{
	in >> T.day
		>> T.month
		>> T.year;
	return in;
}