#ifndef FUMEMO_H
#define FUMEMO_H


/*
filename: FuMemo.h
time: 2019/6/30
author: ZHAOMANGANG
describe: ȫ����ӳ��ʱ����
	����ֿ顢
	����ÿ��4���֣������С1024���֣����61���ֵ������ַΪ��
	00001111 01����� ���ڵ�ַ��

*/

#include"Address.h"
#include <iostream>

using namespace std;

#define SIZE 1024		//�����С
#define LUMP_SIZE 4		//���С
#define AREA_SIZE 4		//����С=cache����

struct Lump
{
	char data[LUMP_SIZE];	//������
};

struct Area
{
	Lump lump[AREA_SIZE];	
};
class FuMemo
{
public:
	FuMemo();
	void writeData();	//д������
	void divideLump();	//����ֿ�
	void divideArea();	//�������
	char getData(Address address);	//cpuֱ�ӷ�������ӿ�
	char getDataArea(Address address);

private:
	char data[SIZE];	//��������
	Lump lump[SIZE/LUMP_SIZE];	//��
	Area area[SIZE /AREA_SIZE];	//����cache������������з���
};
#endif // !FUMEMO_H