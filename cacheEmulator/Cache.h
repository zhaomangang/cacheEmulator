
/*
filename: FuMemo.h
time: 2019/6/30
author: ZHAOMANGANG
describe: 全相联映射时Cache
cache分行（与主存块大小相同）、
主存每块4个字，主存大小1024个字，则第61个字的主存地址为：
00001111 01（块号 块内地址）

*/

#pragma once

#define SIZE 64	//cache大小
#define LINE_SIZE 4	//cache行大小
struct Line
{
	bool valid;	//是否有效
	int tag[8];	//标志
	char data[LINE_SIZE];	//块大小
};



class Cache
{
public:
	Cache();
	~Cache();

private:
	Line line[SIZE];	//cache行
};

Cache::Cache()
{
}

Cache::~Cache()
{
}

