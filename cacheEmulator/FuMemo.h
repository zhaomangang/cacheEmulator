/*
filename: FuMemo.h
time: 2019/6/30
author: ZHAOMANGANG
describe: 全相联映射时主存
	主存分块、
	主存每块4个字，主存大小1024个字，则第61个字的主存地址为：
	00001111 01（块号 块内地址）

*/

#pragma once

#define SIZE 1024		//主存大小
#define LUMP_SIZE 4		//块大小
struct Address
{
	int tag[8];		//哪个块
	int lu_ad[2];	//块内地址
};
struct Lump
{
	int lu_nu[LUMP_SIZE];	//块内地址
};
class FuMemo
{
public:

private:
	char data[SIZE];	//主存数据
	Lump lump[SIZE/LUMP_SIZE];	//块
};

int* hexToBin(char hex[3])
{
	int bin[24];
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
		//for(int j = 0;j<)
		
	}
	
}

Address addreAna(char addr[3])
{
	//地址解析，将8位16进制地址解析为二进制tag和lu_ad即块号和块内地址
	//返回Address型地址
	Address address;
	int bin[24];
	//转二进制
	for (int i = 0; i < 3; i++)
	{
		
	}


	return address;
}

