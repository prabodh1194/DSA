#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node_info
{
	struct node *head;
	struct node *last;
	struct node *pivot;
};

struct node * partition(struct node **head, struct node **last);

void readData(struct node **head, struct node **last, char *fname)
{
	struct node *tra, *newnode;
	*head = NULL;
	FILE *fp;
	int a;
	fp = fopen(fname,"r");
	while(1)
	{
		fscanf(fp,"%d",&a);
		if(feof(fp))
			break;
		newnode = malloc(sizeof(struct node));
		newnode->data = a;
		newnode->next = NULL;

		if(*head==NULL)
		{
			*head = newnode;
			tra = *head;
		}
		else
		{
			tra->next = newnode;
			tra = tra->next;
		}
	}
	fclose(fp);
	*last = tra;
}

void printList(struct node *head, char *fname)
{
	struct node *tra;
	tra = head;
	FILE *fp;
	fp = fopen(fname,"w");
	while(tra!=NULL)
	{
		fprintf(fp,"%d\n",tra->data);
		//printf("%d\n",tra->data);
		tra=tra->next;
	}
	fclose(fp);
}

void qSort(struct node **head, struct node **last)
{
	struct node *pivot,*tra;
	if(*head!=*last)
	{
		pivot = partition(head,last);
		tra = *head;
		//sort upper half
		if(tra!=pivot)
		{
			while(tra->next!=pivot)
			{
				tra = tra->next;
			}
			qSort(head,&tra);
			tra->next = pivot;
		}

		//sort lower half
		if(pivot->next!=NULL&&pivot!=*last)
		{
			tra = pivot->next;
			qSort(&tra,last);
			pivot->next = tra;
		}
	}
}

struct node * partition(struct node **head, struct node **last)
{
	struct node *pivot,*tra,*prev;
	pivot = *last;
	tra = *head;
	prev=tra;
	int pivotd = pivot->data;
	while(tra!=*last)
	{
		if(tra->data > pivotd)
		{
			if(tra==*head)
			{
				*head = tra->next;
				prev = *head;
			}
			else
				prev->next = tra->next;
			pivot->next = tra;
			pivot = pivot->next;
			tra = tra->next;
			pivot->next = NULL;
		}
		else
		{
			prev=tra;
			tra=tra->next;
		}
	}
	*last = pivot;
	return tra;
}

/*struct node * merge(struct node *head, struct node *head2)
{
    struct node *tra,*tra2,*pos,*newnode;
    tra = *head;
    tra2 = *head2;
    pos = tra;
    while(true)
    {
	if(tra->data <= tra2->data)
	{
	}
	else
	{

}*/

int main()
{
	struct node *head, *last;
	printf("\nEnter input file name ");
	char c[100];
	scanf("%s",c);
	printf("\nEnter output file name ");
	char d[100];
	scanf("%s",d);
	readData(&head, &last, c);
	printList(head,d);
	qSort(&head,&last);
	printf("***********************************************\n");
	printList(head,d);
	//merge(&head,10);
	return 0;
}
