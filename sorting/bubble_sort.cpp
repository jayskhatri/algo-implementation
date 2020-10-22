#include<stdio.h>
#include<iostream>
using namespace std;

void bubble_sort(float *a,int size){
int pass;
float temp;
for(int i=0;i<size;i++){
        pass=0;
    for(int j=0;j<size-i-1;j++){
        if(a[j]>a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            pass++;
        }
    }
    if(pass==0)
        return;
}
}

int main(){
int s,val,count=0;
cout<<"Enter Size Of Array :";
cin>>s;
cout<<"Enter elements of Array :\n";
float *a=new float[s+1];
for(int i=0;i<s;i++)
    cin>>*(a+i);
bubble_sort(a,s);
cout<<"\n\nAfter Bubble Sort...\n";
for(int i=0;i<s;i++)
    {   cout<<"  "<<a[i];
        count++;
        if(count%4==0)
            cout<<"\n";
    }
return 0;
}

