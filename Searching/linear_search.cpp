
#include <iostream>
using namespace std;
int lin_search(int temp[],int value,int pos,int s){
    if (temp[pos]==value)
        return pos;
    else{
        if (pos==s)
                return -1;
        else
            lin_search(temp,value,++pos,s);
    }
}


int main(){
int size, result;
int val,a[100];

cout<<"Enter Size Of Array :";
cin>>size;
cout<<"Enter elements of Array : \n";
for(int i=0;i<size;i++){
    cin>>a[i];
}
cout<<"Enter element for Search : ";
cin>>val;
result=lin_search(a,val,0,size);

if(result==-1)
    cout<<"\n\nElement Not Found...";
else
    cout<<"\nEntered element "<<val<<" is present in position of "<<result+1;

return 0;
}
