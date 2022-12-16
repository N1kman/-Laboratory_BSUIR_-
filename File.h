#pragma once
#include "Standart.h"
#include "Input_error.h"
#include "File_error.h"
#include "Container_error.h"

/*__________����� �����__________*/
class File
{
protected:

	char _file_name[_length_80]; //�������� �����

public:

	/*__________�����������__________*/
	File(const char* name)
	{
		strcpy_s(_file_name, name);
	}

	/*__________����������__________*/
	~File() {}
};