#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int x1,y1,x2,y2,length,weight,area;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	
	length = x2-x1;
	weight = y1-y2;
	
	area = length*weight;
	printf("%d", area);
	
	return 0;
}

//https://wm5.nccu.edu.tw/base/10001/course/10027586/content/asgmt01/index.html
