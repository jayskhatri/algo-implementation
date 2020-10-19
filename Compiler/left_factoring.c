#include <stdio.h>
#include <string.h>
#include <ctype.h>

void leftFactoring(char str[]){

	int i,j,k,x;
	int in;
	char  memory[100][100];
	k=0;
	x=0;
	in=1000;
	for(i=0; i<strlen(str); i++)
	{
		if(str[i]=='|' || str[i]== ' ' || (str[i] == '-' && str[i+1]=='>'))
		{
			if(str[i]=='-')
			{
				i=i+1;
			}
			if(x>0)
			{
				memory[k][x] = '\0';
				if(in>strlen(memory[k])&&k>0)
				{
					in = strlen(memory[k]);
				}
				k++;
				x=0;
			}
		}
		else
		{
			memory[k][x++]=str[i];
		}
	}
	if(x>0)
	{
		memory[k][x++] = '\0';
		if(in>strlen(memory[k]))
		{
			in = strlen(memory[k]);
		}
		k=k+1;
		x=0;
	}

	int flag=1, index=-1;
	for(i=0; i<in; i++)
	{

		for(j=2;j<k;j++)
		{
			if(memory[j][i]!=memory[1][i])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			index=i;
			flag=1;
		}
		else{
			break;
		}
	}

	if(index==-1 || k<3)
	{
		printf("\n\n Grammer is already factored.");
	}
	else{
		printf("\n\t%c -> ",memory[0][0]);

		for(i=0;i<=index;i++)
		{
			printf("%c",memory[1][i]);
		}
		printf("%c'",memory[0][0]);

		printf("\n\t%c' -> ",memory[0][0]);


		for(i=1;i<k;i++)
		{
			if(i>1)
			{
				printf(" | ");
			}
			if(strlen(memory[i])>index+1)
			{
				for(j=index+1;j<strlen(memory[i]);j++)
				{
					printf("%c",memory[i][j]);
				}
			}
			else
			{
				printf("null");
			}
		}

	}
	printf("\n");


}

int main(){
	char str[100];

	printf("Enter Grammer:\n");
	while(gets(str)){
		leftFactoring(str);
	}
	return 0;
}
