//cache��������
/*
������
1�����У�HIT��cpu���������ַ��ַ��cache���ҵ��������ݡ�cpu��cacheÿ�ν���һ����  �����cacheÿ�ν���һ���顷
2��ȱʧ
	����ֱ���͸�cpu Ȼ�����ݰᵽcache��ĳһ��
д����
д������<cache����Ч���ò���>
cpu�� ����д������֮�����д��Ӧ
д�ز��ԡ�����Ч�����õ��������������ݿ�����Ч��
cpu������д��cache��cache����д��Ӧ��cpu��cup����д֮��cache������д������
д��ǰ�������������µ���?

����ж�������cache�У�
cache�е���������Ч���𣿡�DMA�޸����桷

*/ 

#include "FuMemo.h"
#include "Cache.h"
#include <iostream>
using namespace std;
int main()
{
	char address[3];
	Cache cache;
	FuMemo memory;
	for(int i=0;i<4;i++)
	{
		cin >> address;
		cache.accessContrl(address, memory);
	}


	return 0;
}