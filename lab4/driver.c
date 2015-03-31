#include <stdio.h>
#include <stdlib.h>

int* file_read(char *input_file_name, long int N);
void file_write(char *input_file_name, int* data,long int N);

int* file_read(char *input_file_name, long int N)
{
    int *arr;
    arr = malloc(sizeof(int) * N);
    FILE *fp;
    int i=0;
    fp = fopen(input_file_name,"r");
    while(1)
    {
	if(i>=N)
	    break;
	fscanf(fp,"%d",arr+i);
	i+=1;
    }
    fclose(fp);
    return arr;
}

void file_write(char *output_file_name, int *data, long int N)
{
    int i;
    FILE *fp;
    fp = fopen(output_file_name,"w");
    i=0;
    while(i<N)
    {
	fprintf(fp,"%d\n",*(data+i));
	i+=1;
    }
    fclose(fp);
}

int main(int argc, char *argv[])
{
    int n,i,*arr;
    n=atoi(argv[1]);
    printf("\nEnter input file name");
    char c[100];
    scanf("%s",c);
    printf("\nEnter output file name");
    char d[100];
    scanf("%s",d);
    arr = file_read(c,n);
    if(strcmp(argv[0],"./insert")==0)
	sort(arr,n);
    else if(strcmp(argv[0],"./merge")==0)
	sort(arr,0,n-1);
    else if(strcmp(argv[0],"./quickFirst")==0)
	sort(arr,0,n-1);

    file_write(d,arr,n);

    return 1;
}
