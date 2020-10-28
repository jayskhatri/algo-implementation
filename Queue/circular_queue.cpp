#include<iostream>
using namespace std;
int ar[10],x, f=-1,r=-1;
class CqueueC{

public:   void  Cqinsert(int n, int x){
        if((r>=n-1 & f=0) || (f=r+1))
            {cout<<"Queue Overflow !\n";
            return;
            }

           if(r==n-1)
                r=0;
           else
                r=r+1;

            ar[r]=x;

            if(f==-1)
            {
                f=0;
            }

    }
 void  Cqdelete(){
         if(f==-1)
            {
               cout<<"Queue Underflow !\n";

            }

            int y=ar[f];

            if(f==r)
                f=r=-1;
            else
                if(f==n-1)
                f=0;
            else
                f=f+1;
    }
