#pragma once
#include "Error.h"

/*__________класс ошибки контейнер__________*/
class Container_error :public Error
{
private:

	char _prim[_length_80];  //примечание

public:
    /*__________конструктор__________*/
	Container_error(int code, const char* str1, const char* str2) :Error(code, str1)
	{
		strcpy_s(_prim, str2);
	}

	/*__________деструктор__________*/
	~Container_error() {}

	/*__________вывод__________*/
	virtual void show_e();
};

