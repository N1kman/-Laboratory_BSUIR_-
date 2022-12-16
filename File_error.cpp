#include "File_error.h"

/*__________вывод__________*/
void File_error::show_e()
{
	Beep(400, 700);
	Error::show_e();
	setColor(12);
	cout << "Примечание: " << _prim << "." << endl;
	setColor(7);
}