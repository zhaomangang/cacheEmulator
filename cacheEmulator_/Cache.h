#ifndef CACHE_H
#define CACHE_H
/*
filename: Cache.h
time: 2019/6/30
author: ZHAOMANGANG
describe: 全相联映射时Cache
cache分行（与主存块大小相同）、
主存每块4个字，主存大小1024个字，则第61个字的主存地址为：
00001111 01（块号 块内地址）

*/


#include"Address.h"
#include "FuMemo.h"
#include <string.h>


#define CACHE_SIZE 64	//cache大小
#define LINE_SIZE 4	//cache行大小
struct Line
{
	bool valid;	//是否有效
	int tag[8];	//标志
	char data[LINE_SIZE];	//块数据
};



class Cache
{
public:
	Cache();
	~Cache();
	void accessContrl(char addr[3],FuMemo memory);	//cpu访问cache接口
	bool compare(int ta[8]);	//比较cpu传入地址的tag是否在cache行
	char getData(Address address);	//从cache中取一个字数据
private:
	Line line[CACHE_SIZE];	//cache行
};


#endif