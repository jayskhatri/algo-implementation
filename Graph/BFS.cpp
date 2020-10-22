#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;

int g[10][10],visited[10],n;
    queue<int> q;

void bfs()
{
    cout<<" "<<q.front();

    visited[q.front()]=1;

    for(int k=0;k<n;k++)
    {
           if(!visited[k] && g[q.front()][k]==1)
              {
                  q.push(k);
              }
    }
     q.pop();

     if(q.empty())

     {
        exit(0);
     }

    bfs();
}

int main()
{

    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter adj matrix: \n";
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
          cout<<"["<<i<<"]""["<<j<<"] = ";
           cin>>g[i][j];

       }
    }
    q.push(0);

    bfs();
}
