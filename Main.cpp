#include "Header.h"



int main()
{
	QInt x;
	string str;
	cout << "Nhap vao chuoi so: ";
	cin >> str;

	ScanQInt(x, str);

	cout << endl;
	PrintQInt(x);

	return 0;
}
