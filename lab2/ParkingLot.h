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
void InserSort(struct ParkingLot *lot, int top);
void merge(struct ParkingLot *lot, int p, int q, int r);
void mergeSort(struct ParkingLot *lot, int beg, int top);
int Enter_ParkingLot(struct ParkingLot *lot,int top, int n);
int Exit_ParkingLot(struct ParkingLot *lot, int top);
int Is_Parked(struct ParkingLot *lot, int top);
void Parking_Snapshot(struct ParkingLot *lot, int top);

