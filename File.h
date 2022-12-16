#pragma once
#include "Standart.h"
#include "Input_error.h"
#include "File_error.h"
#include "Container_error.h"

/*__________класс файла__________*/
class File
{
protected:

	char _file_name[_length_80]; //название файла

public:

	/*__________конструктор__________*/
	File(const char* name)
	{
		strcpy_s(_file_name, name);
	}

	/*__________деструктор__________*/
	~File() {}
};