#pragma once
#include "File.h"

template<class T>
class Text_file :public File
{
private:

	ifstream _file_input;
	ofstream _file_output;

public:

	/*__________�����������__________*/
	Text_file(const char* name) :File(name)
	{}

	/*__________����������__________*/
	~Text_file()
	{
		_file_input.close();
		_file_output.close();
	}

	/*__________�������� ���������� �����__________*/
	void OpenFileIn();

	/*__________�������� ���������� �����__________*/
	void CloseFileIn();

	/*__________�������� ���������� �����__________*/
	void OpenFileOut();

	/*__________�������� ���������� �����__________*/
	void CloseFileOut();

	/*__________�������� �� ����� �����__________*/
	bool isEndInFile();

	/*__________�������� �� ����� �����__________*/
	bool isEndOutFile();

	/*__________������������ �� ������ �����__________*/
	void remote();

	/*__________������ �� �����__________*/
	void ReadFromFile(T& obj);

	/*__________������ � ����__________*/
	void WriteInFile(T& obj);
};

