//cache工作过程
/*
读操作
1、命中（HIT）cpu根据主存地址地址在cache中找到所需内容《cpu与cache每次交换一个字  主存和cache每次交换一个块》
2、缺失
	主存直接送给cpu 然后将数据搬到cache的某一行
写操作
写穿策略<cache高速效果用不到>
cpu将 数据写回主存之后产生写相应
写回策略《高速效果能用到但是主存中数据可能无效》
cpu将数据写入cache，cache返回写响应给cpu，cup不再写之后cache将数据写回主存
写回前主存数据是最新的吗?

如何判断数据在cache中？
cache中的数据是有效的吗？《DMA修改主存》

*/ 

/*
主存 1024字节 单数地址放的是‘J’ 双数‘L’


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
	cache.setPolice(0);	//0、全相联1、直接映射
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
		cout << "输入地址（3位16进制，不够补0，例如00F）：";
		cin >> address;
		cache.accessContrl(address, memory);
	}
	return 0;
}