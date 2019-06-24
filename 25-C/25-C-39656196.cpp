#include<bits/stdc++.h>
using namespace std;
long long d[305][305][2];
int main()
{
  int n;
  cin>>n;

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>d[i][j][0];
    }
  }
  int m,c=0;
 
  cin>>m;
  for(int i=0;i<m;i++)
  {
   long long sum=0;
    long x,y,z;
    cin>>x>>y>>z;
    x--;
    y--;
    if(d[x][y][c]>z)
    {
      c=1^c;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
          d[i][j][c]=min(d[i][j][1^c],min(d[i][x][1^c]+z+d[y][j][1^c],d[i][y][1^c]+z+d[x][j][1^c]));
        }
      }
    }

     for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      sum+=d[i][j][c];
    }
  }
    cout<<sum<<" ";
  }
 printf("\n");


}