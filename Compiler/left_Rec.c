#include <stdio.h>
#include <string.h>
#include <ctype.h>


void removeLeftRecursion(char str[]){

	int i,j,k,x;
	char  memory[100][100];
	k=0;
	x=0;

	for(i=0; i<strlen(str); i++){
		if(str[i]=='|' || str[i]== ' ' || (str[i] == '-' && str[i+1]=='>'))
		{
			if(str[i]=='-')
			{
				i=i+1;
			}
			if(x>0)
			{
				memory[k][x] = '\0';
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
		k=k+1;
		x=0;
	}
	int ff=0;
	for(int i=1;i<k;i++)
	{
		if(memory[i][0]==memory[0][0])
			ff=1;
	}
	if(!ff)
	{
		printf('\nGiven Grammer is not Left Recursive.');
		return;
	}
	int in=-1;
	for(int i=1;i<k;i++)
	{
		if(memory[i][0]!=memory[0][0])
		{
			in = i;
			break;
		}
	}
	if(in==-1)
	{
		printf("\n\t%c -> %c'",memory[0][0],memory[0][0]);
		printf("\n\t%c' -> ",memory[0][0]);
		for(int i=1;i<k;i++)
		{
			if(strlen(memory[i])<2)
			{
				continue;
			}
			else
			{
				for(j=1;j<strlen(memory[i]);j++)
				{
					printf("%c", memory[i][j]);
				}
				printf("%c'",memory[0][0]);
				printf(" | ");
			}
			
		}
		printf("NULL\n");
	}
	else
	{
		printf("\n\t%c -> ",memory[0][0]);
		for(i=in; i<k; i++)
		{
			if(memory[i][0]!=memory[0][0])
			{
				if(i!=in){
					printf(" | ");
				}
				for(j=0;j<strlen(memory[i]);j++)
				{
					printf("%c",memory[i][j]);
				}
				printf("%c'", memory[0][0]);
			}
		}
		printf("\n\t%c' -> ",memory[0][0]);
		for(i=1;i<k;i++)
		{	
			if(memory[i][0]==memory[0][0])
			{
				if(strlen(memory[i])<2)
				{
					continue;
				}
				else
				{
				
					for(j=1;j<strlen(memory[i]);j++)
					{
						printf("%c", memory[i][j]);
					}
					printf("%c'",memory[0][0]);
					printf(" | ");
				}
			}
		}
		printf("NULL\n");
	}

}

int main(){
	char str[100];

	printf("Enter Grammer:\n");
	while(gets(str)){
		removeLeftRecursion(str);
	}
	return 0;
}
