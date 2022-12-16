#include "Interface.h"

/*__________���� �� ������ ����������__________*/
template<class T>
void Interface<T>::menu()
{
	Interface<int> ob;
	
	int choice = 1;
	for (; choice;)
	{
		setColor(5);
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		setColor(2);
		cout << "_________#####___________MENU__________#####___________" << endl;
		setColor(5);
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		setColor(11);
		cout << ">> 1 - ������ � ��������.                     " << endl;
		cout << ">> 2 - ������ � set.             " << endl;
		setColor(4);
		cout << ">> 0 - �����.                                          " << endl;
		setColor(7);
		choice = input_int(cin, 0, 2);
		switch (choice)
		{
		case 1:

			system("CLS");
			ob.menu_choice();
			break;

		case 2:

			system("CLS");
			ob.menu_choice_set();
			break;

		default:

			system("CLS");
			break;
		}
	}
}
/*__________���� ������ ������� ��� ������__________*/
template <class T>
void Interface<T>::menu_choice()
{
	Queue<Tourist> tourist;
	Queue<Entrepreneur> entrepreneur;
	Queue<Businessman> businessman;
	Interface<Tourist> work1;
	Interface<Entrepreneur> work2;
	Interface<Businessman> work3;
	int choice = 1;
	for (; choice;)
	{
		setColor(5);
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		setColor(2);
		cout << "_________#####___________MENU__________#####___________" << endl;
		setColor(5);
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		setColor(11);
		cout << ">> 1 - ������ � �������� ��������.                     " << endl;
		cout << ">> 2 - ������ � �������� ����������������.             " << endl;
		cout << ">> 3 - ������ � �������� ������������.                 " << endl;
		setColor(4);
		cout << ">> 0 - �����.                                          " << endl;
		setColor(7);
		choice = input_int(cin, 0, 3);
		switch (choice)
		{
		case 0:
			system("cls");
			break;

		case 1:
			system("cls");
			tourist = work1.menu_func(tourist, file1, file2);
			break;

		case 2:
			system("cls");
			entrepreneur = work2.menu_func(entrepreneur, file11, file22);
			break;

		case 3:
			system("cls");
			businessman = work3.menu_func(businessman, file111, file222);
			break;

		default:
			break;
		}
	}
}

/*__________���� ������ ������� ��� ������__________*/
template <class T>
void Interface<T>::menu_choice_set()
{
	set<Tourist> tourist;
	set<Entrepreneur> entrepreneur;
	set<Businessman> businessman;
	Interface<Tourist> work1;
	Interface<Entrepreneur> work2;
	Interface<Businessman> work3;
	int choice = 1;
	for (; choice;)
	{
		setColor(5);
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		setColor(2);
		cout << "_________#####___________MENU__________#####___________" << endl;
		setColor(5);
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		setColor(11);
		cout << ">> 1 - ������ � ���������� ��������.                     " << endl;
		cout << ">> 2 - ������ � ���������� ����������������.             " << endl;
		cout << ">> 3 - ������ � ���������� ������������.                 " << endl;
		setColor(4);
		cout << ">> 0 - �����.                                          " << endl;
		setColor(7);
		choice = input_int(cin, 0, 3);
		switch (choice)
		{
		case 0:
			system("cls");
			break;

		case 1:
			system("cls");
			tourist = work1.menu_func(tourist);
			break;

		case 2:
			system("cls");
			entrepreneur = work2.menu_func(entrepreneur);
			break;

		case 3:
			system("cls");
			businessman = work3.menu_func(businessman);
			break;

		default:
			break;
		}
	}
}

