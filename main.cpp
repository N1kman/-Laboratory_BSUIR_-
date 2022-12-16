/*

Лабораторная работа № 5

*/

#include "Standart.h"
#include "Interface.cpp"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    for (;;)
    {
        Interface<int>T;
        T.menu();
 
        end_program();      //функция окончания программы
    }
}