/*
filename: FuMemo.h
time: 2019/6/30
author: ZHAOMANGANG
describe: ȫ����ӳ��ʱ����
	����ֿ顢
	����ÿ��4���֣������С1024���֣����61���ֵ������ַΪ��
	00001111 01����� ���ڵ�ַ��

*/

#pragma once

#define SIZE 1024		//�����С
#define LUMP_SIZE 4		//���С
struct Address
{
	int tag[8];		//�ĸ���
	int lu_ad[2];	//���ڵ�ַ
};
struct Lump
{
	int lu_nu[LUMP_SIZE];	//���ڵ�ַ
};
class FuMemo
{
public:

private:
	char data[SIZE];	//��������
	Lump lump[SIZE/LUMP_SIZE];	//��
};

int* hexToBin(char hex[3])
{
	int bin[24];
	int dec;
	for (int i = 0; i < 3; i++)
	{
		switch (hex[i])
		{
		case'0':dec = 0; break;
		case'1':dec = 1; break;
		case'2':dec = 2; break;
		case'3':dec = 3; break;
		case'4':dec = 4; break;
		case'5':dec = 5; break;
		case'6':dec = 6; break;
		case'7':dec = 7; break;
		case'8':dec = 8; break;
		case'9':dec = 9; break;
		case'A':dec = 10; break;
		case'B':dec = 11; break;
		case'C':dec = 12; break;
		case'D':dec = 13; break;
		case'E':dec = 14; break;
		case'F':dec = 15; break;
		default:
			break;
		}	
		//for(int j = 0;j<)
		
	}
	
}

Address addreAna(char addr[3])
{
	//��ַ��������8λ16���Ƶ�ַ����Ϊ������tag��lu_ad����źͿ��ڵ�ַ
	//����Address�͵�ַ
	Address address;
	int bin[24];
	//ת������
	for (int i = 0; i < 3; i++)
	{
		
	}


	return address;
}

