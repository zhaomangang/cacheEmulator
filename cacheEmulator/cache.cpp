#include "Cache.h"
#include <time.h>
#include "FuMemo.h"
#include "Address.h"
#include <iostream>
using namespace std;

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
Address addreAnaArea(char addr[3])
{
	//全相联地址解析
	Address address;
	int bin[12] = { 0 };
	//转二进制
	hexToBin(addr, bin);
	address.tag[0] = 0;
	address.tag[1] = 0;
	for (int i = 2; i < 8; i++)
	{
		address.tag[i] = bin[i];
	}
	for (int i = 8; i < 10; i++)
	{
		address.area[i - 8] = bin[i];
	}
	for (int i = 10; i < 12; i++)
	{
		address.lu_ad[i - 10] = bin[i];
	}
	cout << "Tag is: ";
	for (int i = 0; i < 8; i++)
	{
		cout << address.tag[i];
	}
	cout << endl;
	cout << "Area is: " << address.area[0] << address.area[1] << endl;
	cout << "Offset is: " << address.lu_ad[0] << address.lu_ad[1] << endl;
	return address;
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
bool Cache::compareArea(Address address)
{
	int line_temp = binToDec_2_(address.area);
	line_temp = line_temp % CACHE_SIZE;
	if (comp(address.tag, this->line[line_temp].tag))
	{
		return true;
	}
	return false;
}

void Cache::accessContrl(char addr[3], FuMemo memory)
{
	//cpu访问cache时传入16进制地址
	char data;
	Address address;
	if (this->police == 0)
	{
		//全相联映射
		address = addreAna(addr);	//解析地址
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

			moveDate(memory, address);//将主存中某一块数据搬至cache并填写相应标志位


		}
	}
	else if (this->police == 1)
	{
		//直接映射
		address = addreAnaArea(addr);	//解析地址
		if (compareArea(address))
		{
			//命中
			cout << "命中cache" << endl;
			getDataArea(address,&data);	//从cache获取数据
		}
		else {
			//未命中
			cout << "未命中cache" << endl;
			data = memory.getDataArea(address);	//访问主存
			moveDataArea(memory, address);	//移动数据
		}
	}

	cout << "data is " << data << endl;


}
void Cache::moveDataArea(FuMemo memory, Address address)
{
	//直接映射时将数据从主存搬至cache
	int i = binToDec_2_(address.area);	//行号
	cout << "将主存中数据放入cache哪一行：" << i << endl;
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
		this->line[i].data[j] = memory.getDataArea(address);
	}
	this->line[i].valid = true;
	for (int j = 0; j < 8; j++)
	{
		this->line[i].tag[j] = address.tag[j];
	}
}
void Cache::moveDate(FuMemo memory,Address address)
{
	//根据相应策略将主存中数据搬至cache并填写相应标志位
	int i;
	srand((unsigned)(time(NULL)));
	int bre = 0;
	do {
		bre++;
		i = rand() % CACHE_SIZE;	//随机放入行
	}while(this->line[i].valid&&bre == CACHE_SIZE);
	cout << "将主存中数据放入cache哪一行：" << i << endl;
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

void Cache::getDataArea(Address address,char *data)
{
	//data = new char;
	if (comp(this->line[binToDec_2_(address.area)].tag, address.tag))
	{
		*data = this->line[binToDec_2_(address.area)].data[binToDec_2_(address.lu_ad)];
	}
	
}
int Cache::getPolice()
{
	return police;
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

void Cache::setPolice(int po)
{
	//设置映射策略
	/*
		0、全相联
		1、直接映射
	*/
	this->police = po;
}