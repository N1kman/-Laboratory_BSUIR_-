#include "Text_file.h"

/*__________открытие текстового файла__________*/
template<class T>
void Text_file<T>::OpenFileIn()
{
	try
	{
		_file_input.open(_file_name, ios::in);
		//проверка на существование файла
		if (!_file_stream.good())
		{
			_file_stream.close();
			_file_output.open(_file_name, ios::out | ios_base::trunc);
			_file_stream.close();
			_file_input.open(_file_name, ios::in);
			throw File_error(14, "Файл не открыт",
				"Проверьте целостность файла. Был создан новый файл");
		}
		if (!_file_input.is_open())
			throw File_error(15, "Файл не открыт",
				"Проверьте целостность файла");
	}
	catch (File_error er)
	{
		er.show_e();
		exit(1);
	}
}

/*__________закрытие текстового файла__________*/
template<class T>
void Text_file<T>::CloseFileIn()
{
	try
	{
		_file_input.close();
		if (_file_input.is_open())
			throw File_error(15, "Файл не закрыт",
				"Проверьте целостность файла");
	}
	catch (File_error er)
	{
		er.show_e();
		exit(1);
	}
}

/*__________открытие текстового файла__________*/
template<class T>
void Text_file<T>::OpenFileOut()
{
	try
	{
		_file_output.open(_file_name, ios::out | ios_base::trunc);
		if (!_file_output.is_open())
			throw File_error(15, "Файл не открыт",
				"Проверьте целостность файла");
	}
	catch (File_error er)
	{
		er.show_e();
		exit(1);
	}
}

/*__________закрытие текстового файла__________*/
template<class T>
void Text_file<T>::CloseFileOut()
{
	try
	{
		_file_output.close();
		if (_file_output.is_open())
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
bool Text_file<T>::isEndInFile()
{
	return _file_input.eof();
}

/*__________проверка на конец файла__________*/
template<class T>
bool Text_file<T>::isEndOutFile()
{
	return _file_output.eof();
}

/*__________установление на начало файла__________*/
template<class T>
void Text_file<T>::remote()
{
	_file_input.seekg(0, ios::beg);
	_file_output.seekp(0, ios::beg);
}

/*__________чтение из файла__________*/
template<class T>
void Text_file<T>::ReadFromFile(T& obj)
{
	_file_input >> obj;
}

/*__________запись в файл__________*/
template<class T>
void Text_file<T>::WriteInFile(T& obj)
{
	_file_output << obj;
}