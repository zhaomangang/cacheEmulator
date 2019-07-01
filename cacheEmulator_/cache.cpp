#include "Cache.h"
#include "sundry.h"
#include "FuMemo.h"
#include "Address.h"
#include <iostream>
using namespace std;
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
	Address address = addreAna(addr);	//解析地址
	if (compare(address.tag))
	{
		//命中
		cout << "命中cache" << endl;
		this->getData(address);	//从cache中取数据

	}
	else
	{
		//没有命中,cpu访问主存

	}


}

char Cache::getData(Address address)
{
	//根据地址从Cache中取数据
	char data = {};


	return data;

}