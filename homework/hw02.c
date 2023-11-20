#include <stdio.h>

int Letter2int(char c)
{
	int list[26] = {1, 0, 9, 8, 7, 6, 5, 4, 9, 3, 2, 2, 1, 0, 8, 9, 8, 7, 6, 5, 4, 3, 1, 3, 2, 0};
	return(list[c-'A']);
}

int main(void) 
{
	int total;
	scanf("%d", &total);
	
	for(int a=0;a<total;a++)
	{
		char Letter[100];
		int checksum = 0;
		scanf("%s", Letter);
	
		checksum += Letter2int(Letter[0]);
		int j=8;
		
		for(int i=1;i<9;i++)
	  	{
			checksum += (Letter[i]-'0')*j;
			
			j--;
	  	}
		checksum += (Letter[9]-'0')*1;
	
		if(checksum%10==0 && (Letter[1]-'0'==2 || Letter[1]-'0'==1))
			printf("Valid\n");
		else 
			printf("Invalid\n");
	}
	
	return 0;
}

//https://wm5.nccu.edu.tw/base/10001/course/10027586/content/asgmt02/index.html
