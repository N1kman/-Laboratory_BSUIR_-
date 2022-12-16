#include "Text_file.h"

/*__________�������� ���������� �����__________*/
template<class T>
void Text_file<T>::OpenFileIn()
{
	try
	{
		_file_input.open(_file_name, ios::in);
		//�������� �� ������������� �����
		if (!_file_stream.good())
		{
			_file_stream.close();
			_file_output.open(_file_name, ios::out | ios_base::trunc);
			_file_stream.close();
			_file_input.open(_file_name, ios::in);
			throw File_error(14, "���� �� ������",
				"��������� ����������� �����. ��� ������ ����� ����");
		}
		if (!_file_input.is_open())
			throw File_error(15, "���� �� ������",
				"��������� ����������� �����");
	}
	catch (File_error er)
	{
		er.show_e();
		exit(1);
	}
}

/*__________�������� ���������� �����__________*/
template<class T>
void Text_file<T>::CloseFileIn()
{
	try
	{
		_file_input.close();
		if (_file_input.is_open())
			throw File_error(15, "���� �� ������",
				"��������� ����������� �����");
	}
	catch (File_error er)
	{
		er.show_e();
		exit(1);
	}
}

/*__________�������� ���������� �����__________*/
template<class T>
void Text_file<T>::OpenFileOut()
{
	try
	{
		_file_output.open(_file_name, ios::out | ios_base::trunc);
		if (!_file_output.is_open())
			throw File_error(15, "���� �� ������",
				"��������� ����������� �����");
	}
	catch (File_error er)
	{
		er.show_e();
		exit(1);
	}
}

/*__________�������� ���������� �����__________*/
template<class T>
void Text_file<T>::CloseFileOut()
{
	try
	{
		_file_output.close();
		if (_file_output.is_open())
			throw File_error(15, "���� �� ������",
				"��������� ����������� �����");
	}
	catch (File_error er)
	{
		er.show_e();
		exit(1);
	}
}

/*__________�������� �� ����� �����__________*/
template<class T>
bool Text_file<T>::isEndInFile()
{
	return _file_input.eof();
}

/*__________�������� �� ����� �����__________*/
template<class T>
bool Text_file<T>::isEndOutFile()
{
	return _file_output.eof();
}

/*__________������������ �� ������ �����__________*/
template<class T>
void Text_file<T>::remote()
{
	_file_input.seekg(0, ios::beg);
	_file_output.seekp(0, ios::beg);
}

/*__________������ �� �����__________*/
template<class T>
void Text_file<T>::ReadFromFile(T& obj)
{
	_file_input >> obj;
}

/*__________������ � ����__________*/
template<class T>
void Text_file<T>::WriteInFile(T& obj)
{
	_file_output << obj;
}