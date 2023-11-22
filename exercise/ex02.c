#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int main(void)
{
	double x1, x2, x3, x4, x5, x6, x7, x8;
	double y1, y2, y3, y4, y5, y6, y7, y8;
	double area1, area2;
	double length1, length2;
	double width1, width2;

	scanf("(%lf, %lf), (%lf, %lf), (%lf, %lf), (%lf, %lf)\n", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	scanf("(%lf, %lf), (%lf, %lf), (%lf, %lf), (%lf, %lf)", &x5, &y5, &x6, &y6, &x7, &y7, &x8, &y8);

	length1 = sqrt((fabs(x1 - x2) * fabs(x1 - x2)) + (fabs(y1 - y2) * fabs(y1 - y2)));
	width1 = sqrt((fabs(x2 - x3) * fabs(x2 - x3)) + (fabs(y2 - y3) * fabs(y2 - y3)));

	length2 = sqrt((fabs(x5 - x6) * fabs(x5 - x6)) + (fabs(y5 - y6) * fabs(y5 - y6)));
	width2 = sqrt((fabs(x6 - x7) * fabs(x6 - x7)) + (fabs(y6 - y7) * fabs(y6 - y7)));

	area1 = length1 * width1;
	area2 = length2 * width2;


	if (area1 == (int)area1)
		printf("%.0f\n", area1);
	else if (area1 * 10 == (int)(area1 * 10))
		printf("%.1f\n", area1);
	else
		printf("%.2f\n", area1);
		
	
	if (area2 == (int)area2)
		printf("%.0f\n", area2);
	else if (area2 * 10 == (int)(area2 * 10))
		printf("%.1f\n", area2);
	else
		printf("%.2f\n", area2);
		
	if (area1 > area2)
		printf("A > B");
	else if(area1 < area2)
		printf("A < B");
	else
		printf("A = B");
	
	
	return 0;
}

//introduction
//這段程式碼計算了兩個矩形的面積，然後比較它們的大小，最後輸出相應的結果
