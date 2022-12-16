#pragma once
#include "Standart.h"

/*__________класс ошибки__________*/
class Error
{
protected:

	int _code;             //код ошибки
	char _msg[_length_80]; //сообщение

public:
	/*__________конструктор__________*/
	Error(int code, const char* str) :_code(code)
	{
		strcpy_s(_msg, str);
	}

    /*__________деструктор__________*/
	~Error(){}

    /*__________вывод__________*/
	virtual void show_e();

};

