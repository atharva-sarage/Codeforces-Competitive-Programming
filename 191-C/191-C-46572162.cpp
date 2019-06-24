#include<bits/stdc++.h>
using namespace std;
# define mx 100005
# define mp make_pair
# define pb push_back
# define ff first
# define ss second
# define D 20
vector <pair<int,int> > adj[mx];
int final[mx],parent[mx],val[mx],depth[mx],par[21][mx],edge[mx],deg[mx];
void addedge(int u,int v,int w)
{
	adj[u].pb(mp(v,w));
	adj[v].pb(mp(u,w));
}
void dfs(int u,int p,int id)
{
	parent[u]=p;
	par[0][u]=p;
	edge[u]=id;
	if(u!=1)
	depth[u]=1+depth[p];
	for(auto v:adj[u])
	{
		if(v.ff==p)continue;	
		dfs(v.ff,u,v.ss);
	}
}
int  walk(int  i,int  k)
{
    for(int  d=0;d<=D;d++)
    {
        if((k & 1<<d )>0)
            i=par[d][i];
    }
    return i;
}

int  lca(int  i,int  j)
{
    if(depth[i]>depth[j])
        i=walk(i,depth[i]-depth[j]);
    if(depth[i]<depth[j])
        j=walk(j,depth[j]-depth[i]);
    if(i==j)
        return i;        

    for(int  d=D;d>=0;d--)
    {
        if(par[d][i]!=par[d][j])
        {
            i=par[d][i];
            j=par[d][j];
        }
    }
    return par[0][i];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		addedge(x,y,i);
		deg[x]++;
		deg[y]++;
	}
	memset(par,-1,sizeof(par));
	dfs(1,-1,-1);
	for(int  d=1;d<=D;d++)
       {
            for(int i=1;i<=n;i++)
            { 
                int  mid=par[d-1][i];
                if(mid!=-1)
                par[d][i]=par[d-1][mid];
       		 }
       }
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int x,y;
		cin>>x>>y;
		int z=lca(x,y);	
		val[x]++;
		val[y]++;
		val[z]-=2;
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==1)
			q.push(i);
	}	
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		if(v==1)continue;
		final[edge[v]]=val[v];
		val[parent[v]]+=val[v];
		deg[parent[v]]--;
		if(deg[parent[v]]==1)
			q.push(parent[v]);
	}
	for(int i=0;i<n-1;i++)
	{
		cout<<final[i]<<" ";
	}
}