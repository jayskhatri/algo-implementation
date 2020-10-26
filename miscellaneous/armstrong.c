#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
int n,count=0,or_n,or_n1,rem,x,ans=0;
clrscr();
printf("\nEnter Any Number = ");
scanf("%d",&n);
or_n=n;
or_n1=n;
while(n!=0)
	{
	count++;
	n=n/10;
	}
while(or_n!=0)
	{
	rem=or_n%10;
	ans=ans+pow(rem,count);
	or_n=or_n/10;
	}
if(ans==or_n1)
printf("\nIt is Armstrong Number.");
else
printf("\nIt is not Armstrong Number.");
getch();
}