/*__________�������������� ����__________*/
template <class T>
Queue<T> Interface<T>::menu_func(Queue<T> obj, const char* name1, const char* name2)
{
	Text_file<T> fil1(name1);
	Binary_file<T> fil2(name2);
	Queue<T> res;
	Algos<T> point;
	T for_add;            //������ ��� ����������
	T read;               //������ ��� ������
	int pos;              //��� ������ �������
	int choice = 1;
	for (; choice;)
	{
		setColor(5);
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		setColor(2);
		cout << "_______#####______FUNCTION_______MENU______#####_______" << endl;
		setColor(5);
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		setColor(11);
		cout << ">> 1 - ����� � ������." << endl;
		cout << ">> 2 - ����� � ������." << endl;
		cout << ">> 3 - ���������� � �����." << endl;
		cout << ">> 4 - ���������� � ������." << endl;
		cout << ">> 5 - ���������� �� �������." << endl;
		cout << ">> 6 - �������� �� ������." << endl;
		cout << ">> 7 - �������� �� ������." << endl;
		cout << ">> 8 - �������� �� �������." << endl;
		cout << ">> 9 - ��������� ���������� ��������� �������." << endl;
		cout << ">> 10 - ������ ������� �������." << endl;
		cout << ">> 11 - ������ � ��������� ����." << endl;
		cout << ">> 12 - ������ �� ���������� �����." << endl;
		cout << ">> 13 - ������ � �������� ����." << endl;
		cout << ">> 14 - ������ �� ��������� �����." << endl;
		cout << ">> 15 - ���������� �� �����������." << endl;
		cout << ">> 16 - ���������� �� ��������." << endl;
		cout << ">> 17 - �����." << endl;
		cout << ">> 18 - ����� ����� ��������." << endl;
		setColor(12);
		cout << ">> 0 - �����." << endl;
		setColor(7);
		choice = input_int(cin, 0, 18);
		switch (choice)
		{
		case 0:
			system("cls");
			break;

		case 1:
			system("cls");
			if (!obj.empty())obj.get_example_zero().table();
			obj.show(0);
			break;

		case 2:
			system("cls");
			if (!obj.empty())obj.get_example_zero().table();
			obj.show(1);
			break;

		case 3:
			system("cls");
			setColor(2);
			cout << "������� ����������:" << endl;
			setColor(7);
			cin >> for_add;
			obj.push_back(for_add);
			setColor(2);
			cout << "������� ��������!" << endl;
			setColor(7);
			break;

		case 4:
			system("cls");
			setColor(2);
			cout << "������� ����������:" << endl;
			setColor(7);
			cin >> for_add;
			obj.push_front(for_add);
			setColor(2);
			cout << "������� ��������!" << endl;
			setColor(7);
			break;

		case 5:
			system("cls");
			setColor(2);
			cout << "������� ������:" << endl;
			setColor(7);
			pos = input_int(cin, 0, obj.size());
			setColor(2);
			cout << "������� ����������:" << endl;
			setColor(7);
			cin >> for_add;
			obj.push_any(for_add, pos);
			setColor(2);
			cout << "������� ��������!" << endl;
			setColor(7);
			break;

		case 6:
			system("cls");
			obj.pop_back();
			break;

		case 7:
			system("cls");
			obj.pop_front();
			break;

		case 8:
			system("cls");
			cout << "������� ������:" << endl;
			pos = input_int(cin, 0, obj.size());
			obj.pop_any(pos);
			setColor(2);
			cout << "������� ������!" << endl;
			setColor(7);
			break;

		case 9:
			system("cls");
			obj = menu_correct(obj, obj.size());
			break;

		case 10:
			system("cls");
			obj.clear();
			setColor(2);
			cout << "������� �������!" << endl;
			setColor(7);
			break;

		case 11:
			system("cls");
			fil1.OpenFileOut();
			fil1.remote();
			while (!obj.empty())
			{
				read = obj.pop_back_ret();
				fil1.WriteInFile(read);
			}
			fil1.CloseFileOut();
			setColor(2);
			cout << "���������� �������� � ��������� ����!" << endl;
			setColor(7);
			break;

		case 12:
			system("cls");
			fil1.OpenFileIn();
			fil1.remote();
			while (1)
			{
				fil1.ReadFromFile(read);
				if (fil1.isEndInFile())break;
				obj.push_front(read);
			}
			fil1.CloseFileIn();
			setColor(2);
			cout << "���������� ��������� �� ���������� �����!" << endl;
			setColor(7);
			break;

		case 13:
			system("cls");
			fil2.OpenFileOut();
			fil2.remote();
			while (!obj.empty())
			{
				read = obj.pop_back_ret();
				fil2.WriteInFile(read);
			}
			fil2.CloseFile();
			setColor(2);
			cout << "���������� �������� � �������� ����!" << endl;
			setColor(7);
			break;

		case 14:
			system("cls");
			fil2.OpenFileIn();
			fil2.remote();
			while (1)
			{
				fil2.ReadFromFile(read);
				if (fil2.isEndFile())break;
				obj.push_front(read);
			}
			fil2.CloseFile();
			setColor(2);
			cout << "���������� ��������� �� ��������� �����!" << endl;
			setColor(7);
			break;

		case 15:
			system("cls");
			try
			{
				if (!obj.size())
				{
					throw Container_error(6, "������� �����",
						"�������� �������� ��������� ������ ��������");
				}
				else
				{
					int choice = (*(obj.begin())).menu_sort();
					point.sort(obj.begin(), obj.end(),
						[](T& ob1, T& ob2)
						{
							return ob1 < ob2; 
						}
					, choice);
					system("cls");
					setColor(2);
					cout << "������� �������������!" << endl;
					setColor(7);
				}
			}
			catch (Container_error e)
			{
				e.show_e();
			}
			break;

		case 16:
			system("cls");
			try
			{
				if (!obj.size())
				{
					throw Container_error(6, "������� �����",
						"�������� �������� ��������� ������ ��������");
				}
				else
				{
					int choice = (*(obj.begin())).menu_sort();
					point.sort(obj.begin(), obj.end(),
						[](T& ob1, T& ob2)
						{
							return ob1 > ob2;
						}
					, choice);
					system("cls");
					setColor(2);
					cout << "������� �������������!" << endl;
					setColor(7);
				}
			}
			catch (Container_error e)
			{
				e.show_e();
			}
			break;

		case 17:
			system("cls");
			try
			{
				if (!obj.size())
				{
					throw Container_error(6, "������� �����",
						"�������� �������� ��������� ������ ��������");
				}
				else
				{
					for_add = for_add.menu_for_poisk();
					for (auto it = obj.begin();; ++it)
					{
						it = point.poisk(it, obj.end(), for_add);
						if (it == obj.end()) break;
						res.push_back(*it);
					}
					cout << "��������� ������:" << endl;
					if (!res.empty())res.get_example_zero().table();
					res.show(0);
					res.clear();
				}
			}
			catch (Container_error e)
			{
				e.show_e();
			}
			break;

		case 18:
			system("cls");
			try
			{
				if (!obj.size())
				{
					throw Container_error(6, "������� �����",
						"�������� �������� ��������� ������ ��������");
				}
				else
				{
					obj.get_example_zero().table();
					for (auto it = obj.begin(); it != obj.end(); ++it)
						cout << *it;
				}
			}
			catch (Container_error e)
			{
				e.show_e();
			}
			break;

		default:
			system("cls");
			break;
		}
	}
	return obj;
}

