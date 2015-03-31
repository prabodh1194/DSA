#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ParkingLot.h"

int main(int argc, char *argv[])
{
	int n,top,ch=0;
	//printf("\nEnter the number of Cars\t");
	//scanf("%d",&n);
	n=atoi(argv[1]);
	struct ParkingLot * arr;
	arr = malloc(n*sizeof(struct ParkingLot));
	top=0;
	do
	{
		printf("Enter the following\n1:Insert car\n2:Delete car\n3:Find car\n4:Write snapshot to file and to screen\n0:Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			top = Enter_ParkingLot(arr, top, n);
		}
		if(ch==2)
		{
			top = Exit_ParkingLot(arr, top);
		}
		if(ch==3)
		{
			int a = Is_Parked(arr,top);
			if(a==-1)
				printf("\nCar lot empty\n");
			if(a>=0)
				printf("\nCar parkingID: %s owner: %s and reg no.: %d\n",arr[a].parkingID,arr[a].car.name,arr[a].car.reg);
		}
		if(ch==4)
			Parking_Snapshot(arr,top);
	}while(ch!=0);
	return 0;
}

void InsertSort(struct ParkingLot *lot, int top)
{
	int i,j;
	struct ParkingLot key;
	for(i=1;i<top;i++)
	{
		key = lot[i];
		j = i-1;
		while(j>=0 && lot[j].car.reg>key.car.reg)
		{
			lot[j+1] = lot[j];
			j--;
		}
		lot[j+1] = key;
	}
}

void merge(struct ParkingLot *lot, int p, int q, int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	//printf("\n**** %d,%d\n",n1,n2);
	struct ParkingLot *left,*right;
	left = malloc((n1+1)*sizeof(struct ParkingLot));
	right = malloc((n2+1)*sizeof(struct ParkingLot));
	int k,i,j;
	for(i=0;i<n1;i++)
	{
		left[i]=lot[p+i];
	}
	left[n1].car.reg=1000000;
	for(j=0;j<n2;j++)
	{
		right[j]=lot[q+j+1];
	}
	right[n2].car.reg=1000000;
	i=0;j=0;
	for(k=p;k<=r;k++)
	{
		if(left[i].car.reg<=right[j].car.reg)
			lot[k]=left[i++];
		else
			lot[k]=right[j++];
	}
}

void mergeSort(struct ParkingLot *lot, int beg, int top)
{
	//printf("asas%d\n",top);
	int mid = (beg+top)/2;
	if(beg<top)
	{
		mergeSort(lot, beg, mid);
		mergeSort(lot, mid+1, top);
		merge(lot, beg, mid, top);
	}
}

int Enter_ParkingLot(struct ParkingLot *lot, int top, int n)
{
	struct Car car;
	char a[20];
	printf("\nEnter owner name\t");
	scanf("%s",car.name);
	printf("\nEnter registration number of four digits\t");
	scanf("%d",&car.reg);
	sprintf(a,"%s%d",car.name,car.reg);
	if(top-1!=n)
	{
		lot[top].car.reg=car.reg;
		strcpy(lot[top].car.name,car.name);
		strcpy(lot[top++].parkingID,a);
	}
	else
		printf("\nParking lot flow\n");
	return top;
}

int Exit_ParkingLot(struct ParkingLot *lot, int top)
{
	if(top<0)
	{
		printf("\nParking lot empty\n");
	}
	else
	{
		printf("\nCar owner: %s and reg no.: %d\n",lot[top].car.name,lot[top].car.reg);
		strcpy(lot[top].parkingID,"");
		top-=1;
	}
	return top;
}

int Is_Parked(struct ParkingLot *lot, int top)
{
	int i;
	char parkID[500];
	if(top<0)
		return -1;  //car park empty
	else
	{
		printf("\nParking id:  ");
		scanf("%s",parkID);
		for(i=0;i<top;i++)
		{
			if(strcmp(lot[i].parkingID,parkID)==0)
			{
				return i; //car found
			}
		}
	}
	return -2; //car not found
}

void Parking_Snapshot(struct ParkingLot *lot, int top)
{
	int i;
	FILE *ofp;
	ofp = fopen("snap","w");
	printf("Enter \n1(default): Insertion Sort\n2: Merge Sort\t");
	int ch;
	scanf("%d",&ch);
	if(ch==2)
		mergeSort(lot,0,top-1);
	else
		InsertSort(lot,top);
	for(i=0;i<top;i++)
	{
		fprintf(ofp,"Car parkingID: %s owner: %s and reg no.: %d\n",lot[i].parkingID,lot[i].car.name,lot[i].car.reg);
		printf("Car parkingID: %s owner: %s and reg no.: %d\n",lot[i].parkingID,lot[i].car.name,lot[i].car.reg);
	}
	fclose(ofp);
}
