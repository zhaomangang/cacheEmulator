#include"sundry.h"
#include "FuMemo.h"
#include "Address.h"
FuMemo::FuMemo()
{
	this->writeData();
	this->divideLump();

}
void FuMemo::writeData()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (i % 2 == 0) data[i] = 'O';
		else data[i] = 'J';
	}
}

void FuMemo::divideLump()
{
	//主存分块
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < LUMP_SIZE; j++)
		{
			this->lump[i % 4].data[j] = data[i];
		}
	}
}

char FuMemo::getData(Address address)
{
	//cache未命中，cpu直接访问主存获取数据
	//int lu_no = address.tag
	return this->lump[binToDec_8(address.tag)].data[binToDec_2(address.lu_ad)];
}


