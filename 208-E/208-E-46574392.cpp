#include<bits/stdc++.h>
using namespace std;
# define mx 100005
# define D 20
# define pb push_back
vector <int> adj[mx];
vector<int> depth[mx];
int t1[2][mx],par[21][mx],depth1[mx],t=0;
void addedge(int u,int v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}
void dfs(int u,int p,int d)
{
	depth1[u]=d;
	t1[0][u]=++t;
	par[0][u]=p;
	depth[d].pb(t);
	for(auto v:adj[u])
	{
		if(v==p)continue;
		dfs(v,u,d+1);
	}
	t1[1][u]=t;
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
    if(depth1[i]>depth1[j])
        i=walk(i,depth1[i]-depth1[j]);
    if(depth1[i]<depth1[j])
        j=walk(j,depth1[j]-depth1[i]);
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
	int n;
	cin>>n;
	vector <int> vec;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x==0)
			vec.pb(i);
		else 
			addedge(i,x);
	}
	memset(par,-1,sizeof(par));
	for(auto z:vec)
	{
		dfs(z,-1,0);
	}
	for(int  d=1;d<=D;d++)
       {
            for(int i=1;i<=n;i++)
            { 
                int  mid=par[d-1][i];
                if(mid!=-1)
                par[d][i]=par[d-1][mid];
       		 }
       }
	int q;
	cin>>q;
	while(q--)
	{
		int v,p,ans;
		cin>>v>>p;
		int lca=walk(v,p);
		if(lca==-1)
			{cout<<0<<" ";continue;}
		p+=depth1[lca];
		//cout<<lca<<endl;
		//cout<<t1[1][lca]<<" "<<t1[0][lca]<<endl;
		if(!depth[p].empty() && lca!=-1)
		ans=upper_bound(depth[p].begin(),depth[p].end(),t1[1][lca])-(lower_bound(depth[p].begin(),depth[p].end(),t1[0][lca]))-1;
		else
		ans=0;
		cout<<ans<<" ";
	}
}