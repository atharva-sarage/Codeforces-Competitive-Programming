#include<bits/stdc++.h>
#define ll long long

using namespace std;
int n,m,x1,y1,x2,y2,temp;
char ar[505][505];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool isval(int a,int b)
{
    return a>=1&&a<=n&&b>=1&&b<=m;
}
void dfs(int a,int b)
{
    
    if(a==x2&&b==y2&&ar[a][b]=='X')
    {
        temp=1;
        return;
    }
    if(ar[a][b]=='.')
        ar[a][b]='X';
    else
        return;
    for(int i=0;i<4;i++)
    {
        int a1=a+dx[i];
        int b1=b+dy[i];
        if(isval(a1,b1))
        {
            dfs(a1,b1);
        }

    }
}
int main()
{
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cin>>ar[i][j];
    }
    cin>>x1>>y1>>x2>>y2;
    ar[x1][y1]='.';
    dfs(x1,y1);
    if(temp)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}