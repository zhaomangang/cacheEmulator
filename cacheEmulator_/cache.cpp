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
	//��cpu��ַ���λ���룬��cache�н��бȽϣ����з���true�������з���false
	for (int i = 0; i < CACHE_SIZE; i++)
	{
		if (comp(ta, this->line[i].tag)) return true;
	}
	return false;
}
void Cache::accessContrl(char addr[3], FuMemo memory)
{
	//cpu����cacheʱ����16���Ƶ�ַ
	Address address = addreAna(addr);	//������ַ
	if (compare(address.tag))
	{
		//����
		cout << "����cache" << endl;
		this->getData(address);	//��cache��ȡ����

	}
	else
	{
		//û������,cpu��������

	}


}

char Cache::getData(Address address)
{
	//���ݵ�ַ��Cache��ȡ����
	char data = {};


	return data;

}