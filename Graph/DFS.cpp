#include<iostream>
using namespace std;

int g[10][10], visited[10],n;

void dfs(int x)
{
    cout<<x;
    visited[x]=1;
    for(int k=0;k<n;k++)
    {
            if(!visited[k] && g[x][k]==1)
              {
                dfs(k);
              }
    }
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

    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }

    dfs(0);


}
