#include<stdio.h>
#include<iostream>
using namespace std;
void selection_sort(float *a,int size,int start){
if(start<size){
float tem,min=a[start],ch_min=a[start];
for(int i=start;i<size;i++){
    if(a[i]<min && a[i]<ch_min){
        ch_min=a[i];
        tem=a[i];
        a[i]=a[start];
        a[start]=tem;
    }
}
selection_sort(a,size,++start);
}
else{
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
selection_sort(a,s,0);
cout<<"\nAfter Selection Sort...\n\n";
for(int i=0;i<s;i++)
   {
    cout<<"  "<<a[i];
    count++;
        if(count%4==0)
            cout<<"\n";
   }
return 0;
}

