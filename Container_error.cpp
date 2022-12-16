#include "Container_error.h"

/*__________вывод__________*/
void Container_error::show_e()
{
	Beep(400, 700);
	Error::show_e();
	setColor(12);
	cout << "Примечание: " << _prim << "." << endl;
	setColor(7);
}