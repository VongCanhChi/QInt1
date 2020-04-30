#include "Header.h"



int main()
{
	QInt x;
	string str;
	cout << "Nhap vao chuoi so: ";
	cin >> str;

	ScanQInt(x, str);


//	int daybit[128];
//	qIntToDayBit(x, daybit);
//	for (int i = 0; i < 128; i++)
//{
//	cout << daybit[i];
//}

	//cout << endl;
	//int dayso1[100];
	//tinhHaiMuX(dayso1, 12);
	//int dayso2[100];
	//tinhHaiMuX(dayso2, 12);
	//
	//truHaiDayBit(dayso1, dayso2);
	//for (int i = 0; i < 100; i++)
	//{
	//	cout << dayso2[i];
	//}


	cout << endl;
	PrintQInt(x);

	return 0;
}