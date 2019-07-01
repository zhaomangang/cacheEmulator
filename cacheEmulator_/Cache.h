#ifndef CACHE_H
#define CACHE_H
/*
filename: Cache.h
time: 2019/6/30
author: ZHAOMANGANG
describe: ȫ����ӳ��ʱCache
cache���У���������С��ͬ����
����ÿ��4���֣������С1024���֣����61���ֵ������ַΪ��
00001111 01����� ���ڵ�ַ��

*/


#include"Address.h"
#include "FuMemo.h"
#include <string.h>


#define CACHE_SIZE 64	//cache��С
#define LINE_SIZE 4	//cache�д�С
struct Line
{
	bool valid;	//�Ƿ���Ч
	int tag[8];	//��־
	char data[LINE_SIZE];	//������
};



class Cache
{
public:
	Cache();
	~Cache();
	void accessContrl(char addr[3],FuMemo memory);	//cpu����cache�ӿ�
	bool compare(int ta[8]);	//�Ƚ�cpu�����ַ��tag�Ƿ���cache��
	char getData(Address address);	//��cache��ȡһ��������
private:
	Line line[CACHE_SIZE];	//cache��
};


#endif