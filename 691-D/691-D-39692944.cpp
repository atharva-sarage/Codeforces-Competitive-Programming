#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
typedef long long  LL;
int fa[1000100];
int a[1000100];
priority_queue<int> G[1000100];
int Find(int x)
{
    return (x==fa[x])?x:(fa[x]=Find(fa[x]));
}

void Union(int x,int y)
{
    int rx=Find(x),ry=Find(y);
    if(rx!=ry)  fa[ry]=rx;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    memset(fa,0,sizeof fa);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) {
        int x,y;scanf("%d %d",&x,&y);Union(x,y);
        //fa[Find(x)]=Find(y);
    }
    for(int i=1;i<=n;i++) {
        G[Find(i)].push(a[i]);
    }
    /*
    for(int i=1;i<=n;i++) {
        for(auto e:G[i]) cout<<e<<" ";cout<<endl;
    }
    */
    for(int i=1;i<=n;i++) {
        printf("%d ",G[Find(i)].top());
      // cout<<G[Find(i)].top()<<" ";
        G[Find(i)].pop();
    }
    return 0;
}