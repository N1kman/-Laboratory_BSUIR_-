#include "Error.h"

/*__________вывод__________*/
void Error::show_e()
{
	Beep(400, 700);
	setColor(12);
	cout << "Код ошибки: " << _code << ". ";
	cout << "Описание: " << _msg << ". " << endl;
	setColor(7);
}