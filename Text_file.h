#pragma once
#include "File.h"

template<class T>
class Text_file :public File
{
private:

	ifstream _file_input;
	ofstream _file_output;

public:

	/*__________конструктор__________*/
	Text_file(const char* name) :File(name)
	{}

	/*__________деструктор__________*/
	~Text_file()
	{
		_file_input.close();
		_file_output.close();
	}

	/*__________открытие текстового файла__________*/
	void OpenFileIn();

	/*__________закрытие текстового файла__________*/
	void CloseFileIn();

	/*__________открытие текстового файла__________*/
	void OpenFileOut();

	/*__________закрытие текстового файла__________*/
	void CloseFileOut();

	/*__________проверка на конец файла__________*/
	bool isEndInFile();

	/*__________проверка на конец файла__________*/
	bool isEndOutFile();

	/*__________установление на начало файла__________*/
	void remote();

	/*__________чтение из файла__________*/
	void ReadFromFile(T& obj);

	/*__________запись в файл__________*/
	void WriteInFile(T& obj);
};

