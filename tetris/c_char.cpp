#include "c_char.h"

void Cchar::printCchar(bool color_flag)
{
	if(color_flag)
		setTextColor(this->color);
	cout << this->ch;
}
