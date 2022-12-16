#include "Interface.h"

/*__________меню по выбору контейнера__________*/
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
		cout << ">> 1 - работа с очередью.                     " << endl;
		cout << ">> 2 - работа с set.             " << endl;
		setColor(4);
		cout << ">> 0 - выход.                                          " << endl;
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
/*__________меню выбора объекта для работы__________*/
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
		cout << ">> 1 - работа с очередью туристов.                     " << endl;
		cout << ">> 2 - работа с очередью предпринимателей.             " << endl;
		cout << ">> 3 - работа с очередью бизнессменов.                 " << endl;
		setColor(4);
		cout << ">> 0 - выход.                                          " << endl;
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

/*__________меню выбора объекта для работы__________*/
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
		cout << ">> 1 - работа с множеством туристов.                     " << endl;
		cout << ">> 2 - работа с множеством предпринимателей.             " << endl;
		cout << ">> 3 - работа с множеством бизнессменов.                 " << endl;
		setColor(4);
		cout << ">> 0 - выход.                                          " << endl;
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

/*__________функциональное меню__________*/
template <class T>
Queue<T> Interface<T>::menu_func(Queue<T> obj, const char* name1, const char* name2)
{
	Text_file<T> fil1(name1);
	Binary_file<T> fil2(name2);
	Queue<T> res;
	Algos<T> point;
	T for_add;            //объект для добавления
	T read;               //объект для чтения
	int pos;              //для выбора позиции
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
		cout << ">> 1 - вывод с головы." << endl;
		cout << ">> 2 - вывод с хвоста." << endl;
		cout << ">> 3 - добавление в хвост." << endl;
		cout << ">> 4 - добавление в голову." << endl;
		cout << ">> 5 - добавление по индексу." << endl;
		cout << ">> 6 - удаление из хвоста." << endl;
		cout << ">> 7 - удаление из головы." << endl;
		cout << ">> 8 - удаление по индексу." << endl;
		cout << ">> 9 - изменение параметров элементов очереди." << endl;
		cout << ">> 10 - полная очистка очереди." << endl;
		cout << ">> 11 - запись в текстовый файл." << endl;
		cout << ">> 12 - чтение из текстового файла." << endl;
		cout << ">> 13 - запись в бинарный файл." << endl;
		cout << ">> 14 - чтение из бинарного файла." << endl;
		cout << ">> 15 - сортировка по возрастанию." << endl;
		cout << ">> 16 - сортировка по убыванию." << endl;
		cout << ">> 17 - поиск." << endl;
		cout << ">> 18 - вывод через итератор." << endl;
		setColor(12);
		cout << ">> 0 - назад." << endl;
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
			cout << "Введите информацию:" << endl;
			setColor(7);
			cin >> for_add;
			obj.push_back(for_add);
			setColor(2);
			cout << "Элемент добавлен!" << endl;
			setColor(7);
			break;

		case 4:
			system("cls");
			setColor(2);
			cout << "Введите информацию:" << endl;
			setColor(7);
			cin >> for_add;
			obj.push_front(for_add);
			setColor(2);
			cout << "Элемент добавлен!" << endl;
			setColor(7);
			break;

		case 5:
			system("cls");
			setColor(2);
			cout << "Введите индекс:" << endl;
			setColor(7);
			pos = input_int(cin, 0, obj.size());
			setColor(2);
			cout << "Введите информацию:" << endl;
			setColor(7);
			cin >> for_add;
			obj.push_any(for_add, pos);
			setColor(2);
			cout << "Элемент добавлен!" << endl;
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
			cout << "Введите индекс:" << endl;
			pos = input_int(cin, 0, obj.size());
			obj.pop_any(pos);
			setColor(2);
			cout << "Элемент удален!" << endl;
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
			cout << "Очередь очищена!" << endl;
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
			cout << "Информация записана в текстовый файл!" << endl;
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
			cout << "Информация прочитана из текстового файла!" << endl;
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
			cout << "Информация записана в бинарный файл!" << endl;
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
			cout << "Информация прочитана из бинарного файла!" << endl;
			setColor(7);
			break;

		case 15:
			system("cls");
			try
			{
				if (!obj.size())
				{
					throw Container_error(6, "Очередь пуста",
						"Возможно выхотели выполнить другое действие");
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
					cout << "Очередь отсортирована!" << endl;
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
					throw Container_error(6, "Очередь пуста",
						"Возможно выхотели выполнить другое действие");
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
					cout << "Очередь отсортирована!" << endl;
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
					throw Container_error(6, "Очередь пуста",
						"Возможно выхотели выполнить другое действие");
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
					cout << "Результат поиска:" << endl;
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
					throw Container_error(6, "Очередь пуста",
						"Возможно выхотели выполнить другое действие");
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

/*__________функциональное меню__________*/
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
		cout << ">> 1 - вывод размера контейнера." << endl;
		cout << ">> 2 - вывод максимального размера контейнера." << endl;
		cout << ">> 3 - добавление объекта." << endl;
		cout << ">> 4 - удаление объекта." << endl;
		cout << ">> 5 - вывод контейнера от большего либо равного заданного объекта." << endl;
		cout << ">> 6 - вывод контейнера." << endl;
		cout << ">> 7 - очистка контейнера." << endl;
		setColor(12);
		cout << ">> 0 - назад." << endl;
		setColor(7);
		choice = input_int(cin, 0, 7);
		switch (choice)
		{
		case 0:
			system("cls");
			break;

		case 1:
			system("cls");
			//метод size() - возвращает размер контейнера
			cout << "Размер: " << arr.size() << endl;
			break;

		case 2:
			system("cls");
			//метод max_size() - возвращает максимальный размер контейнера
			cout << "Максимальный размер: " << arr.max_size() << endl;
			break;

		case 3:
			system("cls");
			try
			{
				cin >> for_add;
				//метод insert() - добавляет объект в контейнер и 
				//возвращает пару pair<объект,true при выполнении(false при не выполнении)>
				if (!(arr.insert(for_add)).second)
					throw Container_error(8, "Элемент не добавлен",
						"Проверьте введенные данные");
				setColor(2);
				cout << "Элемент добавлен!" << endl;
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
				//метод find() - возвращает итератор на найденный объектбесли таковых нет, вернется итератор на end
				if (arr.find(for_add) != arr.end())
				{
					setColor(2);
					cout << "Элемент удален!" << endl;
					setColor(7);
					//метод erase() - удаляет объект из контейнера
					arr.erase(for_add);
				}
				else
				{
					throw Container_error(8, "Элемент не найден",
						"Возможно вы хотели удалить другой элемент");
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
				//метод lower_bound() - возвращает итератор на больший либо равный заданному объекту в параметрах
				typename set<T>::iterator it = arr.lower_bound(for_add);
				if (it != arr.end())
				{
					(*it).table();
					/*for (; it != arr.end(); it++)
						cout << *it;*/
					//цикл for_each
					for_each(it, arr.end(), [](T ob) {cout << ob; });
				}
				else
				{
					throw Container_error(8, "Элемент больший либо равный не найден",
						"Возможно вы хотели удалить другой элемент");
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
				//метод emty() - проверка пуст ли контейнер
				if (arr.empty())
				{
					throw Container_error(7, "Выход за пределы контейнера",
						"Возможно вы хотели выполнить другое действие");
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
			//метод clear() - очистка контейнера
			arr.clear();
			break;

		default:
			system("cls");
			break;
		}
	}
	return arr;
}
