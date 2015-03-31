#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"MazeOps.h"

Boolean findCheese(Maze m, int posi, int posj, char *path, int past_i, int past_j)
{
	Boolean ret;
	if(m[posi][posj]==9)
	{
		char b[10];
		sprintf(b,"(%d,%d)",posi,posj);
		strcat(path,b);
		return true;
	}
	else if((m[posi-1][posj] == 8||m[posi-1][posj] == 9) && past_i !=posi-1) 
	{
		if(findCheese(m, posi-1,posj, path,posi,posj))
		{
			char b[10];
			sprintf(b,"(%d,%d)",posi,posj);
			strcat(path,b);
			return true;
		}
	}
	else if((m[posi+1][posj] == 8||m[posi+1][posj] == 9) && past_i !=posi+1)
	{
		if(findCheese(m, posi+1,posj, path, posi, posj))
		{
			char b[10];
			sprintf(b,"(%d,%d)",posi,posj);
			strcat(path,b);
			return true;
		}
	}
	else if((m[posi][posj-1] == 8||m[posi][posj-1] == 9) && past_j!=posj-1)
	{
		if(findCheese(m, posi,posj-1, path, posi, posj))
		{
			char b[10];
			sprintf(b,"(%d,%d)",posi,posj);
			strcat(path,b);
			return true;
		}
	}
	else if((m[posi][posj+1] == 8||m[posi][posj+1] == 9) && past_j!=posj+1)
	{
		if(findCheese(m, posi,posj+1, path, posi, posj))
		{
			char b[10];
			sprintf(b,"(%d,%d)",posi,posj);
			strcat(path,b);
			return true;
		}
	}
	return false;
}
