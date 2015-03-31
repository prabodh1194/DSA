int SIZE_T;

typedef struct{
	int cust_id;
	char item_code[9];
	int item_cost;
}Node;

typedef	Node* Hash_id;

typedef struct{
	int CSIZE;
	Hash_id hashId;
}Hash_item;
