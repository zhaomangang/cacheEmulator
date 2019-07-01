#ifndef SUNDRY_H
#define SUNDRY_H


/*
filename: sundry.h
time: 2019/7/1
author: ZHAOMANGANG
describe: 其它所需函数

*/

#include "Address.h"
#include <iostream>

using namespace std;



void hexToBin(char hex[3], int bin[12])
{
	//int bin[12] = {0};
	int dec;
	for (int i = 0; i < 3; i++)
	{
		switch (hex[i])
		{
		case'0':dec = 0; break;
		case'1':dec = 1; break;
		case'2':dec = 2; break;
		case'3':dec = 3; break;
		case'4':dec = 4; break;
		case'5':dec = 5; break;
		case'6':dec = 6; break;
		case'7':dec = 7; break;
		case'8':dec = 8; break;
		case'9':dec = 9; break;
		case'A':dec = 10; break;
		case'B':dec = 11; break;
		case'C':dec = 12; break;
		case'D':dec = 13; break;
		case'E':dec = 14; break;
		case'F':dec = 15; break;
		default:
			break;
		}
		for (int j = 4 * (i + 1) - 1; dec != 0; j--)
		{
			bin[j] = dec % 2;
			dec = dec / 2;
		}

	}
	//cout << "hexto:" << bin << endl;
	for (int i = 0; i < 12; i++)
	{
		cout << bin[i];
	}
}

Address addreAna(char addr[3])
{
	//地址解析，将8位16进制地址解析为二进制tag和lu_ad即块号和块内地址
	//返回Address型地址
	Address address;
	int bin[12] = { 0 };
	//转二进制
	hexToBin(addr, bin);
	for (int i = 0; i < 8; i++)
	{
		address.tag[i] = bin[i];
	}
	for (int i = 8; i < 10; i++)
	{
		address.lu_ad[i - 8] = bin[i];
	}

	cout << "tag is:";
	for (int i = 0; i < 8; i++)
	{
		cout << address.tag[i];
	}
	cout << endl;
	cout << "lu_Ad is:" << address.lu_ad[0] << address.lu_ad[1];
	return address;
}

bool comp(int a[8], int b[8])
{
	//比较两个8位int型数组是否相等
	for (int i = 0; i < 8; i++)
	{
		if (a[i] != b[i]) return false;
	}
	return true;
}

int binToDec_2(int bin[2])
{
	int dec = bin[0] * 2 + bin[1] * 1;
	return dec;
}
int binToDec_8(int bin[8])
{
	int dec = 0;
	for (int i = 0; i < 8; i++)
	{
		dec = dec+bin[i] * pow(2, 7 - i);
	}
	return dec;
}


#endif // !SUNDRY_H
