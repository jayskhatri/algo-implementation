#include<stdio.h>
#include<iostream>
using namespace std;
void quick_sort(float *a,int lb,int ub)
{
    int pivot,i,j;
    float temp;
    if (lb<ub)
    {
        pivot=lb;
        i=lb;
        j=ub;
        while(i<j)
        {
            while (a[i]<=a[pivot] && i<=ub)
            {
                i++;
            }
            while (a[j]>a[pivot] && j>=lb)
            {
                j--;
            }
            if (i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[j];
        a[j]=a[pivot];
        a[pivot]=temp;
        quick_sort(a,lb,j-1);
        quick_sort(a,j+1,ub);
    }
}

int main()
{
int s,i,count=0;
cout<<"Enter Size Of Array : ";
cin>>s;
float *a=new float[s+1];
cout<<"Enter elements of Array :\n";
for(i=0;i<s;i++)
{
    cin>>*(a+i);
}
quick_sort(a,0,s-1);
cout<<"\nAfter Quick Sort...\n\n";
for(i=0;i<s;i++)
{
        cout<<"  "<<a[i];
        count++;
        if(count%4==0)
            cout<<"\n";
}
return 0;
}
