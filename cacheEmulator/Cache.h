
/*
filename: FuMemo.h
time: 2019/6/30
author: ZHAOMANGANG
describe: ȫ����ӳ��ʱCache
cache���У���������С��ͬ����
����ÿ��4���֣������С1024���֣����61���ֵ������ַΪ��
00001111 01����� ���ڵ�ַ��

*/

#pragma once

#define SIZE 64	//cache��С
#define LINE_SIZE 4	//cache�д�С
struct Line
{
	bool valid;	//�Ƿ���Ч
	int tag[8];	//��־
	char data[LINE_SIZE];	//���С
};



class Cache
{
public:
	Cache();
	~Cache();

private:
	Line line[SIZE];	//cache��
};

Cache::Cache()
{
}

Cache::~Cache()
{
}

