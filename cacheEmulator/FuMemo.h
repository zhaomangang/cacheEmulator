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


struct Lump
{
	int lu_nu[LUMP_SIZE];	//���ڵ�ַ
	char data[LUMP_SIZE];	//������
};
class FuMemo
{
public:
	FuMemo();
	void writeData();	//д������
	void divideLump();	//����ֿ�
	char getData(Address address);	//cpuֱ�ӷ�������ӿ�

private:
	char data[SIZE];	//��������
	Lump lump[SIZE/LUMP_SIZE];	//��
};
#endif // !FUMEMO_H