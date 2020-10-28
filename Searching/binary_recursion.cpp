#include<stdlib.h>
#include<iostream>
using namespace std;

void bin_rec(int *a,int x,int start,int end){
 int flag,mid=(start+end)/2;
    if (end<start){
        cout<<"NOT FOUND..";
        exit(0);
    }
    if (a[mid]==x){
            flag=mid;
            cout<<"Value of "<<a[mid];
            cout<<"\tFound at position "<<(flag+1)<<"\n";
    }
    else{
    if (x<a[mid]){
        bin_rec(a,x,0,mid);
    }
    else{
        bin_rec(a,x,mid+1,end);
    }

}
}
int main(){
int s,val;
cout<<"Enter Size Of Array :";
cin>>s;
int *a=new int[s+1];
for(int i=0;i<s;i++)
    cin>>*(a+i);
cout<<"\nEnter element for Search : ";
cin>>val;
bin_rec(a,val,0,s-1);
return 0;
}
