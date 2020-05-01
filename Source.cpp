#include "Header.h"


void DocDayBit(int X, int a[32])
{
	for (int i = 0; i < 32; i++)
		a[i] = (X >> (31 - i)) & 1;
}

void setBit1(int &X, int i)
{
	X = (X | (1 << (31 - i)));
}

void setBit0(int& X, int i)
{
	X = (X & (0 << (31 - i)));
}
int GetBit(int X, int i)
{
	return (X >> (31 - i)) & 1;
}

void stringToBit(string str, int daybit[])
{
	for (int i = 0; i < 128; i++) {
		daybit[i] = 0;
	}
	int leng = str.length();
	int* songuyenlon = new int[100];
	int t = 0;
	if (str.compare(0, 1, "-") == 0) {
		leng = leng - 1;
		t = 1;
	}
	for (int i = 0; i < leng; i++) {
		songuyenlon[i] = (int)str[i + t] - 48;
	}
	int dem = 0;
	for (int j = 0; ; j++) {
		dem = 0;
		if (songuyenlon[leng - 1] % 2 != 0)
			daybit[127 - j] = 1;
		for (int l = 0; l < leng; l++) {
			if (songuyenlon[l] % 2 != 0)
				songuyenlon[l + 1] = songuyenlon[l + 1] + 10;
			songuyenlon[l] = songuyenlon[l] / 2;
			if (songuyenlon[l] == 0) {
				dem++;
			}
		}
		if (dem == leng) {
			break;
		}
	}
	if (str.compare(0, 1, "-") == 0) {
		for (int i = 0; i < 128; i++) {
			if (daybit[i] == 0) daybit[i] = 1;
			else daybit[i] = 0;
		}
		daybit[127] = daybit[127] + 1;
		for (int i = 127; i >= 0; i--) {
			if (daybit[i] == 2) {
				daybit[i] = 0;
				daybit[i - 1] = daybit[i - 1] + 1;
			}
			else {
				daybit[i] = 1;
				break;
			}
		}
	}
}

void ScanQInt(QInt& x, string str)
{
	for (int i = 0; i < 4; i++) {
		x.data[i] = 0;
	}
	int daybit[128];
	stringToBit(str, daybit);

	for (int i = 0; i < 128; i++) {
		if (daybit[i] == 1) {
			setBit1(x.data[i / 32], i % 32);
		}
	}
	cout << "Dang nhi phan:" << endl;
	for (int i = 0; i < 128; i++) {
		cout << GetBit(x.data[i / 32], i % 32);

	}
}

void qIntToDayBit(QInt x, int daybit[])
{
	for (int i = 0; i < 128; i++) {
		if (GetBit(x.data[i / 32], i % 32) == 1) {
			daybit[i] = 1;
		}
		else {
			daybit[i] = 0;
		}
	}
}

void setMangKhong(int mang[100])
{
	for (int i = 0; i < 100; i++) {
		mang[i] = 0;
	}
}
void tinhHaiMuX(int dayso[100], int x)
{
	setMangKhong(dayso);
	if (x == 0) {
		dayso[99] = 1;
		return;
	}
	dayso[99] = 2;
	int m = 0;
	for (int i = 99; i > 100 - x; i--) {
		for (int k = 99; k >= 0; k--)
		{
			if (2 * dayso[k] < 10) {
				dayso[k] = (dayso[k] * 2) + m;
				m = 0;
			}
			else {
				dayso[k] = (2 * dayso[k] - 10) + m;
				m = 1;
			}
		}
	}
}

void congHaiDayBit(int daybit[100], int kq[100])
{
	for (int i = 99; i >= 0; i--) {
		if (kq[i] + daybit[i] < 10) {
			kq[i] = kq[i] + daybit[i];
		}else{
			kq[i] = kq[i] + daybit[i] - 10;
			kq[i - 1] += 1;
		}
		
	}
}

void truHaiDayBit(int daybit[100], int kq[100])
{
	for (int i = 99; i >= 0; i--) {
		if (kq[i] - daybit[i] >= 0) {
			kq[i] = kq[i] - daybit[i];
		}
		else {
			kq[i] = kq[i] - daybit[i] + 10;
			kq[i - 1] -= 1;
		}

	}
}

string PrintQInt(QInt x)
{
	int daybit[128];
	qIntToDayBit(x, daybit);

	int kq[100];
	setMangKhong(kq);
	int temp[100];
	setMangKhong(temp);

	for (int i = 1; i < 128; i++) {
		if (daybit[i] == 1) {
			tinhHaiMuX(temp, 127 - i);
			congHaiDayBit(temp, kq);
		}
	}
	
	if (daybit[0] == 1) {
		tinhHaiMuX(temp, 127);
		truHaiDayBit(kq, temp);
		for (int i = 0; i < 100; i++) {
			kq[i] = temp[i];
		}
	}
	int i = 0;
	for (i = 0; i < 100; i++) {
		if (kq[i] != 0) break;
	}
	if (daybit[0] == 1) {
		kq[i] = kq[i] * -1;
	}
	cout << "Dang thap phan: " << endl;
	for (int j = i; j < 100; j++) {
		cout << kq[j];
	}

	return "";
}
