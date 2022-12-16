#pragma once
#include "File.h"

template<class T>
class Binary_file :public File
{
private:

	fstream _file_stream;

public:

	/*__________конструктор__________*/
	Binary_file(const char* name) :File(name)
	{}

	/*__________деструктор__________*/
	~Binary_file()
	{
		_file_stream.close();
	}

	/*__________открытие бинарного файла__________*/
	void OpenFileIn();

	/*__________открытие бинарного файла__________*/
	void OpenFileOut();

	/*__________закрытие бинарного файла__________*/
	void CloseFile();

	/*__________проверка на конец файла__________*/
	bool isEndFile();

	/*__________установление на начало файла__________*/
	void remote();

	/*__________чтение из файла__________*/
	void ReadFromFile(T& obj);

	/*__________запись в файл__________*/
	void WriteInFile(T& obj);
};


