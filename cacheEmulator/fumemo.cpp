
#include "FuMemo.h"
#include "Address.h"
int binToDec_2(int bin[2])
{
	int dec = bin[0] * 2 + bin[1] * 1;
	return dec;
}
int binToDec_8(int bin[8])
{
	int dec = 0;
	for (int i = 0; i < 8; i++)
	{
		dec = dec + bin[i] * pow(2, 7 - i);
	}
	return dec;
}

FuMemo::FuMemo()
{

}
void FuMemo::writeData()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (i % 2 == 0) data[i] = 'L';
		else data[i] = 'J';
		//cout << data[i] << " ";
	}
	//cout<<"///"<<endl;
	//data[0] = 'k';
}

void FuMemo::divideLump()
{
	//����ֿ�
	int k = 0;
	for (int i = 0; i < SIZE/LUMP_SIZE; i++)
	{
		for (int j = 0; j < LUMP_SIZE; j++,k++)
		{
			this->lump[i].data[j] = data[k];
			//cout << data[k] << " ";
		}
		//cout << endl;
		
	}
	//cout << endl;
}

char FuMemo::getData(Address address)
{
	//cacheδ���У�cpuֱ�ӷ��������ȡ����
	//int lu_no = address.tag
	return this->lump[binToDec_8(address.tag)].data[binToDec_2(address.lu_ad)];
}
char FuMemo::getDataArea(Address address)
{
	//�������ʱ
	//cacheδ���У�cpuֱ�ӷ��������ȡ����
	//int lu_no = address.tag
	return this->area[binToDec_8(address.tag)].lump[binToDec_2(address.lu_ad)].data[binToDec_2(address.lu_ad)];
}


void FuMemo::divideArea()
{
	//�������
	int k = 0;
	for (int i = 0; i < SIZE / AREA_SIZE; i++)
	{
		for (int j = 0; j < AREA_SIZE; j++)
		{
			for (int t = 0; t < LUMP_SIZE; t++,k++)
			{
				area[i].lump[j].data[t] = data[k];
				//cout << data[k] << " ";
			}
			//cout << "\t";
		}
		//cout << endl;
	}
}
