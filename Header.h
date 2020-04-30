#ifndef HEADER_H_
#define HEADER_H_

#include <string>
#include <iostream>
using namespace std;


struct QInt
{
	int data[4];
};

void setBit1(int& X, int i);
void setBit0(int& X, int i);
int GetBit(int X, int i);
void stringToBit(string str, int daybit[]);
void ScanQInt(QInt& x, string str);

void setMangKhong(int mang[100]);
void qIntToDayBit(QInt x, int daybit[]);
void tinhHaiMuX(int dayso[100], int x);
void congHaiDayBit(int daybit1[100], int kq[100]);
void truHaiDayBit(int daybit[100], int kq[100]);
string PrintQInt(QInt x);

#endif