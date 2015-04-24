#include <stdio.h>

static inline int countLines(FILE *fp)
{
	char c;
	int count=0;
	do
	{
		c=fgetc(fp);
		if(c == '\n')
		count++;
	}
	while (c!= EOF);
	return count;
}

int main(int argc, char *argv[])
{
	FILE *fp,*ofp;
	int line_count, i,j,word_count;
	#define BUF_SIZE 100
	char buffer[BUF_SIZE];
	if(argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>", argv[0]);
		exit(-1);
	}
	fp= fopen(argv[1], "r");
	ofp = fopen("output.txt","w");
	line_count = countLines (fp);
	printf("\n No of lines in %s is %d\n", argv[1], line_count);

	rewind(fp);

	// Take input from the files...
	for (i=0; i< line_count; i++)
	{
		int len,ret;
		int id, l, amount;
		fgets(buffer, BUF_SIZE, fp);
		buffer[BUF_SIZE-1] = '\0'; // for safety
		len=strlen(buffer);
		if (buffer[len-1] == '\n')
			buffer[len-1]='\0';
		j=0;
		word_count=0;
		while(buffer[j]!='\0')
		{
			if(!(buffer[j]==32 || (buffer[j]>=65 && buffer[j]<=90) || (buffer[j]>=97 && buffer[j]<=122)))
			{
				buffer[j]=' ';
			}
			if(buffer[j]>=65 && buffer[j]<=90)
				buffer[j]+=32;
			j+=1;
		}
		len=strlen(buffer); // for dealing with empty lines
		printf("%s\n",buffer);
		fprintf(ofp,"%s\n",buffer);
		ret=sscanf(buffer,"%d,%d,%d", &id, &l, &amount);
	}
	fclose(fp);
	fclose(ofp);
	
	fp = fopen("output.txt","r");
	char *a;
	while(!feof(fp))
	{
		a = malloc(sizeof(char)*100);
		fscanf(fp,"%s",a);
		printf("%s ",a);
	}
	return 1;
}
