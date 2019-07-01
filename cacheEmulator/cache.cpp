#include "Cache.h"
#include <time.h>
#include "FuMemo.h"
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
	cout << "BIN ADRESS IS: ";
	for (int i = 0; i < 12; i++)
	{
		cout << bin[i];
	}
	cout << endl;
}

Address addreAna(char addr[3])
{
	//地址解析，将8位16进制地址解析为二进制tag和lu_ad即块号和块内地址
	//返回Address型地址
	Address address;
	int bin[12] = { 0 };
	//转二进制
	hexToBin(addr, bin);
	for (int i = 2; i < 10; i++)
	{
		address.tag[i-2] = bin[i];
	}
	for (int i = 10; i < 12; i++)
	{
		address.lu_ad[i - 10] = bin[i];
	}

	cout << "Tag is:";
	for (int i = 0; i < 8; i++)
	{
		cout << address.tag[i];
	}
	cout << endl;
	cout << "Offset is:" << address.lu_ad[0] << address.lu_ad[1]<<endl;
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



Cache::Cache()
{
	for (int i = 0; i < CACHE_SIZE; i++)
	{
		this->line[i].valid = false;
		for (int j = 0; j < 8; j++)
		{
			this->line[i].tag[j] = -1;
		}
	}
}

Cache::~Cache()
{
}
bool Cache::compare(int ta[8])
{
	//将cpu地址标记位传入，与cache行进行比较，命中返回true，不命中返回false
	for (int i = 0; i < CACHE_SIZE; i++)
	{
		if (comp(ta, this->line[i].tag)) return true;
	}
	return false;
}
void Cache::accessContrl(char addr[3], FuMemo memory)
{
	//cpu访问cache时传入16进制地址
	char data;
	Address address = addreAna(addr);	//解析地址
	if (compare(address.tag))
	{
		//命中
		cout << "命中cache" << endl;
		data = this->getData(address);	//从cache中取数据

	}
	else
	{
		//没有命中,cpu访问主存
		cout << "未命中cache" << endl;
		data = memory.getData(address);	//访问主存
		
		moveDate(memory,address);//将主存中某一块数据搬至cache并填写相应标志位


	}
	cout << "data is " << data << endl;


}

void Cache::moveDate(FuMemo memory,Address address)
{
	//根据相应策略将主存中数据搬至cache并填写相应标志位
	int i;
	srand((unsigned)(time(NULL)));
	do {
		
		i = rand() % CACHE_SIZE;	//随机放入行
		cout << "将主存中数据放入cache哪一行：" <<i<< endl;
	}while(this->line[i].valid);
	for (int j = 0; j < LINE_SIZE; j++)
	{
		switch (j)
		{
		case 0:address.lu_ad[0] = 0; address.lu_ad[1] = 0; break;
		case 1:address.lu_ad[0] = 0; address.lu_ad[1] = 1; break;
		case 2:address.lu_ad[0] = 1; address.lu_ad[1] = 0; break;
		case 3:address.lu_ad[0] = 1; address.lu_ad[1] = 1; break;
		default:
			break;
		}
		this->line[i].data[j] = memory.getData(address);
	}
	this->line[i].valid = true;
	for (int j = 0; j < 8; j++)
	{
		this->line[i].tag[j] = address.tag[j];
	}

}
int binToDec_2_(int bin[2])
{
	int dec = bin[0] * 2 + bin[1] * 1;
	return dec;
}
int binToDec_8_(int bin[8])
{
	int dec = 0;
	for (int i = 0; i < 8; i++)
	{
		dec = dec + bin[i] * pow(2, 7 - i);
	}
	return dec;
}
char Cache::getData(Address address)
{
	//根据地址从Cache中取数据
	char data;
	for (int i = 0; i < SIZE; i++)
	{
		if (comp(this->line[i].tag, address.tag))
		{
			data = this->line[i].data[binToDec_2_(address.lu_ad)];
			return data;
		}
	}
}