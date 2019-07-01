#ifndef ADRESS_H
#define ADRESS_H


class Address 
{
public:
	int tag[8];		//标志
	int lu_ad[2];	//块内地址
	int area[2];	//
	Address()
	{

	}
	Address(const Address &add)
	{
		for (int i = 0; i < 8; i++)
		{
			tag[i] = add.tag[i];
		}
		for (int i = 0; i < 2; i++)
		{
			lu_ad[i] = add.lu_ad[i];
		}
		for (int i = 0; i < 2; i++)
		{
			area[i] = add.area[i];
		}
	}
private:

};


#endif 