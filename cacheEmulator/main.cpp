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

/*
���� 1024�ֽ� ������ַ�ŵ��ǡ�J�� ˫����L��


*/
#include "FuMemo.h"
#include "Cache.h"
#include <iostream>
using namespace std;
int main()
{
	char address[4];
	Cache cache;
	FuMemo memory;
	cache.setPolice(0);	//0��ȫ����1��ֱ��ӳ��
	memory.writeData();
	if (0==cache.getPolice())
	{
		memory.divideLump();
	}
	else
	{
		memory.divideArea();
	}
	while(1)
	{
		cout << "�����ַ��3λ16���ƣ�������0������00F����";
		cin >> address;
		cache.accessContrl(address, memory);
	}
	return 0;
}