#include "Binary_file.h"

/*__________открытие бинарного файла__________*/
template<class T>
void Binary_file<T>::OpenFileIn()
{
	try
	{
		_file_stream.open(_file_name, ios::in | ios::binary);
		//проверка на существование файла
		if (!_file_stream.good())
		{
			_file_stream.close();
			_file_stream.open(_file_name, ios::out | ios::binary | ios::trunc);
			_file_stream.close();
			_file_stream.open(_file_name, ios::in | ios::binary);
			throw File_error(14, "Файл не открыт",
				"Проверьте целостность файла. Был создан новый файл");
		}
		if (!_file_stream.is_open())
			throw File_error(15, "Файл не открыт",
				"Проверьте целостность файла");
	}
	catch (File_error er)
	{
		er.show_e();
		exit(1);
	}
}

/*__________открытие бинарного файла__________*/
template<class T>
void Binary_file<T>::OpenFileOut()
{
	try
	{
		_file_stream.open(_file_name, ios::out | ios::binary | ios::trunc);
		if (!_file_stream.is_open())
			throw File_error(15, "Файл не открыт",
				"Проверьте целостность файла");
	}
	catch (File_error er)
	{
		er.show_e();
		exit(1);
	}
}

/*__________закрытие бинарного файла__________*/
template<class T>
void Binary_file<T>::CloseFile()
{
	try
	{
		_file_stream.close();
		if (_file_stream.is_open())
			throw File_error(15, "Файл не закрыт",
				"Проверьте целостность файла");
	}
	catch (File_error er)
	{
		er.show_e();
		exit(1);
	}
}

/*__________проверка на конец файла__________*/
template<class T>
bool Binary_file<T>::isEndFile()
{
	return _file_stream.eof();
}

/*__________установление на начало файла__________*/
template<class T>
void Binary_file<T>::remote()
{
	_file_stream.seekg(0, ios::beg);
}

/*__________чтение из файла__________*/
template<class T>
void Binary_file<T>::ReadFromFile(T& obj)
{
	_file_stream >> obj;
}

/*__________запись в файл__________*/
template<class T>
void Binary_file<T>::WriteInFile(T& obj)
{
	_file_stream << obj;
}