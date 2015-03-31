#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Car
{
	int reg;
	char name[100];
};
struct ParkingLot
{
	struct Car car;
	char parkingID[500];	
};
int Enter_ParkingLot(struct ParkingLot *lot,int top, int n);
int Exit_ParkingLot(struct ParkingLot *lot, int top);
int Is_Parked(struct ParkingLot *lot, int top);
void Parking_Snapshot(struct ParkingLot *lot, int top);

int main(void)
{
	int n,i,top,ch=0;
	char a[20];
	printf("\nEnter the number of Cars\t");
	scanf("%d",&n);
	struct ParkingLot * arr;
	arr = malloc(n*sizeof(struct ParkingLot));
	top=0;
	do
	{
		printf("Enter the following\n1:Insert car\n2:Delete car\n3:Find car\n4:Write snapshot to file\n0:Exit\n");
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

int Enter_ParkingLot(struct ParkingLot *lot, int top, int n)
{
	struct Car car;
	char a[20];
	printf("\nEnter owner name\t");
	scanf("%s",car.name);
	printf("\nEnter registration number\t");
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
	for(i=0;i<top;i++)
	{
		fprintf(ofp,"\nCar parkingID: %s owner: %s and reg no.: %d",lot[i].parkingID,lot[i].car.name,lot[i].car.reg);
	}
	fclose(ofp);
}
