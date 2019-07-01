#ifndef FUMEMO_H
#define FUMEMO_H


/*
filename: FuMemo.h
time: 2019/6/30
author: ZHAOMANGANG
describe: 全相联映射时主存
	主存分块、
	主存每块4个字，主存大小1024个字，则第61个字的主存地址为：
	00001111 01（块号 块内地址）

*/

#include"Address.h"
#include <iostream>

using namespace std;

#define SIZE 1024		//主存大小
#define LUMP_SIZE 4		//块大小
#define AREA_SIZE 4		//区大小=cache行数

struct Lump
{
	char data[LUMP_SIZE];	//块数据
};

struct Area
{
	Lump lump[AREA_SIZE];	
};
class FuMemo
{
public:
	FuMemo();
	void writeData();	//写入数据
	void divideLump();	//主存分块
	void divideArea();	//主存分区
	char getData(Address address);	//cpu直接访问主存接口
	char getDataArea(Address address);

private:
	char data[SIZE];	//主存数据
	Lump lump[SIZE/LUMP_SIZE];	//块
	Area area[SIZE /AREA_SIZE];	//根据cache行数对主存进行分区
};
#endif // !FUMEMO_H