/*__________�������������� ����__________*/
template <class T>
set<T> Interface<T>::menu_func(set<T> arr)
{
	T for_add;
	int choice = 1;
	for (; choice;)
	{
		setColor(5);
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		setColor(2);
		cout << "_______#####______FUNCTION_______MENU______#####_______" << endl;
		setColor(5);
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		setColor(11);
		cout << ">> 1 - ����� ������� ����������." << endl;
		cout << ">> 2 - ����� ������������� ������� ����������." << endl;
		cout << ">> 3 - ���������� �������." << endl;
		cout << ">> 4 - �������� �������." << endl;
		cout << ">> 5 - ����� ���������� �� �������� ���� ������� ��������� �������." << endl;
		cout << ">> 6 - ����� ����������." << endl;
		cout << ">> 7 - ������� ����������." << endl;
		setColor(12);
		cout << ">> 0 - �����." << endl;
		setColor(7);
		choice = input_int(cin, 0, 7);
		switch (choice)
		{
		case 0:
			system("cls");
			break;

		case 1:
			system("cls");
			//����� size() - ���������� ������ ����������
			cout << "������: " << arr.size() << endl;
			break;

		case 2:
			system("cls");
			//����� max_size() - ���������� ������������ ������ ����������
			cout << "������������ ������: " << arr.max_size() << endl;
			break;

		case 3:
			system("cls");
			try
			{
				cin >> for_add;
				//����� insert() - ��������� ������ � ��������� � 
				//���������� ���� pair<������,true ��� ����������(false ��� �� ����������)>
				if (!(arr.insert(for_add)).second)
					throw Container_error(8, "������� �� ��������",
						"��������� ��������� ������");
				setColor(2);
				cout << "������� ��������!" << endl;
				setColor(7);
			}
			catch (Container_error err)
			{
				err.show_e();
			}
			break;

		case 4:
			system("cls");
			cin >> for_add;
			try
			{
				//����� find() - ���������� �������� �� ��������� ����������� ������� ���, �������� �������� �� end
				if (arr.find(for_add) != arr.end())
				{
					setColor(2);
					cout << "������� ������!" << endl;
					setColor(7);
					//����� erase() - ������� ������ �� ����������
					arr.erase(for_add);
				}
				else
				{
					throw Container_error(8, "������� �� ������",
						"�������� �� ������ ������� ������ �������");
				}
			}
			catch (Container_error err)
			{
				system("cls");
				err.show_e();
			}
			break;

		case 5:
			system("cls");
			cin >> for_add;
			try
			{
				//����� lower_bound() - ���������� �������� �� ������� ���� ������ ��������� ������� � ����������
				typename set<T>::iterator it = arr.lower_bound(for_add);
				if (it != arr.end())
				{
					(*it).table();
					/*for (; it != arr.end(); it++)
						cout << *it;*/
					//���� for_each
					for_each(it, arr.end(), [](T ob) {cout << ob; });
				}
				else
				{
					throw Container_error(8, "������� ������� ���� ������ �� ������",
						"�������� �� ������ ������� ������ �������");
				}
			}
			catch (Container_error err)
			{
				system("cls");
				err.show_e();
			}
			break;

		case 6:
			system("cls");
			try
			{
				//����� emty() - �������� ���� �� ���������
				if (arr.empty())
				{
					throw Container_error(7, "����� �� ������� ����������",
						"�������� �� ������ ��������� ������ ��������");
				}
				for_add.table();
				for (auto obj : arr)
					cout << obj;
			}
			catch (Container_error er)
			{
				system("cls");
				er.show_e();
			}
			break;

		case 7:
			system("cls");
			//����� clear() - ������� ����������
			arr.clear();
			break;

		default:
			system("cls");
			break;
		}
	}
	return arr;
}
