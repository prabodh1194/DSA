#include "hashtable.h"

Hash_item * populateHashTable(char *filename);
void printHT(Hash_item *ht, int htsize, FILE *fp);
void insertHashtable(Hash_item ht, int htsize, int cust_id, char *item_code, int cost_item);
int findEntry(Hash_item ht, int htsize, int cust_id, char *item_code);
int purchasedby(Hash_item ht, int htsize, int cust_id);
int hash1(char *key, int size);
int hash2(int key, int size);
