#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"

void InsertSort(struct ParkingLot *lot, int top)
{
	int i,j,key;
	for(i=1;i<top;i++)
	{
		key = lot[i].car.reg;
		j = i-1;
		while(j>0 && lot[j].car.reg>key)
		{
			lot[j+1].car.reg = lot[j].car.reg;
			j--;
		}
	}
}
