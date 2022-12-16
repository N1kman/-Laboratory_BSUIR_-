#pragma once
#include "File.h"

template<class T>
class Binary_file :public File
{
private:

	fstream _file_stream;

public:

	/*__________�����������__________*/
	Binary_file(const char* name) :File(name)
	{}

	/*__________����������__________*/
	~Binary_file()
	{
		_file_stream.close();
	}

	/*__________�������� ��������� �����__________*/
	void OpenFileIn();

	/*__________�������� ��������� �����__________*/
	void OpenFileOut();

	/*__________�������� ��������� �����__________*/
	void CloseFile();

	/*__________�������� �� ����� �����__________*/
	bool isEndFile();

	/*__________������������ �� ������ �����__________*/
	void remote();

	/*__________������ �� �����__________*/
	void ReadFromFile(T& obj);

	/*__________������ � ����__________*/
	void WriteInFile(T& obj);
};


